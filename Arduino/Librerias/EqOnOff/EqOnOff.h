/*
	EqOnOff.h - Biblioteca para encender o apagar un equipo que solo tiene esa función.
	Creado por Álvaro Ceroni, Septiembre 2014.
*/
#ifndef EqOnOff_h
#define EqOnOff_h

#include "Arduino.h"

class EqOnOff
{
	public:
		EqOnOff(int pin);
		void encender();
		void apagar();
		int getStatus();
	private:
		int _pin;
		int _status;
};

#endif