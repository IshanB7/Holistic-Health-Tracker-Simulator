#include "Profile.h"

Profile::Profile(std::string name): name(name) {}

std::array<int, 12> Profile::getReading(int i) const{
    return readings.at(i);
}

void Profile::addReading(std::array<int, 24> dataPoints) {
    for (size_t i = 0; i < dataPoints.size(); ++i) latestReading[i] = dataPoints.at(i);
    analyzeReading();
}

void Profile::analyzeReading() {
    std::array<int, 12> newAnalysis;

    for (int i = 0; i < 12; ++i) {
        newAnalysis[i] = (latestReading[i] + latestReading[i+6]) / 2;
    }

    readings.push_back(newAnalysis);
}

const std::string& Profile::getName() const { return name; }
