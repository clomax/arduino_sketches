#include <IRremote.h>
#include "remote_rgb.h"

int led[3] = {6,5,9};
int led_values[3] = {};
int selected_channel;

int rcv_pin = 11;
IRrecv irrecv(rcv_pin);
decode_results results;


void set_led_values(int r, int g, int b, int set)
{
    led_values[RED] = r;
    led_values[GRN] = g;
    led_values[BLU] = b;

    if(set)
        set_led(r,g,b);
}

void set_led(int r, int g, int b)
{
    analogWrite(led[RED], r);
    analogWrite(led[GRN], g);
    analogWrite(led[BLU], b);
}

void blink(int ch)
{
    set_led(OFF,OFF,OFF);

    int toggle_val = 230;
    for(int i=0; i<8; i++)
    {
        analogWrite(led[ch], toggle_val);
        toggle_val = (toggle_val == 230) ? OFF : 230;
        delay(50);
    }

    set_led(led_values[RED],led_values[GRN],led_values[BLU]);
}

void alter_channel(int ch, int value, int delta)
{
    if(selected_channel == -1)
    {
        Serial.println("Select a channel.");
        return;
    }

    int new_value = led_values[ch] + value;
    Serial.println(new_value);

    if (!(new_value <= 255 && new_value >= 0))
    {
        Serial.println("Out of range!");
        return;
    }

    switch(ch)
    {
        case RED:
            set_led_values(new_value, led_values[GRN], led_values[BLU], 1);
            break;

        case GRN:
            set_led_values(led_values[RED], new_value, led_values[BLU], 1);
            break;

        case BLU:
            set_led_values(led_values[RED], led_values[GRN], new_value, 1);
            break;
    }
}


void setup()
{
    Serial.begin(9600);

    pinMode(rcv_pin, INPUT);
    irrecv.enableIRIn();

    set_led_values(255, 255, 255, 1);
    selected_channel = -1;
}

void loop()
{
    if (irrecv.decode(&results))
    {
        irrecv.resume();
        Serial.println(results.value, HEX);

        switch(results.value)
        {
            case CH_MINUS:
                Serial.println("Red channel selected");
                selected_channel = RED;
                blink(RED);
                break;

            case CH:
                Serial.println("Green channel selected");
                selected_channel = GRN;
                blink(GRN);
                break;

            case CH_PLUS:
                Serial.println("Blue channel selected");
                selected_channel = BLU;
                blink(BLU);
                break;

            case VOL_DN:
                alter_channel(selected_channel, 20, 1);
                break;

            case VOL_UP:
                alter_channel(selected_channel, -20, 1);
                break;

            case _100:
                set_led_values(OFF,OFF,OFF,1);
                break;
        }
    }
}

