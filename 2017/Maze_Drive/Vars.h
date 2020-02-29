#include  "Arduino.h"


//die richtungen sind passend, wenn man von oben auf den Roboter schaut und die vorderseite nach Norden zeigt
#define  SensorRightBack    A4
#define  SensorRightFront   A7        //The value givin by the Sharp IR Sensors are not higher than round about 720
#define  SensorFrontRight   A5
#define  SensorFrontLeft    A6


#define  LED            13


//definition of gearvariables

#define  ena     10      
#define  A_IN_1  40
#define  A_IN_2  41
#define  enb     11
#define  B_IN_1  44
#define  B_IN_2  45


#define NORTH   1
#define WEST    2
#define SOUTH   3
#define EAST    4


#define valueMAX 600


//defines for the Map Array properties
#define UNKNOWN_ 0 
#define WALL_NORTH 1
#define WALL_SOUTH 2
#define WALL_WEST 3
#define WALL_EAST 4
#define RAMP 5
#define VICTEM 6
#define BLACK 7
#define CHECKPOINT 8


//defines for the Position
#define StartPosX 0
#define StartPosZ 0
#define StartPosY 0

