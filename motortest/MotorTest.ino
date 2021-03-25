// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor4(4);
AF_DCMotor motor1(1, MOTOR12_64KHZ);

void setup()
{
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor4.setSpeed(200);
  motor1.setSpeed(200);

  motor4.run(RELEASE);
  motor1.run(RELEASE);
}

void loop()
{
  uint8_t i;

  Serial.print("tick");

  motor4.run(FORWARD);
  motor1.run(FORWARD);
  for (i = 0; i < 255; i++)
  {
    Serial.println("Forward");
    motor4.setSpeed(i);
    motor1.setSpeed(i);
    delay(10);
  }

  for (i = 255; i != 0; i--)
  {
    motor4.setSpeed(i);
    motor1.setSpeed(i);
    delay(10);
  }

  Serial.print("tock");

  motor4.run(BACKWARD);
  motor1.run(BACKWARD);
  for (i = 0; i < 255; i++)
  {
    Serial.println("Backward");
    motor4.setSpeed(i);
    motor1.setSpeed(i);
    delay(10);
  }

  for (i = 255; i != 0; i--)
  {
    motor4.setSpeed(i);
    motor1.setSpeed(i);
    delay(10);
  }

  Serial.print("tech");
  motor4.run(RELEASE);
  motor1.run(RELEASE);
  delay(1000);
}
