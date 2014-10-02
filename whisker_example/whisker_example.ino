#include <Servo.h>                           // Include servo library
 
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;

void setup()// Built-in initialization block
{
//  tone(4, 3000, 1000);// Play tone for 1 second
//  delay(1000);// Delay to finish tone
  pinMode(7, INPUT); // Set right whisker pin to input
  pinMode(5, INPUT); // Set left whisker pin to input
  
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12
}
  
void loop() // Main loop auto-repeats
{
  byte wLeft= digitalRead(5); // Copy left result to wLeft
  byte wRight= digitalRead(7); // Copy right result to wRight

  if (wLeft == 0 && wRight == 0) {
    backward(1000);
    turnRight(600);
  }
  else if (wLeft == 0) {
    backward(1000);
    turnRight(600);
  }
  else if (wRight == 0) {
    backward(1000);
    turnLeft(600);
  }
  else
    forward(20);
}

void forward(int time)                       // Forward function
{
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnLeft(int time)                      // Left turn function
{
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnRight(int time)                     // Right turn function
{
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}

void backward(int time)                      // Backward function
{
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}
