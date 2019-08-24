#include <Adafruit_NeoPixel.h>

int dataPin = 1;  // data pin 1
int pixels = 8;  // number of Neopixels

Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixels, dataPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// Fade lower/higher to achieve an active glow effect
void loop() {
  for (int i = 100; i <= 180; i++) {
    colorWipe(strip.Color(0, 0, i), 1); // Blue
    delay(5);
  }
  for (int i = 180; i >= 100; i--) {
    colorWipe(strip.Color(0, 0, i), 1); // Blue
    delay(5);
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
