#include "Arduino.h"
#include "RC4.h"

unsigned char S[256];
unsigned i,j;
unsigned char en[256];
unsigned char de[256];

RC4::RC4(char *key){
	_key=(unsigned char*)key;
}
char* RC4::encrypt(char * text,int length){	
	rc4_init(_key, strlen((char*)_key));
	for(int k=0;k<length;k++){
		en[k]=text[k] ^ rc4_output();
	}
	
	return (char*)en;
}

char* RC4::decrypt(char * en_text,int length){
	rc4_init(_key, strlen((char*)_key));
	for(int k=0;k<length;k++){
		de[k]=en_text[k] ^ rc4_output();
	}
	return (char*) de;
}
	
void RC4::swap(unsigned char *s, unsigned int i, unsigned int j){
	unsigned char temp = s[i]; 
    s[i] = s[j]; 
    s[j] = temp;  
}

void RC4::rc4_init(unsigned char *key, unsigned int key_length){
	for (i = 0; i < 256; i++) 
        S[i] = i; 
    for (i = j = 0; i < 256; i++) { 
        j = (j + key[i % key_length] + S[i]) & 255; 
        swap(S, i, j); 
    } 
    i = j = 0; 
}

unsigned char RC4::rc4_output(){
	i = (i + 1) & 255; 
    j = (j + S[i]) & 255; 
    swap(S, i, j); 
    return S[(S[i] + S[j]) & 255]; 
}

unsigned char* RC4::getKey(){
	return _key;
	}