#include "Radotech.h"

bool Radotech::isOn = false;
int Radotech::battery = 100;

Radotech::Radotech() {}

bool Radotech::on() { return isOn; }

// generates random points for reading
std::array<int, 24> Radotech::getReading() {
    std::srand(std::time(0));
    std::array<int, 24> readings;

    int seed = 0;
    
    for (int i = 0; i < 12; ++i) {
        readings[i] = 5 + rand() % (200 - 5 + 1);
        seed = readings[i];

        if (seed - 10 < 5) seed += 10;
        else if (seed + 10 > 200) seed -= 10;

        // the corresponding point on the other hand/foot is generated within a range of 10 from the first
        readings[i+6] = (seed - 10) + rand() % ((seed + 10) - (seed - 10) + 1);
    }

    return readings;
}
