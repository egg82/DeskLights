#ifndef ChaseRandColor_h
#define ChaseRandColor_h

#include <Arduino.h>
#include "IEffect.h"
#include "LEDController.h"
#include "RandColor.h"

class ChaseRandColor : public IEffect {
    private:
    bool set = false;
    bool destroyed = false;
    uint8_t currentIndex = UINT8_MAX;
    CHSV currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
    const uint16_t TAIL_LENGTH = NUM_LEDS / 8;
    uint16_t currentTailLength = 0;
    public:
    ChaseRandColor();
    bool canLoop(unsigned long delta) { return delta >= 20; }
    void loop(CHSV leds[], unsigned long delta);
    void setup(CHSV leds[], unsigned long delta);
    bool isSetup() { return set; }
    void destroy(CHSV leds[], unsigned long delta);
    bool isDestroyed() { return destroyed; }
};

#endif