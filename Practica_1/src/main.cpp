#include <Arduino.h>
#define LED 15

void setup() {
  
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  
  digitalWrite(LED,HIGH);
  Serial.println("ON");
  delay(500);
  digitalWrite(LED,HIGH);
  Serial.println("OFF");
  digitalWrite(LED,LOW);
  delay(500);

}