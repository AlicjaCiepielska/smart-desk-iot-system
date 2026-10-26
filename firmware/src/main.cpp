
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

// Adresy czujnikow
const uint8_t BH1750_ADDR = 0x23;
const uint8_t BME280_ADDR = 0x76;

// Tworzymy obiekt obslugujacy BME280
Adafruit_BME280 bme;

bool bmeReady = false;

void setup() {
    Serial.begin(115200);
    delay(1000);

    // I2C: SDA = 21, SCL = 22
    Wire.begin(21, 22);

    Serial.println("SMART DESK - START");

    // Uruchamiamy BME280
    bmeReady = bme.begin(BME280_ADDR, &Wire);

    if (bmeReady) {
        Serial.println("BME280: OK");
    } else {
        Serial.println("BME280: BLAD");
    }

    // Uruchamiamy pomiar swiatla BH1750
    Wire.beginTransmission(BH1750_ADDR);
    Wire.write(0x10);

    if (Wire.endTransmission() == 0) {
        Serial.println("BH1750: OK");
    } else {
        Serial.println("BH1750: BLAD");
    }

    delay(200);
}

void loop() {
    Serial.println("--------------------");

    // Pomiary BME280
    if (bmeReady) {
        float temperature = bme.readTemperature();
        float humidity = bme.readHumidity();
        float pressure = bme.readPressure() / 100.0f;

        Serial.print("Temperatura: ");
        Serial.print(temperature);
        Serial.println(" C");

        Serial.print("Wilgotnosc: ");
        Serial.print(humidity);
        Serial.println(" %");

        Serial.print("Cisnienie: ");
        Serial.print(pressure);
        Serial.println(" hPa");
    }

    // Pomiar BH1750
    int received = Wire.requestFrom(
        BH1750_ADDR, (uint8_t)2
    );

    if (received == 2) {
        uint16_t raw = (Wire.read() << 8) | Wire.read();
        float lux = raw / 1.2f;

        Serial.print("Swiatlo: ");
        Serial.print(lux);
        Serial.println(" lx");
    } else {
        Serial.println("Blad odczytu BH1750");
    }

    delay(2000);
}
