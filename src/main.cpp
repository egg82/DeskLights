#include <Arduino.h>

#include <RandColor.h>
#include <LEDController.h>

#include <Effects/FadeRandColor.h>
#include <Effects/PongRandColor.h>
#include <Effects/RadiateRandColor.h>
#include <Effects/ChaseRandColor.h>
#include <Effects/ChaseRainbow.h>

enum Effect {
    FADE_RAND_COLOR,
    PONG_RAND_COLOR,
    RADIATE_RAND_COLOR,
    CHASE_RAND_COLOR,
    CHASE_RAINBOW,
    NONE
};

LEDController controller;
unsigned long lastRandTime = 0;
bool ready = false;
Effect currentEffect;

void setSeeds(float seed);
float randFloat();
float getNoise();
IEffect *getEffect(Effect effect);

void setup() {
  Serial.begin(9600);

  setSeeds(getNoise());

  uint8_t index = UINT8_MAX;
  controller.clear(getRandColor(CURRENT_PALETTE, LINEARBLEND, &index));
  currentEffect = static_cast<Effect>(random(0, NONE));
  controller.setEffect(getEffect(currentEffect));

  lastRandTime = millis();
}

void loop() {
  unsigned long mills = millis();
  if (controller.loop(mills)) {
    // Account for time taken during setup when calculating for effect switch
    if (!ready && controller.isReady()) {
      ready = true;
      lastRandTime = mills;
    }

    // Ensure we don't switch effects too quickly
    unsigned long m = mills - lastRandTime;
    if (ready && (m >= 30000 || (m >= 15000 && randFloat() <= 0.01F))) {
      // Ensure we get a different random function
      do {
        Effect e = static_cast<Effect>(fairRoundedRandom(0.0f, (float) NONE - 1.0f));
        if (e != NONE && e != currentEffect) {
          currentEffect = e;
          controller.setEffect(getEffect(e));
          setSeeds(getNoise());
          break;
        }
      } while (true);
      ready = false;
    }
  }
}

void setSeeds(float seed) {
  random16_set_seed(seed);
  randomSeed(seed);
}

float getNoise() {
  float retVal = 0.0F;
  do {
    retVal += analogRead(A0);
    retVal += analogRead(A1);
    retVal += analogRead(A2);
    retVal += analogRead(A3);
    retVal += analogRead(A4);
    retVal += analogRead(A5);
    if (retVal != 0.0F) {
      retVal /= 6.0F;
      while (floor(retVal) != retVal) {
        retVal *= 10.0F;
      }
      return retVal;
    }
  } while (true);
}

IEffect *getEffect(Effect effect) {
  Serial.print("Using effect ");
  Serial.println(effect);
  switch (effect) {
    case FADE_RAND_COLOR:
    return new FadeRandColor();
    case PONG_RAND_COLOR:
    return new PongRandColor();
    case RADIATE_RAND_COLOR:
    return new RadiateRandColor();
    case CHASE_RAND_COLOR:
    return new ChaseRandColor();
    case CHASE_RAINBOW:
    return new ChaseRainbow();
    default:
    return NULL;
  }
}