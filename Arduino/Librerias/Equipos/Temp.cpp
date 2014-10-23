/* 
	Temp.cpp Biblioteca que permite transformar una medición de voltaje en temperatura
	Creado por Álvaro Ceroni, Septiembre 2014.
*/
#include "Arduino.h"
#include "Temp.h"

Temp::Temp(int port)
{
	_port=port;
	pinMode(_port,INPUT);
}
double Temp::measure()
{
	double calc;
	int val=analogRead(_port);
	double v_in=5.0/1023*val;
	if(v_in<0.7)
		calc=7.9902*v_in+5.4596;
	else
		calc=136.38*v_in-78.856;
	return calc;
}