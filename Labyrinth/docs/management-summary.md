# Management Summary – Praxisarbeit Programmiertechnik (C)

Dieses Projekt implementiert ein kleines, textbasiertes **Labyrinth-Spiel** in C. 
Der Spieler (`P`) bewegt sich mit **W/A/S/D** zum Schatz (`T`). Hindernisse (`O`) blockieren den Weg. 
Ziel war es, zentrale Inhalte der Programmiertechnik praxisnah umzusetzen (Datenstrukturen, Algorithmik, Modularisierung, Build & Test, Dokumentation).

---

## Vorgehen & Qualitätssicherung
- **Datenmodell & Schnittstellen:** im Header definiert, modulare Struktur, klare Trennung von Spiellogik, Eingabe, Spielfeld und Renderer.  
- **Robustheit:** Eingaben validiert, Kollisionen mit Wänden/Hindernissen korrekt behandelt.  
- **Tests:** `make test` prüft Bewegungen, Eingaben und Spiellogik automatisch.  
- **Dokumentation:** Diagramme und Beschreibung der einzelnen Module.  

---

## Praxistauglichkeit & Nutzen
- **Einfach reproduzierbar:** Kompilierbar mit `make`, Start über `./labyrinth`.  
- **Wartbar & erweiterbar:** modulare Aufteilung, klare Schnittstellen.  
- **Didaktischer Nutzen:** eignet sich als Vorlage für Übungen (z. B. Erweiterung mit mehreren Leveln oder Punktezähler).  

---

## Grenzen & Risiken
- Spiel ist bewusst **textbasiert** (keine GUI).  
- Bei sehr vielen Hindernissen kann das Spielfeld für Spieler unübersichtlich wirken.  
- Erweiterte Features (Punktesystem, mehrere Level) sind noch nicht umgesetzt.  

---

## Diagramme (Überblick)
Die Diagramme helfen, Aufbau und Abläufe des Programms verständlich darzustellen.  
👉 [Zu den Diagrammen (lokal)](./diagramme.md)  
👉 [Zu den Diagrammen (GitHub)](https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/diagramme.md)


---

## Nächste Schritte (Roadmap)
- Einführung von Schwierigkeitsstufen und Punktezähler.  
- Entwicklung einer grafischen Benutzeroberfläche.  
- Erweiterte Tests zur Verbesserung von Stabilität und Robustheit.  

---

## Fazit
Das Projektziel – ein funktionierendes Konsolenspiel mit klarer Spiellogik, zuverlässiger Eingabeverarbeitung und verständlicher Dokumentation – wurde erreicht.  
Die Arbeit zeigt, dass sich mit **systematischem Vorgehen**, **Einsatz von Diagrammen** und **schrittweiser Umsetzung** ein vollständiges Programm entwickeln lässt, das sowohl technisch korrekt als auch nachvollziehbar dokumentiert ist.
