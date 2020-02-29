#include "Arduino.h"
#define ena 9 //Rechter Motor
#define enb 8
#define IN1 45
#define IN2 44
#define IN3 43
#define IN4 42

#define TACHO0 18
#define TACHO1 19
#define TACHO2 2
#define TACHO3 3

//Address of the LCD
#define LCDAddress 0x20
#define LCDCols 20
#define LCDRows 4

#define LEFT 0
#define RIGHT 1

#define leftTurnGoal 445
#define rightTurnGoal 445

#define rightMoveGoal 800
#define leftMoveGoal 800

#define HIGHSPEED 255
#define MIDDLESPEED 170
#define LOWSPEED 80
#define OFF 0
