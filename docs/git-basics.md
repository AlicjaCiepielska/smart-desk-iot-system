# Git i GitHub — podstawy

- **Git** śledzi historię zmian w plikach projektu na komputerze.
- **GitHub** jest usługą, na której możemy przechowywać repozytorium i pokazywać postępy.
- **Repozytorium** to folder projektu razem z historią zmian.
- **Commit** to zapisana porcja zmian z krótkim opisem.
- **Push** wysyła lokalne commity do repozytorium na GitHubie.
- **Issue** to zadanie, pytanie lub błąd, który chcemy śledzić.

## Sugerowane pierwsze commity
1. `chore: initialize Smart Desk repository`
2. `feat(firmware): print startup message over serial`
3. `feat(firmware): read BME280 sensor`

## Przykładowe komendy — dopiero po utworzeniu pustego repozytorium online

Uruchom terminal w **głównym folderze projektu**, nie w `firmware`.

```bash
git init
git add .
git commit -m "chore: initialize Smart Desk repository"
git branch -M main
git remote add origin https://github.com/TWOJ-LOGIN/smart-desk-iot-system.git
git push -u origin main
```

Zamień `TWOJ-LOGIN` na swój login. Przed push trzeba
zalogować się do GitHub (np. przez VS Code lub Git Credential Manager).
Jeśli repozytorium online ma już README, najpierw trzeba
zsynchronizować historie — dlatego na start najłatwiej utworzyć
**puste repozytorium** bez automatycznie generowanego README.

## Dobry zwyczaj
Commitujemy po **jednym działającym etapie**, a nie jedną wielką
zmianę na końcu projektu.
