#ifndef EncryptedChat_h
#define EncryptedChat_h

#include "Arduino.h"
#include <SPI.h>
#include <WiFi.h>
#include <RC4.h>

class EncryptedChat{
	public:
		EncryptedChat(int port, char* key, int flag);
		int connect(char *ssid ,char *pswd);
		void write(char *text, int length);
		int read(char *text);
		void disconnect();
	private:
		int _port;
		int _flag;
		char* _key;
		int _status;
		char key[];
};

#endif