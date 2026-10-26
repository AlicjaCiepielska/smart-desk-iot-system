# Smart Desk IoT System 🌸

**Inteligentna stacja biurkowa oparta na ESP32** — projekt edukacyjny i portfolio.

Celem jest zaprojektowanie urządzenia, które mierzy warunki otoczenia,
wyświetla je na kolorowym ekranie, przesyła pomiary przez Wi-Fi
i prezentuje historię pomiarów w aplikacji internetowej.

## Docelowe funkcje
- Pomiar temperatury, wilgotności i ciśnienia (BME280).
- Pomiar oświetlenia (BH1750).
- Pomiar stężenia CO₂ (SCD40; integracja w późniejszym etapie).
- Kolorowy interfejs ST7789 2,0″ z animowanym stworkiem.
- Focus Mode i timer.
- Komunikacja ESP32 → MQTT → backend → baza danych → dashboard.
- Statystyki, historia pomiarów i zdalne sterowanie.

**Styl projektu:** pastelowy / różowe akcenty, ale z naciskiem na
czytelność, niezawodność i solidną dokumentację techniczną.

## Technologia (plan)
| Warstwa | Technologia |
| --- | --- |
| Urządzenie | ESP32 + C++ (Arduino framework, PlatformIO) |
| Czujniki | BME280, BH1750, SCD40 |
| Ekran | ST7789 (SPI) |
| Komunikacja | Wi-Fi, MQTT, JSON |
| Backend | Python, FastAPI |
| Baza danych | PostgreSQL |
| Frontend | React |
| Narzędzia | Git, GitHub, VS Code, PlatformIO |

## Obecny stan
🚧 **Etap 0 — start repozytorium i test firmware.**

Pierwsza wersja programu nie używa jeszcze czujników:
co 2 sekundy wypisuje komunikat do monitora portu szeregowego.
To celowy, mały test połączenia komputera z ESP32.

## Plan rozwoju
- [ ] 0. Utworzyć repozytorium, uruchomić pierwszy firmware i wykonać commit.
- [ ] 1. Odczytać wartości BME280 i BH1750 przez I²C.
- [ ] 2. Wyświetlać pomiary i interfejs na ST7789 przez SPI.
- [ ] 3. Dodać Wi-Fi, MQTT i wysyłanie JSON.
- [ ] 4. Odbierać dane w backendzie FastAPI.
- [ ] 5. Zapisywać pomiary w PostgreSQL.
- [ ] 6. Zbudować dashboard w React.
- [ ] 7. Dodać SCD40, Focus Mode i komunikację zwrotną.
- [ ] 8. Wykonać obudowę 3D, montaż finalny i testy.

## Struktura repozytorium
```text
smart-desk-iot-system/
├── firmware/           # Kod wgrywany do ESP32 (PlatformIO)
│   ├── platformio.ini
│   └── src/main.cpp
├── backend/            # Backend Python/FastAPI (później)
├── frontend/           # Dashboard React (później)
├── hardware/           # Komponenty, schematy, obudowa
├── docs/               # Architektura, dziennik nauki, Git
├── .gitignore
└── README.md
```

## Pierwsze uruchomienie
1. Zainstaluj VS Code oraz rozszerzenie **PlatformIO IDE**.
2. Otwórz folder `firmware` w VS Code.
3. Sprawdź, czy `board = esp32dev` w `platformio.ini` odpowiada
   Twojej płytce — jest to **ustawienie wstępne**, niepotwierdzone.
4. Podłącz ESP32 do komputera przewodem USB obsługującym dane.
5. Wybierz **Build**, potem **Upload**, a następnie **Serial Monitor**
   (115200 baud).
6. Oczekiwany komunikat: `Smart Desk: firmware wystartowal`.
7. Powinny pojawiać się także komunikaty z liczbą sekund pracy.

Jeśli nie masz jeszcze osobnego ESP32 do Smart Desk,
możesz już stworzyć repozytorium. Wgrywanie programu zrobimy
dopiero po potwierdzeniu modelu płytki.

## Dokumentacja
- [Architektura](docs/architecture.md)
- [Podstawy Git](docs/git-basics.md)
- [Dziennik nauki](docs/learning-log.md)
- [Notatki sprzętowe](hardware/README.md)

## Status
Projekt w budowie. Implementujemy i dokumentujemy kolejne funkcje etapami.
