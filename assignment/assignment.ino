
void setup()
{
  
}

void loop()
{
	if (count == 4) {
		rotate(180);
		count = 0;		
	}
	if (count == 2 || detected ()) {
		rotate(90);
		count++;
	}
	else {
		forward();
		count = 0;
	}
}

