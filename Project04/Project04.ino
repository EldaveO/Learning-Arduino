// Declaring all the variables
const int GREEN_LED_PIN = 11;
const int RED_LED_PIN = 9;
const int BLUE_LED_PIN = 10;

const int GREEN_SENSOR_PIN = A1;
const int RED_SENSOR_PIN = A0;
const int BLUE_SENSOR_PIN = A2;

int RedValue = 0;
int GreenValue = 0;
int BlueValue = 0;

int RedSensorValue = 0;
int GreenSensorValue = 0;
int BlueSensorValue =0;

void setup()
{
  Serial.begin(9600);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() 
{
  RedSensorValue = analogRead(RED_SENSOR_PIN);
  delay(50);
  GreenSensorValue = analogRead(GREEN_SENSOR_PIN);
  delay(50);
  BlueSensorValue = analogRead(BLUE_SENSOR_PIN);

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

  analogWrite(RED_LED_PIN, RedValue);
  analogWrite(GREEN_LED_PIN, GreenValue);
  analogWrite(BLUE_LED_PIN, BlueValue);
}
