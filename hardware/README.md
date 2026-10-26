# Hardware i montaż

## Uzgodniony zestaw
| Moduł | Rola | Status |
| --- | --- | --- |
| ESP32 | Sterowanie i Wi-Fi | Weryfikacja modelu/posiadania |
| BME280 | Temperatura, wilgotność, ciśnienie | Weryfikacja modułu |
| BH1750 / GY-302 | Oświetlenie [lx] | Weryfikacja modułu |
| SCD40 | Stężenie CO₂ [ppm] | Planowany |
| ST7789 2,0″ 240×320 | Wyświetlacz SPI | Weryfikacja modułu |
| WS2812B | Wskaźnik kolorowy | Posiadane LED-y |
| Przyciski | Sterowanie lokalne | Posiadane |
| Płytka stykowa | Prototypowanie | Posiadana |
| Perfboard 7×9 cm | Montaż finalny | Planowana |
| USB 5 V | Zasilanie | Założenie projektu |

## WAŻNE
Dokładny pinout ustalimy po sprawdzeniu napisów
na **konkretnych modułach**, które masz na biurku.
Nie zakładamy, że każdy sprzedawany moduł jest identyczny.

- ESP32 używa logiki 3,3 V na GPIO — nie podłączaj do GPIO 5 V.
- Sprawdź napięcie zasilania konkretnego modułu przed podłączeniem.
- Najpierw testujemy czujniki na płytce stykowej.
- Lutowanie i projekt obudowy dopiero po stabilnych testach.
