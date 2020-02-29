#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 20, 4);

#define  SensorVorne    A6
int highestValue = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(SensorVorne,  INPUT);
}

void loop() {
int value = analogRead(SensorVorne);
  if(highestValue < value){
    highestValue = value;
    lcd.clear();
  }
  lcd.setCursor(0,0);
  lcd.print(highestValue);
  
  lcd.setCursor(0, 2);
  lcd.print(value);
}
