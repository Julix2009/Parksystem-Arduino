# Smart Parking System 🚗

Ein intelligentes Parkplatz-Managementsystem, entwickelt im Rahmen des Laborunterrichts der Klasse 2IT.

## 📋 Projektübersicht
Das Ziel dieses Projekts ist die Entwicklung eines automatisierten Parksystems. Das System erkennt mittels Ultraschallsensoren, ob ein Parkplatz frei oder belegt ist, und visualisiert diesen Status für den Nutzer. Zusätzlich verfügt das System über eine schrankengesteuerte Zufahrt.

## 🛠 Hardware-Architektur
Das System basiert auf folgenden Komponenten:
* **Ultrasonic Distance Sensoren**: Zur Überprüfung der Parkplatzbelegung.
* **LEDs**: Zur Signalisierung der Belegung (Rot = belegt, Grün = frei).
* **Servo**: Steuert die Bewegung der Schranke.
* **Sensor-Eingabe**: Ein Wasserstandssensor, welcher als Touchpad zur Schrankenöffnung fungiert.



[Image of Arduino ultrasonic sensor circuit diagram]


## 🚀 Entwicklung & Problemlösung

### Schaltplan
Die initiale Planung und der Schaltplan wurden in Tinkercad erstellt.

### Herausforderungen & Lösungen
Während der Entwicklung traten folgende Probleme auf:

* **Servo-Fehlfunktion**: Der Bewegungsmelder versetzte den Servo in eine fehlerhafte Dauerschleife mit langsamer Bewegung.
    * *Lösung*: Austausch des Bewegungsmelders gegen einen Wasserstandssensor, der nun als Touch-Schnittstelle dient.
* **Display-Fehler**: Das angeschlossene Display zeigte fehlerhafte Zeichen an.
    * *Lösung 1*: Austausch des Codes (funktionierte nur temporär).
    * *Lösung 2*: Prüfung der Verkabelung (lockere Kabel verursachten Datenfehler).



[Image of Arduino LCD wiring schematic]


---
*Referenz-Konzeptbild: [Smart Parking Diagram](https://letsmakeprojects.com/wp-content/uploads/2024/05/smart-parking-1024x590.jpg)*

## 👥 Team
* Schneider
* Massong
* Schleef

*Labor-Datum: 2.03.2026*
