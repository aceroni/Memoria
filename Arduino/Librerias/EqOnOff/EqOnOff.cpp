/*
	EqOnOff.cpp - Biblioteca para encender o apagar un equipo que solo tiene esa función.
	Creado por Álvaro Ceroni, Septiembre 2014.
*/

#include "Arduino.h"
#include "EqOnOff.h"

EqOnOff::EqOnOff(int pin)
{
	_pin=pin;
	_status=-1; // 0 encendido, 1 apagado, -1 desconocido
	pinMode(_pin,OUTPUT);
}

void EqOnOff::encender()
{
	if(_status!=0){
		digitalWrite(_pin,HIGH);
		_status=0;
	}
	return;
}

void EqOnOff::apagar()
{
	if(_status!=1){
		digitalWrite(_pin,LOW);
		_status=1;
	}
	return;
}

int EqOnOff::getStatus()
{
	return _status;
}