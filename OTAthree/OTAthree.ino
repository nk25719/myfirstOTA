/* from: https://randomnerdtutorials.com/esp32-over-the-air-ota-programming/
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com

 version: V.0.0.2
 */

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>

const char* host = "esp32";
const char* ssid = "Home";
const char* password = "adt@1963#";

//variabls to blink without delay:
const int led = 2;
unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 1000;        // interval at which to blink (milliseconds)
int ledState = LOW;                // ledState used to set the LED

WebServer server(80);


void setup(void) {
  pinMode(led, OUTPUT);

  Serial.begin(115200);

  // Connect to WiFi network
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  setupfunction();
}

void loop(void) {
  server.handleClient();
  delay(1);

  //loop to blink without delay
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    ledState = not(ledState);

    // set the LED with the ledState of the variable:
    digitalWrite(led, ledState);
  }
}
