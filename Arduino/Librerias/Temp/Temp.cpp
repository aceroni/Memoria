/* 
	Temp.cpp Biblioteca que permite transformar una medición de voltaje en temperatura
	Creado por Álvaro Ceroni, Septiembre 2014.
*/
#include "Arduino.h"
#include "Temp.h"

Temp::Temp(int pin)
{
	_pin=pin;
	pinMode(_pin,INPUT);
}
double Temp::medir()
{
	double calc;
	int val=analogRead(_pin);
	double v_in=5.0/1023*val;
	if(v_in<0.7)
		calc=7.9902*v_in+5.4596;
	else
		calc=136.38*v_in-78856;
	return calc;
}