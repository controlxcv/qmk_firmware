#pragma once

#define STARTUP_SONG SONG(PREONIC_SOUND)
#define DEFAULT_LAYER_SONGS { \
    SONG(COLEMAK_SOUND), \
    SONG(QWERTY_SOUND), \
    SONG(DVORAK_SOUND) \
}

#define NO_MUSIC_MODE

#define FORCE_NKRO

/* RGB Layout
    esc ------------\
    |  6  5   4  3  |
    |       0       |
    |  7  8   1  2  |
    \----- spc -- ent
*/
// #ifdef RGBLED_NUM
// #undef RGBLED_NUM
// #endif
// #define RGBLED_NUM 9
//                            0  1  2  3  4  5  6  7  8  unmapped
// #define RGBLIGHT_LED_MAP { 0, 3, 4, 8, 7, 6, 5, 1, 2 }
// #define RGBLIGHT_LED_MAP { 0, 3, 4, 4, 3, 2, 1, 1, 2 }
// #define RGBLIGHT_LED_MAP { 2, 2, 3, 4, 3, 2, 1, 0, 1 }

//#define USE_CIE1931_CURVE

#undef RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST

#define RGBLIGHT_HUE_STEP 8      // 0 8 16 24 ... 240 248 256 (32 steps, wrap around)
#define RGBLIGHT_DEFAULT_HUE 0

#define RGBLIGHT_SAT_STEP 51     // 0 51 102 153 204 255 (6 steps)
#define RGBLIGHT_DEFAULT_SAT 255

#define RGBLIGHT_VAL_STEP 51     // 0 51 102 153 204 255 (6 steps)
#define RGBLIGHT_DEFAULT_VAL 255

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
