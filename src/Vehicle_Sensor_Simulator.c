#include <stdio.h>
#include <stdlib.h>

typedef enum {
	on = 1, off = 0
} bool;
void print_array(int arr[], int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++) {
		if (i == (arrSize - 1)) {
			printf(" %d ", arr[i]);
			break;
		}
		printf(" %d, ", arr[i]);
	}
	printf("\n");
}
void print_string(int arr[], int arrSize) {
	int i;
	for (i = 0; arr[i] != '\0'; i++) {
		if (arr[i + 1] == '\0') {
			printf(" %c ", arr[i]);
			break;
		}
		printf(" %c, ", arr[i]);
	}
	printf("\n");
}
/****************************************/


struct sensors {
	bool engine_state;
	bool engine_temp_controller;
	bool AC;
	int speed;
	int room_temp;
	int engine_temp;
	char traffic_light;
}sensor;

struct sensors sensor = {on, on, on, 100, 20, 125, 'g'};

int flag = 0;

/***************************************** Functions prototypes *************************************/
void print_system_state_menu();
void print_Sensors_menu();
void print_sensor_state();
int system_state(char choice);
int traffic_light(char ch);
void room_temp(int temp);
void engine_temp(int temp);
void vehicle_speed();
int Sensors_set_menu(char ch);
/***************************************************************************************************/



/*********************************** Main ************************************/
int main(void) {
	char input, sensor_action_color;
	int state_action, sensor_action, temp, speed;

	print_system_state_menu();
	scanf(" %c", &input);
//		input = 'a';
	state_action = system_state(input);

	while(1) {
		if(state_action == -1) {
			print_system_state_menu();
			scanf(" %c", &input);
		//		input = 'a';
			state_action = system_state(input);
		}

		if(state_action == 1) {
			scanf(" %c", &input);
//			input = 'b';
			sensor_action = Sensors_set_menu(input);
			sensor_action_color = (char) sensor_action;

			if(sensor_action == 1) {
				scanf(" %c", &input);
//				input = 'a';
				state_action = system_state(input);
			}

			if(sensor_action == -1) {
				scanf(" %c", &input);
				sensor_action = Sensors_set_menu(input);
				sensor_action_color = (char) sensor_action;
			}


			if(flag == 1) {
				flag = 0;
				speed = traffic_light(sensor_action_color);
				if(speed == 30) {
					vehicle_speed();
				}
				print_sensor_state();
				print_Sensors_menu();

//				scanf(" %d", &temp);
//				sensor_action = Sensors_set_menu(input);
//				sensor_action_color = (char) sensor_action;
			}


			if(sensor_action == 3) {
				scanf(" %d", &temp);
				room_temp(temp);
				print_sensor_state();
				print_Sensors_menu();

//				scanf(" %d", &temp);
//				sensor_action = Sensors_set_menu(input);
//				sensor_action_color = (char) sensor_action;
			}


			if(sensor_action == 4) {
				scanf(" %d", &temp);
				engine_temp(temp);
				print_sensor_state();
				print_Sensors_menu();

//				scanf(" %d", &temp);
//				sensor_action = Sensors_set_menu(input);
//				sensor_action_color = (char) sensor_action;
			}
		}
		if(state_action == 2) {
			scanf(" %c", &input);
			state_action = system_state(input);
		}
		if(state_action == 3) {
			break;
		}
	}

	return 0;
}
///////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////
void print_system_state_menu() {
	printf(">>> system state <<< \n");
	printf("a. Turn on the vehicle engine \n");
	printf("b. Turn off the vehicle engine \n");
	printf("c. Quit the system \n \n");
}
void print_Sensors_menu(){
	printf(">>> sensors menu <<< \n");
	printf("a. Turn off the engine. \n");
	printf("b. Set the traffic light color. \n");
	printf("c. Set the room temperature (Temperature Sensor). \n");
	printf("d. Set the engine temperature (Engine Temperature Sensor). \n \n");
}
void print_sensor_state() {
	printf(">>> sensors state <<< \n");
	(sensor.engine_state)? printf("engine is ON \n") : printf("engine is OFF \n");
	(sensor.AC)? printf("AC is ON \n") : printf("AC is OFF \n");
	printf("vehicle speed = %d \n", sensor.speed);
	printf("Room temperature = %d  \n", sensor.room_temp);
	(sensor.engine_temp_controller)? printf("Engine temp controller is ON \n") : printf("Engine temp controller is OFF \n");
	printf("Engine temperature = %d  \n \n", sensor.engine_temp);
}
///////////////////////////////////////////////////////////////////////////////////////////////////

int system_state(char ch){
	switch(ch) {
	case 'A':
	case 'a':
		print_Sensors_menu();
		return 1;

	case 'B':
	case 'b':
		print_system_state_menu();
		return 2;

	case 'C':
	case 'c':
		return 3;

	default:
		printf("Invalid choice, try again \n \n");
		return -1;
	}
}


int traffic_light(char ch) {
	switch(ch) {
	case 'G':
	case 'g':
		sensor.speed = 100;
		sensor.traffic_light = 'g';
		return sensor.speed;

	case 'O':
	case 'o':
		sensor.speed = 30;
		sensor.traffic_light = 'o';
		return sensor.speed;

	case 'R':
	case 'r':
		sensor.speed = 0;
		sensor.traffic_light = 'r';
		return sensor.speed;
	}
	return -1;
}

void room_temp(int temp) {
	if((temp >= 30) || (temp <= 10)) {
		sensor.AC = on;
		sensor.room_temp = 20;
	}else{
		sensor.AC = off;
		sensor.room_temp = 20;
	}
}

void engine_temp(int temp) {
	if((temp >= 150) || (temp <= 100)) {
		sensor.engine_temp_controller = on;
		sensor.engine_temp = 125;
	}else{
		sensor.engine_temp_controller = off;
		sensor.engine_temp = 125;
	}
}

void vehicle_speed() {
	sensor.AC = on;
	sensor.engine_temp_controller = on;

	sensor.engine_temp *= ((5/4) + 1);
	sensor.room_temp *= ((5/4) + 1);
}

int Sensors_set_menu(char ch) {
	char color;

	switch(ch) {
	case 'A':
	case 'a':									//Turn off the engine.
		print_system_state_menu();
		return 1;

	case 'B':
	case 'b':									//Set the traffic light color
		printf("Enter the traffic light color \n");
		while(1) {
			scanf(" %c", &color);
//			color = 'o';
			if( color == 'G' || color == 'g' || color == 'O' || color == 'o' || color == 'R' || color == 'r') {
				flag = 1;
				return color;
			}else if(color == -1){
				return -1;
			}else{
				printf("invalid input \n try again \n or type -1 to go to the Sensors_set_menu \n \n");
			}
		}
		return -1;

	case 'C':
	case 'c':									//Set the room temperature (Temperature Sensor)
		printf("Enter the required room temperature \n");
		return 3;

	case 'D':
	case 'd':									///Set the engine temperature (Engine Temperature Sensor)
		printf("Enter the required engine temperature \n");
		return 4;


	default:
		printf("Invalid choice, try again \n \n");
		return -1;
	}
	return -1;
}

















