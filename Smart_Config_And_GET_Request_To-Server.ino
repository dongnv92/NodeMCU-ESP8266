#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char Led   = D5;
const char *host  = "http://trungtamytemelinh.com/test.php";
void setup() {
  // Smart Config
  pinMode(Led, OUTPUT);
  Serial.begin(115200);//for serial communication
  Serial.println("Smart config");
  WiFi.disconnect();//clear all current wifi data 
  WiFi.mode(WIFI_STA);//set station mode or smart config
  delay(500);
  WiFi.beginSmartConfig();//begin smart config
  Serial.println("Smart config started");
  while(WiFi.status()!=WL_CONNECTED){// checking for wifi is connected or not
    Serial.print('.');
    digitalWrite(Led, HIGH);
    delay(50);
    digitalWrite(Led, LOW);
    delay(50);
  }
  Serial.println();
  Serial.println("WIFI CONNECTED");
  Serial.print("IP :");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.SSID().c_str());
  // Smart Config
}

void loop() {
  /* REQUEST GET TO WEB SITE */
  HTTPClient http;    //Declare object of class HTTPClient  
  http.begin(host);   //Specify request destination
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
  // Led Control
  if(payload.indexOf("on") != -1 || payload.indexOf("On") != -1 || payload.indexOf("ON") != -1 || payload.indexOf("mo") != -1 || payload.indexOf("Mo") != -1 || payload.indexOf("mở") != -1 || payload.indexOf("Mở") != -1 || payload.indexOf("MỞ") != -1 || payload.indexOf("MO") != -1){
    digitalWrite(D5, HIGH);
    delay(2000);
    http.end();  //Close connection
  }else if(payload.indexOf("off") != -1 || payload.indexOf("Off") != -1 || payload.indexOf("OFF") != -1 || payload.indexOf("tat") != -1 || payload.indexOf("Tat") != -1 || payload.indexOf("TAT") != -1 || payload.indexOf("tắt") != -1 || payload.indexOf("Tắt") != -1 || payload.indexOf("TẮT") != -1){
    digitalWrite(D5, LOW);
    delay(2000);
    http.end();  //Close connection
  }else if(payload.indexOf("nhay") != -1 || payload.indexOf("Nhay") != -1 || payload.indexOf("NHAY") != -1 || payload.indexOf("nháy") != -1 || payload.indexOf("Nháy") != -1 || payload.indexOf("NHÁY") != -1){
    digitalWrite(D5, HIGH);
    delay(500);
    digitalWrite(D5, LOW);
    delay(500);
    http.end();  //Close connection
  }else if(payload.indexOf("cham") != -1 || payload.indexOf("Cham") != -1 || payload.indexOf("Chậm") != -1 || payload.indexOf("chậm") != -1 || payload.indexOf("CHẬM") != -1 || payload.indexOf("CHAM") != -1){
    digitalWrite(D5, HIGH);
    delay(1000);
    digitalWrite(D5, LOW);
    delay(1000);
    http.end();  //Close connection
  }else if(payload.indexOf("nhanh") != -1 || payload.indexOf("Nhanh") != -1 || payload.indexOf("NHANH")){
    digitalWrite(D5, HIGH);
    delay(50);
    digitalWrite(D5, LOW);
    delay(50);
    http.end();  //Close connection
  } 
  /* REQUEST GET TO WEB SITE */
}
