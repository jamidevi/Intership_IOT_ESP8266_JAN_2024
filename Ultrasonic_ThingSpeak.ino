#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "ThingSpeak.h"

char* ssid = "Devi"; 
char* passphrase = "crabdish2013"; 

WiFiServer server(80);
WiFiClient client;

unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "BYBJ7ZB60291VFY3";

unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

const int trigPin = D5;
const int echoPin = D6;

#define SOUND_SPEED 0.034 
#define CM_TO_INCH 0.393701

long duration;  
float distanceCm;  
float distanceInch;  

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

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop() 
{  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); 
  distanceCm = duration * SOUND_SPEED/2; 
  distanceInch = distanceCm * CM_TO_INCH;  
  
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);  
  delay(2000);

  ThingSpeak.setField(1,distanceCm );
  ThingSpeak.setField(2,distanceInch);
  ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
}





