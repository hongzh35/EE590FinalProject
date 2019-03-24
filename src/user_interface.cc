#include <unistd.h>
#include "car.h"


using namespace driving_car;
//using namespace cruise_control;
UserInterface::UserInterface(Car& ca) : Process("user input"), _car(ca) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    keypad(stdscr,TRUE);
    curs_set(0); // Do not show the cursor
};


void UserInterface::show_velocity(int x, int y, double v) {
    mvprintw(x,y,"Speed:%f m/s",v);
}
void UserInterface::show_mileage(int x, int y, double m) {
    mvprintw(x,y,"Mileage: %f m",m);
}
void UserInterface::show_state(int x, int y, std::string _state){
    mvprintw(x,y, "State: %s",_state.c_str());
}


void UserInterface::show_warning(int x, int y, std::string _warning){
    attron(A_BLINK);
    mvprintw(x,y, "%s",_warning.c_str());
    attroff(A_BLINK);
}


void UserInterface::update() {
    watch("max speed", [this](Event& e) {
        desired_speed = e.value();
    });
    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();
    switch(c){
        case 'w':
            emit(Event("desired speed",desired_speed));
            break;
        case 's':
            emit(Event("braking"));
            break;
        case KEY_UP:
            emit(Event("girdup"));
            break;
        case KEY_DOWN:
            emit(Event("girddown"));
            break;
        case KEY_LEFT:
            emit(Event("girdleft"));
            break;
        case KEY_RIGHT:
            emit(Event("girdright"));
            break;
   }

    // OUTPUT
    clear();
    show_velocity(1,1, _car.currentvelocity()); 
    show_state(1,30, _car.currentstate());
    show_mileage(1,55,_car.currentmileage());
    mvprintw(6,1,"Info:");
    if (_car.operationstate() == false){
        show_warning(6,7, _car.currentwarning());
    }
    else{
        mvprintw(6, 7, "All Functions Performs Well!");
    }

    if(channel("Throttle").size()>0){
        if (channel("Throttle").latest()>0.01){
            attron(A_BOLD); 
            mvaddstr(9,5,"Throttle(w)");
            attroff(A_BOLD); 
        }
        else{
            mvprintw(9,5,"Throttle(w)");
        }
    }
    
    if(channel("Brake").size()>0){
        if (channel("Brake").latest() == 1){
            attron(A_BOLD); 
            mvaddstr(9,20,"Brake(s)");
            attroff(A_BOLD); 
        }
        else{
            mvprintw(9,20,"Brake(s)");
        }
    }
    
    mvprintw(4, 40, "[S]Sport");
    mvprintw(5, 40, "[D]Direct");
    mvprintw(6, 40, "[P]Parking");
    mvprintw(6, 53, "[!]Parking Brake");
    mvprintw(7, 40, "[R]Return");
    if(_car.currentstate() == "stop"){
        mvprintw(6, 38, "->");
    }
    else if(_car.currentstate() == "sport"){
        mvprintw(4, 38, "->");
    }
    else if(_car.currentstate() == "forward"){
        mvprintw(5, 38, "->");
    }
    else if(_car.currentstate() == "backward"){
        mvprintw(7, 38, "->");
    }
    else if(_car.currentstate() == "park"){
        mvprintw(6, 51, "->");
    }
    mvprintw(9,40,"Use 4 Arrow Key to Switch Between Gears");

    usleep(9999);

}