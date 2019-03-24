#ifndef _ELMA_PROTECT_STATE_H
#define _ELMA_PROTECT_STATE_H

#include "car.h"
#include "elma/elma.h"
#include <ncurses.h>
namespace driving_car {

    using namespace std::chrono;
    using namespace elma;

    class Car; // Declare containing class so it can be refered to here
                     // before it is defined in car.h

    //! A State class to represen the state between the stop state and forward or backward state
    class ProtectState : public State {

        public:
        //! Construct a new protect state
        ProtectState() : State("protect") {}

        //! Perform actions required when switching from other states to protect
        //! \param e The event that triggered the transition
        void entry(const Event& e) {}

        //! Perform actions during this state
        void during();

        //! Perform actions required when switching from protect to other states
        //! \param e The event that triggered the transition
        void exit(const Event& e) {}

        //! \return A reference to the containing finite state machine object
        Car& car();
        private:

    };

}

#endif