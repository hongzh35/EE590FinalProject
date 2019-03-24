#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "car.h"

namespace driving_car {

    using namespace std::chrono;
    using namespace elma;
    using namespace driving_car;

    //! A user interface for the a Car object
    class UserInterface : public Process {

        public:

        //! Create a new car user interface using curses
        //! \param ca A reference to a StopWatch object
        UserInterface(Car& ca);

        void init() {}
        void start() {}

        //! Display the velocity at the given x,y position on the screen
        void show_velocity(int x, int y, double v);
        //! Display the mileage at the given x,y position on the screen
        void show_mileage(int x, int y, double m);
        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        //! Nothing to do to stop
        void stop() {}
        //! Display the current state at the given x,y position on the screen
        void show_state(int x, int y, std::string _state);
        //! Display the warning message at the given x,y position on the screen
        void show_warning(int x, int y, std::string _warning);


        private:
        Car& _car;
        double desired_speed = 50;
        int temp = 1;

    };

}
