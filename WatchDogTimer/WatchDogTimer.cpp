#include "WatchDogTimer.h"
#include <avr/wdt.h>


void WatchDogTimerClass::setup(uint8_t interval, bool resetOnTimeout, bool useInterrupt)
{
	 uint8_t bits = interval;
	 bits = ((bits & 0x08) << 2) | (bits & 0x07);
	 
	 if(useInterrupt) 	bits |= 0x40;
	 if(resetOnTimeout)	bits |= 0x08;
	 
	 __asm__ __volatile__ ("cli" ::); 	//zet interrupts uit
	 WDTCSR |= 0x18;					//setup mode
	 WDTCSR = bits;
	 __asm__ __volatile__ ("sei" ::); 	//zet interrupts aan
}


void WatchDogTimerClass::reset()
{
	wdt_reset();
}


void WatchDogTimerClass::resetArduino()
{
	this->setup(0, false, true);  	//kortste time-out, interrupt uit en reset aan
	while(true);					//wacht op de watchdog time-out
}

