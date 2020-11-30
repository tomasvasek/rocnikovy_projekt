#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <IFTTTWebhook.h>

#define ledPin 5 
#define wakePin 16
#define ssid "YOUR_WIFI_SSID"
#define password "YOUR_WIFI_PASSWORD"
#define IFTTT_API_KEY "IFTTT_KEY_GOES_HERE"
#define IFTTT_EVENT_NAME "IFTTT_EVENT_NAME_HERE"

void setup() {
    Serial.begin(115200);
  while(!Serial) { 
  }
  Serial.println(" ");// print an empty line before and after Button Press  	
  Serial.println("Button Pressed");
  Serial.println(" TEST ");// print an empty line  
  ESP.deepSleep(wakePin); 
}

void loop() {
  //if deep sleep is working, this code will never run.
  Serial.println("This shouldn't get printed");
}