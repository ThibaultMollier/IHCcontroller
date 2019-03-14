// Transmiter.h

#ifndef _TRANSMITER_h
#define _TRANSMITER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class TransmiterClass
{
 protected:
	

 public:
	void init();
	void TransmiterClass::read(unsigned int* Data);
};

extern TransmiterClass Transmiter;

#endif

