// Declare Constants
const int CONTROL_PIN_1 = 2;
const int CONTROL_PIN_2 = 3;
const int ENABLE_PIN = 9;
const int DIRECTION_SWITCH_PIN = 4;
const int ON_OFF_SWITCH_STATE_SWITCH_PIN = 5;
const int POT_PIN = A0;

// Declare switch state variables
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

// Declare motor variables
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
 pinMode(DIRECTION_SWITCH_PIN, INPUT);
 pinMode(ON_OFF_SWITCH_STATE_SWITCH_PIN, INPUT);
 pinMode(CONTROL_PIN_1, OUTPUT);
 pinMode(CONTROL_PIN_2, OUTPUT);
 pinMode(ENABLE_PIN, OUTPUT);
 digitalWrite(ENABLE_PIN, LOW);
}

void loop() {
  
  onOffSwitchState = digitalRead(ON_OFF_SWITCH_STATE_SWITCH_PIN);
  delay(1);
  directionSwitchState = digitalRead(DIRECTION_SWITCH_PIN);
  motorSpeed = analogRead(POT_PIN)/4;

  if(onOffSwitchState != previousDirectionSwitchState) {
    if(directionSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  if(directionSwitchState != previousDirectionSwitchState) {
    if(directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  
  if(motorDirection == 1) {
    digitalWrite(CONTROL_PIN_1, HIGH);
    digitalWrite(CONTROL_PIN_2, LOW);
   } 
  else {
    digitalWrite(CONTROL_PIN_1, LOW);
    digitalWrite(CONTROL_PIN_2, HIGH);
  }

  if(motorEnabled == 1){
    analogWrite(ENABLE_PIN, motorSpeed);
  }
  else {
    analogWrite(ENABLE_PIN, 0);
  }

   previousDirectionSwitchState = directionSwitchState;
   previousOnOffSwitchState = onOffSwitchState;
}
