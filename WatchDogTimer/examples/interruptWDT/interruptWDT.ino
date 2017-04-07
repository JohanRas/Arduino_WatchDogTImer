#include <WatchDogTimer.h>

#define LED 13
#define LEDPORT PORTB
#define LEDBIT 0x20

//moet volatile zijn omdat hij in de isr gebruikt wordt
volatile bool wdtTimeout = false;

void setup()
{
  Serial.begin(9600);
  Serial.write("startup\n\r");
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  //watchdog setup zonder reset met interrupt
  watchDogTimer.setup(WDT_1S, false, true);
}


void loop()
{
  delay(10);  

  if(wdtTimeout)
  {
    LEDPORT ^= LEDBIT; //toggle led
    Serial.write("wdt timeout\n\r");
    wdtTimeout = false;
  }
}


// deze functie wordt aangeroepen door de watchdog. gebruik in de ISR geen lange/blokeerende functies/loops
ISR(WDT_vect)
{
  wdtTimeout = true;
}