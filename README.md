# SevenSegControl Library

The `SevenSegControl` library allows easy control of multiplexed 7-segment LED displays using Arduino. It supports displays with 1 to 4 digits and enables specifying the update frequency for refreshing the display to minimize flickering.

## Features

- Support for common cathode and common anode 7-segment displays.
- Dynamic adjustment of the display update frequency.
- Support for displaying integers across multiple digits.
- Easy to use with a straightforward interface.

## Installation

To install this library, download the ZIP archive and extract it to the "libraries" folder in your Arduino sketchbook directory. Then restart the Arduino IDE if it was open.

## Usage

Here's a simple example to get you started:

```cpp
#include <SevenSegControl.h>

// Define the pins for the segments and digits
int segmentPins[] = {A, B, C, D, E, F, G}; // Update these with your actual pins
int digitPins[] = {1, 2, 3, 4}; // Update these with your actual pins

// Initialize the display (segmentPins, digitPins, number of digits, update frequency)
SevenSegControl display(segmentPins, digitPins, 4, 60.0);

void setup() {
  // Your setup code here
}

void loop() {
  // Display the number 1234
  display.displayNumber(1234);
  delay(1000); // Just for testing, adjust as needed
}
```

## API Reference

- `SevenSegControl(int* digitPins, int* segmentPins, int numDigits, float updateFrequency)`: Constructor to initialize the display.
- `void displayNumber(int number)`: Displays the specified integer number on the 7-segment display.
- `void clean()`: Clears the display.
- More details can be found in the header file `SevenSegControl.h`.

## Contributing

Contributions to the `SevenSegControl` library are welcome. If you have suggestions for improvements or find a bug, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.

## Acknowledgments

- Thanks to everyone who has contributed to this project.
- Inspired by various other 7-segment display projects.
