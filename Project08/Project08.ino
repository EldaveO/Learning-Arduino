// Declare Variables
const int SWITCH_PIN = 8;
unsigned long PreviousTime = 0;
int SwitchState = 0;
int PrevSwitchState = 0;
int Led = 2;
long INTERVAL = 6000;

void setup()
{
  for(int x = 2; x < 8; x++)
  {
    pinMode(x, OUTPUT);
  }
  pinMode(SWITCH_PIN, INPUT);
}

void loop() 
{
  unsigned long CurrentTime = millis();
  if(CurrentTime - PreviousTime > INTERVAL)
  {
    PreviousTime = CurrentTime;
    digitalWrite(Led, HIGH);
    Led++;
    if(Led == 7)
    {
    }
    SwitchState = digitalRead(SWITCH_PIN);
    if(SwitchState != PrevSwitchState)
    {
      for(int x = 2; x < 8; x++)
      {
        digitalWrite(x, LOW);
      }
      Led = 2;
      PreviousTime = CurrentTime;
    }
    PrevSwitchState = SwitchState;      
    }
}
