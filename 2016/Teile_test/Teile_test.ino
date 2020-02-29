#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
lcd.init();

lcd.backlight();
lcd.print("Let's get ready!");
delay(750);
lcd.clear();
}

void loop() {
  delay(50);
lcd.clear();
int wert = analogRead(A4);
lcd.print("Wert: ");
lcd.print(wert);
}
