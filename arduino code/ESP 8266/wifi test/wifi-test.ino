#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

//IP is 10.0.0.128

const char* ssid = "Netgear1";
const char* password = "a3aaf93071";

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
}

void loop() {

  digitalWrite(2, !digitalRead(2));
  delay(1000);
}
