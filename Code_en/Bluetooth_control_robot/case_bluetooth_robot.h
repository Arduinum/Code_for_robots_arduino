// Button configuration for Bluetooth RC Controller (android software)
unsigned long _move_time; // speed change variable.
int value_timer_1 = 0; // variable for timer mode
int value_led = 0; // variable for burning LEDs
char value_bl = 0; // variable to store the symbol of the pressed button
int buzzer = A5; // variable for piezo tweeter pin

// Choice of actions:
void move_case(char bt_input) {
	switch (bt_input) {
		// Forward
		case 'F':
			forward();
			if (value_led == 1 && value_bl != 'F') {
				Timer1.pause(); // stop the timer
				leds_off(); // turn off the LEDs
				value_timer_1 = 2; // both LEDs are lit
				Timer1.resume(); // restart the timer
				value_bl = 'F';
			}
			break;
		// Back
		case 'B':
			backward();
			if (value_led == 1 && value_bl != 'B') {
				Timer1.pause();
				leds_off();
				value_timer_1 = 3; // both LEDs blink the same
				leds_on();
				Timer1.resume();
				value_bl = 'B';
			}
			break;
		// Left
		case 'L':
			reversal_left();
			if (value_led == 1 && value_bl != 'L') {
				Timer1.pause();
				leds_off();
				value_timer_1 = 4; // flashing red_led
				red_on_only();
				Timer1.resume();
				value_bl = 'L';
			}
			break;
		// Right
		case 'R':
			reversal_right();
			if (value_led == 1 && value_bl != 'R') {
				Timer1.pause();
				leds_off();
				value_timer_1 = 5; // blue_led flashes
				blue_on_only();
				Timer1.resume();
				value_bl = 'R';
			}
			break;
		// Straight and left
		case 'G':
			forward_left(); 
			if (value_led == 1 && value_bl != 'G') {
				Timer1.pause();
				leds_off();
				value_timer_1 = 6; // red_led is on
				Timer1.resume();
				value_bl = 'G';
			}
			break;
		// Straight and right
		case 'I':
			forward_right();
			if (value_led == 1 && value_bl != 'I') {
				Timer1.pause();
				leds_off();
				value_timer_1 = 7; // blue_led is on
				Timer1.resume();
				value_bl = 'I'; 
			}
			break;
		// Back And Left
		case 'H':
			backward_left();
			if (value_led == 1 && value_bl != 'H') {
				Timer1.pause();
				leds_off();
				value_timer_1 = 6; // flashing red_led
				red_on_only();
				Timer1.resume();
				value_bl = 'H';
			}
			break;
		// Back And Right
		case 'J':
			backward_right();
			if (value_led == 1 && value_bl != 'J') {
				Timer1.pause();
				leds_off();
				value_timer_1 = 7; // blue_led flashes
				blue_on_only();
				Timer1.resume();
				value_bl = 'J'; 
			}
			break;
		// Stop
		case 'S':
			_stop();
			break;
		// Speed ​​0%
		case '0':
			_move_time = 0;
			break;
		// Speed ​​10%
		case '1':
			_move_time = 50;
			break;
		// Speed ​​20%
		case '2':
			_move_time = 100;
			break;
		// Speed ​​30%
		case '3':
			_move_time = 150;
			break;
		// Speed ​​40%
		case '4':
			_move_time = 200;
			break;
		// Speed ​​50%
		case '5':
			_move_time = 250;
			break;
		// Speed ​​60%
		case '6':
			_move_time = 300;
			break;
		// Speed ​​70%
		case '7':
			_move_time = 350;
			break;
		// Speed ​​80%
		case '8':
			_move_time = 400;
			break;
		// Speed ​​90%
		case '9':
			_move_time = 450;
			break;
		case 'q':
			_move_time = 500;
			break;
		case 'D':
			_stop();
			break;
		case 'U': // taillight button
			// turn on if other LED mode is off
			if (value_led == 0) {
				value_timer_1 = 1;
				blue_on(); // start position for LEDs
				Timer1.resume();
			}
			break;
		case 'u':
			// turn off if other LED mode is off
			if (value_led == 0) {
				value_timer_1 = 0;
			}
			break;
		case 'W': // headlight button
			// turn on if other LED mode is off
			if (value_timer_1 != 1) {
				value_led = 1;
			}
			break;
		case 'w':
			// turn off if other LED mode is off
			if (value_timer_1 != 1) {
				value_led = 0;
				value_timer_1 = 0;
				value_bl = 0;
			}
			break;
		case 'V': // enable beep
			tone(buzzer, 500); // turn on 500 Hz
			break;
		case 'v': // turn off the beep
			noTone(buzzer); // I keep sound
			break;
	}
}
