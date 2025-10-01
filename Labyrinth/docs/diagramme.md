## Modul-Überblick (Dateien & Abhängigkeiten)
```mermaid
flowchart LR
  subgraph Projekt
    main["main.c"] --> api["labyrinth.h (API)"]
    api --> impl["labyrinth.c (Implementierung)"]
    tests["tests/ (Autotests)"] --> api
    impl --> std["stdlib.h, stdio.h, rand()"]
    main --> io["stdio.h / I/O"]
  end

  classDef file fill:#eef6ff,stroke:#1e66f5,stroke-width:1px,color:#0b2b6b;
  classDef sys  fill:#fff4e6,stroke:#e8590c,color:#5f3c00;

  class main,api,impl,tests file;
  class std,io sys;
```
**Abb. 1 – Modul-Überblick:** `main.c` spricht via `labyrinth.h` mit `labyrinth.c`; Tests hängen an der API; Nutzung von `stdlib.h/stdio.h/rand()`.

---

## Datenmodell (C-Structs)
```mermaid
classDiagram
  class Pos { +int r; +int c }
  class Game {
    +int rows
    +int cols
    +float ratio
    +int moves
    +char** grid
    +Pos player
    +Pos treasure
  }
  Game "1" o-- "1" Pos : player
  Game "1" o-- "1" Pos : treasure
```
**Abb. 2 – Datenmodell:** `Game` kapselt den Spielzustand (`rows/cols/ratio/moves/grid/player/treasure`); `Pos` beschreibt Koordinaten.

---

## Spielzug – Ablauf
```mermaid
flowchart TD
  A["Start: Eingabe lesen (W/A/S/D oder Q)"] -->|Q| Z["Ende"]
  A --> B{"Eingabe gueltig?"}

  B -- "nein" --> M["Hinweis"]
  M --> A

  B -- "ja" --> C["Zielposition berechnen"]
  C --> D{"Innerhalb Feld?"}

  D -- "nein" --> M2["Ignorieren"]
  M2 --> A

  D -- "ja" --> E{"Zelle am Ziel?"}

  E -- "Hindernis O" --> M3["Blockiert"]
  M3 --> A

  E -- "Schatz T" --> F["Spieler = Ziel setzen"]
  E -- "Leere Punkt" --> F

  F --> G["Zuege++ und Grid aktualisieren"]
  G --> H{"Schatz gefunden?"}

  H -- "ja" --> I["Siegmeldung und Ende"]
  H -- "nein" --> J["Spielfeld ausgeben"]
  J --> A
```
**Abb. 3 – Spielzug:** Eingabe pruefen → Zielposition berechnen → Kollision/Hindernis pruefen → Position/Zaehler aktualisieren → Siegen oder weiterzeichnen.

---

## Spielzustände – State Machine
```mermaid
stateDiagram-v2
  [*] --> Init
  Init --> Generate : rows/cols/ratio
  Generate --> Running : Grid erstellt und P/T/O gesetzt
  Running --> Won : Spieler erreicht Schatz
  Running --> Ended : Q gedrueckt
  Won --> Ended : Meldung
  Ended --> [*]
```
**Abb. 4 – Zustände:** Vom Start (`Init/Generate`) in `Running`; Ende bei `Won` (Schatz) oder `Ended` (Quit).

---

## Kartenerzeugung – Ablauf
```mermaid
flowchart TD
  S["Start"] --> A["Grid rows x cols = '.'"]
  A --> B["Spieler zufaellig P"]
  B --> C["Schatz zufaellig T (P != T)"]
  C --> D{"ratio > 0"}
  D -- "nein" --> F["Grid zurueckgeben"]
  D -- "ja" --> E["Anteil (ratio) Zellen zu O"]
  E --> F
  F --> G["Status = Running"]
  G --> H["Ende"]
```
**Abb. 5 – Kartenerzeugung:** Grid fuellen, `P`/`T` platzieren, je nach `ratio` Hindernisse `O` setzen; danach Status `Running`.

---

## (Optional) Sequenz – Ein Zug
```mermaid
sequenceDiagram
  participant U as User
  participant I as Input
  participant G as Game
  participant R as Renderer

  U->>I: Taste (W/A/S/D/Q)
  I->>G: normalisierte Eingabe
  alt gueltig und frei
    G->>G: Position berechnen
    G->>G: Grid und Zaehler aktualisieren
  else blockiert/ungueltig
    G->>U: Hinweis
  end
  G->>R: aktuelles Grid
  R-->>U: Spielfeld anzeigen
```
**Abb. 6 – Sequenz (optional):** Interaktion von Nutzer, Eingabe, Spiel-Logik und Rendering in einem Zug.
