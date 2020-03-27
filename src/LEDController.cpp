#include "LEDController.h"

CHSV leds[NUM_LEDS]; // CHSV colors
CRGB c[NUM_LEDS]; // (converted) CRGB colors
unsigned long lastMills;

LEDController::LEDController() {
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(c, NUM_LEDS);
    FastLED.setBrightness(LED_BRIGHTNESS);
    lastMills = millis();
}

void LEDController::setEffect(IEffect *effect) {
    if (previousEffect != NULL) {
        // Free memory of PREVIOUS previous effect. We keep references to three effects in memory max
        delete previousEffect;
    }
    previousEffect = this->effect;
    this->effect = effect;
    ready = false;
}

bool LEDController::loop(unsigned long mills) {
    unsigned long delta = mills - lastMills;
    if (previousEffect != NULL && !previousEffect->isDestroyed()) {
        // Previous effect hasn't been destroyed yet
        if (previousEffect->canLoop(delta)) {
            previousEffect->destroy(leds, delta);
            lastMills = mills;
            display();
            return true;
        }
    } else if (!ready) {
        // New effect isn't ready yet
        if (effect->canLoop(delta)) {
            effect->setup(leds, delta);
            lastMills = mills;
            display();

            if (effect->isSetup()) {
                ready = true;
            }
            return true;
        }
    } else {
        // Loop new effect
        if (effect->canLoop(delta)) {
            effect->loop(leds, delta);
            lastMills = mills;
            display();
            return true;
        }
    }
    
    displayFast();
    return false;
}

void LEDController::clear(CHSV color) {
    // Convert CHSV to CRGB
    CRGB cCol = CRGB(color);
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        leds[i] = color;
        c[i] = cCol;
    }
    FastLED.show();
}

void LEDController::display() {
    // Convert CHSV to CRGB
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
        c[i] = CRGB(leds[i]);
    }
    FastLED.show();
}