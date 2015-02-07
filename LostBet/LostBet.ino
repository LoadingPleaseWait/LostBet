//declare pin number constants
const int JAGUAR_SIGNAL= 3;
const int JAGUAR_POWER = 3;
const int JAGUAR_GROUND = 3;
const int FORWARD_INPUT = 3;
const int BACK_INPUT = 3;
const int LEFT_INPUT = 3;
const int RIGHT_INPUT = 3;

/*
 * set up the ports
 */
void setup(){
  // output ports
  pinMode(JAGUAR_SIGNAL, OUTPUT);
  pinMode(JAGUAR_POWER, OUTPUT);
  pinMode(JAGUAR_GROUND, OUTPUT);
  
  // power is 5V ground is 0V
  digitalWrite(JAGUAR_POWER, HIGH);
  digitalWrite(JAGUAR_GROUND, LOW);
  
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
