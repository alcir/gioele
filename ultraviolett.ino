const int buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 4;       // the pin that the LED is attached to

int buttonPushCounter = 1;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
unsigned long previousMillis = 0;
unsigned long fade = 0;
bool neg = 0;

int ledState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {

    if (buttonState == HIGH) {

      buttonPushCounter++;

    }

    delay(50);

  }

  lastButtonState = buttonState;

  if (buttonPushCounter % 5 == 0) {
    fading();
    buttonPushCounter = 0;
  } else if (buttonPushCounter % 4 == 0) {
    lampeggia(100);
  } else if (buttonPushCounter % 3 == 0) {
    lampeggia(500);
  } else if (buttonPushCounter % 2 == 0) {
    lampeggia(1000);
  } else if (buttonPushCounter % 1 == 0) {
    fisso();
  }

}

void fisso() {
  digitalWrite(ledPin, HIGH);
}

void lampeggia(const long interval) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

void fading() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 10) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    //  Serial.println(fade);

    if ( neg == 0) {
      fade++;
    } else {
      fade--;
    }

    if (fade > 255) {
      neg = 1;
    } else if (fade == 0 ) {
      neg = 0;
    }
    // set the LED with the ledState of the variable:
    analogWrite(ledPin, fade);
  }
}
