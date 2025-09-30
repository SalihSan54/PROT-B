# Dokumentation – Labyrinth (C)

## Management Summary
- **PDF (Repo-intern):** [management-summary.pdf](./management-summary.pdf)
- **PDF (GitHub-Webansicht):** https://github.com/SalihSan54/PROT-B/blob/main/Labyrinth/docs/management-summary.pdf
- **Markdown:** [management-summary.md](./management-summary.md)

> Hinweis: In VS Code Codespaces lässt sich PDF nicht direkt anzeigen.  
> Auf GitHub (Link oben) öffnet sich das PDF im Browser.

---

## Kurz-Anleitung (Build & Run)
```bash
make
./labyrinth                # Standard: 10x10, ~15% Hindernisse
# Beispiel mit Parametern:
./labyrinth 12 12 0.2
make test                  # Autotest -> "OK"
