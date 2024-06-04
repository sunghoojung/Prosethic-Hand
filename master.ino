#include <Servo.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>


const byte rxPin = 3;
const byte txPin = 2;
SoftwareSerial bluetooth(rxPin, txPin);  //rx - tx

int flex1 = A0;
int flex2 = A1;
int flex3 = A2;
int flex4 = A3;
int flex5 = A4;

JsonDocument values;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  delay(1000);  // Wait for HC-05 module to initialize
}


void loop() {
  int flex1_pos;
  int servo1_pos;

  flex1_pos = analogRead(flex1);
  servo1_pos = map(flex1_pos, 840, 900, 0, 180);
  servo1_pos = constrain(servo1_pos, 0, 180);
  values["servo1pos"] = servo1_pos;

  int flex2_pos;
  int servo2_pos;

  flex2_pos = analogRead(flex2);
  servo2_pos = map(flex2_pos, 840, 900, 0, 180);
  servo2_pos = constrain(servo2_pos, 0, 180);
  values["servo2pos"] = servo2_pos;

  int flex3_pos;
  int servo3_pos;

  flex3_pos = analogRead(flex3);
  servo3_pos = map(flex3_pos, 840, 900, 0, 180);
  servo3_pos = constrain(servo3_pos, 0, 180);
  values["servo3pos"] = servo3_pos;

  
  int flex4_pos;
  int servo4_pos;

  flex4_pos = analogRead(flex4);
  servo4_pos = map(flex4_pos, 840, 900, 0, 180);
  servo4_pos = constrain(servo4_pos, 0, 180);
  values["servo4pos"] = servo4_pos;


  int flex5_pos;
  int servo5_pos;

  flex5_pos = analogRead(flex5);
  servo5_pos = map(flex5_pos, 1000, 900, 0, 180);
  servo5_pos = constrain(servo5_pos, 0, 180);
  values["servo5pos"] = servo5_pos;


  serializeJson(values, bluetooth);

  
  Serial.println("--");
  Serial.print(flex1_pos);
  Serial.print("--");
  Serial.print(flex2_pos);
  Serial.print("--");
  Serial.print(flex3_pos);
  Serial.print("--");
  Serial.print(flex4_pos);
  Serial.print("--");
  Serial.print(flex5_pos);
  Serial.println("--");

  
  
}