//#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <EEPROM.h>
//for LED status
#include <Ticker.h>
Ticker ticker;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "158b73f047214e689d42abdac0ca81fb";

void tick()
{
  //toggle state
  int state = digitalRead(D5);  // get the current state of GPIO1 pin
  digitalWrite(D5, !state);     // set pin to the opposite state
}

void setup()
{
  //set led pin as output
  pinMode(D5, OUTPUT);
  // start ticker with 0.5 because we start in AP mode and try to connect
  ticker.attach(0.6, tick);
  EEPROM.begin(512);
  Serial.begin(115200);
  WiFiManager wifiManager;
  //wifiManager.resetSettings();    //Uncomment this to wipe WiFi settings from EEPROM on boot.  Comment out and recompile/upload after 1 boot cycle.
  if (!wifiManager.autoConnect("DONG SMART ROOM")) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(1000);
  }
  //if you get here you have connected to the WiFi
  Serial.println("Wifi Da Duoc Ket Noi :)");
  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
  ticker.detach();
  //keep LED on
  digitalWrite(D5, LOW);
}

void loop()
{
  Blynk.run();  // Commented out for a short time.
}
