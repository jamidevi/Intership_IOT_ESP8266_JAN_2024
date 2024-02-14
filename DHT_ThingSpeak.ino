#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <DHT.h>
#include "ThingSpeak.h"

char* ssid = "Devi";
char* passphrase = "crabdish2013";

WiFiServer server(80);
WiFiClient client;

unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "DJIVERI3LLBMUYCS";

unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

#define DHTPIN D5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, passphrase);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  ThingSpeak.begin(client);
}

void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    delay(2500);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    if (isnan(h) || isnan(t))
    {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    Serial.print("Temperature (ºC): ");
    Serial.print(t);
    Serial.println("ºC");
    Serial.print("Humidity: ");
    Serial.println(h);

    ThingSpeak.setField(1, h);
    ThingSpeak.setField(2, t);
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    if (x == 200)
    {
      Serial.println("Channel update successful.");
    }
    else
    {
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}
