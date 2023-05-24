// Implementing for NodeMCU ESP8266 WiFi
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// SSID & Password 
const char* ssid = "NodeMCU";  
const char* password = "123456789"; 

// server is gonna listen on port 80
ESP8266WebServer server(80);

void setup() {
  // Initializing serial monitor
  Serial.begin(9600);
  WiFi.softAP(ssid, password);

  // Getting IP adress
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Access Point IP:");
  Serial.println(myIP);

  // Controlling routes
  server.on("/", get_effects);
  
  // Starting server
  server.begin();
  Serial.println("HTTP Server Started...");
}

void loop() {
  server.handleClient();

  // Apply led cube logic here
}

// Response example for getting effects names
void get_effects(){
  Serial.println("Connect sucefull");
   server.send(200, "application/json", "{\"effects\": [\\ 
   { \"id\": \"joao\" },\\
   { \"id\": \"arthur\" },\\
   { \"id\": \"ana tereza\" },\\
   { \"id\": \"vitor\" },\\
   { \"id\": \"joao pedro\" },\\
   { \"id\": \"luis\" },\\
   { \"id\": \"caio\" },\\
   { \"id\": \"sofia\" } \\
   ] }" );
}

