#include <RC4.h>
char* key="key";
char* text="plaintext";
RC4 myRC4(key);

void setup(){
  Serial.begin(9600);
  int l=strlen(text);
  char* en=myRC4.encrypt(text,l);
  hexPrint(en,l);
  char* de=myRC4.decrypt(en,l);
  hexPrint(de,l);
}

void loop(){}

void hexPrint(char* t, int large){
  Serial.println(strlen(t));
  for(int i=0;i<large;i++){
    Serial.print(t[i],HEX);
    Serial.print(":");  
  }
  Serial.println("");
}
