#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


#define MR 7
#define ML 6
#define IN_1 4                //Motorenpins  
#define IN_2 31
#define IN_3 5
#define IN_4 30
#define LED 13
void setup() {
  
  lcd.init();                      // initialize the lcd 
 
  lcd.backlight(); 

pinMode(IN_1 , OUTPUT);
pinMode(IN_2 , OUTPUT);
pinMode(IN_3 , OUTPUT);
pinMode(IN_4 , OUTPUT);

pinMode(LED  , OUTPUT);

digitalWrite(IN_1, HIGH);
digitalWrite(IN_3, HIGH);       //definiere Drehrichtung
digitalWrite(IN_2, LOW);
digitalWrite(IN_4, LOW);

lcd.print("Motorentest kann ");
lcd.setCursor(0,1);
lcd.print("beginnen!");
delay(1000);
lcd.clear();
}

void loop() {
lcd.print("Max Speed");
digitalWrite(ML, HIGH);
digitalWrite(MR, HIGH);         //lässt die Motoren für eine Sekunde auf höchster
digitalWrite(LED, HIGH);        // Geschwindigkeit fahren: HIGH/255
delay(1000);
lcd.clear();
digitalWrite(ML, LOW);
digitalWrite(MR, LOW);           //lässst die Moteren für eine halbe Sekunde ruhen
digitalWrite(LED,LOW);           //LED am Board wird ausgeschaltet.
delay(500);
}
