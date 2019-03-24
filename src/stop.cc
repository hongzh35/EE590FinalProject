#include <iostream>
#include <chrono>
#include <vector>

#include "car.h"

using namespace std::chrono;
using namespace elma;
using namespace driving_car;

Car& StopState:: car() { return (Car&) state_machine(); }
void StopState::entry(const Event& e){
    car().goodoperation();
}
void StopState::during() {
    car().warningmessage();
}

