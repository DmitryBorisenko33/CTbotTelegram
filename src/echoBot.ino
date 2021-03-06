#ifdef ESP8266
#include <ESP8266WiFi.h>
#endif
#ifdef ESP32
#include <WiFi.h>
#endif
#include "CTBot.h"
CTBot myBot;
//это рабочий
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

	while (WiFi.status() != WL_CONNECTED) {
		Serial.print(".");
		delay(500);
	}
	Serial.println("");
	Serial.print("WiFi connected. IP address: ");

	myBot.setTelegramToken(token);

	if (myBot.testConnection()) {
		Serial.println("\n test Connection OK");
	}
	else {
		Serial.println("\n test Connection NOK");
	}
}

void loop() {
	TBMessage msg;

	if (myBot.getNewMessage(msg)) {

		Serial.println(msg.text);
		myBot.sendMessage(msg.sender.id, msg.text);
	}

	delay(500);
}
