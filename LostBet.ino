#include<Servo.h>

//declare pin number constants
const int LEFT_ESC = 10;
const int RIGHT_ESC = 5;
const int FORWARD_INPUT = A2;
const int TURN_INPUT = A3;

Servo leftMotor;
Servo rightMotor;

/*
 * set up the ports
 */
void setup(){
  // set up the ESCs
  leftMotor.attach(LEFT_ESC);
  rightMotor.attach(RIGHT_ESC);
  
  // input ports
  pinMode(FORWARD_INPUT, INPUT);
  pinMode(TURN_INPUT, INPUT);

  Serial.begin(9600);
}

/*
 * Drive with the joystick input
 */
void loop(){
  Serial.println(analogRead(FORWARD_INPUT));
  // control right motor
  if (analogRead(TURN_INPUT) > 1023/2 + 200 || analogRead(FORWARD_INPUT) > 1023/2 + 200)
    rightMotor.write(105);// right forward
  else if(digitalRead(FORWARD_INPUT) < 1023/2 - 200)
    rightMotor.write(80);// back
  else
    rightMotor.write(90);// stop
  // control left motor
  if (analogRead(TURN_INPUT) < 1023/2 - 200 || analogRead(FORWARD_INPUT) > 1023/2 + 200)
    leftMotor.write(80);// left forward
  else if(analogRead(FORWARD_INPUT) < 1023/2 - 200)
    leftMotor.write(100);// back
  else
    leftMotor.write(90);// stop
}

