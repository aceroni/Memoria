#include "Arduino.h"
#include <SPI.h>
#include <WiFi.h>
#include "EncryptedChat.h"
#include "RC4.h"

int large;

EncryptedChat::EncryptedChat(int port, char* key, int flag){
	_port=port;
	_flag=flag;
	_key=key;
}

int EncryptedChat::connect(char *ssid, char *pswd){
	if(_flag)
		Serial.println("connecting...");
	if(WiFi.status()==WL_NO_SHIELD){
		if (WiFi.status() == WL_NO_SHIELD) 
			if(_flag)
				Serial.println("WiFi Shield not available");
			return 1;
	}
	if( _status != WL_CONNECTED) {
		// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
		_status = WiFi.begin(ssid, pswd);
		// wait 10 seconds for connection:
		delay(10000);
	}
	if(_flag && _status==WL_CONNECTED){
		 // print your WiFi shield's IP address:
		  IPAddress ip = WiFi.localIP();
		  Serial.print("IP Address: ");
		  Serial.println(ip);
		  Serial.println(ip);

		  // print your MAC address:
		  byte mac[6];
		  WiFi.macAddress(mac);
		  Serial.print("MAC address: ");
		  Serial.print(mac[5], HEX);
		  Serial.print(":");
		  Serial.print(mac[4], HEX);
		  Serial.print(":");
		  Serial.print(mac[3], HEX);
		  Serial.print(":");
		  Serial.print(mac[2], HEX);
		  Serial.print(":");
		  Serial.print(mac[1], HEX);
		  Serial.print(":");
		  Serial.println(mac[0], HEX);
	}
	if(_flag && _status!=WL_CONNECTED){
		Serial.println("Couldn't get a wifi connection");
		return !WL_CONNECTED;
	}
	return 0;
}

void EncryptedChat::write(char *text, int length){
	WiFiServer server(_port);
	server.begin();
	RC4 myRC4(_key);
	
	while(true){
		WiFiClient client=server.available();
		if(client.connected() && client.available()){
			if(_flag)
				Serial.println("New Client!");
			client.flush();
			char* textEncrypted=myRC4.encrypt(text,length);
	
			for(int i=0;i<length;i++){
				client.write(textEncrypted[i]);
			}
			client.stop();
			return;	
		}
	}
	
}

int EncryptedChat::read(char *r){
	int i=0;
	char temp[256];
	boolean endLine;
	WiFiServer server(_port);
	server.begin();
	RC4 myRC4(_key);
	
	while(true){
		WiFiClient client=server.available();
		if(client.connected() && client.available()){
			if(_flag)
				Serial.println("New Client!");
			client.flush();
			client.println("Hello, client");
			while(true){
				char c=client.read();
				if(c!=-1 && c!=13 && c!=10){
					temp[i]=c;
					i++;
				}
				if(c==13)
					endLine=true;
				if(endLine && c==10){
					temp[i]='\0';
					large=i;
					break;
				}
			}
		client.stop();
		
		char* temp2=myRC4.decrypt(temp,i);
		for(int j=0;j<=i;j++)
			r[j]=temp2[j];
		
		Serial.println("");		
		return large;
		}
		client.stop();
	}
}
	


