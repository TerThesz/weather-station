#ifndef REOIRT_PARSER_H
#define REOIRT_PARSER_H

#include <Arduino.h>

String parse (int rain_intensity, bool is_raining) {
  return (
    "is_raining: " + String(is_raining) + "\n" +
    "rain_intensity: " + String(rain_intensity) + "\n"
  );
}

#endif