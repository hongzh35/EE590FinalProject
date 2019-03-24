#ifndef _ELMA_DRIVING_CAR_H
#define _ELMA_DRIVING_CAR_H

#include "elma/elma.h"

#include "forward.h"
#include "parkingbrake.h"
#include "user_interface.h"
#include "backward.h"
#include "protectstate.h"
#include "stop.h"
#include "sportmode.h"
#include <ncurses.h>

namespace driving_car {
    using namespace std::chrono;
    using std::vector;
    using namespace elma;
    //! Example: A car simulation process, that inherits from StateMachine
    class Car : public StateMachine {
        public:
        //! Make a new car
        Car();

        //! Get the real-time velocity of the car
        double currentvelocity();

        //! Get the real-time mileage that the car pass through during this simulation
        double currentmileage();

        //! Telling the state the driver is doing a bad operation
        void badoperation();

        //! Telling the state the driver is doing a good operation
        void goodoperation();

        //! Update the warning message if the driver is doing a bad operation
        void warningmessage();

        //! Return the current state of the car
        std::string currentstate();

        //! Return the warning message
        std::string currentwarning();

        //! Store the latest state of the car
        void changestate();

        //! Return the latest state of the car
        std::string viewlast();

        //! Change the accelerate coefficient of the car
        void changeacce(double acce);

        //! Process the throtte or brake to update the velocity of the car
        void moving();

        //! Return if the driver did a bad operation
        bool operationstate();

        //! Nothing to do to reset
        void reset() {}

        private:
        ForwardState forward;
        ParkingBrakeState park;
        BackwardState backward;
        StopState stop;
        SportMode sport;
        ProtectState check;
        double velocity = 0.0;
        double mileage = 0.0;
        double force;
        double delta_time;
        std::string laststate;
        std::string warning;
        bool correctoperation = true;
        double k = 0.02;
        const double m = 1000;
    }; 
}
#endif


    

