// Объявляем переменные для хранения состояния двух моторов.
int motor_L1, motor_L2;
int motor_R1, motor_R2;

// Функция инициализации управления моторами.
void setup_motor_system(int L1, int L2, int R1, int R2) {
	// Заносятся в переменные номера контактов (пинов) Arduino.
	motor_L1 = L1; motor_L2 = L2; // Для левых моторов
	motor_R1 = R1; motor_R2 = R2; // Для правых моторов

	// Переводятся указанные порты в состояние вывода данных.
	pinMode(motor_L1, OUTPUT);
	pinMode(motor_L2, OUTPUT);
	pinMode(motor_R1, OUTPUT);
	pinMode(motor_R2, OUTPUT);
}

// движение вперед.
void forward() {
	digitalWrite(motor_L2, HIGH);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, HIGH);
	digitalWrite(motor_R1, LOW);
}

// движение назад
void backward() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, HIGH);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, HIGH);
}

// Поворот налево с блокировкой левых колес.
void forward_left() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, HIGH);
	digitalWrite(motor_R1, LOW);
}

// Разворот на месте влево
void reversal_left() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, HIGH);
	digitalWrite(motor_R2, HIGH);
	digitalWrite(motor_R1, LOW);
}

// Поворот направо с блокировкой правых колес.
void forward_right() {
	digitalWrite(motor_L2, HIGH);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, LOW);
}

// Разворот на месте вправо
void reversal_right() {
	digitalWrite(motor_L2, HIGH);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, HIGH);
}

// Поворот налево с блокировкой левых колёс
void backward_left() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, HIGH);
}

// Поворот направо с блокировкой правых колёс
void backward_right() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, HIGH);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, LOW);
}

// Останавливаем все моторы
void _stop() {
	digitalWrite(motor_L2, LOW);
	digitalWrite(motor_L1, LOW);
	digitalWrite(motor_R2, LOW);
	digitalWrite(motor_R1, LOW);
}