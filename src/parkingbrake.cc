#include <iostream>
#include <chrono>
#include <vector>

#include "car.h"

using namespace std::chrono;
using namespace elma;
using namespace driving_car;

Car& ParkingBrakeState:: car() { return (Car&) state_machine(); }

void ParkingBrakeState::during() {
    car().warningmessage();
}
