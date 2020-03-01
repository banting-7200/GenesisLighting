#include <FastLED.h>
#define NUM_LEDS 300
#define INPIN 2

int mode = 0;
int count = 0;
int hue = 255;
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, INPIN>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    if (checkButton(true)) break;
    leds[i + 10] = CRGB::Blue;
    FastLED.show();
  }
}
