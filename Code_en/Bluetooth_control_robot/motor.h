// Declare variables to store the state of the two motors.
int motor_L1, motor_L2;
int motor_R1, motor_R2;

// Motor control initialization function.
void setup_motor_system(int L1, int L2, int R1, int R2) {
	// Entered into variable numbers of pins (pins) of the Arduino.
	motor_L1 = L1; motor_L2 = L2; // For left motors
	motor_R1 = R1; motor_R2 = R2; // For right motors

	// Set the specified ports to the data output state.
	pinMode(motor_L1, OUTPUT);
	pinMode(motor_L2, OUTPUT);
	pinMode(motor_R1, OUTPUT);
	pinMode(motor_R2, OUTPUT);
}

// forward movement.
void forward() {
	digitalWrite(motor_L2, HIGH);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, HIGH);
	digitalWrite(motor_R1, LOW);
}

// move backwards
void backward() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, HIGH);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, HIGH);
}

// Turn left with the left wheels locked.
void forward_left() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, HIGH);
	digitalWrite(motor_R1, LOW);
}

// Turn in place to the left
void reversal_left() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, HIGH);
	digitalWrite(motor_R2, HIGH);
	digitalWrite(motor_R1, LOW);
}

// Turn right with the right wheels locked.
void forward_right() {
	digitalWrite(motor_L2, HIGH);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, LOW);
}

// Turn in place to the right
void reversal_right() {
	digitalWrite(motor_L2, HIGH);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, HIGH);
}

// Turn left with left wheel lock
void backward_left() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, HIGH);
}

// Turn right with right wheels locked
void backward_right() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, HIGH);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, LOW);
}

// Stop all motors
void _stop() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, LOW);
}