#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const int buzz_pin=D0;
const char *ssid = "NodeMCU";
const char *password = "withESP32";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
}
void request()
{
  server.send(200,"text/html","<h1>Objected Detected</h1>");
  Serial.println("Incomming Request");
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
  }
}
void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Setting up Access point");
  WiFi.softAP(ssid, password);
  pinMode(2, OUTPUT);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/request",request);
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}
