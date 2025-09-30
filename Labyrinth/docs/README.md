# Dokumentation – Labyrinth (C)

## Management Summary

- **PDF (Browser/GitHub):**  
  https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/management-summary.pdf

- **PDF (Repo-relativ):**  
  [management-summary.pdf](./management-summary.pdf)

- **PDF (Direkt-Download/RAW):**  
  https://raw.githubusercontent.com/SalihSan54/PROT-B/main/Labyrinth/docs/management-summary.pdf

- **Summary als Markdown (Browser/GitHub):**  
  https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/management-summary.md

- **Summary als Markdown (Repo-relativ):**  
  [management-summary.md](./management-summary.md)

> **Hinweis:** In VS Code Codespaces lassen sich PDFs im Editor nicht direkt anzeigen.  
> Öffne dafür den **Browser-Link** (oben) oder nutze den **Direkt-Download**.

---

## Kurz-Anleitung (Build & Run)

```bash
make
./labyrinth           # Standard: 10x10, ~15% Hindernisse

# Beispiel mit Parametern:
./labyrinth 12 12 0.2

make test             # Autotest -> "OK"
