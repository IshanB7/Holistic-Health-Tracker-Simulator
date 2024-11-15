#include "Profile.h"

Profile::Profile() {}

std::array<int, 12> Profile::getReading(int i) const{
    return readings.at(i);
}

void Profile::addReading(vector<int> dataPoints) {
    for (size_t i = 0; i < dataPoints.size(); ++i) latestReading[i] = dataPoints.at(i);
    analyzeReading();
}

void Profile::analyzeReading() {
    std::array<int, 12> newAnalysis;

    for (int i = 0; i < 12; ++i) {
        newAnalysis[i] = (dataPoints[i] + dataPoints[i+6]) / 2;
    }

    readings.push_back();
}