#ifndef Temp_h
#define Temp_h

#include "Arduino.h"
#include "Sensor.h"

class Temp : public Sensor{
	public:
		Temp(int port);
		virtual double measure();
	private:
		int _port;
};

#endif