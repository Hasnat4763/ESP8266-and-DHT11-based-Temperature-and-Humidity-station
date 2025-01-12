#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "html.h"
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(2,DHT11);
ESP8266WebServer server(80);
String html;

void handleRoot(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  html = FPSTR(INDEX_HTML);
  html.replace("{{Temperature}}",String(t));
  html.replace("{{Humidity}}",String(h));
  server.send(200,"text/html", html);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  delay(2000);
}
void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();
  WiFi.begin("PPut your WiFi SSID","Put your WiFi password");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
Serial.print("IP Address: ");
Serial.println(WiFi.localIP());
server.on("/", handleRoot);
server.begin();
}

void loop() {
  server.handleClient();
}
