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
pinMode(LED, OUTPUT);
pinMode(WS, INPUT);

digitalWrite(LED, LOW);


// Drehrichtung (Vorwärts)
digitalWrite(IN_1, HIGH);
digitalWrite(IN_3, HIGH);
digitalWrite(IN_2, LOW);
digitalWrite(IN_4, LOW);


//LCD initialisierung
lcd.init();
lcd.backlight();
lcd.clear();
lcd.print("LOS!!");
delay(700);

}

void loop(){
  lcd.clear();
 
 
 SensorSeiteWert = analogRead(SENSOR_SEITE);
 lcd.setCursor(0,0);
 lcd.print(SensorSeiteWert);
 SensorVorneWert = analogRead(SENSOR_VORNE);
 lcd.setCursor(0,1);
 lcd.print(SensorVorneWert);
 WSwert = analogRead(WS);
 lcd.setCursor(0,2);
 lcd.print(WSwert);
 delay(50);
 

   //Sensor auslesen vorne
   if(SensorVorneWert > Vorne_Nah){
     WandVorne(VORNE_NAH);   
   }else
     WandVorne(VORNE_FERN);
     
     
   //Sensor auslesen Seite
   if(SensorSeiteWert > Seite_Nah ){
     WandSeite(SEITE_NAH);
   }else if((SensorSeiteWert < Seite_Nah) && (SensorSeiteWert > Seite_Fern)){
     WandSeite(SEITE_GUT);
   // lcd.print("Seite_Gut");
   }else if((SensorSeiteWert < Seite_Fern)){
     WandSeite(SEITE_FERN);
    //lcd.print("Seite_Fern");
   }
    
   
   //Opfer finden
  /* 
   if(WSwert > HEAT)
   Opfer(JA);
   else if(WSwert < HEAT)
   Opfer(NEIN);
   */
   
   
   
   
    //LineTracker
   /*if((LT_R == true) && (LT_L == true)){
     LineTracker(Schwarz);
   } */ 
   
 }
 
 
 
 
 
 
 
 
 
 

