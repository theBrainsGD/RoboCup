
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

typedef struct{

  //char name[50];
  int row;
  
}Manu;
int row = 1;

Manu main = 1;

void setup()
{
  lcd.init();                      // initialize the lcd 
  Serial.begin(9600);
  
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  lcd.backlight();
  MainManu();
}

void loop()
{
  if(digitalRead(7) == HIGH){
    row++;
    digitalWrite(13, LOW);
  if(row > 4){
  row = 1;
  }
  if(row == 1){
    MainManu();
    lcd.setCursor(0,0);
    lcd.print(">state 1");
  }
  if(row == 2){
    MainManu();
    lcd.setCursor(0,1);
    lcd.print(">state 2");
  }
  if(row == 3){
    MainManu();
    lcd.setCursor(0,2);
    lcd.print(">state 3");
  }
  if(row == 4){
    MainManu();
    lcd.setCursor(0,3);
    lcd.print(">state 4");
  }
  delay(200);
  }
  digitalWrite(13, HIGH);
  Serial.print(digitalRead(7));
  
  Serial.print(row);
}

void MainManu(){
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
