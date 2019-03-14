#include "Timer1.h"

void Timer1Class::init()
{
		cli();//stop interrupts
		
		//set timer1 interrupt
		TCCR1A = 0;// set entire TCCR1A register to 0
		TCCR1B = 0;// same for TCCR1B
		TCNT1  = 0;//initialize counter value to 873
		
		// turn on CTC mode
		TCCR1B |= (1 << WGM12) | (1 << WGM13);
		
		// no prescaler
		TCCR1B |= (1 << CS10);
		
		// set compare match register
		OCR1A = t_450us;
		OCR1B = t_300us;
		
		// enable timer compare and overflow interrupt
		TIMSK1 |= (1 << TOIE1) | (1 << OCIE1B) | (1 << OCIE1A);
		
		sei();//allow interrupts

}

/*
	Set time until the next overflow by setting the counter value
*/
void Timer1Class::time_to_OVF(unsigned int countervalue){	
	TCNT1  = countervalue;
}

Timer1Class Timer1;

