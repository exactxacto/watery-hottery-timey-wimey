//refer to https://forum.arduino.cc/t/keypad-data-entry-a-beginners-guide/660309/8 for documentation

#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS );

char key;
boolean entryComplete;
char timerVal[2];
byte inputIndex = 0;
float floatTotal = 0;
unsigned int intTotal;

void setup()
{
  Serial.begin(9600);
}

void readKeypad()
{
  key = customKeypad.getKey();
  if (key == '#') //user signal that entry has finished
  {
    entryComplete = true; //flag completion
    floatTotal = atof(timerVal);  //convert buffer to a float
    Serial.println("done");

  }
  if (key >= '0' && key <= '9' || key == '.') //only act on numeric or '.' keys
  {
    timerVal[0] = key;  //put the key value in the buffer
    if (inputIndex = 0)
    {
      inputIndex++; //increment the array
    }
    timerVal[1] = key;
    timerVal[inputIndex] = '\0';  //terminate the string
  }
}

void loop()
{
  entryComplete = false;  //will be checked after reading a key
  readKeypad(); //run function readKeypad
  if (entryComplete)  //if readKeypad is true, meaning number entry is complete
  {
        intTotal = floatTotal;  //convert float to integer
    Serial.print("number entered (integer) : ");
    Serial.println(intTotal);
    floatTotal = 0;  //reset the total
    inputIndex = 0; //and the index to the input buffer
  }
}

