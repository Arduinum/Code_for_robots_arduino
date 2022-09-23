#include <GyverTimers.h> // library for working with the timer
#include <SoftwareSerial.h> // include the library to create additional serial (Serial) ports
#include "motor.h" // functions for working with motors
#include "leds.h" // functions for working with LEDs
#include "case_bluetooth_robot.h" // code to control buttons

//Create a serial port on pins 10-read and 11-transmit
SoftwareSerial BTSerial(10, 11); // RX, TX

char bt_input; // variable for receiving data via Bluetooth

unsigned long _time; // stores the time of the last button press

void setup() {
	setup_motor_system(2, 3, 4, 5); // variables - pin numbers (pins) Arduino
	
	_stop(); // engines stopped
		
	setup_led(A1, A2); // analog pin numbers for LEDs
	
	BTSerial.begin(9600); // set baud rate for HC-05 (Bluetooth module)
	
	Serial.begin(9600); // set the baud rate on the cable
	_time = micros(); // time
	
	// Settings for the timer:
	Timer1.setPeriod(200000); // 200000 mcs
	Timer1.enableISR(CHANNEL_A);
}

void loop() {
	if (BTSerial.available()) {
		// Read the command and store it in a variable. char converts
		// Command character code to character.
		bt_input = (char)BTSerial.read();
		
		// Send a command to the port so we can
		// check them in the "Port Monitor".
		Serial.println(bt_input);
		
		move_case(bt_input); // Calling the action selection function by command
		_time = micros(); // time in mcs
	}

	if ((micros() - _time) >= _move_time) {
		_stop(); // stop all motors
	}

	if ((micros() - _time) >= 500) {
		_time = micros();
		move_case(bt_input); // wait for command
	}
}

// work with LEDs on a timer
ISR(TIMER1_A) {
	if (value_timer_1 == 1) {
		// both LEDs blink
		digitalWrite(Led_01, !digitalRead(Led_01));
		digitalWrite(Led_02, !digitalRead(Led_02));
	}

	if (value_timer_1 == 2) {
		// both LEDs are lit
		leds_on();
	}

	if (value_timer_1 == 3) {
		// both LEDs blink
		digitalWrite(Led_01, !digitalRead(Led_01));
		digitalWrite(Led_02, !digitalRead(Led_02));
	}

	if (value_timer_1 == 4) {
		// only the red LED blinks
		digitalWrite(Led_02, !digitalRead(Led_02));
	}

	if (value_timer_1 == 5) {
		// only the blue LED blinks
		digitalWrite(Led_01, !digitalRead(Led_01));
	}

	if (value_timer_1 == 6) {
		// only the red LED is on
		red_on();
	}

	if (value_timer_1 == 7) {
		// only blue LED is on
		blue_on();
	}

	if (value_timer_1 == 0) {
		Timer1.pause(); // turn off the timer
		leds_off(); // turn off the LEDs
	}
}
