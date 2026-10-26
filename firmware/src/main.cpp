
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// Piny sterujace ekranem
#define TFT_CS  27
#define TFT_DC  26
#define TFT_RST 25

// Tworzymy obiekt wyswietlacza
Adafruit_ST7789 tft = Adafruit_ST7789(
    TFT_CS, TFT_DC, TFT_RST
);

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("Uruchamianie ST7789...");

    // Inicjalizacja wyswietlacza 240x320
    // ESP32 korzysta z SPI:
    // SCK = GPIO18, MOSI = GPIO23
    tft.init(240, 320);

    // Obracamy obraz do poziomu
    tft.setRotation(1);

    // TEST 1 - czerwony ekran
    tft.fillScreen(ST77XX_RED);
    delay(1000);

    // TEST 2 - zielony ekran
    tft.fillScreen(ST77XX_GREEN);
    delay(1000);

    // TEST 3 - niebieski ekran
    tft.fillScreen(ST77XX_BLUE);
    delay(1000);

    // TEST 4 - nasz pierwszy interfejs
    // Tworzymy pastelowy roz
    uint16_t pink = tft.color565(255, 205, 225);

    tft.fillScreen(pink);

    // Bialy panel
    tft.fillRoundRect(
        20, 20, 280, 200, 15, ST77XX_WHITE
    );

    // Glowny napis
    tft.setTextColor(ST77XX_BLACK);
    tft.setTextSize(3);
    tft.setCursor(65, 75);
    tft.println("SMART DESK");

    // Podpis
    tft.setTextSize(2);
    tft.setCursor(90, 130);
    tft.println("HELLO!");

    tft.setTextSize(1);
    tft.setCursor(92, 175);
    tft.println("ST7789 TEST OK");

    Serial.println("Wyslano obraz do ST7789!");
}

void loop() {
    // Na razie niczego nie powtarzamy
}
