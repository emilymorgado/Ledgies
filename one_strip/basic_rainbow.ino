#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS 289
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void create_rainbow_colors() {
    // 16 red, [0-7] && [93-100]
    for (uint8_t a = 0; a < 8; a++) {
      leds[a] = CHSV(255, 255, 50);
    }
    for (uint8_t b = 93; b < 101; b++) {
      leds[b] = CHSV(255, 255, 50);
    }

     // 16 orange, [8-15] && [85-92]
    for (uint8_t c = 8; c < 16; c++) {
      leds[c] = CHSV(10, 255, 50);
    }
    for (uint8_t d = 85; d < 93; d++) {
      leds[d] = CHSV(10, 255, 50);
    }

     // 16 yellow, [16-23] && [77-84]
    for (uint8_t e = 16; e < 24; e++) {
      leds[e] = CHSV(50, 255, 50);
    }
    for (uint8_t f = 77; f < 85; f++) {
      leds[f] = CHSV(50, 255, 50);
    }

    // 16 green, [24-31] && [69-76]
    for (uint8_t g = 24; g < 32; g++) {
      leds[g] = CHSV(100, 255, 50);
    }
    for (uint8_t h = 69; h < 77; h++) {
      leds[h] = CHSV(100, 255, 50);
    }

    // 16 blue, [32-39] && [61-68]
    for (uint8_t i = 32; i < 40; i++) {
      leds[i] = CHSV(150, 255, 50);
    }
    for (uint8_t j = 61; j < 69; j++) {
      leds[j] = CHSV(150, 255, 50);
    }

    // 18 purple, [40-60]
    for (uint8_t k = 40; k < 61; k++) {
      leds[k] = CHSV(200, 255, 50);
    }
}


void loop() {
  uint8_t hue1 = 0;
  int outer_count = 0;

  while(outer_count < 3) {
    uint8_t led_value = 255;
    uint8_t j = 100;
    uint8_t k = 0;

    while(k < 51) {
      led_value = led_value - 5;
      leds[j] = CHSV(hue1, 255, led_value);
      leds[k] = CHSV(hue1, 255, led_value);
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
