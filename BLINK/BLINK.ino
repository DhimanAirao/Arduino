#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

#define PORT 1000       //PORT on which you want to open your socket mostly choose large value because value values are mostly taken by sites
#define LED 2           // GPIO 2 pin of ESP01

WiFiClient client;
WiFiServer server(PORT);


const char *ssid="MYESP";       // Name of your esp01 wifi when it is started
const char *pass="PASSWORD";    // Password to connect your device to esp01 wifi if you don't want any password keep it empty

/*
 Here we are using our ESP module in Acess Point mode. But perfer to use it in Station mode.
 For using in Station Mode Write SSID to your wifi network which you want to connect and
 PASSWORD to it's password and if you want to use it in combine mode write both with different name
 */


void setup() 
{
    Serial.begin(9600);
    pinMode(LED,OUTPUT);
    WiFi.mode(WIFI_AP);   /* for using in station mode wite WiFi.mode(WIFI_STA), and for combine mode use WiFi.mode(WIFI_AP_STA)*/    
    WiFi.softAP(ssid, pass);
    delay(200);
    Serial.println(WiFi.softAPIP());  //to get the ip address of your esp module mostly it is 192.1684.1 in AP mode
    server.begin();
}

void loop() 
{
  while(!client.connected())
  {
    client=server.available();
  }

  if (client.connected())
  {
    digitalWrite(LED,HIGH); 
  }
 delay(1000);
   if (!client.connected())
  {
    digitalWrite(LED,LOW); 
  }
 delay(1000);
 
}
