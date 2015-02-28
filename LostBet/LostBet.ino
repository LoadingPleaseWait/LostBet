//declare pin number constants
const int LEFT_JAGUAR_SIGNAL= 3;
const int LEFT_JAGUAR_POWER = 3;
const int LEFT_JAGUAR_GROUND = 3;
const int RIGHT_JAGUAR_SIGNAL = 3;
const int RIGHT_JAGUAR_POWER = 3;
const int RIGHT_JAGUAR_GROUND = 3;
const int FORWARD_INPUT = 3;
const int BACK_INPUT = 3;
const int LEFT_INPUT = 3;
const int RIGHT_INPUT = 3;
const int BUTTON = 3;// push button under the seat when at the bottom of lift

/*
 * set up the ports
 */
void setup(){
  // output ports
  pinMode(LEFT_JAGUAR_SIGNAL, OUTPUT);
  pinMode(LEFT_JAGUAR_POWER, OUTPUT);
  pinMode(LEFT_JAGUAR_GROUND, OUTPUT);
  pinMode(RIGHT_JAGUAR_SIGNAL, OUTPUT);
  pinMode(RIGHT_JAGUAR_POWER, OUTPUT);
  pinMode(RIGHT_JAGUAR_GROUND, OUTPUT);
  
  // power is high voltage ground is low voltage
  digitalWrite(LEFT_JAGUAR_POWER, HIGH);
  digitalWrite(RIGHT_JAGUAR_POWER, HIGH);
  digitalWrite(LEFT_JAGUAR_GROUND, LOW);
  digitalWrite(RIGHT_JAGUAR_GROUND, LOW);
  
  // input ports
  pinMode(FORWARD_INPUT, INPUT);
  pinMode(BACK_INPUT, INPUT);
  pinMode(LEFT_INPUT, INPUT);
  pinMode(RIGHT_INPUT, INPUT);
  pinMode(BUTTON, INPUT);
}

/*
 * Drive with the joystick input
 */
void loop(){
  if(digitalRead(BUTTON) == LOW)
    return;// don't do anything when the seat isn't at the bottom
  // control right motor
  if (digitalRead(RIGHT_INPUT) == HIGH || (digitalRead(FORWARD_INPUT) == HIGH))
    analogWrite(RIGHT_JAGUAR_SIGNAL, intToSignedByte(127));
  else if(digitalRead(BACK_INPUT) == HIGH)
    analogWrite(RIGHT_JAGUAR_SIGNAL, intToSignedByte(-128));
  else
    analogWrite(RIGHT_JAGUAR_SIGNAL, intToSignedByte(0));
  // control left motor
  if (digitalRead (LEFT_INPUT) == HIGH || (digitalRead(FORWARD_INPUT) == HIGH))
    analogWrite(LEFT_JAGUAR_SIGNAL, intToSignedByte(127));
  else if(digitalRead(BACK_INPUT == HIGH))
    analogWrite(LEFT_JAGUAR_SIGNAL, intToSignedByte(-128));
  else
    digitalWrite (LEFT_JAGUAR_SIGNAL, intToSignedByte(0));
}

/*
 * Convert a signed integer to a signed byte
 */
byte intToSignedByte(int number){
  if(number < 0){
    return 256 - number;
  }else{
    return number;
  }
}
