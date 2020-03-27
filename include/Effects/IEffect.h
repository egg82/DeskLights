#ifndef IEffect_h
#define IEffect_h

#include <FastLED.h>

class IEffect {
    public:
    virtual ~IEffect(){};
    virtual bool canLoop(unsigned long delta) { return true; }
    virtual void loop(CHSV leds[], unsigned long delta) = 0;
    virtual void setup(CHSV leds[], unsigned long delta) = 0;
    virtual bool isSetup() { return true; }
    virtual void destroy(CHSV leds[], unsigned long delta) = 0;
    virtual bool isDestroyed() { return true; }
};

#endif