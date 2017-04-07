#include <WatchDogTimer.h>

#define LED LED_BUILTIN

// this boolean has to be volatile because it is used in the IRS (interrupt service routine)
volatile bool wdtTimeout = false;

void setup()
{
  //make startup easily visible
  Serial.begin(9600);
  Serial.write("startup\n\r");
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  //watchdog setup without reset with interrupt
  watchDogTimer.setup(WDT_1S, false, true);
}


void loop()
{
  delay(10);  

  //this boolean is set true by the ISR
  if(wdtTimeout)
  {
	//toggle led
    digitalWrite(LED, !digitalRead(LED));
    Serial.write("wdt timeout\n\r");
    wdtTimeout = false;
  }
}


// this is the ISR that gets called on the watchdog timeout. prevent using long and blocking functions or loops in the ISR
ISR(WDT_vect)
{
  wdtTimeout = true;
}