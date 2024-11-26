#ifndef RADOTECH_H
#define RADOTECH_H

#include <array>
#include <cstdlib>
#include <ctime>

class RadotechWidget;

class Radotech {

friend class RadotechWidget;

public:
    Radotech(RadotechWidget*);
    static std::array<int, 24> getReading();
    static bool on();
    static bool skinOn();
    static void toggleSkin();

private:
    static bool isOn;
    static bool onSkin;
    static int battery;
    static RadotechWidget* widget;

};

#endif
