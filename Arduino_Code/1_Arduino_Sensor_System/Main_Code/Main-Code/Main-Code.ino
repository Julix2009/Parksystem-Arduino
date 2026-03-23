#include <Servo.h>
#include <Wire.h>

const int trig1 = 2;
const int trig2 = 3;
const int echo1 = 4;
const int echo2 = 5;
const int buttonPin = 7;
const int servoPin = 6;

Servo meineSchranke;
const int distanzSchwelle = 10;

// Nicht-blockierende Schrankensteuerung
unsigned long schrankeOffen = 0;
bool schrankeAktiv = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(trig1, OUTPUT); pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT); pinMode(echo2, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  meineSchranke.attach(servoPin);
  meineSchranke.write(0);
}

void loop() {
  long d1 = getDistance(trig1, echo1);
  long d2 = getDistance(trig2, echo2);

  bool p1frei = (d1 >= distanzSchwelle);
  bool p2frei = (d2 >= distanzSchwelle);
  int frei = (p1frei ? 1 : 0) + (p2frei ? 1 : 0);

  // Sende Daten an Webinterface über Serial
  Serial.print("P1:");
  Serial.print(p1frei ? "FREI" : "BELEGT");
  Serial.print(",P2:");
  Serial.print(p2frei ? "FREI" : "BELEGT");
  Serial.print(",FREI:");
  Serial.println(frei);

  // Daten an zweiten Arduino senden (Display)
  Wire.beginTransmission(8);
  Wire.write(frei);
  Wire.endTransmission();

  // Schranke öffnen (nicht-blockierend)
  if (!schrankeAktiv && digitalRead(buttonPin) == LOW && frei > 0) {
    meineSchranke.write(90);
    schrankeOffen = millis();
    schrankeAktiv = true;
  }

  // Schranke nach 3 Sekunden schließen
  if (schrankeAktiv && millis() - schrankeOffen >= 3000) {
    meineSchranke.write(0);
    schrankeAktiv = false;
  }

  delay(500);
}

long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long dauer = pulseIn(echo, HIGH, 30000);
  if (dauer == 0) return 999;
  return dauer * 0.034 / 2;
}