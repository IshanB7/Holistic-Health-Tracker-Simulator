#ifndef PROFILE_H
#define PROFILE_H

#include <vector>
#include <array>
#include <string>

class Profile {

public:
    Profile(std::string);
    const std::array<std::pair<int, int>, 24>& getReading(int) const;
    void addReading(std::array<int, 24>);
    const std::string& getName() const;

private:
    std::vector <std::array <std::pair<int, int>, 24>> readings;
    std::string name;
    static const std::array<std::pair <int, int>, 12> range;
    
};

#endif