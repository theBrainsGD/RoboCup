#ifndef LED13_H
#define LED13_H

#include <Arduino.h>

class LED13{
public:
   LED13();
   ~LED13();
   void on();
   void off();
   void blink(int time);
};

#endif
