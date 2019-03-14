#include "hwapi.h"

// 
/*
    Name:       IHCcontroller.ino
    Created:	22/01/2019 17:57:39
    Author:     Thibault Mollier
*/

enum T_FRAME{START,DATA,PARITY} FRAME;
unsigned int DataIn[NUM_MODULE] = {0xFFFF};

void setup()
{
	
	Timer1.init();
	Transmiter.init();
	Hwapi.init();
	FRAME = START;
	Serial.print("Port open\n");
		
}

void loop()
{	
}
/*
	Interrupt on CompA register
*/
ISR(TIMER1_COMPA_vect){
	switch (FRAME)
	{
		case START:
			break;
		case DATA:
			if (Hwapi.AllDataTransmitted())
			{
				FRAME=PARITY;	
				Hwapi.WriteParity();
			}else{
				Hwapi.Write(DataIn);
			}
			break;
		case PARITY:
			break;
	}	
}
/*
	Interrupt on CompB register
*/
ISR(TIMER1_COMPB_vect){
	switch (FRAME)
	{
		case START:
			break;
		case DATA:
		case PARITY:
			Hwapi.Write(LOW);
			break;
	}
}
/*
	Interrupt on overflow
*/
ISR(TIMER1_OVF_vect){
	switch (FRAME)
	{
		case START:
			Hwapi.Write(LOW);
			Timer1.time_to_OVF(t_300us);	
			FRAME=DATA;
			break;
		case DATA:
			Hwapi.Write(HIGH);
			Timer1.time_to_OVF(t_600us);	
			break;
		case PARITY:
			Hwapi.Write(HIGH);
			Timer1.time_to_OVF(t_4100us);
			Transmiter.read(DataIn);
			FRAME=START;
			break;	
	}
}

 