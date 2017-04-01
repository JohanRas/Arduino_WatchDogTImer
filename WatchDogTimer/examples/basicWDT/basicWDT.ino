#include <WatchDogTimer.h>

#define LED LED_BUILTIN
#define BUTTON 1

void setup() 
{ 
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

  // maak reset duidelijk zichtbaar
  digitalWrite(LED, LOW);
  delay(1000);
  digitalWrite(LED, HIGH);

  // zet de watchdog timer aan met als interval 1s, In reset mode zonder interrupt.
  // mogelijke intervallen zijn: 
  // WDT_16MS, WDT_32MS, WDT_64MS, WDT_128MS, WDT_256MS, WDT_512MS, 
  // WDT_1S, WDT_2S, WDT_4S, WDT_8S 
  watchDogTimer.setup(WDT_1S , true, false);
}


void loop() 
{
  //rest de processor door de knop in te houden (1 seconde). Door de while loop wordt de wdt niet gereset
  while(digitalRead(BUTTON));

  //reset de timer
  watchDogTimer.reset();      
}
