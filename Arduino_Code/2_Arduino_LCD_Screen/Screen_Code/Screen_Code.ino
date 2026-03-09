#include <LiquidCrystal.h>

#include <Wire.h>
 
// Pins: RS=12, E=11, D4=5, D5=4, D6=3, D7=2

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
// volatile ist wichtig für Variablen, die in receiveEvent geändert werden

volatile int plaetzeFrei = 2;
 
void setup() {

  // 1. I2C starten

  Wire.begin(8); 

  Wire.onReceive(receiveEvent);

  // 2. Dem System Zeit geben zum "Wachwerden" (verhindert Zeichensalat)

  delay(1000); 

  // 3. LCD initialisieren

  lcd.begin(16, 2);

  lcd.clear();

  lcd.print("System bereit");

  delay(1000);

  lcd.clear();

}
 
void loop() {

  // Anzeige aktualisieren

  lcd.setCursor(0, 0);

  lcd.print("Parkhaus Status");

  lcd.setCursor(0, 1);

  lcd.print("Frei: ");

  lcd.print(plaetzeFrei);

  lcd.print(" Plätze "); // Leerzeichen am Ende löschen alte Reste
 
  // Sonderanzeige wenn voll

  if (plaetzeFrei == 0) {

    lcd.setCursor(12, 1);

    lcd.print("VOLL");

  } else {

    lcd.setCursor(12, 1);

    lcd.print("    "); // Löscht das Wort "VOLL"

  }

  delay(200); 

}
 
// Diese Funktion wird aufgerufen, wenn der andere Arduino sendet

void receiveEvent(int howMany) {

  if (Wire.available()) {

    plaetzeFrei = Wire.read(); 

  }

}
 