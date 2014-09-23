#include <Temp.h>
//#include <PID_v1.h>
#include <GrundfosUP2560.h>
#include <EqOnOff.h>
#include <DPL250K.h>

int pin_t1, pin_t2, pin_pump1, pin_pump2, pin_pump3, pin_cooler, pin_heater, pin_fl;
double temp1, temp2, flow;
int pumpStatus, coolerStatus, heaterStatus;

Temp t1=Temp(pin_t1);
Temp t2=Temp(pin_t2);
GrundfosUP2560 pump=GrundfosUP2560(pin_pump1, pin_pump2, pin_pump3);
EqOnOff cooler=EqOnOff(pin_cooler);
EqOnOff heater=EqOnOff(pin_heater);
DPL250K flowmeter=DPL250K(pin_fl);

void setup(){
  Serial.begin(9600);
  getPorts();
  pump.changeStatus(3);
  cooler.apagar();
  heater.encender();
}

void loop(){
}

void getPorts(){
}
