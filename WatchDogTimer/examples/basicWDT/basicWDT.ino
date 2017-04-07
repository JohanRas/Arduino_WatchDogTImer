#include <WatchDogTimer.h>

#define LED LED_BUILTIN
#define BUTTON 2

//connect a button between gpio2 and GND

void setup() 
{ 
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  // make startup easily 
  Serial.begin(9600);
  Serial.write("startup\r\n");
  
  digitalWrite(LED, LOW);
  delay(1000);
  digitalWrite(LED, HIGH);

  // enable watchdog timer with interval an 1 second interval, in reset mode and without interrupt
  // possible intervals are: 
  // WDT_16MS, WDT_32MS, WDT_64MS, WDT_128MS, WDT_256MS, WDT_512MS, 
  // WDT_1S, WDT_2S, WDT_4S, WDT_8S 
  watchDogTimer.setup(WDT_1S , true, false);
}


void loop() 
{
  // press the button for 1s to let the watchdog timer timeout
  while(!digitalRead(BUTTON));

  // reset the watchdog timer
  watchDogTimer.reset();      
}