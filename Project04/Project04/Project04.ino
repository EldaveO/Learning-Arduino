// Declaring all the variables
const int GreenLEDPin = 9;
const int RedLEDPin = 11;
const int BlueLEDPin = 10;

const int RedSensorPin = A0;
const int GreenSensorPin = A1;
const int BlueSensorPin = A2;

int RedValue = 0;
int GreenValue = 0;
int BlueValue = 0;

int RedSensorValue = 0;
int GreenSensorValue = 0;
int BlueSensorValue =0;

void setup()
{
  Serial.begin(9600);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
  pinMode(BlueLEDPin, OUTPUT);
}

void loop() 
{
  RedSensorValue = analogRead(RedSensorPin);
  delay(5);
  GreenSensorValue = analogRead(GreenSensorPin);
  delay(5);
  BlueSensorValue = analogRead(BlueSensorPin);

  Serial.print("Raw Sensor Values /t Red: ");
  Serial.print(RedSensorValue);
  Serial.print("/t Green: ");
  Serial.print(GreenSensorValue);
  Serial.print("/t Blue: ");
  Serial.println(BlueSensorValue);
  
  
}
