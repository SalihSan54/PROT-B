# Diagramme – Labyrinth (C)

Die folgenden Diagramme erklären Aufbau und Ablauf des Projekts. GitHub rendert die Mermaid-Diagramme automatisch.

---

## 1. Modul-Überblick (Dateien & Abhängigkeiten)

**Abb. 1:** Überblick über Dateien, Header und Tests.

```mermaid
flowchart LR
    subgraph Projekt
      main["main.c"] --> api["labyrinth.h"]
      api --> impl["labyrinth.c"]
      tests["tests/ (Autotests)"] --> api
      impl -->|nutzt| rand["<stdlib.h> rand()"]
      impl --> io["<stdio.h> / I/O"]
    end

    style main fill:#cfe8ff,stroke:#2a6fdb
    style api fill:#e8ffe8,stroke:#24a148
    style impl fill:#fff4cf,stroke:#a17800
    style tests fill:#ffe0e8,stroke:#c2185b
    
## 2. Datenmodell (C-Structs)

```mermaid
classDiagram
    class Game {
      +int rows
      +int cols
      +float ratio
      +int moves
      +char** grid
      +Pos player
      +Pos treasure
    }

    class Pos {
      +int r
      +int c
    }

    %% Beziehungen (Rollen als Label):
    Game "1" o-- "1" Pos : player
    Game "1" o-- "1" Pos : treasure
