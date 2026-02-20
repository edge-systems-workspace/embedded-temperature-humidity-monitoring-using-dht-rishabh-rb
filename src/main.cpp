#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author YOUR_NAME
 * @date 2026-02-20
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 */

#include <DHT.h>

// TODO 1:
// Define the DHT data pin (Use digital pin 2)
#define DHTPIN 2

// TODO 2:
// Define the DHT sensor type (DHT11)
#define DHTTYPE DHT11

// TODO 3:
// Create a DHT object using the defined pin and sensor type
DHT dht(DHTPIN, DHTTYPE);

void setup() {

    // TODO 4:
    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // TODO 5:
    // Initialize the DHT sensor
    dht.begin();

    // TODO 6:
    // Print a system initialization message
    Serial.println("DHT11 Temperature & Humidity Monitoring System");
    Serial.println("Initializing sensor...");
    delay(2000);
}

void loop() {

    // TODO 7:
    // Read humidity value from sensor
    float humidity = dht.readHumidity();

    // TODO 8:
    // Read temperature value from sensor
    float temperature = dht.readTemperature();

    // TODO 9:
    // Check if either reading failed using isnan()
    // If failed, print error message and return
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    // TODO 10:
    // Print formatted temperature and humidity values
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    // TODO 11:
    // Add a 2-second delay before next reading
    delay(2000);
}