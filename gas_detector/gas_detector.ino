// Blynk Credentials
// #define BLYNK_TEMPLATE_ID "your_template_id_here"
// #define BLYNK_TEMPLATE_NAME "Gas Leakage Detector"
// #define BLYNK_AUTH_TOKEN "your_blynk_token_here"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi Credentials
// char ssid[] = "your_wifi_name";
// char pass[] = "your_wifi_password";

// Hardware Pins
#define GAS_SENSOR_PIN 14   // MQ-2 Digital Output pin (ESP-32 GPIO 14)
#define BUZZER_PIN 12       // Buzzer pin
#define LED_PIN 13          // LED pin

void connectToWiFi() {
    WiFi.begin(ssid, pass);
    Serial.print("Connecting to WiFi");
    
    int retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < 30) {
        Serial.print(".");
        delay(500);
        retries++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConnected to WiFi!");
        Blynk.config(BLYNK_AUTH_TOKEN);
        Blynk.connect(); // Connect to Blynk manually
    } else {
        Serial.println("\nWiFi not connected. Running in offline mode.");
    }
}

void setup() {
    Serial.begin(115200);
    
    connectToWiFi(); // Connect to WiFi at startup

    pinMode(GAS_SENSOR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi disconnected. Reconnecting...");
        connectToWiFi(); // Try reconnecting if WiFi disconnects
    } else {
        Blynk.run(); // Run Blynk if connected
    }

    int gasValue = digitalRead(GAS_SENSOR_PIN);
    Serial.print("Gas Sensor Value: ");
    Serial.println(gasValue);

    if (gasValue != 1) {
        Serial.println("⚠️ Gas Leakage Detected! ALERT!");
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);

        if (Blynk.connected()) {
            Blynk.logEvent("leakage_alert", "⚠️ Gas Leakage Detected! Take Action!");
        }

        delay(5000);
    } else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
    }

    delay(1000);
}
