#include "Arduino.h"

//Pins
#define MR 7
#define ML 6
#define IN_1 4                //Motorenpins  
#define IN_2 45
#define IN_3 5
#define IN_4 44

#define LED 3             
#define SENSOR_SEITE A3     //Entfernungssensor Seite 
#define SENSOR_VORNE A4     //Entfernungssensor Vorne
#define LT_L 41             //LineTracker
#define LT_R 42             
#define WS A7               //Wärmesensor

//andere Konstaten
#define SPEED 200
#define SPEED_HIGH 255
#define SPEED_LOW 50

//die werte müssen noch kalibriert werden!!!!
//Entfernungen
#define Vorne_Fern 500
#define Vorne_Nah 550

#define Seite_Nah   590
#define Seite_Fern   500


//Opfertemperatur
#define HEAT 30


