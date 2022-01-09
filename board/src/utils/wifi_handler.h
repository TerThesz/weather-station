#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <Arduino.h>
#include <WiFi.h>
#include "utils/variables.h"

bool connect_wifi() {
  Serial.println("Connecting to WIFI. . .");
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(SSID, PASSWORD);

  int i = 0;
  while (WiFi.status() != WL_CONNECTED && i < 10) {
    Serial.print(". ");
    i++;

    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnection established\n");
    return true;
  }

  Serial.println("\nConnection failed\n");
  return false;
}

void get_mac() {
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());
}

#endif