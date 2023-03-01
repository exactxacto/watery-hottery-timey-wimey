#include <Arduino.h>
#include <Servo.h>

Servo myservo;
int pos = 0;
int timer;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
Serial.begin(9600);
myservo.write (0);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0);
  timer = Serial.parseInt();
  Serial.println(timer);
      delay(timer*1000);
      Serial.println("waiting");
      myservo.write (180);

}