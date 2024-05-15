#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX but actually reversed

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(BTSerial.available() > 0) {
    Serial.println(BTSerial.read());
  }

}
