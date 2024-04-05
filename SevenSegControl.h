#ifndef SevenSegControl_h
#define SevenSegControl_h

#include "Arduino.h"

class SevenSegControl {
public:
    SevenSegControl(int digitPins[], int segmentPins[], int numDigits, float updateFrequency);
    ~SevenSegControl();
    void displayNumber(int number);
private:
    int* _digitPins; // Puntero a un array que almacena los pines de los dígitos
    int* _segmentPins; // Puntero a un array que almacena los pines de los segmentos
    int _numDigits; // Número de dígitos en el display
    unsigned long _updateInterval; // Intervalo de actualización en microsegundos basado en la frecuencia
    void clean(); // Método para limpiar/apagar todos los segmentos
    void setNumber(uint8_t segments); // Método para establecer un número en los segmentos
    void displayDigit(int digit, int value); // Método para mostrar un dígito
};



#endif
