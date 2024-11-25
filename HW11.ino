int ledPins[] = {10, 9, 8, 4, 3, 2}; // reversed the order to see why my original code wasn't working 
int currentLed = 0;  
int previousMillis = 0;
int start = 0;  
int interval = 10000; //shorten to test code 
int oneMinute = 60000;  

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  start = millis();  
}

void loop() {
  int now = millis();  
  if (now - start >= oneMinute) {
    // After 60 seconds, turn off all LEDs
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW);  
    }
  return; 
  }

  // Move to the next LED every 10 seconds
  if (now - previousMillis >= interval && currentLed < 6) {
    previousMillis = now;  // Reset the timer for the next LED
    currentLed++;  // Move to the next LED in the line
  }

  for (int i = 0; i < currentLed; i++) {
    digitalWrite(ledPins[i], HIGH);  // turns on the current LED 
  }
}