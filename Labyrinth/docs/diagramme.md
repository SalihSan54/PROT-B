# Diagramme – Labyrinth (C)

Die folgenden Mermaid-Diagramme dokumentieren Aufbau und Ablauf des Projekts.  
GitHub rendert diese Diagramme automatisch in der Dateiansicht.

---

## 1) Modul-Überblick (Dateien & Abhängigkeiten)

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

**Abb. 1 – Modul-Überblick:** `main.c` spricht über `labyrinth.h` mit `labyrinth.c`; Tests hängen an der API; Nutzung von `stdlib.h/stdio.h/rand()`.

---

## 2) Datenmodell (C-Structs)

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

**Abb. 2 – Datenmodell:** `Game` kapselt den gesamten Spielzustand (`rows/cols/ratio/moves/grid/player/treasure`); `Pos` beschreibt Koordinaten.

---

## 3) Spielzug – Ablauf

```mermaid
flowchart TD
  A([Taste lesen (W/A/S/D/Q)]) -->|Q gedrückt| Z((Ende))
  A --> B{Eingabe gültig?}
  B -- Nein --> H[Hinweis anzeigen]
  H --> A
  B -- Ja --> C[Zielposition berechnen]
  C --> D{Innerhalb des Feldes?}
  D -- Nein --> A
  D -- Ja --> E{Zielzelle: Inhalt}
  E -- Hindernis O --> A
  E -- Schatz T --> I([Siegmeldung])
  I --> Z
  E -- Leer --> F[Spieler auf Ziel setzen]
  F --> G[Zuege++ und Grid aktualisieren]
  G --> J{Schatz gefunden?}
  J -- Ja --> I
  J -- Nein --> A
```

**Abb. 3 – Spielzug:** Eingabe prüfen → Zielposition berechnen → Kollision/Hindernis prüfen → Position/Zähler aktualisieren → Siegen oder weiterzeichnen.

---

## 4) Spielzustände – State Machine

```mermaid
stateDiagram-v2
  [*] --> Init
  Init --> Generate : rows/cols/ratio
  Generate --> Running : Grid erstellt & P/T/O gesetzt
  Running --> Won : Spieler erreicht Schatz
  Running --> Ended : 'Q' gedrückt
  Won --> Ended : Meldung
  Ended --> [*]
```

**Abb. 4 – Zustände:** Vom Start (`Init/Generate`) in `Running`; Ende bei `Won` (Schatz) oder `Ended` (Quit).

---

## 5) Kartenerzeugung – Ablauf

```mermaid
flowchart TD
  S[Start] --> A[Grid rows×cols = '.']
  A --> B[Spieler zufällig 'P']
  B --> C[Schatz zufällig 'T' (≠ P)]
  C --> D{ratio > 0?}
  D -- nein --> F[Grid zurückgeben]
  D -- ja --> E[≈ratio Zellen zu 'O']
  E --> F[Grid zurückgeben]
  F --> G[Status = Running]
  G --> H[Ende]
```

**Abb. 5 – Kartenerzeugung:** Grid füllen, `P`/`T` platzieren, je nach `ratio` Hindernisse `O` setzen; danach Status `Running`.

---

## 6) (Optional) Sequenz – Ein Zug

```mermaid
sequenceDiagram
  participant U as User
  participant I as Input
  participant G as Game
  participant R as Renderer

  U->>I: Taste (W/A/S/D/Q)
  I->>G: normalisierte Eingabe
  alt gültig & frei
    G->>G: Position berechnen
    G->>G: Grid + Zähler aktualisieren
  else blockiert/ungültig
    G->>U: Hinweis
  end
  G->>R: aktuelles Grid
  R-->>U: Spielfeld anzeigen
```

**Abb. 6 – Sequenz (optional):** Interaktion von Nutzer, Eingabe, Spiel-Logik und Rendering in einem Zug.

---
