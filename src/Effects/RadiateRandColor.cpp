#include "Effects/RadiateRandColor.h"
#include "LEDController.h"

RadiateRandColor::RadiateRandColor() { }

void RadiateRandColor::setup(CHSV leds[], unsigned long delta) {
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

    leds[0].h = currentColor1.h;
    leds[0].s = currentColor1.s;
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

void RadiateRandColor::destroy(CHSV leds[], unsigned long delta) {
    bool finalized = true;
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        if (leds[i].v != 0) {
            leds[i].v--;
            finalized = false;
        }
    }

    if (finalized) {
        for (uint16_t i = 0; i < NUM_LEDS; i++) {
            leds[i].h = currentColor1.h;
            leds[i].s = currentColor1.s;
        }
        destroyed = true;
    }
}

void RadiateRandColor::loop(CHSV leds[], unsigned long delta) {
    for (int16_t i = 0; i <= TAIL_LENGTH; i++) {
        if (MID_LED + currentLED - i >= MID_LED && MID_LED + currentLED - i < NUM_LEDS) {
            leds[MID_LED + currentLED - i].h = currentColor1.h;
            leds[MID_LED + currentLED - i].s = currentColor1.s;
            leds[MID_LED + currentLED - i].v = (float) currentColor1.v * (1.0f - (float) i / (float) TAIL_LENGTH);
        }
        if (MID_LED - currentLED + i >= 0 && MID_LED - currentLED + i < MID_LED) {
            leds[MID_LED - currentLED + i].h = currentColor2.h;
            leds[MID_LED - currentLED + i].s = currentColor2.s;
            leds[MID_LED - currentLED + i].v = (float) currentColor2.v * (1.0f - (float) i / (float) TAIL_LENGTH);
        }
    }

    if (MID_LED + currentLED - TAIL_LENGTH < NUM_LEDS) {
        currentLED++;
    } else {
        currentLED = 0;
        currentColor1 = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex1);
        currentColor2 = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex1);
    }
}