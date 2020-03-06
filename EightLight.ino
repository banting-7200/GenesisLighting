int lightShift = 0;
boolean toggle = false; // red: false, blue: true

void eightLight() {
  for(int i = 0; i < NUM_LEDS; i++) {
    if(lightShift > 7) {
      lightShift = 0;
      toggle = !toggle;
    }
    if (toggle) leds[i] = CRGB::Red;
    else leds[i] = CRGB::Blue;
    lightShift++;
  }
  FastLED.show();
  delay(100);
}
