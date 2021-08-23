// Declare Variables
int Buttons[6]; //Set up an array with 6 integers
int Notes[] = {262, 294, 330, 349};

void setup()
{
  Buttons[0] = 2; //Give the first element of the array the value of 2
  Serial.begin(9600);
}

void loop() 
{
  int KeyVal = analogRead(A0);
  Serial.println(KeyVal);
  
  if (KeyVal == 1023)
  {
    tone(8, Notes[0]);
  }
  else if(KeyVal >= 990 && KeyVal <= 1010)
  {
    tone(8, Notes[1]);
  }
  else if(KeyVal >= 505 && KeyVal <= 515)
  {
    tone(8, Notes[2]);
  }
  else if(KeyVal >= 5 && KeyVal <= 10)
  {
    tone(8, Notes[3]);
  }
  else
  {
    noTone(8);
  }
}
