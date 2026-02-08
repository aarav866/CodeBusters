#define DO_PIN 2   // Digital pin
#define AO_PIN 34  // Analog pin (ADC1_6)

void setup() {  
 Serial.begin(115200);
  pinMode(DO_PIN, INPUT);
}

void loop() {
  int digitalVal = digitalRead(DO_PIN);  // 0 = gas detected (low signal)
  int analogVal = analogRead(AO_PIN);    // 0-4095 (ESP32 12-bit ADC)
 
  Serial.print("Digital: ");
  Serial.print(digitalVal ? "Clean" : "GAS!");
  Serial.print(" | Analog: ");
  Serial.println(analogVal);
 
  delay(500);  // Preheat sensor 1-2 min on first run [web:2]
} 1`