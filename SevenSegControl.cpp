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
    static unsigned long lastUpdate = 0;
    unsigned long currentMicros = micros();
    
    if (currentMicros - lastUpdate >= _updateInterval) {
        lastUpdate = currentMicros;

        static int currentDigitIndex = 0; // Índice para recorrer los dígitos
        
        // Calcula el valor para el dígito actual ajustado para mostrar de derecha a izquierda
        int positionFromRight = _numDigits - 1 - currentDigitIndex; // Ajusta el índice basado en el número total de dígitos
        int digitValue = (number / (int)pow(10, positionFromRight)) % 10;
        
        // Apaga todos los dígitos antes de encender el actual
        for (int i = 0; i < _numDigits; i++) {
            digitalWrite(_digitPins[i], HIGH); // Suponiendo cátodo común
        }
        
        // Enciende el dígito actual
        digitalWrite(_digitPins[currentDigitIndex], LOW);
        
        // Muestra el valor en el dígito activo
        setNumber(NUMBER_PATTERNS[digitValue]);
        
        // Prepara el índice para el siguiente dígito en la próxima actualización
        currentDigitIndex = (currentDigitIndex + 1) % _numDigits;
    }
}



