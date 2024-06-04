#include <Servo.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

const byte rxPin = 12;
const byte txPin = 13;
SoftwareSerial bluetooth(rxPin, txPin); //rx - tx

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;



JsonDocument values;

void setup()  
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  
}


void loop()
{ 
    
  
  deserializeJson(values, bluetooth);
  int servo1_pos = values["servo1pos"];
  int servo2_pos = values["servo2pos"];
  int servo3_pos = values["servo3pos"];
  int servo4_pos = values["servo4pos"];
  int servo5_pos = values["servo5pos"];

  servo1.write(servo1_pos);
  servo2.write(servo2_pos);
  servo3.write(servo3_pos);
  servo4.write(servo4_pos);
  servo5.write(servo5_pos);

  Serial.print(servo1_pos);
  Serial.print("--");
  Serial.print(servo2_pos);
  Serial.print("--");
  Serial.print(servo3_pos);
  Serial.print("--");
  Serial.print(servo4_pos);
  Serial.print("--");
  Serial.print(servo5_pos);
  Serial.println(" ");  
  

}