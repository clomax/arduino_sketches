float pwr_voltage = 5;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	float temperature;
	float sensorValue = analogRead(A0);
	Serial.print("Temp: ");
	Serial.println(temperature,1);
	delay(10);
}
