#pragma once

#define STARTUP_SONG SONG(PREONIC_SOUND)
#define DEFAULT_LAYER_SONGS { \
    SONG(COLEMAK_SOUND), \
    SONG(QWERTY_SOUND), \
    SONG(DVORAK_SOUND) \
}
#define NO_MUSIC_MODE
#define FORCE_NKRO

/*
    RGB Layout
        esc ------------\
        |  6  5   4  3  |
        |       0       |
        |  7  8   1  2  |
        \----- spc -- ent
*/

#undef USE_CIE1931_CURVE
#undef RGBLIGHT_ANIMATIONS

/*                       |  0  1  2  3  4  5  6  7  8  | */
#define RGBLIGHT_LED_MAP {  6, 0, 0, 8, 7, 5, 4, 0, 0  }

#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RGB_TEST

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL

/* 16 ticks, wrap around */
#define RGBLIGHT_HUE_STEP 1 // 16
#define RGBLIGHT_DEFAULT_HUE 0

/* 51 102 153 204 255 */
#define RGBLIGHT_SAT_STEP 1 // 51
#define RGBLIGHT_DEFAULT_SAT 255

/* 51 102 153 204 255 */
#define RGBLIGHT_VAL_STEP 1 // 51
#define RGBLIGHT_DEFAULT_VAL 153
