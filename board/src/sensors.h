#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include "sensors/rain_sensor.h"
#include "utils/tcp_client.h"

int* rain_data = new int[2];
String parsed_payload;

void start_sensors() {
  start_rain_sensor();
}

void update_sensors() {
  rain_data = update_rain_sensor();

  Serial.println("New data report");

  parsed_payload = parse(rain_data[0], rain_data[1]);

  Serial.println(parsed_payload);
  send_tcp(parse(rain_data[0], rain_data[1]));
}

#endif