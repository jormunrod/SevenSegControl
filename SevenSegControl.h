#ifndef SevenSegControl_h
#define SevenSegControl_h

#include "Arduino.h"

class SevenSegControl {
  public:
    SevenSegControl(int digitPins[], int segmentPins[], int numDigits);
    void displayNumber(int number);
  private:
    int* _digitPins;
    int* _segmentPins;
    int _numDigits;
    void clean();
    void setNumber(uint8_t segments);
    void displayDigit(int digit, int value);
};

#endif
