#include "Transmiter.h"

void TransmiterClass::init()
{
	Serial.begin(9600);
}
/*
	Read 2 serial buffers, overwrite Data if its necessary and reply  
*/
void TransmiterClass::read(unsigned int* Data)
{
	int buffer = -1,Module;
	
	Module = Serial.read();
	buffer = Serial.read();
	if (buffer!= -1 && Module<8 && Module>=0)
	{
		Data[Module]=~buffer;
		Serial.print(Module);
		Serial.println(~Data[Module],HEX);
	}
}


TransmiterClass Transmiter;

