#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x20, 4, 20);


void setup() {
pinMode(A8, INPUT);
pinMode(A9, INPUT);

lcd.init();
lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.print("links:");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A8));
  lcd.setCursor(0, 2);
  lcd.print("right");
  lcd.setCursor(0, 3);
  lcd.print(analogRead(A9));
  delay(250);

}
