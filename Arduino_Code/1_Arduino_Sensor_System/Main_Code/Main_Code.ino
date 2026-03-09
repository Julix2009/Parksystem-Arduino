#include <Servo.h>
#include <Wire.h>
 
const int trig1 = 2; 
const int trig2 = 3; 

const int echo1 = 4;
const int echo2 = 5;

const int buttonPin = 7;
const int servoPin = 6;
 
Servo meineSchranke;
const int distanzSchwelle = 20;
 
void setup() {
  Wire.begin(); // Als Master starten
  pinMode(trig1, OUTPUT); pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT); pinMode(echo2, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
 
  meineSchranke.attach(servoPin);
  meineSchranke.write(0);
}
 
void loop() {
  // Distanzen messen
  long d1 = getDistance(trig1, echo1);
  long d2 = getDistance(trig2, echo2);
 
  // Freie Plätze berechnen
  int frei = 0;
  if (d1 >= distanzSchwelle) frei++;
  if (d2 >= distanzSchwelle) frei++;
 
  // Daten an anderen Arduino senden für Display
  Wire.beginTransmission(8);
  Wire.write(frei); 
  Wire.endTransmission();
 
  // Schranke (Servo)
  if (digitalRead(buttonPin) == LOW && frei > 0) {
    meineSchranke.write(90);
    delay(3000); // damit die Schranke wieder zu geht
    meineSchranke.write(0);
  }
 
  delay(500); // Damit das prgramm nicht abstürzt
}
 
long getDistance(int trig, int echo) { // für die zwei Sensoren 
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long dauer = pulseIn(echo, HIGH, 30000);
  if (dauer == 0) return 999;
  return dauer * 0.034 / 2;
}