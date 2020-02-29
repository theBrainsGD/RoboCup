#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);

#define ONE_WIRE_BUS 2

const int MaxSensors=1;
float temp[MaxSensors];

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(){
Serial.begin(9600);
lcd.init();                    
 
  lcd.backlight();
  lcd.print("Hello, world!");
  delay(750);

}

void loop(){
  lcd.clear();
  sensors.setWaitForConversion(true);
sensors.requestTemperatures();
temp[1]=sensors.getTempCByIndex(1); 

Serial.println(temp[1]);
//lcd.print(temp[1]);
delay(1000);


}
