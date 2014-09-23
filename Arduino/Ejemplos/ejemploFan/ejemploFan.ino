#include <EqOnOff.h>

EqOnOff fan(10);

void setup(){
}

void loop(){
  fan.encender();
  delay(10000);
  fan.apagar();
  delay(10000); 
}

