#include <Arduino.h>
#include <DHTesp.h>

DHTesp              dht;
int                 interval = 2000;
unsigned long       lastDHTReadMillis = 0;
float               humidity = 0;
float               temperature = 0;

void setup() {
    Serial.begin(115200);
    dht.setup(14, DHTesp::DHT22); // Connect DHT sensor to GPIO 14
    delay(1000);

    Serial.println(); Serial.println("Humidity (%)\tTemperature (C)");
}

void readDHT22() {
    unsigned long currentMillis = millis();

    if(currentMillis - lastDHTReadMillis >= interval) {
        lastDHTReadMillis = currentMillis;

        humidity = dht.getHumidity();              // Read humidity (percent)
        temperature = dht.getTemperature();        // Read temperature as Fahrenheit
    }
}
void loop() {
    readDHT22();
    Serial.printf("%.1f\t %.1f\n", humidity, temperature);
    delay(1000);
}
