int Led_01, Led_02;

void setup_led(int Blue, int Red) {
	Led_01 = Blue;
	Led_02 = Red;

	// режимы пинов светодиодов на выход
	pinMode(Led_01, OUTPUT);
	pinMode(Led_02, OUTPUT);
}

void leds_on() {
	// оба светодиода включены
	digitalWrite(Led_01, HIGH);
	digitalWrite(Led_02, HIGH);
}

void leds_off() {
	// оба светодиода выключены
	digitalWrite(Led_01, LOW);
	digitalWrite(Led_02, LOW);
}

void blue_on() {
	// включен только синий светодиод, а красный выключен
	digitalWrite(Led_01, HIGH);
	digitalWrite(Led_02, LOW);
}

void red_on() {
	// включен только красный светодиод, а синий выключен
	digitalWrite(Led_01, LOW);
	digitalWrite(Led_02, HIGH);
}

void blue_on_only() {
	// включен синий светодиод
	digitalWrite(Led_01, HIGH);
}

void red_on_only() {
	// включен красный светодиод
	digitalWrite(Led_02, HIGH);
}