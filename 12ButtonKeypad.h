#ifndef TWELVE_BUTTON_KEYPAD_H
#define TWELVE_BUTTON_KEYPAD_H

#include <Arduino.h>

// Class to manage a 3x4 button matrix (12-button keypad)
class TwelveButtonKeypad {
public:
    /**
     * Constructor
     * @param rowPins Array of 4 GPIO pins connected to the rows of the keypad
     * @param colPins Array of 3 GPIO pins connected to the columns of the keypad
     * @param buttonMap 2D array representing the button values for the 3x4 keypad
     */
    TwelveButtonKeypad(const int *rowPins, const int *colPins, const char buttonMap[4][3]);

    /**
     * Initializes the keypad pins (sets rows as outputs and columns as inputs with pull-up resistors).
     */
    void begin();

    /**
     * Scans the keypad and returns the value of the currently pressed button.
     * @return The character of the button being pressed, or '\0' if no button is pressed.
     */
    char getKey();

private:
    const int *rowPins;               // Array of row GPIO pins
    const int *colPins;               // Array of column GPIO pins
    const char (*buttonMap)[3];       // 2D array for the keypad button layout

    /**
     * Sets the state (HIGH or LOW) of a specific row.
     * @param row The row index (0 to 3)
     * @param state The desired state: HIGH (true) or LOW (false)
     */
    void setRowState(int row, bool state);
};

#endif // TWELVE_BUTTON_KEYPAD_H
