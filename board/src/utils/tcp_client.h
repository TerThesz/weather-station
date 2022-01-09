#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "utils/variables.h"

WiFiClient client;

bool connect_tcp() {
  Serial.println("Connecting to the server. . .");

  client.connect(IP, PORT);

  int i = 0;
  while (!client.connected() && i < 10) {
    Serial.print(". ");
    i++;

    delay(500);
  }

  if (client.connected()) {
    Serial.println("\nConnection established\n");
    return true;
  }

  Serial.println("\nConnection failed\n");
  return false;
}

void send_tcp(String payload) {
  client.println(payload);
}

bool connected() {
  return client.connected();
}

#endif