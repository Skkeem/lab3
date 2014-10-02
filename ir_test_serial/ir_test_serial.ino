void setup()
{
  pinMode(10, INPUT);// Left IR Receiver
  pinMode(9, OUTPUT);// Left IR LED

  pinMode(3, INPUT);// Right IR Receiver
  pinMode(2, OUTPUT);// Right IR LED
  
  Serial.begin(9600);
}

void loop()
{
  int irLeft= irDetect(9, 10, 38000);// Check for object
  int irRight= irDetect(2, 3, 38000);// Check for object

  Serial.print(irLeft);
  Serial.println(irRight);
  delay(100);
  // Do something
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);// IRLED 38 kHz for at least 1 ms
  delay(1); // Wait 1 ms
  int ir = digitalRead(irReceiverPin);// IR receiver -> irvariable
  delay(1); // Down time before recheck
  return ir; // Return 1 not detected, or 0 detected
}
