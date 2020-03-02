#include <FastLED.h>
#define NUM_LEDS 300
#define INPIN 2

int mode = 0;
int count = 0;
int hue = 255;
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, INPIN>(leds, NUM_LEDS);
}

void loop() {
  checkButton();
  switch(count) {
    case 0:
      noLight();
      break;

    case 1:
      whiteLight();
      break;
  }
}

void noLight() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void whiteLight() {
for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}

boolean checkButton() {
  mode = digitalRead(3);

  if (mode == HIGH) {
    noLight();
    if (count == 1) {
      count = 0;
    } else {
      count++;
    }
    delay(1000);
    return true;
  } else return false;
}
