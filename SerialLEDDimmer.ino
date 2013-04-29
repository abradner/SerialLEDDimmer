/*
  Serial LED Dimmer
 
  Using the arduino board to set LED brightness based on data recieved over the serial port

 The circuit:
 * RGB LED connected from digital pin 3, 5 and 6 to ground
 
 created 2013
 by Alex Bradner
 
 Creative Commons Share Alike License 2.0
 */
 
 #define OFF LOW
 #define ON HIGH

const int redPin   = 3; // the pin that the LED is attached to
const int greenPin = 5; // the pin that the LED is attached to
const int bluePin  = 6; // the pin that the LED is attached to

byte incomingByte;

void setup() {
  // initialize serial communication:
  Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:

    switch (incomingByte) {
    case 'r':
      digitalWrite(redPin, OFF);
      break;
    case 'R':
      digitalWrite(redPin, ON);
      break;    

    case 'g':
      digitalWrite(greenPin, OFF);
      break;
    case 'G':
      digitalWrite(greenPin, ON);
      break;    

    case 'b':
      digitalWrite(bluePin, OFF);
      break;
    case 'B':
      digitalWrite(bluePin, ON);
      break;

    case 'W':
      digitalWrite(redPin, ON);
      digitalWrite(greenPin, ON);
      digitalWrite(bluePin, ON);
      break;        
    default:
      digitalWrite(redPin, OFF);
      digitalWrite(greenPin, OFF);
      digitalWrite(bluePin, OFF);
    }
  }
}

//byte* 
