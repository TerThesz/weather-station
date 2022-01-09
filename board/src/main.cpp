#include <Arduino.h>
#include "sensors.h"
#include "utils/wifi_handler.h"
#include "utils/tcp_client.h"
#include "utils/variables.h"

bool wifi_connected = false;
bool tcp_connected = false;

void init_tcp() {
  while(!tcp_connected) {
    tcp_connected = connect_tcp();

    delay(1000);
  }
}

void setup() {
  Serial.begin(9600);

  // connect to wifi
  while(!wifi_connected) {
    get_mac();
    wifi_connected = connect_wifi();

    delay(1000);
  }

  // connect to server
  init_tcp();

  start_sensors();
}

void loop() {
  if (!connected()) {
    tcp_connected = false;
    
    Serial.println("Disconnected from server, reconnecting...");
    init_tcp();
  }

  update_sensors();

  delay(DELAY);
}