#include <Servo.h>
#include <JeeLib.h> // Low power functions library

Servo servo;
int servoValue;
int maxServo;
int minServo;
ISR(WDT_vect) { Sleepy::watchdogEvent(); } // Setup the watchdog

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
    Sleepy::loseSomeTime(1000);
  } else {
    Sleepy::loseSomeTime(5000);
  }

}
