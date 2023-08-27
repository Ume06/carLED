#include <FastLED.h>  
#define NUM_LEDS 25
#define DATA_PIN 10
#define RED 13
#define RED_BUTTON 2
#define REVS A2
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(RED, OUTPUT);
  pinMode(REVS, INPUT);
  pinMode(RED_BUTTON, INPUT);
  setRevs();
}

void loop() {
  setRevs();
  while(digitalRead(RED_BUTTON) == HIGH) {
    setRed();
  }
}


void setRevs() {
    int revs = analogRead(REVS);
    int NUM = map(revs, 0, 1023, 0, NUM_LEDS);
    FastLED.clear();
    FastLED.show();
    for(int pixel = 0; pixel < NUM; pixel++) {
      leds[pixel].setRGB(5+10*pixel,(100-4*pixel),0);
    }
    FastLED.show();
}

void setRed() {
  FastLED.clear();
  for(int pixel = 0; pixel < NUM_LEDS; pixel++) {
    leds[pixel].setRGB(250,0,0);
  }
  FastLED.show();
}
  
