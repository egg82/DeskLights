#ifndef RadiateRandColor_h
#define RadiateRandColor_h

#include <Arduino.h>
#include "IEffect.h"
#include "LEDController.h"
#include "RandColor.h"

class RadiateRandColor : public IEffect {
    private:
    bool set = false;
    bool destroyed = false;
    uint8_t currentIndex1 = UINT8_MAX;
    CHSV currentColor1 = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex1);
    CHSV currentColor2 = getRandColor(CURRENT_PALETTE, LINEARBLEND, &currentIndex1);
    int16_t currentLED = 0;
    const int16_t MID_LED = (NUM_LEDS / 2) % 2 == 0 ? NUM_LEDS / 2 : NUM_LEDS / 2 + 1;
    const int16_t TAIL_LENGTH = NUM_LEDS / 5;
    public:
    RadiateRandColor();
    bool canLoop(unsigned long delta) { return delta >= 10; }
    void loop(CHSV leds[], unsigned long delta);
    void setup(CHSV leds[], unsigned long delta);
    bool isSetup() { return set; }
    void destroy(CHSV leds[], unsigned long delta);
    bool isDestroyed() { return destroyed; }
};

#endif