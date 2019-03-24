#include <chrono>
#include <vector>

#include "car.h"
#include <unistd.h>

using namespace std::chrono;
using namespace elma;
using namespace driving_car;

Car::Car(): StateMachine("car") {

    // Define state machine initial states and transitions here
    set_initial(stop);
    set_propagate(false);
    add_transition("girdup",stop,forward);
    add_transition("girdup",forward,sport);
    add_transition("girdup",backward,check);
    add_transition("girddown",forward,check);
    add_transition("girddown",stop,backward);
    add_transition("girddown",sport,forward);
    add_transition("continue",check,stop);
    add_transition("stayforward",check,forward);
    add_transition("staybackward",check,backward);
    add_transition("girdright",stop,park);
    add_transition("girdleft",park,stop);

    reset();
}

void Car::moving() {

    if ( channel("Throttle").nonempty() ) {
        force = channel("Throttle").latest();
        delta_time = channel("Delta").latest();
        velocity +=  (delta_time/1000) * ( - k * velocity + force ) / m;
        if ( channel("Brake").nonempty() ) {
            if(channel("Brake").latest()==1){
                auto temp = velocity;
                velocity = velocity - 3;
                if(velocity*temp<=0){
                    velocity = 0.0;
                }
            }
        }
    }
    mileage += velocity * 0.01;

    channel("Velocity").send(velocity);
}
double Car::currentvelocity(){
    if(currentstate() == "backward"){
        return -velocity;
    }
    else{
        return velocity;
    }
    
}
void Car::badoperation(){
    correctoperation = false;
}
void Car::goodoperation(){
    correctoperation = true;
}
bool Car::operationstate(){
    return correctoperation;
}
double Car::currentmileage(){
    return mileage;
}

void Car::warningmessage(){
    if(channel("Throttle").size()>0){
        if(channel("Throttle").latest()>0.1 and current().name() == "stop" ){
            warning = "Please Switch the Gear First!";
            badoperation();
        }
        else if (channel("Throttle").latest()>0.1 and current().name() == "park") {
            warning = "Please Release the Parking Brake!";
            badoperation();
        }
        else if(current().name()== "protect"){
            warning = "Cannot Switch Gear When Drving!";
            badoperation();
        }
        else if (channel("Throttle").latest()>0.1){
            warning = "None";
            goodoperation();
        }
    }

}

std::string Car::currentstate(){
    return current().name();
}
std::string Car::currentwarning(){
    return warning;
}

void Car::changestate(){
    laststate = current().name();
}
std::string Car::viewlast(){
    return laststate;
}
void Car::changeacce(double acce){
    k = acce;
}