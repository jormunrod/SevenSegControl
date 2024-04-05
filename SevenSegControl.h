/**
 * @file SevenSegControl.h
 * @brief Library for controlling multiplexed 7-segment displays on Arduino.
 * 
 * This library allows easy control of multiplexed 7-segment LED displays using
 * Arduino. It supports displays with 1 to 4 digits and allows specifying the
 * update frequency for the display refresh.
 * 
 * @author jormunrod
 * @date 2024-04-05
 * 
 * @version 1.0
 * @note This library is designed for common cathode 7-segment displays.
 * 
 */

#ifndef SevenSegControl_h
#define SevenSegControl_h

#include "Arduino.h"

class SevenSegControl {
public:
    /**
     * Constructor for the SevenSegControl class.
     * Initializes a new instance for controlling a 7-segment display.
     * 
     * @param digitPins Array of pins connected to the digits of the display.
     * @param segmentPins Array of pins connected to the segments of the display (A-G).
     * @param numDigits Number of digits in the display.
     * @param updateFrequency Frequency (in Hz) at which the display is refreshed.
     */
    SevenSegControl(int digitPins[], int segmentPins[], int numDigits, float updateFrequency);
    
    /**
     * Destructor for the SevenSegControl class.
     * Cleans up resources by deleting dynamically allocated pin arrays.
     */
    ~SevenSegControl();
    
    /**
     * Displays an integer number on the 7-segment display.
     * The number is displayed according to the set update frequency,
     * ensuring all digits are updated for consistent viewing.
     * 
     * @param number The integer number to display. If the number has more digits
     * than the display, only the least significant digits that fit will be shown.
     */
    void displayNumber(int number);
private:
    int* _digitPins; // Pointer to an array storing the digit pins.
    int* _segmentPins; // Pointer to an array storing the segment pins.
    int _numDigits; // Number of digits in the display.
    unsigned long _updateInterval; // Time interval (in microseconds) for updating the display.
    
    /**
     * Turns off all segments of the display.
     * This method is used before setting a new number to ensure a clean update.
     */
    void clean();
    
    /**
     * Sets the segments of the display to represent a specific number.
     * 
     * @param segments Bitmask representing which segments should be turned on
     * to display a specific digit.
     */
    void setNumber(uint8_t segments);
    
    /**
     * Displays a single digit at a specified position.
     * 
     * @param digit Index of the digit to display (starting from 0).
     * @param value The value of the digit to display.
     */
    void displayDigit(int digit, int value);
};

#endif
