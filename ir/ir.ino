int ir_send_pin = 5;
int ir_recv_pin = 8;
int recv_led_pin = 3;

void setup()
{
	Serial.begin(9600);
	pinMode(ir_send_pin, OUTPUT);
	pinMode(ir_recv_pin, INPUT);
	pinMode(recv_led_pin, OUTPUT);
}

void loop()
{
	for(int i=0; i<100; i++)
	{
		digitalWrite(ir_send_pin, HIGH);
		digitalWrite(recv_led_pin, HIGH);
		delayMicroseconds(13);
		digitalWrite(ir_send_pin, LOW);
		digitalWrite(recv_led_pin, LOW);
		delayMicroseconds(13);
		Serial.println("fdjkgh");
	}

	digitalWrite(ir_send_pin, LOW);
	digitalWrite(recv_led_pin, LOW);
	delay(500);
}
