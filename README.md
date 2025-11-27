# Gas Leakage Detection System using ESP32 and Blynk App

This project is an IoT based Gas Leakage Monitoring and Alert System built using ESP32, MQ-2 Gas Sensor, Buzzer, LED, and the Blynk IoT platform. Whenever the gas level crosses the safety threshold, the system triggers an alert through a buzzer, LED and sends a notification to the Blynk application.

---

## Features

- Real-time gas leakage monitoring using MQ-2 sensor
- Instant alert on Blynk App via event notification
- Buzzer and LED alert locally for unsafe gas levels
- Wi-Fi reconnecting mechanism for reliable connectivity
- Can work offline if Wi-Fi is unavailable (local buzzer + LED only)

---

## Hardware Components

| Component | Description |
|----------|-------------|
| ESP32 | Microcontroller |
| MQ-2 Sensor | Detects LPG, butane, smoke and methane gas |
| Buzzer | Local alert alarm |
| LED | Visual alert |
| Jumper Wires | Connections |
| Wi-Fi Network | For IoT communication |

---

## Circuit Diagram (Pin Connections)

| Component | Pin on Component | ESP32 Pin |
|----------|------------------|-----------|
| MQ-2 Sensor (Digital Output) | VCC | 5V / VIN |
| | GND | GND |
| | D0 | GPIO 14 |
| Buzzer | + | GPIO 12 |
| | – | GND |
| LED | Anode (+) | GPIO 13 + resistor (200 Ω) |
| | Cathode (–) | GND |
| Power Supply (Battery) | + | VIN / 5V |
| | – | GND |

---

## Blynk Dashboard Setup

1. Create a new Blynk Template  
   Template Name: Gas Leakage Detector
2. Add an Event Notification labeled **leakage_alert**
3. Copy the generated values and place them inside the code:
```
BLYNK_TEMPLATE_ID
BLYNK_TEMPLATE_NAME
BLYNK_AUTH_TOKEN
```

---

## Source Code

The complete project source code used in ESP32:

```cpp
// #define BLYNK_TEMPLATE_ID "your_template_id_here"
// #define BLYNK_TEMPLATE_NAME "Gas Leakage Detector"
// #define BLYNK_AUTH_TOKEN "your_blynk_token_here"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// char ssid[] = "your_wifi_name";
// char pass[] = "your_wifi_password";

#define GAS_SENSOR_PIN 14
#define BUZZER_PIN 12
#define LED_PIN 13
...
```

---

## Working Principle

1. MQ-2 measures gas concentration continuously.
2. If gas level is safe, LED and buzzer remain OFF.
3. When gas concentration crosses the safe limit:
   - LED turns ON
   - Buzzer beeps
   - Blynk sends alert notification through event log
4. The ESP32 ensures auto Wi-Fi reconnect if connection drops.

---

## How to Run

1. Install ESP32 board manager and Blynk library in Arduino IDE
2. Select the board: `ESP32 Dev Module`
3. Install USB driver (if required)
4. Replace Wi-Fi and Blynk credentials in the code
5. Upload the code to ESP32
6. Open Serial Monitor at 115200 baud rate

---

## Optional Improvements

- Add gas level indicator using Blynk Gauge widget
- Add fan or relay-based automatic exhaust system
- Add SMS alerts using Twilio or Telegram Bot
- Add temperature and humidity sensors for safety monitoring

---

## Project Requirements

| Software | Version |
|----------|---------|
| Arduino IDE | Latest |
| ESP32 Board Package | Installed |
| Blynk Library | Installed |
| USB Driver | CH340/CP2102 based on board |

---

## Project Outcome

This system provides fast detection and remote alerting for gas leakage incidents, increasing safety in kitchens, industries and gas storage areas using IoT-based automation.

---

## Author

Developer: Brijesh Maurya  
Final Year IT Engineering Student  
Project Domain: IoT and Embedded Systems

