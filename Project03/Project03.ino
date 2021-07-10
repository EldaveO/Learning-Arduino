const int SENSOR_PIN = A0;
const float BASELINE_TEMPERATURE = 30.0;
int pinNumber = 0;

void setup() 
{
  Serial.begin(9600); // open a serial port
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop()
{
  int sensorVal = analogRead(SENSOR_PIN);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // covert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(" , Volts: ");
  Serial.print(voltage);
  Serial.print(" , degrees C: ");
  // convert the voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  if(temperature < BASELINE_TEMPERATURE)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= BASELINE_TEMPERATURE+2 && temperature < BASELINE_TEMPERATURE+4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= BASELINE_TEMPERATURE+4 && temperature < BASELINE_TEMPERATURE+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (temperature >= BASELINE_TEMPERATURE+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
}
