#include "ring.h"

Adafruit_NeoPixel ring(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup_ring() {
    LED0->on();
    ring.begin();
    LED1->on();
    ring.clear();
    LED2->on();

    for(int i = 0; i < NUM_LEDS; i++) {
        ring.setPixelColor(i, ring.Color(255, 0, 0));
    }
    LED3->on();
    ring.show();
    LED4->on();
}

void ring_red() {
    for(int i = 0; i < NUM_LEDS; i++) {
        ring.setPixelColor(i, ring.Color(255, 0, 0));
    }
    ring.show();
}

void ring_off() {
    for(int i = 0; i < NUM_LEDS; i++) {
        ring.setPixelColor(i, ring.Color(0, 0, 0));
    }
    ring.show();
}