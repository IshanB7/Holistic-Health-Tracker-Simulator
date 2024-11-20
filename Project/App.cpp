#include "App.h"
#include "Radotech.h"

Profile* App::profiles[5] = {nullptr}; 
int App::currentProfile = 0;

App::App() {
    currentProfile = 0;
    profiles[0] = new Profile("Demo");
    for (int i = 1; i < 5; ++i) profiles[i] = nullptr;
    profiles[0]->addReading(Radotech::getReading());
}

App::~App() {
    for (int i = 0; i < 5; ++i) {
        if (profiles[i] != nullptr) delete profiles[i];
    }
}

Profile* App::user() { return profiles[currentProfile]; }
