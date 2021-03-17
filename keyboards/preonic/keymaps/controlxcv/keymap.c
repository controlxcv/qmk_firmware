#include QMK_KEYBOARD_H
#include "layers.h"

/*----------------------------------------------------------
 * Key codes
 * https://www.usb.org/sites/default/files/hut1_2.pdf
 */

#if defined MACOS_KEYS_ENABLE
    #define KC_MCON KC_SHOW_ALL_WINDOWS
    #define KC_LPAD KC_SHOW_ALL_APPS
    enum my_keycodes {
        KC_SHOW_ALL_WINDOWS = SAFE_RANGE,
        KC_SHOW_ALL_APPS
    };
    enum my_consumer_usages {
        AC_SHOW_ALL_WINDOWS = 0x29F,
        AC_SHOW_ALL_APPS    = 0x2A0
    };
#endif /* MACOS_KEYS_ENABLE */

/*----------------------------------------------------------
 * Layers
 */

enum my_layers {
    _COLE,
    _QWER,
    _DVOR,
    _BASE,
    _XTND,
    _QMKB,
    _RSET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLE] = KEYMAP_COLE,
    [_QWER] = KEYMAP_QWER,
    [_DVOR] = KEYMAP_DVOR,
    [_BASE] = KEYMAP_BASE,
    [_XTND] = KEYMAP_XTND,
    [_QMKB] = KEYMAP_QMKB,
    [_RSET] = KEYMAP_RSET
};

/*----------------------------------------------------------
 * Functions
 */

/* RGB Layout
    esc ------------\
    |  6  5   4  3  |
    |       0       |
    |  7  8   1  2  |
    \----- spc -- ent
*/
void keyboard_pre_init_user(void) {
    rgblight_set_effect_range(1, 8);
}
void keyboard_post_init_user(void) {
    rgblight_setrgb(RGB_OFF);
}

/*
bool led_update_user(led_t led_state) {
    #if defined AUDIO_ENABLE
        static uint8_t caps_state = 0;
        if (caps_state != led_state.caps_lock) {
            led_state.caps_lock ? PLAY_SONG(caps_on) : PLAY_SONG(caps_off);
            caps_state = led_state.caps_lock;
        }
        static uint8_t num_state = 0;
        if (num_state != led_state.num_lock) {
            led_state.num_lock ? PLAY_SONG(num_on) : PLAY_SONG(num_off);
            num_state = led_state.num_lock;
        }
        static uint8_t scroll_state = 0;
        if (scroll_state != led_state.scroll_lock) {
            led_state.scroll_lock ? PLAY_SONG(scroll_on) : PLAY_SONG(scroll_off);
            scroll_state = led_state.scroll_lock;
        }
    #endif
    return true;
}
*/

/* multiply range values */
inline uint16_t mult(uint16_t a, uint16_t b) { return (a >> 8) * (b >> 8); }
/* complement of range */
inline uint16_t comp(uint16_t a) { return UINT16_MAX - a; }

