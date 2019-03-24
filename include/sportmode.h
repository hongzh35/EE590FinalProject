#ifndef _ELMA_SPORT_MODE_H
#define _ELMA_SPORT_MODE_H

#include "car.h"
#include "elma/elma.h"
namespace driving_car {

    using namespace std::chrono;
    using namespace elma;

    class Car; // Declare containing class so it can be refered to here
                     // before it is defined in car.h

    //! A State class to represen the state in which the car is on Sport Mode Gear
    class SportMode : public State {

        public:
        //! Construct a new sport state
        SportMode() : State("sport") {}

        //! Perform actions required when switching from other states to sport
        void entry(const Event& e);

        //! Perform actions during this state
        void during();

        //! Perform actions required when switching from sport to other states
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        Car& car();
        private:
        double velocity;



    };

}

#endif