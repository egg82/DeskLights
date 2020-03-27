#include "Effects/FadeRandColor.h"
#include "LEDController.h"

#include "Easing.h"

FadeRandColor::FadeRandColor() { }

void FadeRandColor::setup(CHSV leds[], unsigned long delta) {
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
        set = true;
    }
}

void FadeRandColor::destroy(CHSV leds[], unsigned long delta) {
    bool finalized = true;
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        if (leds[i].v != 0) {
            leds[i].v--;
            finalized = false;
        }
    }

    if (finalized) {
        destroyed = true;
    }
}

void FadeRandColor::loop(CHSV leds[], unsigned long delta) {
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        leds[i].v = (isFadingOut) ? ease(currentColor.v, 0.0f, TOTAL_DURATION, currentTime, EasingType::CubicOut) : ease(0.0f, 255.0f, TOTAL_DURATION, currentTime, EasingType::CubicOut);
    }

    if (!isSwappingColors) {
        currentTime += delta;
    } else {
        isSwappingColors = false;
    }

    if (currentTime >= TOTAL_DURATION) {
        if (isFadingOut) {
            isSwappingColors = true;
            currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
            for (uint16_t i = 0; i < NUM_LEDS; i++) {
                leds[i].h = currentColor.h;
                leds[i].s = currentColor.s;
                leds[i].v = 0;
            }
        } else {
            for (uint16_t i = 0; i < NUM_LEDS; i++) {
                leds[i].v = currentColor.v;
            }
        }
        isFadingOut = !isFadingOut;
        currentTime = 0.0f;
    }
}