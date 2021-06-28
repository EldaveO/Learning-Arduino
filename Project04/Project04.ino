// Declaring all the variables
const int GreenLEDPin = 11;
const int RedLEDPin = 9;
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
  delay(50);
  GreenSensorValue = analogRead(GreenSensorPin);
  delay(50);
  BlueSensorValue = analogRead(BlueSensorPin);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(RedSensorValue);
  Serial.print("\t Green: ");
  Serial.print(GreenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(BlueSensorValue);
  
  RedValue = RedSensorValue/4;
  GreenValue = GreenSensorValue/4;
  BlueValue = BlueSensorValue/4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(RedValue);
  Serial.print("\t Green: ");
  Serial.print(GreenValue);
  Serial.print("\t Blue: ");
  Serial.println(BlueValue);

  analogWrite(RedLEDPin, RedValue);
  analogWrite(GreenLEDPin, GreenValue);
  analogWrite(BlueLEDPin, BlueValue);
}
