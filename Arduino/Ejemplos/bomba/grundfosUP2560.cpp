/* 
  grundfosUP2560.cpp - Biblioteca para la bomba Grundfos UP 25-60.
  Creado por Alvaro Ceroni, Septiembre 2014.
*/
#include "Arduino.h"
#include "GrundfosUP2560.h"

GrundfosUP2560::GrundfosUP2560(int p1, int p2, int p3)
{
	_port1=p1;
	_port2=p2;
	_port3=p3;
	_state=-1;
	pinMode(_port1,OUTPUT);
	pinMode(_port2,OUTPUT);
	pinMode(_port3,OUTPUT);
}

int GrundfosUP2560::getPort(){
	switch(_state){
		case 1:
			return _port1;
		case 2:
			return _port2;
		case 3:
			return _port3;
		default:
			return -1;
	}
}

int GrundfosUP2560::getState(){
	return _state;
}

void GrundfosUP2560::changeState(int state){
	if(state<0 || state >3)
		return;
	_state=state;
	if(_state==0){
		digitalWrite(_port1,LOW);
		digitalWrite(_port2,LOW);
		digitalWrite(_port3,LOW);
	}
	else if(_state==1){
			digitalWrite(_port1,HIGH);
			digitalWrite(_port2,LOW);
			digitalWrite(_port3,LOW);
			return;
		}
	else if(_state==2){
			digitalWrite(_port1,LOW);
			digitalWrite(_port2,HIGH);
			digitalWrite(_port3,LOW);
			return;
		}
	else{
		digitalWrite(_port1,LOW);
		digitalWrite(_port2,LOW);
		digitalWrite(_port3,HIGH);
		return;
	}
}
	
	
