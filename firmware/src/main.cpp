#include <Arduino.h>

// setup() wykonuje się jeden raz po uruchomieniu ESP32.
void setup() {
    // Rozpoczynamy komunikację tekstową przez USB/port szeregowy.
    Serial.begin(115200);

    // Krótka przerwa, aby monitor zdążył się uruchomić.
    delay(1000);
    Serial.println("Smart Desk: firmware wystartowal");
}

// loop() wykonuje się wielokrotnie, dopóki ESP32 jest zasilane.
void loop() {
    // millis() to czas pracy mikrokontrolera w milisekundach.
    unsigned long seconds = millis() / 1000;

    Serial.print("Czas pracy: ");
    Serial.print(seconds);
    Serial.println(" s");

    // Celowo czekamy 2 sekundy pomiędzy komunikatami.
    // W przyszłości nauczymy się wersji bez blokującego delay().
    delay(2000);
}
