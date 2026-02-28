#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Obstacle Detection System using IR Sensor
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program reads digital input from an IR obstacle detection sensor.
 * The sensor outputs a LOW signal when an obstacle is detected and HIGH
 * when no obstacle is present. The system continuously monitors the sensor
 * state and prints the detection status to the Serial Monitor with a small delay.
 */

// Define IR sensor digital pin (Use pin 2)
#define IR_PIN 2   ///< Digital pin connected to IR obstacle sensor output

// Variable to store sensor state (HIGH or LOW)
int sensorState;  ///< Stores the current state of the IR sensor

/**
 * @brief Initializes serial communication and configures IR sensor pin.
 *
 * This function runs once when the Arduino boots.
 * It sets up the Serial Monitor and configures the IR sensor pin as input.
 */
void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Configure IR pin as INPUT to read sensor signal
    pinMode(IR_PIN, INPUT);

    // Print system initialization message to Serial Monitor
    Serial.println("IR Obstacle Detection System Initialized");
}

/**
 * @brief Continuously reads IR sensor state and prints obstacle status.
 *
 * The loop checks the digital output of the IR sensor.
 * If the sensor outputs LOW, an obstacle is detected.
 * Otherwise, no obstacle is present. A small delay ensures
 * stable readings and readable serial output.
 */
void loop() {

    // Read digital value from IR sensor
    sensorState = digitalRead(IR_PIN);

    // Check sensor state:
    // Most IR obstacle sensors output LOW when an obstacle is detected
    if (sensorState == LOW) {
        Serial.println("Obstacle Detected");  ///< Obstacle is present
    } else {
        Serial.println("No Obstacle");        ///< No obstacle detected
    }

    // Add small delay (200–500ms) for stable readings and readability
    delay(300);
}
