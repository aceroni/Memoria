/* 
  grundfosUP2560.cpp - Biblioteca para la bomba Grundfos UP 25-60.
  Creado por Alvaro Ceroni, Septiembre 2014.
*/
#include "Arduino.h"
#include "GrundfosUP2560.h"

GrundfosUP2560::GrundfosUP2560(int p1, int p2, int p3)
{
	pinMode(p1,OUTPUT);
	pinMode(p2,OUTPUT);
	pinMode(p3,OUTPUT);
	_port1=p1;
	_port2=p2;
	_port3=p3;
	_status=-1;
}

int GrundfosUP2560::getPort(){
	switch(_status){
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

int GrundfosUP2560::getStatus(){
	return _status;
}

void GrundfosUP2560::changeStatus(int status){
	if(status<0 || status >3)
		return;
	_status=status;
	if(_status==0){
		digitalWrite(_port1,LOW);
		digitalWrite(_port2,LOW);
		digitalWrite(_port3,LOW);
	}
	else if(_status==1){
			digitalWrite(_port1,HIGH);
			digitalWrite(_port2,HIGH);
			digitalWrite(_port3,LOW);
			return;
		}
	else if(_status==2){
			digitalWrite(_port1,HIGH);
			digitalWrite(_port2,LOW);
			digitalWrite(_port3,LOW);
			return;
		}
	else{
		digitalWrite(_port1,LOW);
		digitalWrite(_port2,LOW);
		digitalWrite(_port3,LOW);
		return;
	}
}
	
	
