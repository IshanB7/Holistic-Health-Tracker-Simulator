#ifndef RADOTECH_H
#define RADOTECH_H

#include <array>
#include <cstdlib>
#include <ctime>

class RadotechWidget;

class Radotech {

friend class RadotechWidget;

public:
    Radotech();
    static std::array<int, 24> getReading();
    static bool on();

private:
    static bool isOn;
    static int battery;


};

#endif
