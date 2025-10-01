# Management Summary – Praxisarbeit Programmiertechnik (C)

Dieses Projekt implementiert ein kleines, textbasiertes **Labyrinth-Spiel** in C. Der Spieler (`P`) bewegt sich mit **W/A/S/D** zum Schatz (`T`). Hindernisse (`O`) blockieren den Weg. Ziel war es, zentrale Inhalte der Programmiertechnik praxisnah umzusetzen (Datenstrukturen, Algorithmik, Speicherverwaltung, Modularisierung, Build & Test, Doku).

---

## Vorgehen & Qualitätssicherung
- **Vorgehen:** Zuerst **Datenmodell & Schnittstellen** im Header definiert, dann Funktionen iterativ implementiert und über die Konsole getestet. Randfälle (Wand/Randkollision, Beenden) wurden früh überprüft.
- **Spezifisch & Robustheit:** Alle dynamischen Speicherbereiche werden freigegeben (`maze_free`); Eingaben werden validiert; Out-of-Bounds-Bewegungen verhindert.
- **Build & Tests:** Ein **Makefile** automatisiert Build/Run/Autotest. `make test` verifiziert elementare Bewegungen/Kollision → Ausgabe **“…OK”**. Zusätzlich manuelle Tests (siehe Testplan).
- **Dokumentation:** README (Build/Run), **Diagramme** (Mermaid) zur Architektur und Abläufen, Management-Summary für Entscheider.

**Screenshots / Artefakte:** siehe `docs/diagramme.md` und `docs/tests/testplan.md`.

---

## Praxistauglichkeit & Nutzen
- **Einfach reproduzierbar:** `make` → `./labyrinth 12 12 0.2`
- **Wartbar & erweiterbar:** Klare Trennung von Schnittstellen (Header) und Implementierung; modulare Struktur.
- **Vorlage für Übungen:** Eignet sich als Übungs-/Prüfungsvorlage (z. B. weitere Regeln, Punktezähler, mehrere Level).

---

## Grenzen & Risiken
- Das Spiel ist bewusst **textbasiert** (keine GUI, einfache Darstellung).  
- Bei sehr hoher Hindernisdichte kann ein Pfad **unwahrscheinlicher** werden → Standardwerte moderat wählen (z. B. Ratio ~0.15–0.2).
- Direkte Tastenabfrage ohne Enter wurde zugunsten der Portabilität nicht umgesetzt.

---

## Nächste Schritte (Roadmap)
- Mehrere Schätze / Level und **Punkte-Zähler**  
- **Respawn** eines neuen Schatzes statt sofortigem Spielende  
- Farbliche Hervorhebung, High-Score  
- Optional: Seed-Parameter für reproduzierbare Layouts

---

## Diagramme (Überblick)
Die Diagramme erklären Aufbau und Ablauf. **Alle Diagramme** befinden sich gesammelt in:  
**[`docs/diagramme.md`](./diagramme.md)**

**Abbildungen:**
1. **Modul-Überblick (Dateien & Abhängigkeiten)** – zeigt `main.c`, API (`labyrinth.h`), Implementierung (`labyrinth.c`) und `tests/`.
2. **Datenmodell (C-Structs)** – `Game` (Grid, Parameter, Positionen) und `Pos` (r/c).
3. **Ablauf eines Spielzugs** – Eingabe → Bewegung → Kollision/Blockade → Gewinn/Weiter.
4. **Spielzustände (State Machine)** – `Init → Running → Win/Exit`.
5. **Kartenerzeugung (Map/Seed/Hindernisse)** – Parameter → Hindernisse → Platzierung P/T.
6. **Sequenz – Ein Zug (optional)** – zeitliche Reihenfolge: Input → Berechnung → Ausgabe.

> **Hinweis:** Unter GitHub werden die Mermaid-Diagramme automatisch gerendert. In VS Code (Codespaces) ggf. die Markdown-Vorschau öffnen.

---

## Kurz­anleitung
```bash
make
./labyrinth            # Standard: 10x10, ~15% Hindernisse

# Beispiel mit Parametern (rows cols ratio):
./labyrinth 12 12 0.2

make test              # Autotest -> "OK"
