// Based on code from https://randomnerdtutorials.com/

// Import required libraries
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "secret.h"
#include "sensors.h"
#include "webpage.h"

AsyncWebServer server(80);

String processor(const String& var){
  if(var == "LIGHT"){
    return readLightValue();
  }
  return String();
}

void setup(){
  pinMode(LDRpin, INPUT);
  
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/light", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readLightValue().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
  // Serial.println(analogRead(potPin));
}
