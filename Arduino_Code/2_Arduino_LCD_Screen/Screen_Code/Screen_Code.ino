#include <LiquidCrystal.h>
#include <Wire.h>
 
// Damit der Arduino weiß an welchen pins der LCD Diplay angeschlossen ist
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
// "volatile" bedeutet: Diese Variable kann sich jederzeit durch ein Signal 
// von außen ändern, deshalb muss der Arduino besonders auf sie achten.
volatile int plaetzeFrei = 2;
 
void setup() {
  // 1. I2C-Verbindung als Empfänger starten (Adresse 8)
  Wire.begin(8); 
  // Sagt dem Arduino: "Wenn Daten kommen soll er  receiveEvent ausführen
  Wire.onReceive(receiveEvent);

  // 2. Kurz warten, damit der Diplay gut startet
  delay(1000); 

  // 3. Display starten
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Parksystem");
  delay(1000);
  lcd.clear();
}

    
 
void loop() {
  // In der ersten Zeile den Titel anzeigen
  lcd.setCursor(0, 0);
  lcd.print("Parkhaus Status");

  // In der zweiten Zeile die Anzahl der Parkülätze
  lcd.setCursor(0, 1);
  lcd.print("Frei: ");
  lcd.print(plaetzeFrei);
  lcd.print(" Plaetze "); 
 
  // Wenn das Parkhaus voll ist, zeigt er Voll an
  if (plaetzeFrei == 0) {
    lcd.setCursor(12, 1);
    lcd.print("VOLL");
  } else {
    lcd.setCursor(12, 1);
    lcd.print("    "); // Schreibt Leerzeichen, um VOLL zu löschen
  }

  //  Pause damit die Anzeige nicht zu schnell flackert
  delay(200); 
}
 
// Diese Funktion wird automatisch aufgerufen, sobald der andere Arduino Daten schickt
void receiveEvent(int howMany) {
  // Wenn Daten da sind, lesen wir den Wert aus und speichern ihn in plaetzeFrei
  if (Wire.available()) {
    plaetzeFrei = Wire.read(); 
  }
}