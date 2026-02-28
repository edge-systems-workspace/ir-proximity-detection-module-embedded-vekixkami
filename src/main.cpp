#include <Arduino.h>   // Include core Arduino functions and definitions

// Define IR sensor digital pin (Use pin 2)
#define IR_PIN 2        // IR obstacle sensor connected to digital pin 2

// Variable to store sensor state (HIGH or LOW)
int sensorState;

void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Configure IR pin as INPUT to read sensor signal
    pinMode(IR_PIN, INPUT);

    // Print system initialization message to Serial Monitor
    Serial.println("IR Obstacle Detection System Initialized");
}

void loop() {

    // Read digital value from IR sensor
    sensorState = digitalRead(IR_PIN);

    // Check sensor state:
    // Most IR obstacle sensors output LOW when an obstacle is detected
    if (sensorState == LOW) {  
        Serial.println("Obstacle Detected");  // Print when obstacle is present
    } else {
        Serial.println("No Obstacle");        // Print when no obstacle is detected
    }

    // Add small delay (200–500ms) for stable readings and readability
    delay(300);
}
