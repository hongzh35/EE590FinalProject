#ifndef _ELMA_CRUISE_CONTROL_H
#define _ELMA_CRUISE_CONTROL_H
#include <iostream>
#include <chrono>
#include "elma/elma.h"
#include <ncurses.h>
#include <unistd.h>


using namespace std::chrono;
using std::vector;
using namespace elma;
//! A cruise controller for a Car process.  See src/cruisecontrol.cc.
namespace cruise_control{
    class CruiseControl : public Process {

        public:

        //! Create a new cruise control class
        //! \param name The name of the cruise control      
        CruiseControl(std::string name) : Process(name) {}

        //! Nothing to do to initialize 
        void init() {}

        //! Nothing to do to start    
        void start() {}

        //! Get the velocity from the Velocity Channel, compute
        //! a simple proportional control law, and send the result
        //! to the Throttle channel. 
        //! Also watch for brake status from event, and
        //! send the status to Brake channel. 
        //! Finally send time period for the update to Channel Delta
        void update(); 
        
        //! Nothing to do to stop    
        void stop() {}

        private:
        double speed = 0;
        double _throttle = 0;
        double desired_speed = 0.0;
        const double KP = 314.15;
        vector<double> _v;
        int temp = 0;
    };
}
#endif