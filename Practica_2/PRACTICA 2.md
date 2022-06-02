# PRÀCTICA 2: interrupció per GPIO Y interrupció per timer

## Codi GPIO:

```C++
void TakePin();

int val=0;

void setup() {
Serial.begin(9600);
pinMode(LED,OUTPUT);
attachInterrupt(digitalPinToInterrupt(INTERRUPTPIN),TakePin,FALLING); 
}

void loop() {
  val=digitalRead(0);
  if (val==1) {
   digitalWrite(LED, HIGH);
    Serial.println("ON");
    delay(500);
    digitalWrite(LED, LOW);
    Serial.println("OFF");
    delay(500);
  }
  else {digitalWrite(LED, HIGH); Serial.println("ON");}
}

void TakePin () {

Serial.println("BOOT");

}
```

### Funcionament GPIO:

El programa es similar al de la pràctica 1, el que em afegit, que una vegada pressionem el botó BOOT ens sortirà per pantalla un indicador que l'hem pressionat, però el que és important és que el programa seguirà en marxa, és a dir en bucle. Per tant, el nostre LED s'anirà apagant i encenent cada mig segon i si pressionem BOOT ens sortirà per pantalla.

## Codi TIMER:

```C++
#include <Arduino.h>

#define LED 16

volatile int interruptCounter;
int totalInterruptCounter;
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

void setup() {
  Serial.begin(115200);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true);
  timerAlarmEnable(timer);
}

void loop() {
  if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
    totalInterruptCounter++;
    Serial.print("An interrupt as occurred. Total number: ");
    Serial.println(totalInterruptCounter);
  }
}

```

### Funcionament GPIO:

El codi fa una interrupció per timer, que consisteix que al cap de cert temps s'executa una interrupció, aquest interrupció no es fa manualment sinó que el mateix programa s'encarrega d'executar-lo.

 Està programat perquè a cada segon es provoqui una interrupció, el programa la mostra per pantalla amb un missatge i diu quantes interrupcions ha fet ha fet en total, les quals van incrementant d'una en una.