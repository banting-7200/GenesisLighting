void whiteLight() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(125, 125, 125);
  }
  FastLED.show();
}
