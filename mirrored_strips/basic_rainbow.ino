#include <FastLED.h>
#define NUM_LEDS 289
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, 7, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, 6, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}


void create_rainbow_colors() {
    // 40 red, [0-19] && [231-250]
    for (uint8_t a = 0; a < 20; a++) {
      leds[a] = CHSV(255, 255, 20);
    }
    for (uint8_t b = 231; b < 251; b++) {
      leds[b] = CHSV(255, 255, 20);
    }

     // 40 orange, [19-39] && [211-230]
    for (uint8_t c = 19; c < 40; c++) {
      leds[c] = CHSV(10, 255, 20);
    }
    for (uint8_t d = 211; d < 231; d++) {
      leds[d] = CHSV(10, 255, 20);
    }

     // 40 yellow, [39-59] && [191-210]
    for (uint8_t e = 39; e < 60; e++) {
      leds[e] = CHSV(50, 255, 20);
    }
    for (uint8_t f = 191; f < 211; f++) {
      leds[f] = CHSV(50, 255, 20);
    }

    // 40 green, [59-80] && [171-190]
    for (uint8_t g = 59; g < 81; g++) {
      leds[g] = CHSV(100, 255, 20);
    }
    for (uint8_t h = 171; h < 191; h++) {
      leds[h] = CHSV(100, 255, 20);
    }

    // 40 blue, [79-100] && [151-170]
    for (uint8_t i = 79; i < 101; i++) {
      leds[i] = CHSV(150, 255, 20);
    }
    for (uint8_t j = 151; j < 171; j++) {
      leds[j] = CHSV(150, 255, 20);
    }

    // 18 purple, [99-150]
    for (uint8_t k = 99; k < 151; k++) {
      leds[k] = CHSV(200, 255, 20);
    }
}


void loop() {
  uint8_t hue1 = 0;
  int outer_count = 0;

  while(outer_count < 3) {
    uint8_t j = 250;
    uint8_t k = 0;

    while(k < 126) {
      leds[j] = CHSV(hue1, 255, 255);
      leds[k] = CHSV(hue1, 255, 255);
      FastLED.show();
      delay(50);
      FastLED.clear();
      j--;
      k++;
      hue1 = hue1 + 10;
    }

    outer_count = outer_count + 1;
  }

  create_rainbow_colors();
  FastLED.show();
  delay(200);

  FastLED.showColor(CRGB(0,0,0));
  delay(200);

  create_rainbow_colors();
  FastLED.show();
  delay(100);

  FastLED.showColor(CRGB(0,0,0));
  delay(100);

  create_rainbow_colors();
  FastLED.show();
  delay(200);

  FastLED.showColor(CRGB(0,0,0));
  delay(100);
}
