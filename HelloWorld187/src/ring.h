#ifndef ring_h
#define ring_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "led_matrix.h"

#define LED_PIN     30      // Pin, an dem DIN angeschlossen ist
#define NUM_LEDS    24     // Anzahl LEDs im Ring

extern Adafruit_NeoPixel ring;

void setup_ring();
void ring_red();
void ring_off();

#endif