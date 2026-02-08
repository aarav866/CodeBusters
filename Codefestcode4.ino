#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Kathir_Tank";
const char* password = "12345678"; 

WebServer server(80);

// Motor pins
const int motorPin1 = 13; // L+
const int motorPin2 = 12; // L-
const int motorPin3 = 14; // R-
const int motorPin4 = 27; // R+


void forward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void back() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void left() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void right() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}


void setup() {
  Serial.begin(115200);

 
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  stopMotor();

  WiFi.softAP(ssid, password);
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.softAPIP());
 
  server.on("/forward", []() {
    forward();
    server.send(200, "text/plain", "Forward");
  });

  server.on("/backward", []() {
    back();
    server.send(200, "text/plain", "Backward");
  });

  server.on("/left", []() {
    left();
    server.send(200, "text/plain", "Left");
  });

  server.on("/right", []() {
    right();
    server.send(200, "text/plain", "Right");
  });

  server.on("/stop", []() {
    stopMotor();
    server.send(200, "text/plain", "Stop");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
