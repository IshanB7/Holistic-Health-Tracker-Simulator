#ifndef PROFILE_H
#define PROFILE_H

#include <vector>
#include <array>
#include <string>

class Profile {

public:
    Profile(std::string);
    std::array<int, 12> getReading(int) const;
    void addReading(std::array<int, 24>);
    const std::string& getName() const;

private:
    std::vector<std::array<int, 12>> readings;
    int latestReading[24];
    std::string name;
    void analyzeReading();
};

#endif