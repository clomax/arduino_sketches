int brightness = 0;
int fadeAmount = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}

void loop()
{
  analogWrite(11, brightness);
  brightness += fadeAmount;
  Serial.println(brightness);

  if (brightness == 0 || brightness == 255)
  {
    fadeAmount = fadeAmount * -1;
  }

  delay(30);
}

