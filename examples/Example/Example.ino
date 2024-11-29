#include <12ButtonKeypad.h>

// Define GPIO pins connected to the rows of the keypad
const int rowPins[4] = {18, 19, 20, 21};

// Define GPIO pins connected to the columns of the keypad
const int colPins[3] = {10, 11, 12};

// Define the button layout for the keypad (12 buttons)
const char buttonMap[4][3] = {
    {'1', '2', '3'},  // Row 1 buttons
    {'4', '5', '6'},  // Row 2 buttons
    {'7', '8', '9'},  // Row 3 buttons
    {'*', '0', '#'}   // Row 4 buttons
};

// Create an instance of the TwelveButtonKeypad class
TwelveButtonKeypad keypad(rowPins, colPins, buttonMap);

void setup() {
    // Start the serial communication for debugging/output
    Serial.begin(9600);

    // Initialize the keypad
    keypad.begin();

    Serial.println("12-Button Keypad Initialized");
}

void loop() {
    // Get the current button press (if any)
    char key = keypad.getKey();

    // If a button is pressed, print it to the serial monitor
    if (key != '\0') {
        Serial.print("Button pressed: ");
        Serial.println(key);

        // Delay to debounce the button press
        delay(200);
    }
}
