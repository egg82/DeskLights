#ifndef FadeRandColor_h
#define FadeRandColor_h

#include <Arduino.h>
#include "IEffect.h"
#include "RandColor.h"

class FadeRandColor : public IEffect {
    private:
    bool set = false;
    bool destroyed = false;
    bool isFadingOut = false;
    bool isSwappingColors = false;
    float currentTime = 0.0f;
    const float TOTAL_DURATION = 3000.0f;
    uint8_t currentIndex = UINT8_MAX;
    CHSV currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
    public:
    FadeRandColor();
    bool canLoop(unsigned long delta) {
        if (isSwappingColors) {
            if (delta >= 750) {
                return true;
            }
            return false;
        }
        return true;
    }
    void loop(CHSV leds[], unsigned long delta);
    void setup(CHSV leds[], unsigned long delta);
    bool isSetup() { return set; }
    void destroy(CHSV leds[], unsigned long delta);
    bool isDestroyed() { return destroyed; }
};

#endif