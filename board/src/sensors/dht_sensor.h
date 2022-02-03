#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_PIN 35
#define DHT_TYPE DHT22

float *dht_output = new float[3];

DHT dht(DHT_PIN, DHT_TYPE);

void start_dht_sensor()
{
  dht.begin();
}

float *update_dht_sensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float hic = dht.computeHeatIndex(t, h, false);

  delay(5000);

  dht_output[0] = t;
  dht_output[1] = h;
  dht_output[2] = hic;

  Serial.println(String(h) + " " + String(t) + " " + String(hic));

  return dht_output;
}

#endif