#include "Profile.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>

const std::array <std::pair<int, int>, 12> Profile::range = {{
    {60, 80}, {50, 80}, {45, 60}, {50, 80}, {60, 90}, {60, 90},
    {50, 70}, {40, 55}, {45, 65}, {45, 65}, {40, 60}, {45, 65}
}};

Profile::Profile(std::string newProfileName) {
    // Truncate profile name to first 32 characters
    this->name = newProfileName.substr(0, MAX_PROFILE_NAME_LENGTH - 1);
}

const std::array<std::pair<int, int>, 24>& Profile::getReading(int i) const{
    return readings.at(i);
}

void Profile::addReading(std::array<int, 24> dataPoints) {
    std::array <std::pair<int, int>, 24> newAnalysis;
    int reading;

    for (int i = 0; i < 12; ++i) {

        reading = 0;
        if (dataPoints[i] < range[i].first) {
            reading = -1;
        } else if (dataPoints[i] > range[i].second) {
            reading = 1;
        }
        newAnalysis[2*i] = {dataPoints[i], reading};

        reading = 0;
        if (dataPoints[i+6] < range[i].first) {
            reading = -1;
        } else if (dataPoints[i+6] > range[i].second) {
            reading = 1;
        }
        newAnalysis[2*i+1] = {dataPoints[i+6], reading};

    }

    if (readings.size() > 10) { 
        readings.pop_back(); 
        readingTimes.pop_back();
    }
    readings.insert(readings.begin(), newAnalysis);

    const auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&now_time);
    std::ostringstream oss;
    oss << std::put_time(&local_time, "%d-%m %H:%M:%0S");
    readingTimes.insert(readingTimes.begin(), oss.str());
    std::cout << oss.str() << std::endl;
}

const std::string& Profile::getName() const { return name; }

void Profile::setName(std::string newName) { name = newName; }
