int led[3] = {9,10,11};
int values[3];

void setup()
{
	Serial.begin(9600);

	pinMode(led[0], OUTPUT);
	pinMode(led[1], OUTPUT);
	pinMode(led[2], OUTPUT);
}

void loop()
{
	getInputs(values);
	setColours(values);

	delay(50);
}

void getInputs(int* values)
{
	values[0] = analogRead(A0);
	values[1] = analogRead(A1);
	values[2] = analogRead(A2);
}

void setColours(int* values)
{
	for(int i=0; i<3; i++)
	{
		int v = map(values[i], 0, 1024, 0, 256);
		Serial.println(v);
		analogWrite(led[i], v);
	}
	Serial.println("\n");
}
