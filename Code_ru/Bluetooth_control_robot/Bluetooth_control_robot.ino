#include <GyverTimers.h> // библиотека для работы с таймером
#include <SoftwareSerial.h> // подключаем библиотеку для создания дополнительных последовательных (Serial) портов
#include "motor.h" // функции для работы с моторами
#include "leds.h" // функции для рабьоты со светодиодами
#include "case_bluetooth_robot.h" // код для управления кнопками

//Создаем последовательный порт на пинах 10-чтение и 11-передача
SoftwareSerial BTSerial(10, 11); // RX, TX

char bt_input; // переменная для приема данных по Bluetooth

unsigned long _time; // хранит время последнего нажатия кнопки

void setup() {
	setup_motor_system(2, 3, 4, 5); // переменные – номера контактов (пинов) Arduino
	
	_stop(); // двигатели остановлены
		
	setup_led(A1, A2); // номира аналоговых пинов для светодиодов
	
	BTSerial.begin(9600); // устанавливаем скорость передачи данных для НС-05 (Bluetooth-модуль)
	
	Serial.begin(9600); // устанавливаем скорость передачи данных по кабелю
	_time = micros(); // время
	
	// Настройки для таймера:
	Timer1.setPeriod(200000); // 200000 мкс
	Timer1.enableISR(CHANNEL_A);
}

void loop() {
	if (BTSerial.available()) {
		// Читаем команду и заносим ее в переменную. char преобразует
		// Код символа команды в символ.
		bt_input = (char)BTSerial.read();
		
		// Отправляем команду в порт, чтобы можно было
		// их проверить в "Мониторе порта".
		Serial.println(bt_input);
		
		move_case(bt_input); // Вызов функции выбора действия по команде
		_time = micros(); // время в мкс
	}

	if ((micros() - _time) >= _move_time) {
		_stop(); // останавливаем все моторы
	}

	if ((micros() - _time) >= 500) {
		_time = micros();
		move_case(bt_input); // ждём команду
	}
}

// работаем со светодиодами по таймеру
ISR(TIMER1_A) {
	if (value_timer_1 == 1) {
		// мигают оба светодиода
		digitalWrite(Led_01, !digitalRead(Led_01));
		digitalWrite(Led_02, !digitalRead(Led_02));
	}

	if (value_timer_1 == 2) {
		// горят оба светодиода
		leds_on();
	}

	if (value_timer_1 == 3) {
		// мигают оба светодиода
		digitalWrite(Led_01, !digitalRead(Led_01));
		digitalWrite(Led_02, !digitalRead(Led_02));
	}

	if (value_timer_1 == 4) {
		// мигает только красный светодиод 
		digitalWrite(Led_02, !digitalRead(Led_02));
	}

	if (value_timer_1 == 5) {
		// мигает только синий светодиод
		digitalWrite(Led_01, !digitalRead(Led_01));
	}

	if (value_timer_1 == 6) {
		// горит только красный светодиод
		red_on();
	}

	if (value_timer_1 == 7) {
		// горит только синий светодиод
		blue_on();
	}

	if (value_timer_1 == 0) {
		Timer1.pause(); // выключаем таймер
		leds_off(); // выключаем светодиоды
	}
}