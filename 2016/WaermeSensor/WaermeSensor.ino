#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// arrays to hold device addresses
DeviceAddress insideThermometer, outsideThermometer;

//float to save temperature
float tempC;

//#define HEAT 30

void setup(void)
{
  Serial.begin(9600);
  lcd.init();  
  
  lcd.backlight();
  lcd.print(" Arduino Thermometer");
  lcd.setCursor(0,1);
  lcd.print(" Made by the Brains");
  lcd.setCursor(0,3);
  lcd.print("                V1.0");
  delay(2500);
  
  Serial.println("");

  // Start up the library
  sensors.begin();
  
  // locate devices on the bus
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");

  // search for devices on the bus and assign based on an index.
  if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address for Device 0"); 
  if (!sensors.getAddress(outsideThermometer, 1)) Serial.println("Unable to find address for Device 1"); 

//beschleunigt das auslesen, ist aber unbrauchbar :(
//sensors.setWaitForConversion(true);
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  tempC = sensors.getTempC(deviceAddress);
  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print(" Temp F: ");
  Serial.print(DallasTemperature::toFahrenheit(tempC));
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    Thermometer");
  lcd.setCursor(0,1);
  lcd.print("Temp C: ");
  lcd.print(tempC);
  lcd.setCursor(0,2);
  lcd.print("Temp F: ");
  lcd.print(DallasTemperature::toFahrenheit(tempC));
}

void loop(void)
{ 
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println("DONE");

  printTemperature(insideThermometer);
  printTemperature(outsideThermometer);
}

