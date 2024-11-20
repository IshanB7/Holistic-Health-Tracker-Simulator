#include "Profile.h"

const std::array <std::pair<int, int>, 12> Profile::range = {{
    {60, 80}, {50, 80}, {45, 60}, {50, 80}, {60, 90}, {60, 90},
    {50, 70}, {40, 55}, {45, 65}, {45, 65}, {40, 60}, {45, 65}
}};

Profile::Profile(std::string name): name(name) {}

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

    readings.push_back(newAnalysis);
}

const std::string& Profile::getName() const { return name; }
