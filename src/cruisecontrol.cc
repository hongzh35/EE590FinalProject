#include <iostream>
#include <chrono>
#include "elma/elma.h"
#include "cruisecontrol.h"

using namespace std::chrono;
using std::vector;
using namespace elma;
using namespace cruise_control;

void CruiseControl::update() {
    watch("braking", [this](Event& e) {
        temp = 1;
    });
    channel("Brake").send(temp);
    temp = 0;
    watch("desired speed", [this](Event& e) {
        desired_speed = e.value();
    });
    if ( channel("Velocity").nonempty() ) {
        speed = channel("Velocity").latest();
    }
    _throttle = -KP*(speed - desired_speed);
    
    if ( channel("Velocity").nonempty() ) {
        desired_speed = channel("Velocity").latest();
    }
    else{
        desired_speed = 0.0;
    }
    channel("Throttle").send(_throttle);
    channel("Delta").send(delta());
}