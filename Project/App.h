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
    static void addProfile(std::string);

private:
    // TODO: refactor so that the enumber of profiles is not hardcoded to 5
    // This value is also assumed in other classes so they will also need to be modified
    // git testing
	//
	static Profile* profiles[5];
    static Profile* current;
	static ignore;
};

#endif
