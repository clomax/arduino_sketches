int led_pins[5] = {8,7,6,5,4};
int values[5] = {};
const int MAX_LDR = 1024;

void setup()
{
    Serial.begin(9600);
    for(int i=0; i<5; i++)
    {
        pinMode(led_pins[i], OUTPUT);
        values[i] = MAX_LDR / 6 * (i+1);
    }
}

void loop()
{
    int sensorValue = analogRead(A3);

    for(int i=0; i<5; i++)
    {
        if (sensorValue > values[i])
            digitalWrite(led_pins[i], HIGH);
        else
            digitalWrite(led_pins[i], LOW);
    }

    Serial.println(sensorValue);
    delay(30);
}
