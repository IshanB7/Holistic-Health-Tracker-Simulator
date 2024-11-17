#ifndef RADOTECH_H
#define RADOTECH_H

#include <array>
#include <cstdlib>
#include <ctime>

class Radotech {

public:
    Radotech();
    std::array<int, 24> getReading() const;

private:
    bool isOn;
    int battery;

}

#endif