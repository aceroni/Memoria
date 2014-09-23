/* 
	Temp.h Biblioteca que permite transformar una medición de voltaje en temperatura
	Creado por Álvaro Ceroni, Septiembre 2014.
*/

#ifndef Temp_h
#define Temp_h

#include "Arduino.h"

class Temp
{
	public:
		Temp(int pin);
		double medir();
	private:
		int _pin;
};

#endif