#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#define ldr A0
#define led_lab D2
#define led_lcd D5
#define led_rab D6
#define led_rcd D8
#define T1 D0
#define E1 D1
#define T2 D4
#define E2 D7
int dstat1 = 1;
int dstat2 = 3;
int dstat3 = 10;
#define dstat4 D3  

const char* ssid = "SMART LIGHT"; //Your Network SSID
const char* password = "SMART LIGHT"; //Your Network Password
WiFiClient client;
unsigned long myChannelNumber1 = 966059; 
const char * myWriteAPIKey1 = "QZJTISZMC5I16Z6H"; 
unsigned long myChannelNumber2 = 966057; 
const char * myWriteAPIKey2 = "VJT4WSXPLGKV18GA"; 

long dur1,dur2;
int dis1,dis2;
int a1,a2,a3,a4,a5,a6,a7,a8;
int b1,b2,b3,b4,b5,b6,b7,b8;

void setup() 
{
pinMode(dstat1, FUNCTION_3);
pinMode(dstat2, FUNCTION_3);
pinMode(T1, OUTPUT);
pinMode(E1, INPUT);
pinMode(T2, OUTPUT);
pinMode(E2, INPUT);
pinMode(ldr, INPUT);
pinMode(led_lab,OUTPUT);
pinMode(led_lcd,OUTPUT);
pinMode(led_rab,OUTPUT);
pinMode(led_rcd,OUTPUT);
pinMode(dstat1, INPUT);
pinMode(dstat2, INPUT);
pinMode(dstat3, INPUT);
pinMode(dstat4, INPUT);
WiFi.begin(ssid, password);
ThingSpeak.begin(client);
}

void loop() 
{
/* LDR SENSOR */
int ldrval = analogRead(ldr);
/* ULTRASONIC SENSOR 1 */
digitalWrite(T1,LOW);
delayMicroseconds(2);
digitalWrite(T1, HIGH);
delayMicroseconds(10);
digitalWrite(T1, LOW);
dur1 = pulseIn(E1, HIGH);
dis1= dur1*0.034/2;
/* ULTRASONIC SENSOR 2 */
digitalWrite(T2,LOW);
delayMicroseconds(2);
digitalWrite(T2, HIGH);
delayMicroseconds(10);
digitalWrite(T2, LOW);
dur2 = pulseIn(E2, HIGH);
dis2= dur2*0.034/2;
/* LED GLOW - DAY */
if(ldrval > 512)
{
  analogWrite(led_lab,0);
  analogWrite(led_lcd,0);
  analogWrite(led_rab,0);
  analogWrite(led_rcd,0);
  a1 = 0;
  a2 = 0;
  a3 = 0;
  a4 = 0;
  a5 = 0;
  a6 = 0;
  a7 = 0;
  a8 = 0;
  b1 = 1;
  b2 = 1;
  b3 = 1;
  b4 = 1;
  b5 = 1;
  b6 = 1;
  b7 = 1;
  b8 = 1;
}
/* LED GLOW - NIGHT */
if(ldrval < 512)
{
if(dis1 < 18 && dis2 < 18)
{
  analogWrite(led_lab,1023);
  analogWrite(led_rab,1023);
  analogWrite(led_lcd,1023);
  analogWrite(led_rcd,1023);
  int dstatsensor1 = digitalRead(dstat1);
  int dstatsensor2 = digitalRead(dstat2);
  int dstatsensor3 = digitalRead(dstat3);
  int dstatsensor4 = digitalRead(dstat4);
  a1 = 1023;
  a2 = 1023;
  a3 = 1023;
  a4 = 1023;
  a5 = 1023;
  a6 = 1023;
  a7 = 1023;
  a8 = 1023;
  if (dstatsensor1 == 1)
  {
  b1 = 1;
  b2 = 1;
  }
  else
  {
  b1 = 0;
  b2 = 0;
  }
  if (dstatsensor2 == 1)
  {
  b3 = 1;
  b4 = 1;
  }
  else
  {
  b3 = 0;
  b4 = 0;
  }
  if (dstatsensor3 == 1)
  {
  b5 = 1;
  b6 = 1;
  }
  else
  {
  b5 = 0;
  b6 = 0;
  }
  if (dstatsensor4 == 1)
  {
  b7 = 1;
  b8 = 1;
  }
  else
  {
  b7 = 0;
  b8 = 0;
  }  
  }
else if(dis1 > 18 && dis2 > 18)
{
  analogWrite(led_lab,300);
  analogWrite(led_rab,300);
  analogWrite(led_lcd,300);
  analogWrite(led_rcd,300);
  a1 = 300;
  a2 = 300;
  a3 = 300;
  a4 = 300;
  a5 = 300;
  a6 = 300;
  a7 = 300;
  a8 = 300;
  b1 = 1;
  b2 = 1;
  b3 = 1;
  b4 = 1;
  b5 = 1;
  b6 = 1;
  b7 = 1;
  b8 = 1;
}
else if(dis1 < 18 && dis2 > 18)
{
  analogWrite(led_rab,300);
  analogWrite(led_rcd,300);
  analogWrite(led_lab,1023);
  delay(1000);
  analogWrite(led_lcd,1023);
  delay(1000);
  analogWrite(led_lab,300);
  delay(1000);
  analogWrite(led_lcd,300);
  a1 = 1023;
  a2 = 1023;
  a3 = 1023;
  a4 = 1023;
  a5 = 300;
  a6 = 300;
  a7 = 300;
  a8 = 300;
  b1 = 1;
  b2 = 1;
  b3 = 1;
  b4 = 1;
  b5 = 1;
  b6 = 1;
  b7 = 1;
  b8 = 1;
}
else if(dis1 > 18 && dis2 < 18)
{
  analogWrite(led_lab,300);
  analogWrite(led_lcd,300);
  analogWrite(led_rab,1023);
  delay(1000);
  analogWrite(led_rcd,1023);
  delay(1000);
  analogWrite(led_rab,300);
  delay(1000);
  analogWrite(led_rcd,300);
  a1 = 300;
  a2 = 300;
  a3 = 300;
  a4 = 300;
  a5 = 1023;
  a6 = 1023;
  a7 = 1023;
  a8 = 1023;
  b1 = 1;
  b2 = 1;
  b3 = 1;
  b4 = 1;
  b5 = 1;
  b6 = 1;
  b7 = 1;
  b8 = 1;
}
}
ThingSpeak.setField(1, a1);
ThingSpeak.setField(2, a2);
ThingSpeak.setField(3, a3);
ThingSpeak.setField(4, a4);
ThingSpeak.setField(5, a5);
ThingSpeak.setField(6, a6);
ThingSpeak.setField(7, a7);
ThingSpeak.setField(8, a8);
ThingSpeak.writeFields(myChannelNumber1,myWriteAPIKey1);
ThingSpeak.setField(1, b1);
ThingSpeak.setField(2, b2);
ThingSpeak.setField(3, b3);
ThingSpeak.setField(4, b4);
ThingSpeak.setField(5, b5);
ThingSpeak.setField(6, b6);
ThingSpeak.setField(7, b7);
ThingSpeak.setField(8, b8);
ThingSpeak.writeFields(myChannelNumber2,myWriteAPIKey2);
}
