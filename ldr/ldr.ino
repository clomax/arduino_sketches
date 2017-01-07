int led_pins[5] = {8,7,6,5,4};
int values[5] = {166, 322, 498, 664, 830};
const int MAX_LDR = 1000;

void setup()
{
    Serial.begin(9600);
    for(int i=0; i<5; i++)
    {
        pinMode(led_pins[i], OUTPUT);
    }
}

void loop()
{
    int sensorValue = analogRead(A3);

    // Reverse the lights: More light, more lights come on
    //sensorValue = map(sensorValue, 0, 1000, 1000, 0);

    Serial.println(sensorValue);

    for(int i=0; i<5; i++)
    {
        if (sensorValue > values[i])
            digitalWrite(led_pins[i], HIGH);
        else
            digitalWrite(led_pins[i], LOW);
    }

    delay(30);
}
