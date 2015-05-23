/* 

VU METER FOR ARDUINO
by 
Mebin Skaria
Version 002
This is suppose to emulate the job that a LM3915,6,7 would do.
plug your 10 leds from 2 digital pin to 11 digital pin
plug your analog sensor to A1
plug a button to A3, with it going from A3 to ground
and you have a fully functional VU METER.

*FEATURES 
adjustable incrementing level, change it to your sensor level
currently has line, will include dot in another version.
Automatic Max Adjuster
*/
void setup()
{
#define analogSensor A1 //Analog sensor
  int LED[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //LED PINS
  double readValue = 0; //intializing the value read by the sensor

  Serial.begin(9600);
  pinMode(analogSensor, INPUT_PULLUP);
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);
  pinMode(LED[6], OUTPUT);
  pinMode(LED[7], OUTPUT);
  pinMode(LED[8], OUTPUT);
  pinMode(LED[9], OUTPUT);

}
 int x = 0;
 int incrementing = 180;
void loop()
{
 
   //currently for my setup 200 works the best, go ahead and play around with this
  int readValue = analogRead(analogSensor);
  if(x < readValue)
  {
   x = readValue;
    int incrementing = x;
  } 
  Serial.print("MAX : ");
  Serial.println(x);
  Serial.println(readValue);
  if (readValue >= incrementing)
  {
    scale(11);
  }
  else if (readValue >= incrementing / 2)
  {
    scale(10);
  }
  else if (readValue >= incrementing / 3)
  {
    scale(9);
  }
  else if (readValue >= incrementing / 4)
  {
    scale(8);
  }
  else if (readValue >= incrementing / 5)
  {
    scale(7);
  }
  else if (readValue >= incrementing / 6)
  {
    scale(6);
  }
  else if (readValue >= incrementing / 7)
  {
    scale(5);
  }
  else if (readValue >= incrementing / 8)
  {
    scale(4);
  }
  else if (readValue >= incrementing / 9)
  {
    scale(3);
  }
  else if (readValue >= incrementing / 10)
  {
    scale(2);
  }
  else if (readValue >= incrementing / 11)
  {
    scale(1);
  }
  else
  {
    scale(0);
  }
  delay(20);
}

void scale(int p)
{
  int mode = 0;
  if (analogRead(A3) <= 50)
  { 
    if(mode == 0)
  {
   mode++; 
  }
  else
  {
   mode = 0;
  } 
  }
  if (mode == 0)
  {
    for (int i = 0; i < p; i++)
    {
      if (i + 2 == 3)
      {
        analogWrite(13, 1023);
      }
      digitalWrite(i + 2, HIGH);
    }

    for (int x = 10; x > p; x--)
    {

      digitalWrite(x + 1, LOW);
      if (x + 1 == 3)
        digitalWrite(13, LOW);
    }
    if (p == 0)
    {
      digitalWrite(2, LOW);
    }
  }
  else if (mode == 1)
  {
    for (int x = 10; x > p; x--)
    {

      digitalWrite(x + 1, LOW);
      if (x + 1 == 3)
        digitalWrite(13, LOW);
    }
    digitalWrite(p, HIGH);
  }


}

