#include "Arduino.h"
#include "DPL250K.h"

volatile int NbTopsFan;

void rpm()
{
	NbTopsFan++;
}

DPL250K::DPL250K(int port)
{
	attachInterrupt(port,rpm,RISING);
}

double DPL250K::measure()
{
	double calc;
	NbTopsFan=0;
	sei();
	delay(1000);
	cli();
	calc=1.0*NbTopsFan/35.07;
	return calc;
}