#include "hwapi.h"

void HwapiClass::init()
{
	for (int i =0;i<NUM_MODULE;i++)
	{
		pinMode(PIN_MODULE[i],OUTPUT);
	}
	Write(HIGH);

}
/*
	Write Data on output 
*/
void HwapiClass::Write(unsigned int DataIn[DATA_LENGHT]){

	if(DEBUG) Serial.print((DataIn[0] & (1 << databit))>0);

	for (int i =0;i<NUM_MODULE;i++)
	{
		digitalWrite(PIN_MODULE[i],(DataIn[i] & (1 << databit)));
		parity[i]+=(DataIn[i] & (1 << databit))>0;
	}
	databit++;
	
}
/*
	Write value to all outputs
*/
void HwapiClass::Write(int Data){
	
	if(DEBUG) Serial.print(Data);
	
	for (int i =0;i<NUM_MODULE;i++)
	{
		digitalWrite(PIN_MODULE[i],Data);
	}
}
/*
	Write the parity bit 
*/
void HwapiClass::WriteParity(){
	
	if(DEBUG) Serial.println((parity[0] % 2)==0);
	
	for (int i =0;i<NUM_MODULE;i++)
	{
		digitalWrite(PIN_MODULE[i],(parity[i] % 2)==0);
		parity[i] =0;
	}
	databit=0;
	
}
/*
	Return true if 16 bit has been transmitted 
*/
bool HwapiClass::AllDataTransmitted(){
	return (databit>=DATA_LENGHT);
}

HwapiClass Hwapi;

