#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// SSID & Password 
const char* ssid = "NodeMCU";  
const char* password = "123456789"; 

// server is gonna listen on port 80
ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Access Point IP:");
  Serial.println(myIP);

  server.on("/", get_effects);
  server.on("/exec_effect", callback);
  
  server.begin();
  Serial.println("HTTP Server Started...");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();

  // Apply led cube logic here
}

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

void callback(){
  // mapear o nome da função que vem no corpo da requisição e executá-la
}
