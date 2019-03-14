// hwapi.h

#ifndef _HWAPI_h
#define _HWAPI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Timer1.h"
#include "Transmiter.h"

/*
	Define parameter
*/
#define DEBUG false

#define DATA_LENGHT 16
#define  NUM_MODULE 8
const byte PIN_MODULE[8] = {2,3,4,5,6,7,8,9};

	
class HwapiClass
{
 protected:


 public:
	byte parity[DATA_LENGHT]={0};
	byte databit=0;
	void init();
	void Write(unsigned int DataIn[NUM_MODULE]);
	void Write(int Data);
	void WriteParity();
	bool AllDataTransmitted();
	
};

extern HwapiClass Hwapi;

#endif

