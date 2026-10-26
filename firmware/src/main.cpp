
#include <Arduino.h>
#include <Wire.h>

// Adres naszego czujnika BH1750
const uint8_t SENSOR_ADDRESS = 0x23;

void setup() {
    Serial.begin(115200);
    delay(1000);

    // Uruchomienie magistrali I2C
    Wire.begin(21, 22);

    // Wybór ciągłego trybu pomiarowego
    Wire.beginTransmission(SENSOR_ADDRESS);
    Wire.write(0x10);

    if (Wire.endTransmission() == 0) {
        Serial.println("BH1750 gotowy!");
    } else {
        Serial.println("Blad komunikacji z BH1750!");
    }

    delay(200);
}

void loop() {
    // Prosimy czujnik o 2 bajty pomiaru
    int received = Wire.requestFrom(
        SENSOR_ADDRESS, (uint8_t)2
    );

    if (received == 2) {
        // Łączymy dwa bajty w jedną liczbę
        uint16_t raw = (Wire.read() << 8) | Wire.read();

        // Przeliczamy wynik na luksy
        float lux = raw / 1.2f;

        Serial.print("Natezenie swiatla: ");
        Serial.print(lux);
        Serial.println(" lx");
    } else {
        Serial.println("Blad odczytu czujnika!");
    }

    delay(1000);
}
