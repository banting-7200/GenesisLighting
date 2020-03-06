int hue = 0;
void partyLight() {
  for (int i = 0; i < NUM_LEDS; i++) {

    leds[i] = CHSV(hue, 255, 200);

  }
  if (hue == 255) {
    hue = 0;
  } else {
    hue++;
  }
  delay(50);
  FastLED.show();

}
