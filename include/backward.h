#ifndef _ELMA_BACKWARD_H
#define _ELMA_BACKWARD_H

#include "car.h"
#include "elma/elma.h"
namespace driving_car {

    using namespace std::chrono;
    using namespace elma;

    class Car; // Declare containing class so it can be refered to here
                     // before it is defined in car.h

    //! A State class to represen the state in which the car is on the Reverse Gear
    class BackwardState : public State {

        public:
        //! Construct a new backward state
        BackwardState() : State("backward") {}

        //! Perform actions required when switching from other states to backward
        void entry(const Event& e);
        //! Perform actions during this state
        void during();

        //! Perform actions required when switching from backward to other states
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        Car& car();
        private:
        double velocity;
        double k = 0.02;
        const double m = 1000;

    };

}

#endif