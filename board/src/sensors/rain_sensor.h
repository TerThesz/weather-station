#ifndef RAIN_SENSOR_H
#define RAIN_SENSOR_H

#include <Arduino.h>
#include "utils/report_parser.h"

// pins
const int rain_D = 5;
const int rain_A = A0;
int rain_intensity;
int* output = new int[2];

void start_rain_sensor() {
  pinMode(rain_D, INPUT);
  pinMode(rain_A, INPUT);
}

int* update_rain_sensor() {
  rain_intensity = analogRead(rain_A);

  output[0] = rain_intensity;
  output[1] = digitalRead(rain_D) == LOW;

  if (digitalRead(rain_D) == LOW) {
    Serial.println("Rain detected. Intensity: " + String(rain_intensity));
    delay(10);

    return output;
  }

  Serial.println("No rain detected");
  delay(10);

  return output;
}

#endif