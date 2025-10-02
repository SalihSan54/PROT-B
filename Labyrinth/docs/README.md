# Dokumentation – Labyrinth (C)

## Management Summary

- **Summary als Markdown (Browser/GitHub):**  
  [Management Summary auf GitHub](https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/management-summary.md)

- **Summary lokal im Repo:**  
  [management-summary.md](./management-summary.md)

---

## Hinweis
- In **VS Code Codespaces** lassen sich PDFs im Editor nicht direkt anzeigen.  
- Deshalb ist die **Markdown-Version** die aktuelle und gültige Fassung.  

---

## Kurz-Anleitung (Build & Run)

```bash
make
./labyrinth          # Standard: 10x10, ~15% Hindernisse

# Beispiel mit Parametern (Zeilen, Spalten, Hindernis-Quote):
./labyrinth 12 12 0.2

make test            # Autotest -> "OK"
