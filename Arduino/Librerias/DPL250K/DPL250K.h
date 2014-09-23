/*
	DPL250K.h - Biblioteca para miniturbina DPL250 versión K
	Creado por Álvaro Ceroni, Septiembre, 2014.
	Verifique el puerto corresponda un interrupt pin.
	http://arduino.cc/en/pmwiki.php?n=Reference/AttachInterrupt
*/
#ifndef DPL250K_h
#define DPL250K_h

#include "Arduino.h"

class DPL250K
{
	public:
		DPL250K(int port);
		double medir();
};

#endif