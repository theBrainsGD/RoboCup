#include "Arduino.h"
#include "Vars.h"
#include "SharpIR.h"

extern int readLeftFront(SharpIR sensor);

extern boolean testForVictim(int graySclR, int graySclL);

extern int diff(int compared, int comparing);
