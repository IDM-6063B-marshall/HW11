int ledPins[] = {10, 9, 8, 4, 3, 2};  // LED pins in reverse order
int currentLed = 0;  
int previousMillis = 0;
int start = 0;  
int interval = 10000;  // Time interval to light up the next LED
intg oneMinute = 60000;  // Time duration to keep LEDs on before turning off

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  start = millis();  // Record the start time
  digitalWrite(ledPins[0], HIGH);  // Immediately light up the first LED
  currentLed = 1;  // Set currentLed to 1 because the first LED is already on
}

void loop() {
int now = millis();  
  
  // After 60 seconds, turn off all LEDs
  if (now - start >= oneMinute) {
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW);  // Turn off all LEDs
    }
    return;  // Exit the loop
  }

  // Move to the next LED every 10 seconds
  if (now - previousMillis >= interval && currentLed < 6) {
    previousMillis = now;  // Reset the timer for the next LED
    digitalWrite(ledPins[currentLed], HIGH);  // Turn on the next LED
    currentLed++;  // Move to the next LED
  }
}
