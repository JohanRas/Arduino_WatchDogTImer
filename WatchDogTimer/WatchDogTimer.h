#ifndef WATCHDOGTIMER_H_
#define WATCHDOGTIMER_H_

#include <avr/wdt.h>

#define WDT_16MS 	0
#define WDT_32MS 	1
#define WDT_64MS 	2
#define WDT_128MS 	3
#define WDT_256MS 	4
#define WDT_512MS 	5
#define WDT_1S 		6
#define WDT_2S 		7
#define WDT_4S 		8
#define WDT_8S 		9



class WatchDogTimerClass
{
public:
	void setup(uint8_t interval, bool resetOnTimeout, bool useInterrupt );
	void reset();
	void resetArduino();
};

static WatchDogTimerClass watchDogTimer;
#endif