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
}

/*
 * Drive with the joystick input
 */
void loop(){
  
}
