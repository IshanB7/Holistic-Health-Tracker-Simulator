#ifndef PROFILE_H
#define PROFILE_H

#include <vector>
#include <array>
#include <string>

#define MAX_PROFILE_NAME_LENGTH 32 // Maximum number of characters in a profile name

class ProfilesWidget;
class HistoryWidget;

class Profile {

friend class ProfilesWidget;
friend class HistoryWidget;

public:
    Profile(std::string, bool, short, short);
    const std::array<std::pair<int, int>, 24>& getReading(int) const;
    void addReading(std::array<int, 24>);

private:
    std::vector <std::array <std::pair<int, int>, 24>> readings;
    std::vector <std::string> readingTimes;
    std::string name;
    bool isMale;
    short weight;
    short height;

    static const std::array<std::pair <int, int>, 12> range;
    
};

#endif
