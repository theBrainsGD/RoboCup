#include "Arduino.h"


// Threshold

#define leftTurnGoal 425
#define rightTurnGoal 425

#define rightMoveGoal 850
#define leftMoveGoal 825


// ist der Wert größer als die Schwelle, dann ist es Schwarz
#define blackR 260
#define blackL 240


// Pins:
// Rechter Motor
#define ena 9 
// Linker Motor
#define enb 8
#define IN1 42
#define IN2 43
#define IN3 45
#define IN4 44

#define TACHO0 18
#define TACHO1 19
#define TACHO2 2
#define TACHO3 3

//Address of the LCD
#define LCDAddress 0x20
#define LCDCols 20
#define LCDRows 4

#define graySclR A3
#define graySclL A7


// DEFINITIONEN:
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define HIGHSPEED 255
#define MIDDLESPEED 170
#define LOWSPEED 80
#define OFF 0

#define LEFT 0
#define RIGHT 1
