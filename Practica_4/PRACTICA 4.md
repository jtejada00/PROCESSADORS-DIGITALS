# PRACTICA 4 : SISTEMAS OPERATIVOS EN TIEMPO REAL

## Codi:

```C++
#include <Arduino.h>

void anotherTask( void * parameter );
void setup()
{
    Serial.begin(115200);
    /* we create a new task here */
    xTaskCreate(anotherTask, "another Task", 10000, NULL, 1, NULL); /* Task handle to keep track of created task */
}
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
    Serial.println("this is ESP32 Task");
    delay(1000);
}
 
/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter )
{
    /* loop forever */
    for(;;)
    {
        Serial.println("this is another Task");
        delay(1000);
    }
    /* delete a task when finish,
    this will never happen because this is infinity loop */
    vTaskDelete( NULL );
}

```

### Funcionament:

Per crear el codi d'aquest programa hem fet servir les Task. Primer de tot dins del void setup() cal crear la Task:

Dins del void loop(), posem el temps que trigarà a escriure per pantalla la frase que treura per pantalla i també aquest serà el temps que trigarà per a executar el subprograma cada vegada que ho acabi. Seguidament cal fer el codi del subprograma, en aquest creem un bucle, que s'encarregarà d'escriure per pantalla una frase i es repetirà cada vegada que es faci el delay. En aquest cas el bucle no té fi, així que no pararà. Perquè el subrograma funcioni, cal posar la primera línia d'aquesta per retornar-ho al començament del programa (abans del void setup()).