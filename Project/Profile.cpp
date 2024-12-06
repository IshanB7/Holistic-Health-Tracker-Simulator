#include "Profile.h"
#include <chrono>
#include <iomanip>
#include <sstream>

// healthy range for all 12 organs
const std::array <std::pair<int, int>, 12> Profile::range = {{
    {60, 80}, {50, 80}, {45, 60}, {50, 80}, {60, 90}, {60, 90},
    {50, 70}, {40, 55}, {45, 65}, {45, 65}, {40, 60}, {45, 65}
}};

Profile::Profile(std::string newProfileName, bool newIsMale, short newWeight, short newHeight):
    isMale(newIsMale), weight(newWeight), height(newHeight)
{
    // Truncate profile name to first 32 characters
    this->name = newProfileName.substr(0, MAX_PROFILE_NAME_LENGTH - 1);
}

// returns the reading at index i
const std::array<std::pair<int, int>, 24>& Profile::getReading(int i) const{ return readings.at(i); }

// analyzes a reading and adds it to the array of readings
void Profile::addReading(std::array<int, 24> dataPoints) {
    std::array <std::pair<int, int>, 24> newAnalysis;
    int reading;

    // attaches an int {-1, 0, 1} to each data point
    // -1 for below normal reading
    // 0 for normal reading
    // 1 for above normal reading

    // history tab only needs to access second element in pair
    // to decide what color to give each organ/data point

    // analyze all points for H1,...,H6
    for (int i = 0; i < 6; ++i) {

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

    // analyze all points for F1,...,F6
    for (int i = 12; i < 18; ++i) {

        reading = 0;
        if (dataPoints[i] < range[i-6].first) {
            reading = -1;
        } else if (dataPoints[i] > range[i-6].second) {
            reading = 1;
        }
        newAnalysis[2*i - 12] = {dataPoints[i], reading};

        reading = 0;
        if (dataPoints[i+6] < range[i-6].first) {
            reading = -1;
        } else if (dataPoints[i+6] > range[i-6].second) {
            reading = 1;
        }
        newAnalysis[2*i+1 - 12] = {dataPoints[i+6], reading};
    }

    // keep track of 10 latest readings
    if (readings.size() > 10) { 
        readings.pop_back(); 
        readingTimes.pop_back();
    }
    readings.insert(readings.begin(), newAnalysis);

    // store the time of the reading as a title for the reading in the history screen
    const auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&now_time);
    std::ostringstream oss;
    oss << std::put_time(&local_time, "%d-%m %H:%M:%S");
    readingTimes.insert(readingTimes.begin(), oss.str());
}

QString Profile::getAdvice(){ return adivce; }

void Profile::setAdvice(QString advice){ this->adivce=advice; }
