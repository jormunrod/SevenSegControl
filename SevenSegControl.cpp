#include "SevenSegControl.h"

SevenSegControl::SevenSegControl(int digitPins[], int segmentPins[], int numDigits) {
  _digitPins = digitPins;
  _segmentPins = segmentPins;
  _numDigits = numDigits;
  for (int i = 0; i < _numDigits; i++) {
    pinMode(_digitPins[i], OUTPUT);
  }
  for (int i = 0; i < 7; i++) { // Asumiendo 7 segmentos sin punto decimal
    pinMode(_segmentPins[i], OUTPUT);
  }
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
  // Implementa tu lógica para activar un dígito y mostrar un número aquí
}

void SevenSegControl::displayNumber(int number) {
  int digitPlace = 0;
  do {
    int digitValue = number % 10;
    displayDigit(digitPlace++, digitValue);
    number /= 10;
  } while (number > 0 && digitPlace < _numDigits);

  // Para asegurar que todos los dígitos se muestren por un tiempo visible antes de pasar al siguiente número
  delay(5);
}

// No olvides implementar las funciones para mostrar cada dígito (0-9) usando setNumber.
