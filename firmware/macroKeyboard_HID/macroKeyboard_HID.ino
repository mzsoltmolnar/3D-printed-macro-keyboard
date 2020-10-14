/*
  Physical board: SparkFun Pro Micro
  In Arduino IDE select: Arduino Leonardo
  
  Key modifiers list: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
  Media keys list: https://github.com/NicoHood/HID/wiki/Consumer-API
  Matrix keyboard code example: https://playground.arduino.cc/Main/KeypadTutorial

  Required libs:
  - HID-Project - v3.1.1: https://github.com/NicoHood/HID
  - Keypad - v2.6.1: https://playground.arduino.cc/Code/Keypad/

  How it works?
  
  There are 3 layouts. Each layout has 16 keys. The "if" statement checks whether the command should be repeated
  when the key is kept pressed or not. In case of key repetition, no "if" statement is required.

  To create your own macro, insert the desired key combination in the appropriate "if" statement.
  
  With the Keyboard.press(KEY_LEFT_CTRL); command, the key passed as an argument is pressed and kept pressed
  until the Keyboard.release(KEY_LEFT_CTRL); command pair is executed. For more commands, see the
  "Key modifiers list" above.

  Keyboard.print("Hello World!"); - emulates the typing

  Consumer.write(MEDIA_VOLUME_UP); - this command is used to send media key commands. With a single execution,
  the system volume level will be increased by 1%. For more media key commands, see the "Media keys list" above.
  
  if (!isRepeatKey) - if the "isRepeatKey" is negated, then the command in the "if" statement will not be repeated.
  Otherwise will be repeated, and a delay(); should be added in the "if" statement.

  The first layout is configured with some basic examples.
*/

#include "HID-Project.h"
#include <Keypad.h>

const bool debugON = false;


const int led_0 = 10; // Layout 1 active
const int led_1 = 16; // Layout 2 active
const int led_2 = 14; // Layout 3 active
const int layout = A0;

const byte rows = 4;
const byte cols = 4;

const int repeatDelay = 25;
const int debounceDelay = 30;

int activeLayout = 0;
bool layoutPrevState = false;
bool isRepeatKey = true;
char lastPressed;

char keys[rows][cols] = // key map
{
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'A', 'B', 'C'},
  {'D', 'E', 'F', 'G'}
};

byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};

Keypad mBoard = Keypad (makeKeymap(keys), rowPins, colPins, rows, cols);

void setup()
{
  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(layout, INPUT);

  if (debugON) Serial.begin(9600);
  Keyboard.begin();
}

void loop()
{
  setLayoutLED(activeLayout);

  bool layoutRead = digitalRead(layout);

  if (layoutRead != layoutPrevState)
  {
    if (layoutRead)
    {
      if (activeLayout < 2) activeLayout++;
      else activeLayout = 0;
      delay(debounceDelay);
    }
    layoutPrevState = layoutRead;
  }

  char keyPressed = mBoard.getKey();
  KeyState boardStatus = mBoard.getState();

  if (keyPressed)
  {
    isRepeatKey = false;

    if (debugON)
    {
      Serial.println(keyPressed);
    }

    if (activeLayout == 0) layout_0(keyPressed);
    if (activeLayout == 1) layout_1(keyPressed);
    if (activeLayout == 2) layout_2(keyPressed);

    isRepeatKey = true;
    lastPressed = keyPressed;
  }

  if (boardStatus == HOLD)
  {
    if (activeLayout == 0) layout_0(lastPressed);
    if (activeLayout == 1) layout_1(lastPressed);
    if (activeLayout == 2) layout_2(lastPressed);
  }
}


