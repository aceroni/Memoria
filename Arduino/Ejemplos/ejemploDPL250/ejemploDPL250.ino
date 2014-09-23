#include <DPL250K.h>

DPL250K dpl250k(0);

void setup()
{
}

void loop()
{
  double medicion=dpl250k.medir();
  delay(1000);
}

