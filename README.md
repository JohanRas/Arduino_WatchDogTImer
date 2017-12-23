# Arduino watchdog timer
This library is made to make the arduino's (ATmega328P) on-chip watchdog timer easier to use.

## The watchdog timer
A watchdog timer is a hardware safety feature that can reset a microcontroller in case it hangs. An example could be in case of a runaway loop. When the timer resets the microcontroller when it reaches a specified time-out. To prevent the microcontroller from resetting, the watchdog timer needs to be reset before it reaches the time-out. This is sometimes called 'kicking the dog'. When the watchdog timer is reset it will start counting from 0. It needs to be 'kicked' regularly to prevent the microcontroller from resetting. As a result the microcontroller will be reset, if it ever gets stuck on a piece of code that doesn't 'kick' the watchdog.
The watchdog timer of the ATmega328P can also be configured to generate an interupt instead of a reset.

The watchdog timer is described by the ATmega328P datasheet as follows:
```
ATmega48A/PA/88A/PA/168A/PA/328/P has an Enhanced Watchdog Timer (WDT). The WDT is a timer
counting cycles of a separate on-chip 128kHz oscillator. The WDT gives an interrupt or a system reset when the
counter reaches a given time-out value. In normal operation mode, it is required that the system uses the WDR
- Watchdog Timer Reset - instruction to restart the counter before the time-out value is reached. If the system
doesn't restart the counter, an interrupt or system reset will be issued.
```

## Functions
This library provides three functions for using the watchdog timer. 

### configuring the watchdog timer
```
void setup(uint8_t interval, bool resetOnTimeout, bool useInterrupt );
```
The watchdog timer can be used with different time-out values. the values that can be used are:
- WDT_16MS
- WDT_32MS
- WDT_64MS
- WDT_128MS
- WDT_256MS
- WDT_512MS
- WDT_1S
- WDT_2S
- WDT_4S
- WDT_8S 	

With the setup function you can also specify what happens when a time-out occurs. A reset, an interrupt or both

Usage:
```
watchDogTimer.setup(WDT_1S , true, false);
```

### resetting the timer
```
void reset();
```
Resets or 'kicks' the watchdog timer.

Usage:
```
watchDogTimer.reset();
```

### resetting the arduino / ATmega328P
```
void resetArduino();
```
Uses the watchdog timer to reset the microcontroller. This is done by selecting the lowest time-out value and letting the watchdog time-out on purpose.

Usage:
```
watchDogTimer.resetArduino();
```

## Generating an interrupt
To generate an interrupt on a watchdog time-out an ISR (interrupt service routine) needs to be created. An the ISR can be created like this:
```
ISR(WDT_vect)
{
  // code to be called on a watchdog time-out
}
```


