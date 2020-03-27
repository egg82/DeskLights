#ifndef LEDController_h
#define LEDController_h

#include <FastLED.h>
#include "Effects/IEffect.h"

#define NUM_LEDS 192
#define DATA_PIN 3

#define LED_BRIGHTNESS 64
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

class LEDController {
    private:
    bool ready = false;
    IEffect *effect = NULL;
    IEffect *previousEffect = NULL;
    void display();
    void displayFast() { FastLED.show(); }
    public:
    LEDController();
    void setEffect(IEffect *effect);
    IEffect *getEffect() { return effect; }
    bool loop(unsigned long mills);
    bool isReady() { return ready; }
    bool isDestroyed() { return this->effect->isDestroyed(); }

    void clear(CHSV color);
};
#endif