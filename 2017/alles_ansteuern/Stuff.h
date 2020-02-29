#include  "Arduino.h"
#include  "Vars.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 

extern void ClearLCDLine(int Line, LiquidCrystal_I2C lcd);

extern int getDigits(int value);