/* 16-bit HSV to RGB computation (still outputs 8-bit) */
RGB rgblight_hsv_to_rgb(HSV hsv) {
    RGB rgb = {.r = 0, .g = 0, .b = 0};
    uint16_t sector = 0;
    uint16_t offset = 0;
    uint16_t high = 0;
    uint16_t mid = 0;
    uint16_t low = 0;
    uint16_t hue = 0;
    uint16_t sat = 0;
    uint16_t val = 0;

    // bypass this function
    // return hsv_to_rgb(hsv);

    #if defined USE_CIE1931_CURVE
        extern const uint8_t CIE1931_CURVE[] PROGMEM;
    #endif

    if (hsv.s == 0) {
        #if defined USE_CIE1931_CURVE
            rgb.r = rgb.g = rgb.b = pgm_read_byte(&CIE1931_CURVE[hsv.v]);
        #else
            rgb.r = rgb.g = rgb.b = hsv.v;
        #endif
        return rgb;
    }

    /* Stretch precision of input from 8-bit to 16-bit */
    hue = hsv.h << 8;
    sat = hsv.s << 8;
    #if defined USE_CIE1931_CURVE
        val = pgm_read_byte(&CIE1931_CURVE[hsv.v]) << 8;
    #else
        val = hsv.v << 8;
    #endif

    /* Important Reminder: Fixed point computations always drop fractional components */

    #define USE_RGBY_HUE
    #if defined USE_RGBY_HUE
        if (hue < 32768) {
            /*
                Warm Arc (RYG)
                Used for hue values in [0, 32768)
                sector_width = 16384

                sector should have range [0, 1]
                    sector = hue / sector_width
                    sector = hue / 16384

                offset possible range is [0, sector_width), or [0, 16384)
                offset is multiplied by 4 to normalize the range to [0, 65536)
                    offset = (hue - (sector * sector_width)) * 4
                    offset = (hue - (sector * 16384)) * 4
            */
            sector = hue >> 14;
            offset = (hue - (sector << 14)) << 2;
        }
        else {
            /*
                Cool Arc (GBR)
                Used for hue values in [32768, 65536)
                sector_width = 8192

                sector should have range [2, 5], so subtract 2 after computing offset
                    sector = hue / sector_width
                    sector = hue / 8192

                offset possible range is [0, sector_width), or [0, 8192)
                offset is multiplied by 8 to normalize the range to [0, 65536)
                    offset = (hue - (sector * sector_width)) * 8
                    offset = (hue - (sector * 8192)) * 8
            */
            sector = hue >> 13;
            offset = (hue - (sector << 13)) << 3;
            sector -= 2;
        }
    #else
        /*
            whole circumference: 65536
            sector_width = 65536 / 6

            sector occupies only the least significant 3 bits (0 to 7)
                sector = hue / sector_width
                sector = hue / (65536 / 6)
                sector = hue / 4 * 3 / 8192

            offset possible range is [0, sector_width), or [0, (65536 / 6))
            offset is multiplied by 6 to normalize the range to [0, 65536)
                offset = (hue - (sector * sector_width)) * 6
                offset = (hue - (sector * (65536 / 6))) * 6
                offset = (hue - ((sector * 8192) / 3 * 4)) * 6
        */
        sector = ((hue >> 2) * 3) >> 13;
        offset = (hue - (((sector << 13) / 3) << 2)) * 6;
    #endif

    high = val >> 8;
    low = mult(val, comp(sat)) >> 8;
    /* mid depends on whether the sector is odd or even */
    mid = ((sector & 1) == 1) ? mult(val, comp(mult(sat, offset))) >> 8 :
                                mult(val, comp(mult(sat, comp(offset)))) >> 8 ;

    switch (sector) {
        case 0:  rgb = (RGB) { .r = high, .g = mid,  .b = low  }; break;
        case 1:  rgb = (RGB) { .r = mid,  .g = high, .b = low  }; break;
        case 2:  rgb = (RGB) { .r = low,  .g = high, .b = mid  }; break;
        case 3:  rgb = (RGB) { .r = low,  .g = mid,  .b = high }; break;
        case 4:  rgb = (RGB) { .r = mid,  .g = low,  .b = high }; break;
        case 5:  rgb = (RGB) { .r = high, .g = low,  .b = mid  }; break;
        default: rgb = (RGB) { .r = 0,    .g = 0,    .b = 0    }; break;
    }
    return rgb;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    #if defined AUDIO_ENABLE && defined DEFAULT_LAYER_SONGS
        extern float default_layer_songs[][16][2];
        if (layer_state_cmp(state, _COLE)) {
            PLAY_SONG(default_layer_songs[_COLE]);
        }
        else if (layer_state_cmp(state, _QWER)) {
            PLAY_SONG(default_layer_songs[_QWER]);
        }
        else if (layer_state_cmp(state, _DVOR)) {
            PLAY_SONG(default_layer_songs[_DVOR]);
        }
    #endif /* AUDIO_ENABLE && DEFAULT_LAYER_SONGS */
    return (state | (1UL << _BASE));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        #if defined MACOS_KEYS_ENABLE
            case KC_SHOW_ALL_WINDOWS:
                if (record->event.pressed) {
                    host_consumer_send(AC_SHOW_ALL_WINDOWS);
                } else {
                    host_consumer_send(0);
                }
                return false; /* Skip all further processing of this key */

            case KC_SHOW_ALL_APPS:
                if (record->event.pressed) {
                    host_consumer_send(AC_SHOW_ALL_APPS);
                } else {
                    host_consumer_send(0);
                }
                return false; /* Skip all further processing of this key */
        #endif /* MACOS_KEYS_ENABLE */

        default:
            return true; /* Process all other keycodes normally */

    }
}
