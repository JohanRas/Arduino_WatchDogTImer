#include <WatchDogTimer.h>

#define BUTTON 1
#define LED LED_BUILTIN


void setup() 
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

  //maak reset duidelijk zichtbaar
  digitalWrite(LED, LOW);
  delay(1000);
  digitalWrite(LED, HIGH);
}


void loop() 
{
  if(digitalRead(BUTTON))
  {  
    watchDogTimer.resetArduino();
  }
}