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
    static void showPoint(std::string);
    static bool simulating();
    static void skinOff();

private:
    static bool isOn;
    static bool onSkin;
    static bool simulate;
    static int battery;
    static RadotechWidget* widget;

};

#endif
