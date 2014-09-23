int pin_pump[]={22,24,26};
int pin_heater=28;
int pin_flow=30;
int pin_cooler=32;

int pin_temp[]= {A14,A15};

int largo;

volatile int NbTopsFan;
double Calc;

void rpm(){
  NbTopsFan++;
}


void setup(){
  pinMode(pin_pump[0],OUTPUT);
  pinMode(pin_pump[1],OUTPUT);
  pinMode(pin_pump[2],OUTPUT);
  
  pinMode(pin_heater,OUTPUT);
  pinMode(pin_cooler,OUTPUT);
  
  pinMode(pin_flow,INPUT);
  
  Serial.begin(9600);
  attachInterrupt(0,rpm,RISING);
}

void loop(){
 
}


int bomba(int pin[],int pos){
  if(pos<0 || pos>4)
    return 1;
  if(pos==0){
    digitalWrite(pin[0],LOW);
    digitalWrite(pin[1],LOW);
    digitalWrite(pin[2],LOW);
  }
  for(int i=1;i<=3;i++){
    if(i==pos)
      digitalWrite(pin[i-1],HIGH);
    else
      digitalWrite(pin[i-1],LOW);    
  }
  return 0;
  
}

int encender_pin(int pin, int pos){
  if(pos!=0 || pos!=1)
    return 1;
  if(pos==1)
    digitalWrite(pin,HIGH);
  else
    digitalWrite(pin,LOW);
  return 0;
}


double flujometro(){
  NbTopsFan=0;
  sei();
  delay(1000);
  cli();
  Calc=(NbTopsFan/35.07);
}

double temp(int pin){
  double temp;
  
  int val=analogRead(pin);
  double v_in=5.0/1023*val;
  if(v_in<0.7)
    temp=7.9902*v_in+5.4596;
  else
    temp=136.38*v_in-78856;
  return temp;
}
