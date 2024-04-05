#ifndef SevenSegControl_h
#define SevenSegControl_h

#include "Arduino.h"

class SevenSegControl {
public:
    SevenSegControl(int digitPins[], int segmentPins[], int numDigits, float updateFrequency);
    ~SevenSegControl();
    void displayNumber(int number);
private:
    int* _digitPins;
    int* _segmentPins;
    int _numDigits;
    unsigned long _updateInterval;
    void clean();
    void setNumber(uint8_t segments);
    void displayDigit(int digit, int value);
};


#endif
