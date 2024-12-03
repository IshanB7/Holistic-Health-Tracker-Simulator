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
    /*
     * Readings are stored in an array of integer pairs in the following format:
     * <value, isnormal>
     * value: the actual measured value
     * isnormal: -1 = low, 0 = normal, 1 = high
     *
     * Readings are stored in the following order:
     * readings[0]: left lung
     * readings[1]: right lung
     * readings[2]: left pericardium
     * readings[3]: right pericardium
     * readings[4]: left heart
     * readings[5]: right heart
     * readings[6]: left small intestine
     * readings[7]: right small intestine
     * readings[8]: left lymph vessel
     * readings[9]: right lymph vessel
     * readings[10]: left large intestine
     * readings[11]: right large intestine
     * readings[12]: left pancreas
     * readings[13]: right pancreas
     * readings[14]: left liver
     * readings[15]: right liver
     * readings[16]: left kidney
     * readings[17]: right kidney
     * readings[18]: left bladder
     * readings[19]: right bladder
     * readings[20]: left gallbladder
     * readings[21]: right gallbladder
     * readings[22]: left stomach
     * readings[23]: right stomach
    */
    std::vector <std::array <std::pair<int, int>, 24>> readings;
    std::vector <std::string> readingTimes;
    std::string name;
    bool isMale;
    short weight;
    short height;

    static const std::array<std::pair <int, int>, 12> range;
    
};

#endif
