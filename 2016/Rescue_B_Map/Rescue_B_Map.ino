#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);
#include "hardware.h"
#include "Karte.h"


void setup() {
 Serial.begin(9600);
 
 //  INPUT/OUTPUT
 pinMode(IN_1_L, OUTPUT);
 pinMode(IN_2_L, OUTPUT);
 pinMode(IN_3_L, OUTPUT);
 pinMode(IN_4_L, OUTPUT);
 
 pinMode(IN_1_R, OUTPUT);
 pinMode(IN_2_R, OUTPUT);
 pinMode(IN_3_R, OUTPUT);
 pinMode(IN_4_R, OUTPUT);
 
 pinMode(FRONT_RIGHT, INPUT);
 pinMode(FRONT_LEFT, INPUT);
 pinMode(RIGHTSIDE_FRONT, INPUT);
 pinMode(RIGHTSIDE_BACK, INPUT);
 pinMode(LEFTSIDE_FRONT, INPUT);
 pinMode(LEFTSIDE_BACK, INPUT);
 pinMode(BACK_RIGHT, INPUT);
 pinMode(BACK_LEFT,INPUT);
 
 pinMode(LED, OUTPUT);

 //Drehrichtung (Vorwärts)
 digitalWrite(IN_1_L, HIGH);
 digitalWrite(IN_3_L, HIGH);
 digitalWrite(IN_2_L, LOW);
 digitalWrite(IN_4_L, LOW);
 
 digitalWrite(IN_1_R, HIGH);
 digitalWrite(IN_3_R, HIGH);
 digitalWrite(IN_2_R, LOW);
 digitalWrite(IN_4_R, LOW);
 

 
 
 //LCD initialsierung
 lcd.init();
 lcd.backlight();
 lcd.clear();
 lcd.print("Start");
 delay(500);
 lcd.clear();
 
}

void loop() { 
Mapping(NORTH);
}
