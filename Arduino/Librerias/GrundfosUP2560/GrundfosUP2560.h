/* 
  grundfosUP2560.h - Biblioteca para la bomba Grundfos UP 25-60.
  Creado por Alvaro Ceroni, Septiembre 2014.
*/
#ifndef GrundfosUP2560_h
#define GrundfosUP2560_h

#include "Arduino.h"

class GrundfosUP2560{
	public:
		GrundfosUP2560(int p1, int p2, int p3);
		int getPort();
		int getStatus();
		void changeStatus(int status);
	private:
		int _port1;
		int _port2;
		int _port3;
		int _status;
};

#endif
