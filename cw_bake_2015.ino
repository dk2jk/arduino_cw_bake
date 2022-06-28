#include "cw.h"

Cw cw;
#define pinKey 4
#define pinTon 7

char s[40];
void setup() {
  Serial.begin(9600);
  pinMode(pinKey, OUTPUT);
  strcpy(s,"test de dk2jk+ ");
  Serial.println(__FILE__ __DATE__ __TIME__);
}

void loop() {
  int speed= map( analogRead(A0) ,0,1023,40,5);
  cw.setSpeed(speed);
  cw.setText(s); // nur wenn ready
  cw.run();
  digitalWrite(pinKey, !cw.key);
  cw.key ? tone(pinTon, 650) : noTone(pinTon);
}
