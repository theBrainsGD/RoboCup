
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int row = 1;

void setup()
{
  lcd.init();                      // initialize the lcd 
  Serial.begin(9600);
  
  pinMode(45, INPUT);
  pinMode(13, OUTPUT);
  lcd.backlight();
  clearManu();
  
}

void loop()
{
  if(digitalRead(45) == true){
    row++;
    digitalWrite(13, LOW);
  if(row > 4){
  row = 1;
  }
  if(row == 1){
    clearManu();
    lcd.setCursor(0,0);
    lcd.print(">state 1");
  }
  if(row == 2){
    clearManu();
    lcd.setCursor(0,1);
    lcd.print(">state 2");
  }
  if(row == 3){
    clearManu();
    lcd.setCursor(0,2);
    lcd.print(">state 3");
  }
  if(row == 4){
    clearManu();
    lcd.setCursor(0,3);
    lcd.print(">state 4");
  }
  delay(200);
  }
  digitalWrite(13, HIGH);
  
  Serial.print(row);
}

void clearManu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("state 1");
  lcd.setCursor(0,1);
  lcd.print("state 2");
  lcd.setCursor(0,2);
  lcd.print("state 3");
  lcd.setCursor(0,3);
  lcd.print("state 4");
}
