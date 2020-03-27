#ifndef RandColor_h
#define RandColor_h

#include <Arduino.h>
#include <FastLED.h>

/*enum ColorScheme {
    MARDI_GRAS,
    CHRISTMAS,
    RANDOM,
    PASTEL
};*/

#define CURRENT_PALETTE TROVE

FL_ALIGN_PROGMEM static const TProgmemPalette16 MARDI_GRAS FL_PROGMEM = {
    CRGB::Green,
    CRGB::Purple,
    CRGB::Yellow,
    CRGB::Black,

    CRGB::Green,
    CRGB::Purple,
    CRGB::Yellow,
    CRGB::Black,

    CRGB::Green,
    CRGB::Green,
    CRGB::Purple,
    CRGB::Purple,
    CRGB::Yellow,
    CRGB::Yellow,
    CRGB::Black,
    CRGB::Black
};

// Gradient palette "purplefly_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/purplefly.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.
FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte PURPLEFLY[] FL_PROGMEM {
    0,   0,  0,  0,
   63, 239,  0,122,
  191, 252,255, 78,
  255,   0,  0,  0
};

// Gradient palette "catfairy_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/catfairy.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.
FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte CATFAIRY[] FL_PROGMEM {
    0,  74,124, 85,
   76, 152,128, 44,
  127, 144, 97, 96,
  178, 100, 72,102,
  232,  78, 90,122,
  255,  78, 90,122
};

// Gradient palette "patriot_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/patriot.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.
FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte PATRIOT[] FL_PROGMEM {
    0, 255,  0,  0,
  122, 255,  0,  0,
  132,   0, 16,255,
  255,   0, 16,255
};

// Gradient palette "healingangel_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/healingangel.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.
FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte HEALING_ANGEL[] FL_PROGMEM {
    0,  94,156,174,
   45,  66,105,166,
   84, 117,117,192,
  127, 173,124,156,
  170, 208,108,106,
  211, 197,119, 73,
  255, 210,221,123
};

// Gradient palette "lailah1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/lailah1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 48 bytes of program space.
FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte LAILAH1[] FL_PROGMEM {
    0,  13,  1,  4,
   28,  34,  5, 19,
   56,   1,  1,  3,
   79,   1,  1, 75,
  101,  31, 15,  4,
  127,  80, 43,  7,
  150,   1, 45, 27,
  173,  64,252,205,
  196,  20, 23,  2,
  216, 234,252, 89,
  237,   8,  2,  6,
  255, 175, 70, 88
};

// Gradient palette "spellbound_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/spellbound.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 84 bytes of program space.
FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte SPELLBOUND[] FL_PROGMEM {
    0, 232,235, 40,
   12, 157,248, 46,
   25, 100,246, 51,
   45,  53,250, 33,
   63,  18,237, 53,
   81,  11,211,162,
   94,  18,147,214,
  101,  43,124,237,
  112,  49, 75,247,
  127,  49, 75,247,
  140,  92,107,247,
  150, 120,127,250,
  163, 130,138,252,
  173, 144,131,252,
  186, 148,112,252,
  196, 144, 37,176,
  211, 113, 18, 87,
  221, 163, 33, 53,
  234, 255,101, 78,
  247, 229,235, 46,
  255, 229,235, 46
};

// Gradient palette "sunlitwave_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/sunlitwave.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte SUNLIT_WAVE[] FL_PROGMEM {
    0,   5,  9, 84,
   45,  37, 24,111,
   81,  16,  5, 59,
  112,  24,  1, 20,
  150,  34,  1,  2,
  198, 175, 36,  7,
  237, 208,104, 16,
  255, 239,211,158
};

