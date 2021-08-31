// Declare Variables
const int SWITCH_PIN = 2;
const int MOTOR_PIN = 9;
int SwitchState = 0;

void setup()
{
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);
}

void loop() 
{
  SwitchState = digitalRead(SWITCH_PIN);

  if (SwitchState == HIGH)
  {
    digitalWrite(MOTOR_PIN, HIGH);
  }
  else
  {
    digitalWrite(MOTOR_PIN, LOW);
  }
}
