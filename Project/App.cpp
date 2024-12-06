#include "App.h"
#include "Radotech.h"
#include <iostream>

Profile* App::profiles[5] = {nullptr};
Profile* App::current = nullptr;

// instantiate the app, comes with one profile and a reading for the profile
App::App() {
    profiles[0] = new Profile("Demo", false, 45, 145);
    for (int i = 1; i < 5; ++i) profiles[i] = nullptr;
    profiles[0]->addReading(Radotech::getReading());
    current = profiles[0];
}

App::~App() {
    for (int i = 0; i < 5; ++i) {
        if (profiles[i] != nullptr) delete profiles[i];
    }
}

Profile* App::user() { return current; }

// returns a list of all created profiles as a vector
std::vector<Profile *> App::users() {
    std::vector<Profile *> returnVector;
    for (int i = 0; i < 5; ++i) {
        if (profiles[i] != nullptr) {
            returnVector.push_back(profiles[i]);
        }
    }

    return returnVector;
}

// set another profile as active
void App::setCurrentProfile(Profile* p) { current = p; }

void App::removeProfile(Profile* p) {
    int i = 0;

    // remove the profile that matches the pointer
    for (; i < 5; ++i) {
        if (profiles[i] == p) {
            delete profiles[i];
            break;
        }
    }

    // shift everything left
    for (; i < 4; ++i) { profiles[i] = profiles[i+1]; }
    profiles[4] = nullptr;

    current = profiles[0];
}

void App::addProfile(std::string newProfileName, bool newIsMale, short newWeight, short newHeight) {
    unsigned int i; // Used as a counter
    // Find first available pointer in the profile array to point to the new profile
    for (i = 0; i < 5; ++i) {
        if (profiles[i] == nullptr) {
            // Found an available pointer, create a new profile object
            profiles[i] = new Profile(newProfileName, newIsMale, newWeight, newHeight);
            if (current == nullptr) current = profiles[i];
            return;
        }
    }
}
