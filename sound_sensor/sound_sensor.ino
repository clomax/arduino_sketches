int led_pins[5] = {8,7,6,5,4};
int values[5] = {};
int MAX_SND = 255;
float led_min_time_on = 100.0;
float leds_on[5] = {};

void setup()
{
    Serial.begin(9600);
    for(int i=0; i<5; i++)
    {
        pinMode(led_pins[i], OUTPUT);
        values[i] = MAX_SND / 6 * (i+1);
    }
}

void loop()
{
    int sensorValue = analogRead(A0);

    for(int i=0; i<5; i++)
    {
        if (sensorValue > values[i])
        {
            digitalWrite(led_pins[i], HIGH);
            leds_on[i] = millis();
        }

        if (leds_on[i] < millis() - led_min_time_on)
            digitalWrite(led_pins[i], LOW);
    }

    Serial.println(sensorValue);
    delay(30);
}
