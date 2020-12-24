#include <NewPing.h>
#include "DHT.h"

int vib = 7;

int trig = 6;
int echo = 5;
int max_dist = 1000;
NewPing sonar(trig, echo, max_dist);

int pir = 4;
int pir_val = 0;
int pir_state = LOW;

int dht_pin = 3;
#define DHTTYPE DHT11
DHT dht(dht_pin, DHTTYPE);

int sound = 2;
void setup() {
  pinMode(vib, INPUT);
  pinMode(pir, INPUT);
  pinMode(sound, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  //Serial.print("Ping: ");
  Serial.println(sonar.ping_cm());
  //Serial.println("cm");
  delay(50);
  
  int val;
  val = digitalRead(vib);
  //Serial.print("vibraction: ");
  Serial.println(val);
  delay(200);
 
  pir_val = digitalRead(pir);
  //Serial.print("motion: ");
  Serial.println(pir_val);

  int t = (int)dht.readTemperature();
  //Serial.print("temp: ");
  Serial.println(t);

  //Serial.print("sound: ");
  Serial.println(digitalRead(sound));
  delay(250);
}
