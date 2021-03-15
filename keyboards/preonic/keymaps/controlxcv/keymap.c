#include QMK_KEYBOARD_H
#include "layers.h"

/*----------------------------------------------------------
 * Key codes
 * https://www.usb.org/sites/default/files/hut1_2.pdf
 */

#if defined(MACOS_KEYS_ENABLE)
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

#if defined(AUDIO_ENABLE)
    float eeprom_reset[][2] = SONG(STARTUP_SOUND);
    // float caps_on[][2] = SONG(CAPS_LOCK_ON_SOUND);
    // float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
    // float num_on[][2] = SONG(NUM_LOCK_ON_SOUND);
    // float num_off[][2] = SONG(NUM_LOCK_OFF_SOUND);
    // float scroll_on[][2] = SONG(SCROLL_LOCK_ON_SOUND);
    // float scroll_off[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
#endif

void eeconfig_init_user(void) {
    eeconfig_update_rgblight_default();
    rgblight_setrgb(RGB_OFF);
    rgblight_mode(RGBLIGHT_DEFAULT_MODE);
    default_layer_or(1UL << _BASE);

    #if defined(AUDIO_ENABLE)
        PLAY_SONG(eeprom_reset);
    #endif /* AUDIO_ENABLE */
}

/* RGB Layout
    esc ------------\
    |  6  5   4  3  |
    |       0       |
    |  7  8   1  2  |
    \----- spc -- ent
*/
void keyboard_pre_init_user(void) {
    // define range of virtual leds to be mapped to the physical ones
    // rgblight_set_clipping_range(VLED_START, RGBLED_NUM);
    // define range of virtual leds to use for effects
    rgblight_set_effect_range(1, 8);
}
void keyboard_post_init_user(void) {
    rgblight_setrgb(RGB_OFF);
}

// bool led_update_user(led_t led_state) {
//     #if defined AUDIO_ENABLE
//         static uint8_t caps_state = 0;
//         if (caps_state != led_state.caps_lock) {
//             led_state.caps_lock ? PLAY_SONG(caps_on) : PLAY_SONG(caps_off);
//             caps_state = led_state.caps_lock;
//         }
//         static uint8_t num_state = 0;
//         if (num_state != led_state.num_lock) {
//             led_state.num_lock ? PLAY_SONG(num_on) : PLAY_SONG(num_off);
//             num_state = led_state.num_lock;
//         }
//         static uint8_t scroll_state = 0;
//         if (scroll_state != led_state.scroll_lock) {
//             led_state.scroll_lock ? PLAY_SONG(scroll_on) : PLAY_SONG(scroll_off);
//             scroll_state = led_state.scroll_lock;
//         }
//     #endif
//     return true;
// }

RGB rgblight_hsv_to_rgb(HSV hsv) {
    RGB      rgb;
    uint8_t  region, remainder, p, q, t;
    uint16_t h, s, v;

    #if defined(USE_CIE1931_CURVE)
        extern const uint8_t CIE1931_CURVE[];
    #endif

    if (hsv.s == 0) {
        #if defined(USE_CIE1931_CURVE)
            rgb.r = rgb.g = rgb.b = pgm_read_byte(&CIE1931_CURVE[hsv.v]);
        #else
            rgb.r = rgb.g = rgb.b = hsv.v;
        #endif
        return rgb;
    }

    // transform hue

    h = hsv.h;
    s = hsv.s;
    #if defined(USE_CIE1931_CURVE)
        v = pgm_read_byte(&CIE1931_CURVE[hsv.v]);
    #else
        v = hsv.v;
    #endif

    region    = h * 6 / 255;
    remainder = (h * 2 - region * 85) * 3;

    // P = V * S
    p = (v * (255 - s)) >> 8;

    // Q = V * 
    q = (v * (255 - ((s * remainder) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

    switch (region) {
        case 6:
        case 0:
            rgb.r = v;
            rgb.g = t;
            rgb.b = p;
            break;
        case 1:
            rgb.r = q;
            rgb.g = v;
            rgb.b = p;
            break;
        case 2:
            rgb.r = p;
            rgb.g = v;
            rgb.b = t;
            break;
        case 3:
            rgb.r = p;
            rgb.g = q;
            rgb.b = v;
            break;
        case 4:
            rgb.r = t;
            rgb.g = p;
            rgb.b = v;
            break;
        default:
            rgb.r = v;
            rgb.g = p;
            rgb.b = q;
            break;
    }

    // rgb.r = 0;
    // rgb.g = 255;
    // rgb.b = 0;

    return rgb;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    #if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
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

        #if defined(MACOS_KEYS_ENABLE)
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
