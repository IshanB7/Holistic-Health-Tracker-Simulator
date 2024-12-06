#ifndef APP_H
#define APP_H

#include "Profile.h"
#include <vector>

class App {

public:
    App();
    ~App();
    static std::vector<Profile*> users();
    static Profile* user();
    static void setCurrentProfile(Profile*);
    static void removeProfile(Profile*);
    static void addProfile(std::string, bool, short, short);

private:
    // list of all profiles and one active profile
    static Profile* profiles[5];
    static Profile* current;

};

#endif
