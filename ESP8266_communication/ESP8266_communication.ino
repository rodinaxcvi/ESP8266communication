#include<ESP8266WiFi.h>

// Make sure to download the drivers that are on the back of your chip!

const char* ssid = ""; // Your Wi-Fi ssid
const char* password = ""; // Your Wi-Fi password


// I used a LED to light up with the ESP chip to show that everything was being 
// powered and working properly

int LedPin = 2;


void setup() {

  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin, LOW); 
  // Default baud rate
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  Serial.println();
  Serial.print("Connecting");

  while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println(".");
  }
  // Display ESP IP address
  Serial.print("ESP8266 IP Address:");
  Serial.print(WiFi.localIP());
}

void loop() {
  digitalWrite(LedPin, HIGH);
  delay(500);
  digitalWrite(LedPin, LOW);
  delay(500);
}