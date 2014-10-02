void setup()// Built-in initialization block
{
//  tone(4, 3000, 1000);// Play tone for 1 second
//  delay(1000);// Delay to finish tone
  pinMode(7, INPUT); // Set right whisker pin to input
  pinMode(5, INPUT); // Set left whisker pin to input
}
  
void loop() // Main loop auto-repeats
{
  byte wLeft= digitalRead(5); // Copy left result to wLeft
  byte wRight= digitalRead(7); // Copy right result to wRight
  if (wLeft == 0 && wRight == 0) {
    back(1000);
    right();
  }
  else if (wLeft == 0) {
    back(1000);
    right();
  }
  else if (wRight == 0) {
    back(1000);
    right();
  }
  delay(50); // Pause for 50 ms
}
