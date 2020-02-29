#include "Arduino.h"



//Pins
#define MLH 4  //ena PWM
#define MLV 5  //enb PWM
#define IN_1_L 30
#define IN_2_L 31       //Pins linker Motor
#define IN_3_L 32
#define IN_4_L 33

#define MRH 2 //ena PWM
#define MRV 3 //enb PWM
#define IN_1_R 34
#define IN_2_R 35        //Pins rechter Motor
#define IN_3_R 36
#define IN_4_R 37

#define LED 13

#define FRONT_RIGHT A1
#define FRONT_LEFT A2
#define LEFTSIDE_FRONT A3
#define LEFTSIDE_BACK A4
#define RIGHTSIDE_FRONT A5      //Entfernungssensorports
#define RIGHTSIDE_BACK A6
#define BACK_RIGHT A7
#define BACK_LEFT A8

#define LineTracker 20


//andere Konstaten
#define SPEED_OFF 0
#define SPEED 255

#define RIGHT 0
#define BACK 1
#define LEFT 2
#define RIGHT 3

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
