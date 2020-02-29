#include "Vars.h"
#include "Stuff.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x20 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x20, 20, 4);

int valueLeft = 0;
int valueFront = 0;
int valueLeft2 = 0;
int valueFront2 = 0;

int velocityFrontRight = 0;
int velocityFrontLeft = 0;
int velocityBackRight = 0;
int velocityBacktLeft = 0;


int Direction = NORTH; 

void setup() {
lcd.init  ();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("Starting up!");
  
  Serial.begin(9600);
  pinMode(SensorLinks,  INPUT);
  pinMode(SensorVorne,  INPUT);
  pinMode(SensorLinks2, INPUT);
  pinMode(SensorVorne2, INPUT);

  pinMode(LED, OUTPUT);

  pinMode(A_IN_1,OUTPUT);
  pinMode(A_IN_2,OUTPUT);
  pinMode(B_IN_1, OUTPUT);
  pinMode(B_IN_2, OUTPUT);

  digitalWrite(A_IN_1, HIGH); // Setzen der Drehrichtung
  digitalWrite(A_IN_2, LOW);
  digitalWrite(B_IN_1, HIGH);
  digitalWrite(B_IN_2, LOW);

//  lcd.setCursor(0,0);
//  lcd.print("vL1");
//  lcd.setCursor((20 - String("vF1").length()),0);
//  lcd.print("vF1");
//  
//  lcd.setCursor(0,2);
//  lcd.print("vL2");
//  lcd.setCursor((20 - String("vF2").length()),2);
//  lcd.print("vF2");

  lcd.setCursor(0,0);
  lcd.print("velocityFrontLeft");
  
  lcd.setCursor(0,2);
  lcd.print("velocityFrontRight");
}

void loop() {
  /*valueLeft = analogRead(SensorLinks);
  valueFront = analogRead(SensorVorne);
  valueLeft2 = analogRead(SensorLinks2);
  valueFront2 = analogRead(SensorVorne2);
  
  velocityFrontLeft = map(valueFront, 60, 700, 255, 0);
  if(velocityFrontLeft > 255){
    velocityFrontLeft = 255;
  }
  velocityFrontRight = map(valueFront2, 60, 700, 255, 0);
  if(velocityFrontRight > 255){
    velocityFrontRight = 255;
  }
  
  analogWrite(ena, velocityFrontRight);
  analogWrite(enb, velocityFrontLeft);
  
  ClearLCDLine(1, lcd);
  lcd.print(velocityFrontLeft);
  ClearLCDLine(3, lcd);
  lcd.print(velocityFrontRight);
  
  delay(250);*/
  
  drive();
}
