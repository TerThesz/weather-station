#ifndef RAIN_SENSOR_H
#define RAIN_SENSOR_H

#include <Arduino.h>
#include "utils/report_parser.h"

// pins
const int rain_D = 33;
const int rain_A = 32;
int rain_intensity;
float* rain_output = new float[2];

void start_rain_sensor() {
  pinMode(rain_D, INPUT);
  pinMode(rain_A, INPUT);
}

float* update_rain_sensor() {
  rain_intensity = analogRead(rain_A);
  rain_intensity = 1023 - rain_intensity / 4;

  rain_output[0] = (float) rain_intensity;
  rain_output[1] = (float) digitalRead(rain_D) == LOW;

  return rain_output;
}

#endif