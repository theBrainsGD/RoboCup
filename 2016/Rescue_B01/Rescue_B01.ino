#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);

//Pins
#define MR 7
#define ML 6
#define in1 4
#define in2 45
#define in3 5
#define in4 44
#define ML 6
#define LED 3
#define SensorVRR A3
#define SensorVVR A4

//andere Variablen
#define SPEED 150
#define SPEEDH 255
#define SPEEDL 50

int VRRWert = 0;
int VVRWert = 0;
int wert1 = 0;
int wert2 = 0;

void setup(){
Serial.begin(9600);


//  INPUT/OUTPUT
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(SensorVRR, INPUT);
pinMode(SensorVVR, INPUT);
pinMode(LED, OUTPUT);

digitalWrite(LED, LOW);


// Drehrichtung
digitalWrite(in1, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in4, LOW);


//LCD initialisierung
lcd.init();
lcd.backlight();
lcd.print("LOS!!");
}

void loop(){
  delay(100);
  
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Subject 1");
 
 VRRWert = analogRead(SensorVRR) /2;
 VVRWert = analogRead(SensorVVR) /2;
 analogWrite(MR, SPEED);
 analogWrite(ML, SPEED);
 
 lcd.setCursor(0,1);
 lcd.print("wert: ");
 lcd.print(VRRWert);
 
 lcd.setCursor(0,2);
 lcd.print("Vorne: ");
 lcd.print(VVRWert);
 
 
 //Sensor Seite Anfang
 
 if(VRRWert > 260){
  analogWrite(MR, SPEEDH);
  analogWrite(ML, SPEEDL);
  lcd.setCursor(0,3);
  lcd.print("kl. Entf");
 }
 
 if((VRRWert < 260) && (VRRWert > 200)){
  lcd.setCursor(0,3); 
  lcd.print("normal");
 }
   
 if(VRRWert < 200){
  analogWrite(MR, SPEEDL);
  analogWrite(ML, SPEEDH);
  lcd.setCursor(0,3);
  lcd.print("gr. Entf");
 }
  //Sensor seite Ende
  
  //Sensor vorne Anfang
  if(VVRWert > 260){
  analogWrite(ML, 0);
  analogWrite(MR, 0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("!!!STOP!!!");
  lcd.setCursor(0,1);
  lcd.print("Wand: ");
  lcd.print(VVRWert);
  }

  
 }
