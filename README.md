Vehicle Sensor System
This program simulates a vehicle sensor system. The system has sensors for engine state, engine temperature controller, air conditioning (AC), speed, room temperature, engine temperature, and a traffic light sensor. The program allows the user to interact with the system by turning on/off the engine, setting the traffic light color, and adjusting room/ engine temperature.

Dependencies
This program is written in C language and requires the following libraries:

stdio.h
stdlib.h
How to Run
Compile the code using a C compiler
Run the executable file.
How to Use
The program will display the system state menu
Enter a choice from the menu to perform an action
If the choice is invalid, the system will display an error message and prompt for a valid choice.
The program will display the sensor menu if the user turns on the engine.
Enter a choice from the sensor menu to perform an action
If the choice is invalid, the system will display an error message and prompt for a valid choice.
Functions
The program contains the following functions:

print_system_state_menu(): displays the system state menu
print_Sensors_menu(): displays the sensor menu
print_sensor_state(): displays the current state of the sensors
system_state(): performs an action based on the user's input from the system state menu
traffic_light(): sets the vehicle speed based on the traffic light color
room_temp(): sets the room temperature based on the user's input
engine_temp(): sets the engine temperature based on the user's input
vehicle_speed(): adjusts the speed of the vehicle based on the air conditioning and engine temperature controller settings
Sensors_set_menu(): performs an action based on the user's input from the sensor menu
Variables
The program contains the following variables:

sensor: an instance of the struct 'sensors' that stores the current state of the sensors
flag: a variable used to check if the traffic light color has been set
Contributing
This program is open to contributions. If you would like to contribute, please submit a pull request.