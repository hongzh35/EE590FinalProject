#include <iostream>
#include <chrono>
#include <vector>

#include "car.h"

using namespace std::chrono;
using namespace elma;
using namespace driving_car;

Car& ForwardState:: car() { return (Car&) state_machine(); }
void ForwardState::entry(const Event& e) {
    if (car().viewlast()=="protect"){
        car().badoperation();
    }
    car().changeacce(0.02);
}
void ForwardState::during() {
    car().warningmessage();
    car().moving();
}
void ForwardState::exit(const Event& e) {
    car().changestate();
}