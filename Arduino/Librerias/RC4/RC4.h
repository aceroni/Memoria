#ifndef RC4_h
#define RC4_h

#include "Arduino.h"

class RC4{
	public:
		RC4(char* key);
		char* encrypt(char * text, int length);
		char* decrypt(char * en_text, int length);
		unsigned char* getKey();
		
	private:
		void swap(unsigned char *s, unsigned int i, unsigned int j);
		void rc4_init(unsigned char *key, unsigned int key_length);
		unsigned char rc4_output();
		unsigned char *_key;
};

#endif