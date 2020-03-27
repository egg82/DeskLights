#ifndef ChaseRainbow_h
#define ChaseRainbow_h

#include <Arduino.h>
#include "IEffect.h"
#include "LEDController.h"
#include "RandColor.h"

class ChaseRainbow : public IEffect {
    private:
    bool set = false;
    bool destroyed = false;
    uint8_t currentIndex = UINT8_MAX;
    CHSV currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
    public:
    ChaseRainbow();
    bool canLoop(unsigned long delta) { return delta >= 10; }
    void loop(CHSV leds[], unsigned long delta);
    void setup(CHSV leds[], unsigned long delta);
    bool isSetup() { return set; }
    void destroy(CHSV leds[], unsigned long delta);
    bool isDestroyed() { return destroyed; }
};

#endif