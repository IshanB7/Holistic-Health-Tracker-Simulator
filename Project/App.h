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
    static void setCurrentProfile(int);

private:
    static Profile* profiles[5];
    static int currentProfile;

};

#endif
