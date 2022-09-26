#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
  
//----------- Enter your Wi-Fi and password details---------//
char ssid[] = ""; //SSID
char pass[] = ""; // Password
//---------------------------------------------------------//

const int trigger = 16;
const int echo = 5;
long T;
float amountOfEmptySpace;
WiFiClient  client;

unsigned long myChannelField = 898169;                 // Channel ID
const int ChannelField = 1;                            // Write data to channel 1
const char * myWriteAPIKey = "BOQS5HJNR3W0BYKI";       // enter write API Key

void setup()
{
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin("","");                                //include your "ssid","password"
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  amountOfEmptySpace = T * 0.034;
  amountOfEmptySpace = amountOfEmptySpace / 2;
  Serial.print("Trash filled in cm: ");
  Serial.println(amountOfEmptySpace);
  ThingSpeak.writeField(myChannelField, ChannelField, amountOfEmptySpace, myWriteAPIKey);
  delay(1000);
}
