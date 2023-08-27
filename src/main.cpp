#include <FastLED.h>  
#define NUM_LEDS 25
#define DATA_PIN 10

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  for(int pixel = 0; pixel < NUM_LEDS; pixel++) {
    leds[pixel].setRGB(5+10*pixel,(100-4*pixel),0);
  }
  FastLED.show();
}
  
