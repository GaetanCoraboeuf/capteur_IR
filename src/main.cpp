#include <Arduino.h>

#define IR_PIN 14

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Capteur IR");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Capteur IR: %d\n", analogRead(IR_PIN));
  delay(100);
}

