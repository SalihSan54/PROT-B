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

**Kurz-Erklärung:** `main.c` spricht über `labyrinth.h` mit `labyrinth.c`. Tests hängen am Header → saubere Modularisierung.

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

**Kurz-Erklärung:** `Game` kapselt den Spielzustand, `Pos` beschreibt Koordinaten; `grid` ist die 2D-Matrix (rows×cols).

---

## 3) Spielzug – Ablauf

```mermaid
flowchart TD
  A[Start: Eingabe lesen (W/A/S/D oder Q)] -->|Q| Z[Beenden]
  A --> B{Eingabe gültig?}
  B -- nein --> M[Hinweis] --> A
  B -- ja --> C[Zielposition berechnen]
  C --> D{Innerhalb Feld?}
  D -- nein --> M2[Ignorieren] --> A
  D -- ja --> E{Zelle am Ziel?}
  E -- Hindernis 'O' --> M3[Blockiert] --> A
  E -- Schatz 'T' --> F[Spieler = Ziel setzen]
  E -- Leere '.' --> F
  F --> G[Züge++ & Grid aktualisieren]
  G --> H{Schatz gefunden?}
  H -- ja --> I[Siegmeldung → Ende]
  H -- nein --> J[Spielfeld ausgeben] --> A
  Z((Ende))
```

**Kurz-Erklärung:** Eingabe prüfen → bewegen/kollisionscheck → gewinnen oder weiterlaufen → Spielfeld neu ausgeben.

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

**Kurz-Erklärung:** Explizite Zustände dokumentieren Lebenszyklus (Start, Laufen, Gewinn, Ende).

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

**Kurz-Erklärung:** `ratio` steuert Hindernisdichte; Spieler/Schatz werden platziert; danach Zustand **Running**.

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

**Hinweis:** Sollte ein Diagramm auf GitHub nicht sofort erscheinen, die Seite kurz neu laden.
