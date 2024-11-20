#include "App.h"
#include "Radotech.h"
#include <iostream>

Profile* App::profiles[5] = {nullptr};
Profile* App::current = nullptr;

App::App() {
    profiles[0] = new Profile("Demo");
    profiles[1] = new Profile("Guest");
    for (int i = 2; i < 5; ++i) profiles[i] = nullptr;
    profiles[0]->addReading(Radotech::getReading());
    current = profiles[0];
}

App::~App() {
    for (int i = 0; i < 5; ++i) {
        if (profiles[i] != nullptr) delete profiles[i];
    }
}

Profile* App::user() { return current; }

std::vector<Profile *> App::users() {
    std::vector<Profile *> returnVector;
    for (int i = 0; i < 5; ++i) {
        if (profiles[i] != nullptr) {
            returnVector.push_back(profiles[i]);
        }
    }

    return returnVector;
}

void App::setCurrentProfile(Profile* p) {
    current = p;
}

void App::removeProfile(Profile* p) {
    int i = 0;

    for (; i < 5; ++i) {
        if (profiles[i] == p) {
            delete profiles[i];
            break;
        }
    }

    for (; i < 4; ++i) {
        profiles[i] = profiles[i+1];
        if (profiles[i+1] == nullptr) break;
    }

    current = profiles[0];
}

void App::addProfile(std::string newProfileName) {
    unsigned int i; // Used as a counter
    // Find first available pointer in the profile array to point to the new profile
    for (i = 0; i < 5; ++i) {
        if (profiles[i] == nullptr) {
            // Found an available pointer, create a new profile object
            profiles[i] = new Profile(newProfileName);
            return;
        }
    }
}
