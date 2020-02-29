#include "Arduino.h"

//Pins
#define MR 7    //ena
#define ML 6    //enb
#define IN_1 4                //Motorenpins  
#define IN_2 31
#define IN_3 5
#define IN_4 30

#define LED 13      
#define SENSOR_SEITE A3     //Entfernungssensor Seite 
#define SENSOR_VORNE A4     //Entfernungssensor Vorne
#define LT_L 41             //LineTracker
#define LT_R 42             
#define WS A7               //Wärmesensor

//andere Konstaten
#define SPEED_NORMAL 200
#define SPEED_HIGH 255
#define SPEED_LOW 70
#define SPEED_OFF 0
#define SPEED_VERY_LOW 30

//die werte müssen noch kalibriert werden!!!!
//Entfernungen
#define Vorne_Nah 450

#define Seite_Nah   550
#define Seite_Fern   480
#define Seite_Sehr_Fern 400 

//Opfertemperatur
#define HEAT 30
