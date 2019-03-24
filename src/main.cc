#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "car.h"
#include "cruisecontrol.h"

using namespace std::chrono;
using namespace elma;
using namespace driving_car;
using namespace cruise_control;

int main() {

     Manager m;
    
     Car car;
     CruiseControl cc("Control");
     UserInterface ui(car);
     Channel throttle("Throttle");
     Channel velocity("Velocity");  
     Channel delta("Delta");
     Channel brake("Brake");

     m.schedule(ui, 10_ms)
     .schedule(car, 10_ms) 
     .schedule(cc, 10_ms)
     .add_channel(throttle)
     .add_channel(velocity)
     .add_channel(delta)
     .add_channel(brake)
     .init()
     .run();

     endwin();     
}