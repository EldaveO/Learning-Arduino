// Importing the Library
#include <Servo.h>
Servo MyServo;

// Declare Variables
int const POT_PIN = A0;
int PotVal;
int Angle;

void setup()
{
 MyServo.attach(9);
 Serial.begin(9600); 
}

void loop() 
{
 PotVal = analogRead(POT_PIN);
 Serial.print("PotVal: ");
 Serial.print(PotVal);
 Angle = map(PotVal, 0, 1023, 0, 179);
 Serial.print(", angle: ");
 Serial.println(Angle);
 MyServo.write(Angle);
 delay(15);
}
