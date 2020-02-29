#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


#define PWMA 4
#define PWMB 5
#define AIN_1 30               //Motorenpins  
#define AIN_2 31
#define BIN_1 32
#define BIN_2 33
#define LED 13

int time;

void setup() {
  
  
  lcd.init();                      // initialize the lcd 
  lcd.backlight(); 

pinMode(AIN_1 , OUTPUT);
pinMode(AIN_2 , OUTPUT);
pinMode(BIN_1 , OUTPUT);
pinMode(BIN_2 , OUTPUT);

pinMode(LED  , OUTPUT);

digitalWrite(AIN_1, HIGH);
digitalWrite(BIN_1, HIGH);       //definiere Drehrichtung
digitalWrite(AIN_2, LOW);
digitalWrite(BIN_2, LOW);

lcd.print("    Kalibrieren");
lcd.setCursor(0,1);
lcd.print("      beginnt!");
delay(1000);
lcd.clear();
time = 1650;
}

void loop() {
  /*if (time < 500){
  time = 5000;
  }
  lcd.clear();
  lcd.print("    Kalibrieren");
  lcd.setCursor(0,1);
  lcd.print("      laeuft!");
  lcd.setCursor(0,2);
  lcd.print(time);
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);         //lässt die Motoren für senkende Zeit auf höchster
  digitalWrite(LED, HIGH);        // Geschwindigkeit fahren: HIGH/255
  delay(time);                    //Zeit 
  digitalWrite(PWMA,LOW);
  digitalWrite(PWMB,LOW);
  //delay(2000);                    //Stillstandspause: 2 sec
  //time = time - 10;
  */

digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);
}
