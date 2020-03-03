#include <FastLED.h>
#define NUM_LEDS 300
#define INPIN 2

int mode = 1;
int lastButtonState = 0;
int hue = 255;
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, INPIN>(leds, NUM_LEDS);
  pinMode(3, INPUT);
  Serial.begin(9600);
  Serial.println("Arduino ready.");
}

void loop() {
  Serial.println("Checking button...");
  checkButton();
  switch (mode) {
    case 1:
      noLight();
      break;

    case 2:
      whiteLight();
      break;

    case 3:
      kyleLight();
      break;
      
  }
}

boolean checkButton() {
  int buttonState = digitalRead(3);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      if (mode == 3) {
        mode = 1;
      } else {
        mode++;
      }
      
      Serial.print("Mode changed to: ");
      Serial.println(mode);
      delay(500);
    }
  }
  lastButtonState = buttonState;
}

void noLight() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void whiteLight() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(100, 100, 100);
  }
  FastLED.show();
}
void kyleLight() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(100, 0, 100);
  }
  FastLED.show();
}
