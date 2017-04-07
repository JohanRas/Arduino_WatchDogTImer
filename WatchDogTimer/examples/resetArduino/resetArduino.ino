#include <WatchDogTimer.h>

#define BUTTON 2
#define LED LED_BUILTIN


void setup() 
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  //maak reset duidelijk zichtbaar
  Serial.begin(9600);
  Serial.write("startup\r\n");
  
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}


void loop() 
{
  //maak gpio laag om de ATMEGA te resetten
  if(!digitalRead(BUTTON))
  {  
    watchDogTimer.resetArduino();
  }
}