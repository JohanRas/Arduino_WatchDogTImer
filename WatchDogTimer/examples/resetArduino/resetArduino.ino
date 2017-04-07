#include <WatchDogTimer.h>

#define BUTTON 2
#define LED LED_BUILTIN

//connect a button between gpio2 and GND

void setup() 
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  //make reset easily visible
  Serial.begin(9600);
  Serial.write("startup\r\n");
  
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}


void loop() 
{
  //push the button to reset the arduino
  if(!digitalRead(BUTTON))
  {  
    watchDogTimer.resetArduino();
  }
}