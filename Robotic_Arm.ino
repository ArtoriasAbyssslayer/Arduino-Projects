#include <Servo.h>
Servo Servo1, Servo2, Servo3;
// Servo pins
#define pin1 3
#define pin2 4
#define pin3 5
// Servo angles
double angle1 = 90;
double angle2 = 90;
double angle3 = 90;
// Arm lengths
long length1 = 55; // mm
long length2 = 65; // mm

// Cartecian Values
long x = 120;
bool x_flag = 0;
long y = 0;
bool y_flag = 0;
long z = 0;
bool z_flag = 0;

void setup() {
  // Initializing Servos
  Servo1.attach(pin1,550,2450);
  Servo2.attach(pin2,550,2450);
  Servo3.attach(pin3,550,2450);
  // Initial arm position
  Servo1.write((int)angle1);
  Servo2.write((int)angle2);
  Servo3.write((int)angle3);
  // Serial communication
  Serial.begin(9600);
}

void loop() {
  if (readSerial()){
    execute();
  }
  if (x_flag==1 && y_flag==1 && z_flag==1){
    x_flag = 0;
    y_flag = 0;
    z_flag = 0;
    Serial.println("Moving arm to coordinates");
    MoveServos();
  }
}
