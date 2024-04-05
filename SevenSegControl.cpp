#include "SevenSegControl.h"

const uint8_t NUMBER_PATTERNS[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

SevenSegControl::SevenSegControl(int digitPins[], int segmentPins[], int numDigits, float updateFrequency) {
  _numDigits = numDigits;
  _digitPins = new int[numDigits];
  _segmentPins = new int[7];

  for (int i = 0; i < numDigits; i++) {
    _digitPins[i] = digitPins[i];
    pinMode(digitPins[i], OUTPUT);
  }

  for (int i = 0; i < 7; i++) {
    _segmentPins[i] = segmentPins[i];
    pinMode(segmentPins[i], OUTPUT);
  }

  _updateInterval = static_cast<unsigned long>((1.0 / updateFrequency) * 1000000);
}


SevenSegControl::~SevenSegControl() {
  delete[] _digitPins;
  delete[] _segmentPins;
}

void SevenSegControl::clean() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(_segmentPins[i], LOW);
  }
}

void SevenSegControl::setNumber(uint8_t segments) {
  clean();
  for (int i = 0; i < 7; i++) {
    digitalWrite(_segmentPins[i], segments & (1 << i) ? HIGH : LOW);
  }
}

void SevenSegControl::displayDigit(int digit, int value) {
  for (int i = 0; i < _numDigits; i++) {
    digitalWrite(_digitPins[i], HIGH); // Apaga todos los dígitos primero
  }
  digitalWrite(_digitPins[digit], LOW); // Activa el dígito actual
  setNumber(NUMBER_PATTERNS[value]);
  //delay(5); // Ajusta este valor según sea necesario
}

void SevenSegControl::displayNumber(int number) {
    int firstDigit = number / 10 % 10;
    int secondDigit = number % 10;

    unsigned long currentMicros = micros();
    static unsigned long previousMicros = 0;

    if (currentMicros - previousMicros >= _updateInterval) {
        previousMicros = currentMicros;

        static bool toggle = false;
        if (toggle) {
            displayDigit(0, firstDigit); // Muestra el primer dígito
        } else {
            displayDigit(1, secondDigit); // Muestra el segundo dígito
        }
        toggle = !toggle;
    }
}
