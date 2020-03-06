#include <FastLED.h>
#define NUM_LEDS 89
#define INPIN 3


int mode = 1;
int lastButtonState = 0;
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin (9600);
  FastLED.addLeds<NEOPIXEL, INPIN>(leds, NUM_LEDS);
  pinMode(2, INPUT);
}

void loop() {
  checkButton();
  switch (mode) {
    case 1:
      noLight();
      break;

    case 2:
      whiteLight();
      break;

    case 3:
      blueLight();
      break;

    case 4:
      redLight();
      break;

    case 5:
      eightLight();
      break;

    case 6:
      partyLight();
      break;
  }
}

boolean checkButton() {
  int buttonState = digitalRead(2);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      if (mode == 6) {
        mode = 1;
      } else {
        mode++;
      }
      Serial.print("Mode changed to: ");
      Serial.println(mode);
      delay(400);
      return true;
    }
  }
  lastButtonState = buttonState;
}
