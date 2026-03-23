const int buttonPin = 2;
const int ledPin = 4;

volatile unsigned long pressStart = 0;
volatile unsigned long pressEnd = 0;
volatile bool ready = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPress, CHANGE);
}

void loop() {
  if (ready) {
    unsigned long duration = pressEnd - pressStart;

    unsigned long startTime = millis();
    
    while (millis() - startTime < duration) {
      digitalWrite(ledPin, HIGH);
      delay(200);

      digitalWrite(ledPin, LOW);
      delay(200);
    }

    ready = false;
  }
}


void buttonPress() {
  if (digitalRead(buttonPin) == HIGH) {
    pressStart = millis();
  } else {
    pressEnd = millis();
    ready = true;
  }
}