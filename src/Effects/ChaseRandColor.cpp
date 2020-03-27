#include "Effects/ChaseRandColor.h"
#include "LEDController.h"

ChaseRandColor::ChaseRandColor() { }

void ChaseRandColor::setup(CHSV leds[], unsigned long delta) {
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

void ChaseRandColor::destroy(CHSV leds[], unsigned long delta) {
    leds[0].h = currentColor.h;
    leds[0].s = currentColor.s;
    leds[0].v = 0;
    for (uint16_t i = NUM_LEDS - 1; i > 0; i--) {
        leds[i].h = leds[i - 1].h;
        leds[i].s = leds[i - 1].s;
        leds[i].v = leds[i - 1].v;
    }

    bool finalized = true;
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        if (leds[i].v != 0) {
            finalized = false;
            break;
        }
    }

    if (finalized) {
        destroyed = true;
    }
}

void ChaseRandColor::loop(CHSV leds[], unsigned long delta) {
    leds[0].h = currentColor.h;
    leds[0].s = currentColor.s;
    leds[0].v = currentColor.v;
    currentTailLength++;

    for (uint16_t i = NUM_LEDS - 1; i > 0; i--) {
        leds[i].h = leds[i - 1].h;
        leds[i].s = leds[i - 1].s;
        leds[i].v = leds[i - 1].v;
    }

    if (currentTailLength == TAIL_LENGTH) {
        currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
        currentTailLength = 0;
    }
}