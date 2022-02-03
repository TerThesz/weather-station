#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include "sensors/rain_sensor.h"
#include "utils/tcp_client.h"
#include "sensors/dht_sensor.h"

float* rain_data = new float[2];
float* dht_data = new float[3];

String parsed_payload;

void start_sensors() {
  start_rain_sensor();
  start_dht_sensor();
}

void update_sensors() {
  // get data from sensors
  rain_data = update_rain_sensor();
  dht_data = update_dht_sensor();

  Serial.println("New data report");

  parsed_payload = parse(
    rain_data[0], rain_data[1],
    dht_data[0], dht_data[1], dht_data[2]
  );

  Serial.println(parsed_payload);
  send_tcp(parsed_payload);
}

#endif