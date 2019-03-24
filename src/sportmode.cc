#include <iostream>
#include <chrono>
#include <vector>

#include "car.h"

using namespace std::chrono;
using namespace elma;
using namespace driving_car;

Car& SportMode:: car() { return (Car&) state_machine(); }

void SportMode::entry(const Event& e) {
    car().changeacce(0.01);
    car().goodoperation();
    emit(Event("max speed", 80.0));
}

void SportMode::during() {
    car().moving();
    car().warningmessage();
}

void SportMode::exit(const Event& e) {
    emit(Event("max speed",50.0));
}