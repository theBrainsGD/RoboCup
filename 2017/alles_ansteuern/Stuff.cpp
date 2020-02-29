#include  "Stuff.h"

int getDigits(int value){                                                               //returns the digits of a givin Integer
  int counter = 1;
  for(int i = 10; value >= i;  i = i*10){
    counter++;
  }return counter;
}

void ClearLCDLine(int Line, LiquidCrystal_I2C lcd){
  lcd.setCursor(0, Line);
  lcd.print("                    ");
  lcd.setCursor(0,Line);
}
