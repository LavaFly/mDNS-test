#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


const char *SSID = "yourSSID";
const char *PASS = "yourPASSWORD";

AsyncWebServer server(80);

void setup() {
    Serial.begin(9600);
    Serial.println("Starting Setup");



    Serial.println("Connecting to WiFi");
    WiFi.begin(SSID, PASS);
    if(WiFi.waitForConnectResult() == WL_CONNECTED){
        Serial.println("Connected to local network");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("Could not connect to local network");
        while(true){};
    }



    Serial.println("Setting up the webserver");
    if(WiFi.status() != WL_CONNECTED){
        return;
    }
    server.on("/", handleHTMLRequest);
    server.begin();



    Serial.println("Setting up mDNS");
    if(!MDNS.begin("esp1")){
        Serial.println("Error setting up mDNS responder!");
        while(1){ delay(1000); }
    }
    MDNS.addService("http", "tcp", 80);


    if(!MDNS.begin("esp2")){
        Serial.println("Error setting up mDNS responder!");
        while(1){ delay(1000); }
    }
    Serial.println("mDNS responder started");

    MDNS.addService("http", "tcp", 80);

    Serial.println("Ending Setup");
}

void loop() {
    MDNS.update();
}

void handleHTMLRequest(AsyncWebServerRequest *request){
    Serial.println("sending hello from esp");
    AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", "Hello from esp!\n");
    request->send(response);
}
