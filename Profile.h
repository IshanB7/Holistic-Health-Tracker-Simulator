#ifndef PROFILE_H
#define PROFILE_H

#include <vector>
#include <array>

class Profile {

public:
    Profile();
    std::array<int, 12> getReading(int) const;
    void addReading(std::vector<int>);

private:
    std::vector<std::array<int, 12>> readings;
    int latestReading[24];

    void analyzeReading();
};

#endif