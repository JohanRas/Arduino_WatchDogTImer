#include "WatchDogTimer.h"
#include <avr/wdt.h>


void WatchDogTimerClass::setup(uint8_t interval, bool resetOnTimeout, bool useInterrupt)
{
	 uint8_t bits = interval;
	 bits = ((bits & 0x08) << 2) | (bits & 0x07);	//get the interval bits in the correct format
	 
	 if(useInterrupt) 	bits |= 0x40;
	 if(resetOnTimeout)	bits |= 0x08;
	 
	 __asm__ __volatile__ ("cli" ::); 				//disable interrupts
	 WDTCSR |= 0x18;								//enter setup mode for the watchdog timer
	 WDTCSR = bits;
	 __asm__ __volatile__ ("sei" ::); 				//enable interrupts
}


void WatchDogTimerClass::reset()
{
	wdt_reset();
}


void WatchDogTimerClass::resetArduino()
{
	this->setup(0, true, false);  					//enable the watchdog timer with shortest timeout (16ms) in reset mode without interrupt
	while(true);									//wait for the watchdog timer to timeout
}

