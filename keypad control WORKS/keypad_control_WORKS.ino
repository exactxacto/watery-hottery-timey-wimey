#include <Keypad.h>

char key;
const byte MAX_INDEX = 2;
unsigned char arrayIndex = 0;
char array[MAX_INDEX];
int output;

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

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  key = keypad.getKey();
  if (key >= '0' && key <= '9'){
    array[arrayIndex] = key; 
    if (arrayIndex != MAX_INDEX && key !='#'){
      arrayIndex++;
    }
    array[arrayIndex] = '\0';  //terminate the string
    output = atoi(array);
  }
  else if (key == '#'){
    array[2] = 0;
    Serial.println("the final value is");
    Serial.println(output);
  }
}