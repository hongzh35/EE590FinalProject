#ifndef _ELMA_PARKING_BRAKE_H
#define _ELMA_PARKING_BRAKE_H

#include "car.h"

namespace driving_car {

    using namespace std::chrono;
    using namespace elma;

    class Car; // Declare containing class so it can be refered to here
                     // before it is defined in car.h

    //! A State class to represen the state in which the car has Parking Brake on
    class ParkingBrakeState : public State {

        public:
        //! Construct a new park state
        ParkingBrakeState() : State("park") {}
        //! Perform actions required when switching from other states to park 
        //! \param e The event that triggered the transition
        void entry(const Event& e) {}

        //! Perform actions during this state
        void during();

        //! Perform actions required when switching from park to other states
        //! \param e The event that triggered the transition
        void exit(const Event& e) {}

        //! \return A reference to the containing finite state machine object
        Car& car();

    };

}

#endif