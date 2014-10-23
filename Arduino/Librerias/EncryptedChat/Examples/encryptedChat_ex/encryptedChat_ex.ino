#include <WiFi.h>
#include <EncryptedChat.h>
#include <RC4.h>

EncryptedChat chat(23,"key",1);

void setup(){
  Serial.begin(9600);
  chat.connect("depto_WiFi","123abc789");  
//  char r[256];
//  int l=chat.read(r);
//  hexPrint(r, l); 
  char p[]={0x6a,0x00,0x42,0x8c,0x56,0xe0};
  chat.write(p,6);
}

void loop(){}

void hexPrint(char* t, int large){
  for(int i=0;i<large;i++){
    Serial.print(t[i],HEX);
    Serial.print(":");  
  }
  Serial.println("");
}

