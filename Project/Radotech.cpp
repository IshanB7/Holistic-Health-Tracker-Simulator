#include "Radotech.h"
#include "radotechwidget.h"

bool Radotech::isOn = false;
bool Radotech::onSkin = false;
int Radotech::battery = 100;
bool Radotech::simulate = false;
RadotechWidget* Radotech::widget = nullptr;

Radotech::Radotech(RadotechWidget* rw) { widget = rw; }

// getters
bool Radotech::on() { return isOn; }
bool Radotech::skinOn() { return onSkin; }

// generates random points for reading
std::array<int, 24> Radotech::getReading() {
    std::srand(std::time(0));
    std::array<int, 24> readings;

    int seed = 0;
    
    for (int i = 0; i < 6; ++i) {
        readings[i] = 5 + rand() % (200 - 5 + 1);
        seed = readings[i];

        if (seed - 10 < 5) seed += 10;
        else if (seed + 10 > 200) seed -= 10;

        // the corresponding point on the other hand is generated within a range of 10 from the first
        readings[i+6] = (seed - 10) + rand() % ((seed + 10) - (seed - 10) + 1);
    }

    for (int i = 12; i < 18; ++i) {
        readings[i] = 5 + rand() % (200 - 5 + 1);
        seed = readings[i];

        if (seed - 10 < 5) seed += 10;
        else if (seed + 10 > 200) seed -= 10;

        // the corresponding point on the other foot is generated within a range of 10 from the first
        readings[i+6] = (seed - 10) + rand() % ((seed + 10) - (seed - 10) + 1);
    }

    return readings;
}

// tells RadotechWidget what point MeasureWidget is currently on
void Radotech::showPoint(std::string pointName) { widget->setPointLabel(pointName); }

// getter for simulate
bool Radotech::simulating() { return simulate; }

// setter for skin off, for when a point has been measured
void Radotech::skinOff() { onSkin = false; }
