// Importing the Library
#include <Servo.h>
Servo MyServo;

// Declare Variables
int const POT_PIN = A0;
//int PotVal;
int RotVal;
int Angle;

void setup()
{
 MyServo.attach(9);
 Serial.begin(9600);
 RotVal = 0; 
}

void loop() 
{
 //PotVal = analogRead(POT_PIN);
 //Serial.print("PotVal: ");
 //Serial.print(PotVal);
 //Angle = map(PotVal, 0, 1023, 0, 179);
 for (int RotVal = 0; RotVal <= 1023; RotVal++)
  {
    Angle = map (RotVal, 0, 1023, 0, 179);
    Serial.print("Angle: ");
    Serial.print(Angle);
    Serial.print("  RotVal: ");
    Serial.println(RotVal);
    MyServo.write(Angle);
    delay(100);  
  }
 if (RotVal == 1023)
  {
   RotVal = 0; 
  }
}
