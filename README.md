# Smart Parking System 🚗

[cite_start]Ein intelligentes Parkplatz-Managementsystem, entwickelt im Rahmen des Laborunterrichts der Klasse 2IT[cite: 1].

## 📋 Projektübersicht
[cite_start]Das Ziel dieses Projekts ist die Entwicklung eines automatisierten Parksystems[cite: 1]. [cite_start]Das System erkennt mittels Ultraschallsensoren, ob ein Parkplatz frei oder belegt ist, und visualisiert diesen Status für den Nutzer[cite: 1, 2]. [cite_start]Zusätzlich verfügt das System über eine schrankengesteuerte Zufahrt[cite: 3].

## 🛠 Hardware-Architektur
Das System basiert auf folgenden Komponenten:
* [cite_start]**Ultrasonic Distance Sensoren**: Zur Überprüfung der Parkplatzbelegung[cite: 1].
* [cite_start]**LEDs**: Zur Signalisierung der Belegung (Rot = belegt, Grün = frei)[cite: 2].
* [cite_start]**Servo**: Steuert die Bewegung der Schranke[cite: 3].
* [cite_start]**Sensor-Eingabe**: Ein Wasserstandssensor, welcher als Touchpad zur Schrankenöffnung fungiert[cite: 7, 8].



## 🚀 Entwicklung & Problemlösung

### Schaltplan
[cite_start]Die initiale Planung und der Schaltplan wurden in **Tinkercad** erstellt[cite: 4].

### Herausforderungen & Lösungen
Während der Entwicklung traten folgende Probleme auf:

* [cite_start]**Servo-Fehlfunktion**: Der Bewegungsmelder versetzte den Servo in eine fehlerhafte Dauerschleife mit langsamer Bewegung[cite: 5, 6].
    * [cite_start]*Lösung*: Austausch des Bewegungsmelders gegen einen Wasserstandssensor, der nun als Touch-Schnittstelle dient[cite: 7, 8].
* [cite_start]**Display-Fehler**: Das angeschlossene Display zeigte fehlerhafte Zeichen an[cite: 9].
    * [cite_start]*Lösung 1*: Austausch des Codes (funktionierte nur temporär)[cite: 9].
    * [cite_start]*Lösung 2*: Prüfung der Verkabelung (lockere Kabel verursachten Datenfehler)[cite: 9].



---
[cite_start]*Referenz-Konzeptbild: [Smart Parking Diagram](https://letsmakeprojects.com/wp-content/uploads/2024/05/smart-parking-1024x590.jpg) [cite: 4]*

## 👥 Team
* Schneider
* Massong
* Schleef

[cite_start]*Labor-Datum: 2.03.2026 [cite: 1]*
