# Labyrinth (C, Konsole)

Kleines Konsolenspiel in C. Ein zufälliges Labyrinth wird erzeugt; der Spieler **P** bewegt sich mit **W/A/S/D** zum Schatz **T**. **Q** beendet.

## Build & Run
```bash
make
./labyrinth                    # Standard 10x10, ~15% Hindernisse
./labyrinth 12 12 0.2         # Beispiel mit Parametern (rows cols ratio)
make test                     # Autotest -> "OK"
```

## Dokumentation

- **Doku & Management-Summary (Startseite):** [docs/README.md](./docs/README.md)

