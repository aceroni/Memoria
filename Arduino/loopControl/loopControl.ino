#include <Temp.h>
#include <PID_v1.h>
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

double setpoint, input, output;

PID controlador(&input, &output, &setpoint,2,5,1,DIRECT);
int WindowSize=5000;
unsigned long windowStartTime;

void setup(){
  Serial.begin(9600);
  
  setpoint=25;
  windowStartTime=millis();
  controlador.SetOutputLimits(0, WindowSize);
  controlador.SetMode(MANUAL);
  
  getPorts();
  pump.changeStatus(3);
  cooler.apagar();
  heater.encender();
}

void loop(){
  medir();
  alarma();
  controlar();
  enviar();
  recibir();
}

void getPorts(){
}

void medir(){
  temp1=t1.medir();
  temp2=t2.medir();
  flow=flowmeter.medir();
  pumpStatus=pump.getStatus();
  coolerStatus=cooler.getStatus();
  heaterStatus=heater.getStatus();
}

void alarma(){
  if(temp1>60 || temp2>60){
    heater.apagar();
  }
}

void controlar(){
  input=temp1;
  controlador.Compute();
  unsigned long now=millis();
  if( now-windowStartTime>WindowSize)
  {
    windowStartTime+=WindowSize;
  }
  if(output>now-windowStartTime) heater.encender();
  else heater.apagar();
}

void enviar(){
  Serial.print("temp1:");
  Serial.println(temp1);
  Serial.print("temp2:");
  Serial.println(temp2);
  Serial.print("flow:");
  Serial.println(flow);
  Serial.print("pump:");
  Serial.println(pumpStatus);
  Serial.print("cooler:");
  Serial.println(coolerStatus);
  Serial.print("heater:");
  Serial.println(heaterStatus); 
  Serial.println("--");
}

void recibir(){
}

