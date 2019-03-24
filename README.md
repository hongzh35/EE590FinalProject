# EE590FinalProject
## Project Goal:
This project is to build a embedded system that to simulate a runing car that controled by a driver. The user could play the  role of a driver to control the velocity and gear state by using keyboards. The user could accelerate or brake the car and also switch between gears. It is an automatic car so that the gears are to perform moving forward, moving backward, parking and stop of the car. The interface will show real time data including velocity, mileage, working state, error message during the simulation.
The core process and state machine system is based on elma, an event loop manager.

## Installation
```
git clone https://github.com/hongzh35/EE590FinalProject.git
cd Running_Car
docker run -v $PWD:/source -it klavins/elma:latest bash
make
```

## Execution
To run the simulation of car, type
`bin/driving_car`

The car is controlled via the keyboard, using these keys:
* w: Throtte
* s: Brake
* Arrow keys: Switch gears

## Architecture
- [Car](Car) ([car.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/car.h))
- [Cruise Control](Cruise_Control)([cruisecontrol.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/cruisecontrol.h))
- [Channels](Channels)
- [Car Interface](Car_Interface)([user_interface.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/user_interface.h))

### Car
Car class is inherited to elma's state machine class. In the car state machine, there are several states and funcitons.

States:
![State Machine](https://github.com/hongzh35/EE590FinalProject/blob/master/image/statemachine.png "statemachine")
- Stop([stop.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/stop.h)):
   a. The car is on the Parking gear position.
   b. If driver want to step on the gas pedal, a warning will be visuable to show that the driver should swith to driving gears to drive the car.
- Parking Brake([parkingbrake.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/parkingbrake.h)):
   a. The car has the Parking Brake on.
   b. The velocity of the car will be totally zero.
   c. If driver want to step on the gas pedal, a warning will be visuable to show that the driver should swith to driving gears to drive the car.
- Forward([forward.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/forward.h)):
   a. The car is on Drive gear position, so that the car could be moved by the driver.
   b. The car would receive the data from Cruise Control to perform braking, accelarating or keeping the speed.
   c. Check if any misoperation by the driver.
- Backward([backward.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/backward.h)):
   a. The car is on Reverse gear position, so that the car could be moved by the driver.
   b. The car would receive the data from Cruise Control to perform braking, accelarating or keeping the speed.
   c. Check if any misoperation by the driver.
- Protect State([protectstate.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/protectstate.h)):
   a. When driver tries to switch to Parking gear position from Drive or Backward gear, the car supposed to be totally stop.
   b. If the velocity of the car is not zero, send out error message and back to the previous gear.
   c. If the velocity of the car is zero, continue to switch to Parking gear.
- Sport Mode([sportmode.h](https://github.com/hongzh35/EE590FinalProject/blob/master/include/sportmode.h)):
   a. The car is on Sport Mode gear position.
   b. Change the accelaration of the car.
   c. Change the maximum speed of the car.
### Cruise Control
Cruise Control class is a class to recieve the commands from the driver and transfer to the informations to change the speed or state of the car. 
It can receive the desire speed and using pid control system to compute the throttle that the car needed to acheive the speed smoothly.
Cruise Control class could communicate with the Car class through three channels including Brake, Throttle, Delta.
### Channels
Three are three channels to be used in this project. Channels could help to store the data so that data could be shared between different class.
- Brake Channel: Store the data to show if the driver brakes or not.
- Throttle Channel: Store the data to show if the driver step on the gas pedal.
- Delta Channel: Store the data to show how long it takes during each update clock cycle of the cruise control class. 
### Car Interface
The interface is a class to display the real time data and status that the driver could see when drving. It will display the velocity, mileage, error information and current state. It also displays the keys for the user to do the simulation.
![Initial](https://github.com/hongzh35/EE590FinalProject/image/Initial.png "Initial Interface")
## Results
1. Error messege display when the driver tried to step on the gas pedal before switch to right gears
![Bad driving](https://github.com/hongzh35/EE590FinalProject/blob/master/image/step_on_too_early.png "Bad driving")
2. All functions performs well when driving forward
![Sport Mode](https://github.com/hongzh35/EE590FinalProject/blob/master/image/speedlimit.png "Sport Mode")
3. On sports mode, the max velocity is updated from 50m/s to 80m/s
![Moving Forward](https://github.com/hongzh35/EE590FinalProject/blob/master/image/moveforward.png "Moving forward")
4. When trying to switch to Parking gear before velocity becomes zero, error message shows up.
![Bad Switch](https://github.com/hongzh35/EE590FinalProject/blob/master/image/switchtooearly.png "Bad Switch")
## References
- elma: [https://github.com/klavinslab/elma_project](https://github.com/klavinslab/elma_project)
- pid control: [https://www.omega.com/prodinfo/pid-controllers.html](https://www.omega.com/prodinfo/pid-controllers.html)
- gears: [https://en.wikipedia.org/wiki/Automatic_transmission](https://en.wikipedia.org/wiki/Automatic_transmission)

