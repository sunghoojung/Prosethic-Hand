#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX but actually reversed

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  BTSerial.write(123);
  delay(1000);
}
