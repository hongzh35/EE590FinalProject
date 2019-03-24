#ifndef _ELMA_FORWARD_H
#define _ELMA_FORWARD_H

#include "car.h"
#include "elma/elma.h"
namespace driving_car {

    using namespace std::chrono;
    using namespace elma;

    class Car; // Declare containing class so it can be refered to here
                     // before it is defined in car.h

    //! A State class to represen the state in which the car is on Drive Gear
    class ForwardState : public State {

        public:
        //! Construct a new forward state
        ForwardState() : State("forward") {}

        //! Perform actions required when switching from other states to forward 
        //! \param e The event that triggered the transition
        void entry(const Event& e);

        //! Perform actions during this state
        void during();

        //! Perform actions required when switching from forward to other states
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        Car& car();
        private:

        double k = 0.02;
        const double m = 1000;

    };

}

#endif