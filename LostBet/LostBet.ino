#include<Servo.h>

//declare pin number constants
const int LEFT_ESC = 9;
const int RIGHT_ESC = 10;
const int FORWARD_INPUT = 1;
const int BACK_INPUT = 2;
const int LEFT_INPUT = 4;
const int RIGHT_INPUT = 5;

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
  pinMode(BACK_INPUT, INPUT);
  pinMode(LEFT_INPUT, INPUT);
  pinMode(RIGHT_INPUT, INPUT);
}

/*
 * Drive with the joystick input
 */
void loop(){
  // control right motor
  if (digitalRead(RIGHT_INPUT) == HIGH || (digitalRead(FORWARD_INPUT) == HIGH))
    rightMotor.write(0);// right forward
  else if(digitalRead(BACK_INPUT) == HIGH)
    rightMotor.write(180);// back
  else
    rightMotor.write(90);// stop
  // control left motor
  if (digitalRead (LEFT_INPUT) == HIGH || (digitalRead(FORWARD_INPUT) == HIGH))
    leftMotor.write(0);// left forward
  else if(digitalRead(BACK_INPUT == HIGH))
    leftMotor.write(180);// back
  else
    leftMotor.write(90);// stop
}

