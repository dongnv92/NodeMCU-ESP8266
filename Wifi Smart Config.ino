#include <ESP8266WiFi.h>
void setup() {
  Serial.begin(115200);//for serial communication
  Serial.println("Smart config");
  WiFi.disconnect();//clear all current wifi data 
  WiFi.mode(WIFI_STA);//set station mode or smart config
  delay(500);
  WiFi.beginSmartConfig();//begin smart config
  Serial.println("Smart config started");

  while(WiFi.status()!=WL_CONNECTED){// checking for wifi is connected or not
    Serial.print('.');
    delay(1000);
  }
  Serial.println();
  Serial.println("WIFI CONNECTED");
  Serial.print("IP :");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.SSID().c_str());
}

void loop() {
  // put your main code here, to run repeatedly:

}
