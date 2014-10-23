#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class Sensor
{
	public:
		virtual double measure()=0;
		virtual ~Sensor(int[] port, int nPorts){
			_port=port;
			_nPorts=nPorts;
		}
	private:
		int[] _port;
		int _nPorts;
};

#endif