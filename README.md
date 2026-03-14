# Smart Parking System 

Ein intelligentes Parkplatz-Managementsystem, entwickelt im Rahmen des Laborunterrichts.

## 📋 Projektübersicht
Das Ziel dieses Projekts ist die Entwicklung eines automatisierten Parksystems. Das System erkennt mittels Ultraschallsensoren, ob ein Parkplatz frei oder belegt ist, und visualisiert diesen Status für den Nutzer. Zusätzlich verfügt das System über eine schrankengesteuerte Zufahrt.

## 📝 Vorbereitung
Als erstes haben wir uns gedanken gemacht wie wir am besten ein Parksystem mit gewissen Bauteilen zusammenstellen.
Der nächste Schritt war , dass wir uns einen geigneten Schaltplan in Thinkercad erstellen der alle hindernisse berücksichtigt (ohne LCD Screen).





>Main Arduino:
<img width="1576" height="864" alt="image" src="https://github.com/user-attachments/assets/642e67a2-ee7e-4ed2-b679-6c8b75d4a868" />



>Screen Arduino:
<img width="1463" height="948" alt="image" src="https://github.com/user-attachments/assets/417293d4-87ad-4548-91ad-e445f22b9b19" />


## 🧠 Gedanke 
Zwei Sensoren die die "Parkplätze" überwachen ob sie belegt sind, wenn beide belegt sind dann kann man mit dem butten die "Schranke" (Servo) nicht aufmachen.
Auf einem LCD Screen wird angezeigt wie viele Parklätze belegt sind.
Außerdem wollen wir noch eine WebApp machen wo man sieht wie viele Parkplätze belegt sind.


## 🛠 Hardware-Architektur
Das System basiert auf folgenden Komponenten:
* **Ultrasonic Distance Sensoren**: Zur Überprüfung der Parkplatzbelegung.
* **Servo**: Steuert die Bewegung der Schranke.
* **Butten-Eingabe**: Ein kleiner Knop der die Schranke öffnet wenn gedrückt.



## 🚀 Entwicklung & Problemlösung

### Schaltplan
Die initiale Planung und der Schaltplan wurden in Tinkercad erstellt.

### Herausforderungen & Lösungen
Während der Entwicklung traten folgende Probleme auf:

* **Servo-Fehlfunktion**: Der Bewegungsmelder versetzte den Servo in eine fehlerhafte Dauerschleife mit langsamer Bewegung.
    * *Lösung*: Austausch des Bewegungsmelders gegen einen Butten.
* **Display-Fehler**: Das angeschlossene Display zeigte fehlerhafte Zeichen an.
    * *Lösung 1*: Austausch des Codes (funktionierte nur temporär).
    * *Lösung 2*: Prüfung der Verkabelung (lockere Kabel verursachten Datenfehler).
* **Verbindung**: beider Arduinos: Wie verbindet man zwei Arduinos?
     * *Lösung*: Zwei kabel bei den Analog pins die bei dem jeweiligen Arduino angeschlossen sind und daten austauschen.


## 👥 Team
* Schneider
* Massong
* Schleef


