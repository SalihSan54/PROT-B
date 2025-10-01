# Labyrinth (C, Konsole)

Ein kleines Konsolenspiel:  
Es wird ein zufälliges Labyrinth erzeugt.  
Der Spieler **P** bewegt sich mit **W/A/S/D** durch das Spielfeld, um den Schatz **T** zu erreichen.  
Beenden mit **Q**.  

👉 Ausführliche Dokumentation mit Management-Summary und Diagrammen findest du hier: [docs/README.md](./docs/README.md)

---

## Build & Run

```bash
# Kompilieren
make

# Standard: 10x10, ca. 15% Hindernisse
./labyrinth

# Beispiel mit Parametern: (rows cols ratio)
./labyrinth 12 12 0.2

# Tests ausführen
make test
