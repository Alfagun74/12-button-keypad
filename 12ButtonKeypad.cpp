#include "12ButtonKeypad.h"

// Constructor: Assigns row, column pins and button mapping to the instance
TwelveButtonKeypad::TwelveButtonKeypad(const int *rowPins, const int *colPins, const char buttonMap[4][3])
    : rowPins(rowPins), colPins(colPins), buttonMap(buttonMap) {}

void TwelveButtonKeypad::begin() {
    // Set row pins as outputs and initialize them to HIGH
    for (int i = 0; i < 4; i++) {
        pinMode(rowPins[i], OUTPUT);
        digitalWrite(rowPins[i], HIGH);
    }

    // Set column pins as inputs with internal pull-up resistors enabled
    for (int i = 0; i < 3; i++) {
        pinMode(colPins[i], INPUT_PULLUP);
    }
}

char TwelveButtonKeypad::getKey() {
    // Loop through each row and set it LOW to check for button presses
    for (int row = 0; row < 4; row++) {
        setRowState(row, LOW); // Activate the current row

        // Loop through each column to detect button presses
        for (int col = 0; col < 3; col++) {
            if (digitalRead(colPins[col]) == LOW) {
                // Button at the intersection of this row and column is pressed
                setRowState(row, HIGH); // Reset the row state
                return buttonMap[row][col]; // Return the button's value
            }
        }

        // Reset the current row to HIGH after checking
        setRowState(row, HIGH);
    }

    // Return '\0' if no button is pressed
    return '\0';
}

void TwelveButtonKeypad::setRowState(int row, bool state) {
    // Set the specified row to HIGH (inactive) or LOW (active)
    digitalWrite(rowPins[row], state ? HIGH : LOW);
}
