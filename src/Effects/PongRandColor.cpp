#include "Effects/PongRandColor.h"
#include "LEDController.h"

PongRandColor::PongRandColor() { }

void PongRandColor::setup(CHSV leds[], unsigned long delta) {
    bool finalized = true;
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        if (leds[i].v != 0) {
            finalized = false;
            break;
        }
    }

    if (finalized) {
        set = true;
        return;
    }

    leds[0].h = currentColor.h;
    leds[0].s = currentColor.s;
    leds[0].v = 0;
    for (uint16_t i = NUM_LEDS - 1; i > 0; i--) {
        leds[i].h = leds[i - 1].h;
        leds[i].s = leds[i - 1].s;
        leds[i].v = leds[i - 1].v;
    }

    finalized = true;
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        if (leds[i].v != 0) {
            finalized = false;
            break;
        }
    }

    if (finalized) {
        set = true;
    }
}

void PongRandColor::destroy(CHSV leds[], unsigned long delta) {
    bool finalized = true;
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        if (leds[i].v != 0) {
            leds[i].v--;
            finalized = false;
        }
    }

    if (finalized) {
        for (uint16_t i = 0; i < NUM_LEDS; i++) {
            leds[i].h = currentColor.h;
            leds[i].s = currentColor.s;
        }
        destroyed = true;
    }
}

void PongRandColor::loop(CHSV leds[], unsigned long delta) {
    if (reversed) {
        for (int16_t i = 0; i <= TAIL_LENGTH; i++) {
            if (currentLED + i >= 0 && currentLED + i < NUM_LEDS) {
                leds[currentLED + i].h = currentColor.h;
                leds[currentLED + i].s = currentColor.s;
                leds[currentLED + i].v = (float) currentColor.v * (1.0f - (float) i / (float) TAIL_LENGTH);
            }
        }
        if (currentLED + TAIL_LENGTH > 0) {
            currentLED--;
        } else {
            reversed = false;
            currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
        }
    } else {
        for (int16_t i = 0; i <= TAIL_LENGTH; i++) {
            if (currentLED - i >= 0 && currentLED - i < NUM_LEDS) {
                leds[currentLED - i].h = currentColor.h;
                leds[currentLED - i].s = currentColor.s;
                leds[currentLED - i].v = (float) currentColor.v * (1.0f - (float) i / (float) TAIL_LENGTH);
            }
        }
        if (currentLED - TAIL_LENGTH < NUM_LEDS) {
            currentLED++;
        } else {
            reversed = true;
            currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
        }
    }
}