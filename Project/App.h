#ifndef APP_H
#define APP_H

#include "Profile.h"

class App {

public:
    App();
    ~App();
    static Profile* user();
    static void setCurrentProfile(int);

private:
    static Profile* profiles[5];
    static int currentProfile;

};

#endif
