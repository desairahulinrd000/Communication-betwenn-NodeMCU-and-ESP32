#include <WiFi.h>
#include <HTTPClient.h>
#define pir_sns 2  
const char* ssid ="NodeMCU";
const char* password ="withESP32";
void setup()
{
    Serial.begin(115200);
    pinMode(pir_sns,INPUT);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect(true);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid,password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      Serial.print(".");
      delay(5000);
    }
    Serial.println("Connected");
}
void loop() {
    if((WiFi.status() == WL_CONNECTED)) 
    {
        HTTPClient http;
        if(digitalRead(pir_sns) == HIGH)
        {
          Serial.println("Requested HTTP");
          http.begin("http://192.168.4.1/request");
          int httpCode = http.GET();
          http.end();
        }
    }
}
