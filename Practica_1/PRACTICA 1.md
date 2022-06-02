# PRÁCTICA 1: BLINK

## Codigo:


```C++
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
```

## Funcionalidad codigo:


1. Iniciar pin de led como salida
2. Iniciar el terminal serie
3. - bucle infinito
   - encender led
   - sacar por puerto serie mensaje ON 
   - espera de 500 milisegundos
   - apagar led
   - sacar por puesto serie mensaje OFF 
   - espera de 500 milisegundos


