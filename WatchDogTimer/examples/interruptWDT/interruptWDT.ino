#include <WatchDogTimer.h>

#define LED LED_BUILTIN

bool ledStatus = false;

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  //watchdog setup zonder reset met interrupt
  watchDogTimer.setup(WDT_1S, false, true);
}


void loop()
{
  delay(10);  
  digitalWrite(LED, ledStatus);
}


ISR(WDT_vect)
{
  ledStatus = !ledStatus;
}
