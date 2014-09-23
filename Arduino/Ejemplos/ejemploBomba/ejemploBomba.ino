#include <GrundfosUP2560.h>

GrundfosUP2560 grundfosUP2560(8,9,10);

void setup(){
}

void loop(){
  grundfosUP2560.changeState(1);
  delay(1000);
  grundfosUP2560.changeState(2);
  delay(1000);
  grundfosUP2560.changeState(3);
  delay(1000);
}
