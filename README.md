# EE590FinalProject
## Description
This project is to build a embedded system that to simulate a car runing car that controled by a driver. It is based on the elma and existed cruise control and make the extentions. The system would contain two processes and several channels and one manager. The system would include a driver who can effect how the car runing and change the velocity of the car. During the running of the system, the real-time data of the velocity of the car and other information would be plot as one of the goals. Update: The system will use state machine and have four different state including parking brake, stop, forward, backward, sport mode. In the forward state the car could moving forward. In the backward state, the car could move backward. In the stop state, the car has 0 velocity and the diver could change the state. In the parking brake state, the driver couldn't do anything to the car.

## Milestones
1. Build cruse system that could simulate the basic function of the car -- 3/12
2. Enhance the pid control and add ki and kd. -- 3/13
~3. Include wind, hills that could effect how the velocity changes. --3/15~
3. Include hills that could effect how the velocity changes. 
～4. Add a driver that could control the velocity of the car. -- 3/15～
4. Add a driver that could swith between four different state and also control the velocity of the car.
~5. Include gear channel and brake channel that could be controled by the driver. --3/15~
5. Include four different states.
6. Expore data from simulations and show with plots  --3/16
~7. Extra: Try to send the real-time data of the car as a UDP message to the other elma. --TBD~

