#include <Servo.h>

Servo servo;
int servoValue;
int maxServo;
int minServo;
// the setup routine runs once when you press reset:
void setup() {                   
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  servo.attach(A5); // analog pin 5
  servoValue = 0;
  maxServo = 18;
  minServo = 0;
  Serial.println("Ready");
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  if (sensorValue < 600){
    Serial.println(sensorValue);
    if (servoValue == minServo){
      servoValue = maxServo;
      servo.write(servoValue);
      Serial.println(servoValue);
    } else {
      servoValue = minServo;
      servo.write(servoValue);
      Serial.println(servoValue);
    }
    delay(1000);
  }
  delay(20);

}
