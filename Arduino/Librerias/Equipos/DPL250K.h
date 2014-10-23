#ifndef DPL250K_h
#define DPL250K_h

#include "Arduino.h"
#include "Sensor.h"

class DPL250K : public Sensor{
	public:
		virtual double measure();
};

#endif