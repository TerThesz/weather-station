#ifndef REOIRT_PARSER_H
#define REOIRT_PARSER_H

#include <Arduino.h>

String parse (
    float rain_intensity, float is_raining,
    float temperature, float humidity, float heat_index
  ) {
  return (
    "is_raining: " + String((int) is_raining) + "\n" +
    "rain_intensity: " + String(rain_intensity) + "\n" +
    "temperature: " + String(temperature) + "\n" +
    "humidity: " + String(humidity) + "\n" +
    "heat_index: " + String(heat_index) + "\n"
  );
}

#endif