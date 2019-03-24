#include <iostream>
#include <chrono>
#include <vector>

#include "car.h"

using namespace std::chrono;
using namespace elma;
using namespace driving_car;

Car& BackwardState:: car() { return (Car&) state_machine(); }

void BackwardState::entry(const Event& e) {
    if (car().viewlast()=="protect"){
        car().badoperation();
    }
    
}
void BackwardState::during() {
    car().warningmessage();
    car().moving();
}

void BackwardState::exit(const Event& e) {
    car().changestate();
}
