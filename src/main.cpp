#include <Arduino.h>

// Define IR sensor digital pin (Use pin 2)
#define IR_PIN 2

// Variable to store sensor state
int sensorState;

void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Configure IR pin as INPUT
    pinMode(IR_PIN, INPUT);

    // Print system initialization message
    Serial.println("IR Obstacle Detection System Initialized");
}

void loop() {

    // Read digital value from IR sensor
    sensorState = digitalRead(IR_PIN);

    // If obstacle detected
    if (sensorState == LOW) {  // Most IR modules output LOW when obstacle is present
        Serial.println("Obstacle Detected");
    } else {
        Serial.println("No Obstacle");
    }

    // Add small delay (200–500ms)
    delay(300);
}
