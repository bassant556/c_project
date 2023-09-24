/*
 ============================================================================
 Name        : project2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1

typedef struct{//here we need to gather some variables of different types so we use struct
	unsigned int speed;
	 float room_temp;
    float engine_temperature;

}options;
options op ={25,35,90};
typedef enum{
	OFF,ON
}state;
state engine=ON;
state AC=OFF;
state engine_temperature_state=OFF;

void display(){
	if(engine==OFF){
		printf("Engine is OFF\n");

	}else{
		printf("Engine is ON\n");
	}
	(AC==OFF)?printf("AC is OFF\n"):printf("AC is ON\n");
printf("vehicle_speed : %u Km/Hr\n",op.speed);
printf("Room_Temperature :%.2f C\n",op.room_temp);
if(WITH_ENGINE_TEMP_CONTROLLER){
	(engine_temperature_state==OFF)?printf("Engine temperature controller is OFF\n"):printf("Engine temperature controller is ON\n");
}
if(WITH_ENGINE_TEMP_CONTROLLER){
printf("Engine temperature :%.2f C\n",op.engine_temperature);
}
}
void engine_temp(int *et){
while(WITH_ENGINE_TEMP_CONTROLLER){

	if(*et<100||*et>150){
		engine_temperature_state=ON;
		if(WITH_ENGINE_TEMP_CONTROLLER){
	op.engine_temperature=125;
		}
	}else{
	engine_temperature_state=OFF;
	}

	display();
	sensor_set_menu();
}
}
void room_temp(int *t){




	if(*t<10||*t>30){
		AC=ON;
		op.room_temp=20;

	}else{
		AC=OFF;
	}
	display();
	sensor_set_menu();


}
void trafic_light_color(char *c){

	int speed;

	switch(*c){
	case 'g':
	case 'G':

		op.speed=100;

display();
sensor_set_menu();
break;
	case'o':
   case 'O':
		op.speed=30;

				if(AC==OFF){
				AC=ON;
			}
			if(engine_temperature_state==OFF){
			engine_temperature_state=ON;
			}
			op.room_temp=op.room_temp*((float)5/4)+1;
			if(WITH_ENGINE_TEMP_CONTROLLER){
			op.engine_temperature=op.engine_temperature*((float)5/4)+1;
}
	display();
	sensor_set_menu();
	break;
   case 'r':
	case 'R':
		op.speed=0;

		display();
		sensor_set_menu();
		break;
	}

}
void sensor_set_menu(){
	 char ch;
	 int temp;
	 int e_temp;
			 printf("a. Turn off the engine\n");
			 printf("b. Set the traffic light color.\n");
			 printf("c. Set the room temperature (Temperature Sensor)\n");
			 printf("d. Set the engine temperature \n");

			    fflush(stdout);
			 scanf(" %c",&ch);//here we use space before %c as the compiler considers enter as a character
			 switch(ch){
			 case 'A':
			 case 'a': //we use the case in this way so that we can use the capital and small of the letter
				 main();
			 break;
			 case 'B':
			 case 'b':

				 printf("enter the required color:\n ");
				 fflush(stdout);
				 scanf(" %c",&ch);

				 trafic_light_color(&ch);

			 break;
			 case 'C':
			 case 'c':

				 printf("enter the room temperature:\n");
				fflush(stdout);
				scanf("%d",&temp);
				room_temp(&temp);
				break;
			 case 'D':
			 case 'd':

				 printf("enter engine temperature data:\n");
				 fflush(stdout);
				 scanf("%d",&e_temp);
				 engine_temp(&e_temp);
			 }


}




int main(void) {

	char ch;
			do{

			 printf("a. Turn on the vehicle engine\n");
					 printf("b. Turn off the vehicle engine\n");
					 printf("c. Quit the system\n");
					    fflush(stdout);
					 scanf(" %c",&ch);
					 switch(ch){
					 case'A':
					 case 'a':
						 printf("the vehicle engine turned on\n");
						 sensor_set_menu();
					 break;
					 case'B':
					 case 'b':
						 printf("the vehicle engine turned off\n \n");

					 break;
					 case'C':
					 case 'c':
						 printf("quit the system");
						break;

					 }

			}while(ch=='b'||ch=='B');


}
