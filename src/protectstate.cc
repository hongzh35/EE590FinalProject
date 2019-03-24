#include <iostream>
#include <chrono>
#include <vector>

#include "car.h"
#include <unistd.h>

using namespace std::chrono;
using namespace elma;
using namespace driving_car;

Car& ProtectState:: car() { return (Car&) state_machine(); }

void ProtectState::during() {
    if(car().currentvelocity()>0.001){
        car().badoperation();
        car().warningmessage();
        if(car().viewlast() == "forward"){
            emit(Event("stayforward"));
        }
        else{
            emit(Event("staybackward"));
        }
    }
    else{
        car().goodoperation();
        emit(Event("continue"));
    }
}
