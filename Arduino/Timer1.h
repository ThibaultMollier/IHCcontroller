// Timer1.h

#ifndef _TIMER1_h
#define _TIMER1_h

#define t_4100us 0
#define t_300us 60735
#define t_600us 55935 
#define t_450us 58335

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Timer1Class
{
 protected:


 public:
	void init();
	void time_to_OVF(unsigned int countervalue);
};

extern Timer1Class Timer1;

#endif

