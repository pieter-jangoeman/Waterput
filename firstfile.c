#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
  
// Set WiFi credentials
#define WIFI_SSID "The Lanpire strikes back"
#define WIFI_PASS "TheGreatHanSolo"
#define UDP_PORT 4210
int count = 5;
 
// UDP
WiFiUDP UDP;
char packet[255];
char reply[] = "Packet received!";
  
void setup() {
  // Setup serial port
  Serial.begin(115200);
  Serial.println();
  
  // Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  // Connecting to WiFi...
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  // Loop continuously while WiFi is not connected
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  
  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
 
  // Begin listening to UDP port
  UDP.begin(UDP_PORT);
  Serial.print("Listening on UDP port ");
  Serial.println(UDP_PORT);
  
}
 
void loop() {
 
    UDP.beginPacket("192.168.0.20", 4210);
    UDP.write(1);
    UDP.endPacket();
    count = count+1;
    delay(1000); 
}
