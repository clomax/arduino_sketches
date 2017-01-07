int red_pin = 11;
int grn_pin = 10;
int blu_pin = 9;

void setup()
{
	pinMode(red_pin, OUTPUT);
	pinMode(grn_pin, OUTPUT);
	pinMode(blu_pin, OUTPUT);
}

void loop()
{
	int i,j,k = 0;
	for(i=0; i<10; i++) {
		analogWrite(blu_pin, i*25);
		for(j=0; j<10; j++) {
			analogWrite(grn_pin, j*25);
			for(k=0; k<10; k++) {
				analogWrite(red_pin, k*25);
				delay(100);
			}
		}
	}
}

void setColour(int r, int g, int b)
{
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;

	analogWrite(red_pin, r);
	analogWrite(grn_pin, g);
	analogWrite(blu_pin, b);
}