//--------------------------- LAYOUT 1 active -----------------
void layout_0(char pressedKey)
{
  switch (pressedKey)
  {
    case '1': // SW_1
      if (!isRepeatKey)
      {
        Keyboard.print("This is the FIRST layout that you can use for ANYTHING");
      }
      break;

    case '2': // SW_2
      // Save - Ctrl + s
      if (!isRepeatKey)
      {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('s');
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release('s');
      }
      break;

    case '3': // SW_3
      if (!isRepeatKey)
      {
      }
      break;

    case '4': // SW_4
      // system volume MUTE
      if (!isRepeatKey)
      {
        Consumer.write(MEDIA_VOLUME_MUTE);
      }
      break;

    case '5': // SW_5
      if (!isRepeatKey)
      {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('a');
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release('a');
      }
      break;

    case '6': // SW_6
      if (!isRepeatKey)
      {
      }
      break;

    case '7': // SW_7
      // Backspace
      // if (!isRepeatKey)
      {
        Keyboard.press(KEY_BACKSPACE);
        Keyboard.release(KEY_BACKSPACE);
        delay(repeatDelay);
      }
      break;

    case '8': // SW_8
      // System volume UP
      // if (!isRepeatKey)
      {
        Consumer.write(MEDIA_VOLUME_UP);
        delay(repeatDelay);
      }
      break;

    case '9': // SW_9
      if (!isRepeatKey)
      {
      }
      break;

    case 'A': // SW_A
      if (!isRepeatKey)
      {
      }
      break;

    case 'B': // SW_B
      if (!isRepeatKey)
      {
      }
      break;

    case 'C': // SW_C
      // System volume DOWN
      // if (!isRepeatKey)
      {
        Consumer.write(MEDIA_VOLUME_DOWN);
        delay(repeatDelay);
      }
      break;

    case 'D': // SW_D
      // copy
      if (!isRepeatKey)
      {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('c');
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release('c');
      }
      break;

    case 'E': // SW_E
      // cut
      if (!isRepeatKey)
      {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('x');
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release('x');
      }
      break;

    case 'F': // SW_F
      // paste
      if (!isRepeatKey)
      {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('v');
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release('v');
      }
      break;

    case 'G': // SW_G
      // ENTER
      if (!isRepeatKey)
      {
        Keyboard.press(KEY_RETURN);
        Keyboard.release(KEY_RETURN);
      }
      break;
  }
}

//--------------------------- LAYOUT 2 active -----------------
void layout_1(char pressedKey)
{
  switch (pressedKey)
  {
    case '1': // SW_1
      if (!isRepeatKey)
      {
        Keyboard.print("This is the SECOND layout that you can use for ANYTHING");
      }
      break;

    case '2': // SW_2
      if (!isRepeatKey)
      {
      }
      break;

    case '3': // SW_3
      if (!isRepeatKey)
      {
      }
      break;

    case '4': // SW_4
      if (!isRepeatKey)
      {
      }
      break;

    case '5': // SW_5
      if (!isRepeatKey)
      {
      }
      break;

    case '6': // SW_6
      if (!isRepeatKey)
      {
      }
      break;

    case '7': // SW_7
      if (!isRepeatKey)
      {
      }
      break;

    case '8': // SW_8
      if (!isRepeatKey)
      {
      }
      break;

    case '9': // SW_9
      if (!isRepeatKey)
      {
      }
      break;

    case 'A': // SW_A
      if (!isRepeatKey)
      {
      }
      break;

    case 'B': // SW_B
      if (!isRepeatKey)
      {
      }
      break;

    case 'C': // SW_C
      if (!isRepeatKey)
      {
      }
      break;

    case 'D': // SW_D
      if (!isRepeatKey)
      {
      }
      break;

    case 'E': // SW_E
      if (!isRepeatKey)
      {
      }
      break;

    case 'F': // SW_F
      if (!isRepeatKey)
      {
      }
      break;

    case 'G': // SW_G
      if (!isRepeatKey)
      {
      }
      break;
  }
}

//--------------------------- LAYOUT 3 active -----------------
void layout_2(char pressedKey)
{
  switch (pressedKey)
  {
    case '1': // SW_1
      if (!isRepeatKey)
      {
        Keyboard.print("This is the THIRD layout that you can use for ANYTHING");
      }
      break;

    case '2': // SW_2
      if (!isRepeatKey)
      {
      }
      break;

    case '3': // SW_3
      if (!isRepeatKey)
      {
      }
      break;

    case '4': // SW_4
      if (!isRepeatKey)
      {
      }
      break;

    case '5': // SW_5
      if (!isRepeatKey)
      {
      }
      break;

    case '6': // SW_6
      if (!isRepeatKey)
      {
      }
      break;

    case '7': // SW_7
      if (!isRepeatKey)
      {
      }
      break;

    case '8': // SW_8
      if (!isRepeatKey)
      {
      }
      break;

    case '9': // SW_9
      if (!isRepeatKey)
      {
      }
      break;

    case 'A': // SW_A
      if (!isRepeatKey)
      {
      }
      break;

    case 'B': // SW_B
      if (!isRepeatKey)
      {
      }
      break;

    case 'C': // SW_C
      if (!isRepeatKey)
      {
      }
      break;

    case 'D': // SW_D
      if (!isRepeatKey)
      {
      }
      break;

    case 'E': // SW_E
      if (!isRepeatKey)
      {
      }
      break;

    case 'F': // SW_F
      if (!isRepeatKey)
      {
      }
      break;

    case 'G': // SW_G
      if (!isRepeatKey)
      {
      }
      break;
  }
}

void setLayoutLED(int currLyt)
{
  if (currLyt == 0)
  {
    digitalWrite(led_0, HIGH);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
  }

  if (currLyt == 1)
  {
    digitalWrite(led_0, LOW);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
  }

  if (currLyt == 2)
  {
    digitalWrite(led_0, LOW);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
  }
}

