#include "LED13.h"

const byte LED_PIN = 13;

LED13::LED13(){
  pinMode(LED_PIN, OUTPUT);
}

LED13::~LED13(){

}

void LED13::on(){
  digitalWrite(LED_PIN, HIGH);
}

void LED13::off(){
  digitalWrite(LED_PIN, LOW);
}

void LED13::blink(int time){
  on();
  delay(time/2);
  off();
  delay(time/2);
}
