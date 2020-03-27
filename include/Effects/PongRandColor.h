#ifndef PongRandColor_h
#define PongRandColor_h

#include <Arduino.h>
#include "IEffect.h"
#include "LEDController.h"
#include "RandColor.h"

class PongRandColor : public IEffect {
    private:
    bool set = false;
    bool destroyed = false;
    bool reversed = false;
    uint8_t currentIndex = UINT8_MAX;
    CHSV currentColor = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex);
    int16_t currentLED = 0;
    const int16_t TAIL_LENGTH = NUM_LEDS / 5;
    public:
    PongRandColor();
    bool canLoop(unsigned long delta) { return delta >= 10; }
    void loop(CHSV leds[], unsigned long delta);
    void setup(CHSV leds[], unsigned long delta);
    bool isSetup() { return set; }
    void destroy(CHSV leds[], unsigned long delta);
    bool isDestroyed() { return destroyed; }
};

#endif