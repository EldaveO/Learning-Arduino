// Declare Variables
int SensorValue;
int SensorLow = 1023;
int SensorHigh = 0;
const int LED_PIN = 13;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  while (millis() < 5000)
  {
    SensorValue = analogRead(A0);
    if (SensorValue > SensorHigh)
    {
      SensorHigh = SensorValue; 
    }
    if (SensorValue < SensorLow)
    {
      SensorLow = SensorValue;
    }
  }
  digitalWrite(LED_PIN, LOW);
}

void loop() 
{
  SensorValue = analogRead(A0);
  int pitch = map(SensorValue, SensorLow, SensorHigh, 50, 400);
  tone(8, pitch, 20);
  delay(10);
}
