const int pinSwitch = 12; // Reed
const int pinRedLed = 11; // Red LED
const int pinGreenLed = 10; // Green LED
const int pinBuzzer = 9; // Buzzer

int StatoSwitch = 0;



void setup() {
	pinMode(pinSwitch, INPUT);
	pinMode(pinRedLed, OUTPUT);
	pinMode(pinGreenLed, OUTPUT);
	pinMode(pinBuzzer, OUTPUT);
}



void beepBuzzer() {
	int secondsCounted = 0;
	int secondsToWait = 30;

	// Wait N seconds before buzzing or exit if the switch closes within that timer limit
	while (secondsCounted < secondsToWait) {
		StatoSwitch = digitalRead(pinSwitch);
		
		if (StatoSwitch == LOW) {
			secondsCounted++;
			delay(1000);
		}
		else {
			return;
		}
	}

	// BEEP BEEP BEEP ... until the switch closes
	while (StatoSwitch == LOW) {
		tone(pinBuzzer, 250);
		delay(500);
		noTone(pinBuzzer);
		delay(500);

		StatoSwitch = digitalRead(pinSwitch);
	}
}



void loop() {
	StatoSwitch = digitalRead(pinSwitch);

	// Green LED when the switch is closed
	if (StatoSwitch == HIGH) {
		digitalWrite(pinGreenLed, HIGH);
		digitalWrite(pinRedLed, LOW);
		noTone(pinBuzzer);
	}

	// Red LED and beeping buzzer when the switch is open
	else {
		digitalWrite(pinGreenLed, LOW);
		digitalWrite(pinRedLed, HIGH);
		beepBuzzer();
	}
}
