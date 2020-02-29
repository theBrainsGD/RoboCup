#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,20,4);

#include "hardware.h"
#include "Wand_folgen.h"
#include "LineTracker.h"
#include "Opfer_finden.h"

//andere Variablen
int SensorSeiteWert;
int SensorVorneWert;
int WSwert;


void setup(){
Serial.begin(9600);


//  INPUT/OUTPUT
pinMode(IN_1 , OUTPUT);
pinMode(IN_2 , OUTPUT);
pinMode(IN_3 , OUTPUT);
pinMode(IN_4 , OUTPUT);
pinMode(SENSOR_SEITE, INPUT);
pinMode(SENSOR_VORNE, INPUT);
pinMode(LT_L, INPUT);
pinMode(LT_R, INPUT);
pinMode(LED, OUTPUT);
pinMode(WS, INPUT);



// Drehrichtung (Vorwärts)
digitalWrite(IN_1, HIGH);
digitalWrite(IN_3, HIGH);
digitalWrite(IN_2, LOW);
digitalWrite(IN_4, LOW);


//LCD initialisierung

lcd.init();
lcd.backlight();
lcd.clear();
lcd.print(" Start");
delay(750);


}

void loop(){
  lcd.clear();
  lcd.print("       Jonny");
 
 SensorSeiteWert = analogRead(SENSOR_SEITE);
 lcd.setCursor(0,1);
 lcd.print("SensorSeite: ");
 lcd.print(SensorSeiteWert);
 Serial.println(SensorSeiteWert);
 SensorVorneWert = analogRead(SENSOR_VORNE);
 lcd.setCursor(0,2);
 lcd.print("SensorVorne: ");
 lcd.print(SensorVorneWert);
 int LTWert = digitalRead(LT_R);
 lcd.setCursor(0,3);
 lcd.print(LTWert);
 WSwert = analogRead(WS);
 lcd.setCursor(0,2);
 lcd.print(WSwert);
 delay(50);

 //Serial.println(SensorSeiteWert);
 /*if(digitalRead(LT_L) == true) {
 Serial.println("true");
 }
 
 else{
 Serial.println("false");
 }*/
 
   //Sensor auslesen vorne
   if(SensorVorneWert > Vorne_Nah){
     WandVorne(VORNE_NAH);   
   }else
     WandVorne(VORNE_FERN);
     
     
     
   //Sensor auslesen Seite
   if(SensorSeiteWert > Seite_Nah ){    
     analogWrite(LED, 100);
     WandSeite(SEITE_NAH);
   }else if((SensorSeiteWert < Seite_Nah) && (SensorSeiteWert > Seite_Fern)){
     digitalWrite(LED, HIGH);
     WandSeite(SEITE_GUT);
   }else if((SensorSeiteWert < Seite_Fern) && (SensorSeiteWert > Seite_Sehr_Fern)){
     analogWrite(LED, 100);
     WandSeite(SEITE_FERN);
   }else if((SensorSeiteWert < Seite_Sehr_Fern)) {
     digitalWrite(LED, LOW);
     WandSeite(SEITE_SEHR_FERN);
   }
     


   
   //Opfer finden
  /* 
   if(WSwert > HEAT)
   Opfer(JA);
   else if(WSwert < HEAT)
   Opfer(NEIN);
   */
   
   
   
   
    //LineTracker
/*  if(digitalRead(LT_L) == false){
    Serial.println("LineTracker");
     LineTracker(Schwarz);
   }
   else
   LineTracker(Weiss); */
 }