// Gradient palette "trove_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/trove.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 84 bytes of program space.
FL_ALIGN_PROGMEM static const TProgmemRGBGradientPalette_byte TROVE[] FL_PROGMEM {
    0,  12, 23, 11,
   12,   8, 52, 27,
   25,  32,142, 64,
   38,  55, 68, 30,
   51, 190,135, 45,
   63, 201,175, 59,
   76, 186, 80, 20,
   89, 220, 79, 32,
  101, 184, 33, 14,
  114, 137, 16, 15,
  127, 118, 20, 27,
  140,  79, 16, 35,
  153,  67,  8, 26,
  165,  22,  9, 42,
  178,  11,  3, 34,
  191,  58, 31,109,
  204, 186, 49, 83,
  216, 182, 25, 55,
  229,  39, 90,100,
  242,  15, 81,132,
  255,  68,135, 52
};

//#define CURRENT_SCHEME RANDOM

static float randFloat() { return (float) random(0, RAND_MAX) / (float) RAND_MAX; }

static uint8_t fairRoundedRandom(float min, float max) {
    uint8_t retVal;
    max++;

    do {
        retVal = (uint8_t) floor(randFloat() * (max - min) + min);
    } while (retVal > max - 1);

    return retVal;
}

static CHSV getRandColor(CRGBPalette32 palette, TBlendType blending, uint8_t *currentIndex) {
    while (true) {
        uint8_t r = fairRoundedRandom(0.0f, 255.0f);
        bool flipMin = false;
        float min = *currentIndex - 8.0f;
        if (min < 0.0f) {
            min = 255.0f - min;
            flipMin = true;
        }
        bool flipMax = false;
        float max = *currentIndex + 8.0f;
        if (max > 255.0f) {
            max = 255.0f - max;
            flipMax = true;
        }
        if ((flipMin && r > min) || (!flipMin && r < min) || (flipMax && r < max) || (!flipMax && r > max)) {
            *currentIndex = r;
            return rgb2hsv_approximate(ColorFromPalette(palette, r, 255, blending));
        }
    }
}

/*static uint8_t getRandHue(uint8_t currentHue) {
    uint8_t r;
    switch (CURRENT_SCHEME) {
        case MARDI_GRAS:
            while (true) {
                r = fairRoundedRandom(0.0f, 2.0f);
                if (r == 0 && currentHue != 96) {
                    return 96; // Green
                } else if (r == 1 && currentHue != 192) {
                    return 192; // Purple
                } else if (r == 2 && currentHue != 64) {
                    return 64; // Yellow
                }
            }
        case CHRISTMAS:
            while (true) {
                r = fairRoundedRandom(0.0f, 1.0f);
                if (r == 0 && currentHue != 96) {
                    return 96; // Green
                } else if (r == 1 && currentHue != 0) {
                    return 0; // Red
                }
            }
        case RANDOM:
            while (true) {
                r = fairRoundedRandom(0.0f, 255.0f);
                bool flipMin = false;
                float min = currentHue - 8.0f;
                if (min < 0.0f) {
                    min = 255.0f - min;
                    flipMin = true;
                }
                bool flipMax = false;
                float max = currentHue + 8.0f;
                if (max > 255.0f) {
                    max = 255.0f - max;
                    flipMax = true;
                }
                if ((flipMin && r > min) || (!flipMin && r < min) || (flipMax && r < max) || (!flipMax && r > max)) {
                    return r;
                }
            }
        default:
            return 0;
    }
}

static CHSV getRandColor(CHSV currentColor) {
    uint8_t r;
    switch (CURRENT_SCHEME) {
        case PASTEL:
            while (true) {
                r = fairRoundedRandom(0.0f, 2.0f);
                if (r == 0 && currentColor.h != 96) {
                    return CHSV(96, UINT8_MAX, UINT8_MAX); // Green
                } else if (r == 1 && currentColor.h != 192) {
                    return CHSV(192, UINT8_MAX, UINT8_MAX); // Purple
                } else if (r == 2 && currentColor.h != 64) {
                    return CHSV(64, UINT8_MAX, UINT8_MAX); // Yellow
                }
            }
        default:
            return CHSV(getRandHue(currentColor.h), UINT8_MAX, UINT8_MAX);
    }
}*/

#endif