int Led_01, Led_02;

void setup_led(int Blue, int Red) {
	Led_01 = Blue;
	Led_02 = Red;

	// LED pin modes per output
	pinMode(Led_01, OUTPUT);
	pinMode(Led_02, OUTPUT);
}

void leds_on() {
	// both LEDs are on
	digitalWrite(Led_01, HIGH);
	digitalWrite(Led_02, HIGH);
}

void leds_off() {
	// both LEDs are off
	digitalWrite(Led_01, LOW);
	digitalWrite(Led_02, LOW);
}

void blue_on() {
	// only the blue LED is on, the red one is off
	digitalWrite(Led_01, HIGH);
	digitalWrite(Led_02, LOW);
}

void red_on() {
	// only the red LED is on, the blue one is off
	digitalWrite(Led_01, LOW);
	digitalWrite(Led_02, HIGH);
}

void blue_on_only() {
	// blue LED on
	digitalWrite(Led_01, HIGH);
}

void red_on_only() {
	// red LED on
	digitalWrite(Led_02, HIGH);
}