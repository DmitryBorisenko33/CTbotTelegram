
#include <ESP8266WiFi.h>
#include "CTBot.h"
CTBot myBot;

#define WIFI_SSID "rise"
#define WIFI_PASSWORD "hostel3333"
String token = "1425283609:AAFf3YO8ouCJF23kU8CMiU7XXy21MFhbn9w"; 

void setup() {
	
	Serial.begin(115200);
	Serial.println("Starting TelegramBot...");


	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);

	
	Serial.print("Connecting to Wifi SSID ");
	Serial.print(WIFI_SSID);
	Serial.print(" ");
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
	
	while (WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(500);
	}
	Serial.println();

	Serial.print("WiFi connected. IP address: ");

	myBot.setTelegramToken(token);

	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");
}

void loop() {
	TBMessage msg;

	if (myBot.getNewMessage(msg))
		
	Serial.println(msg.text);
	myBot.sendMessage(msg.sender.id, msg.text);
	
	delay(500);
}
