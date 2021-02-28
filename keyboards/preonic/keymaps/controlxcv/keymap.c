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
    _COMM,
    _OVER,
    _FUNC,
    _LOCK,
    _RSET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLE] = KEYMAP_COLE,
    [_QWER] = KEYMAP_QWER,
    [_DVOR] = KEYMAP_DVOR,
    [_COMM] = KEYMAP_COMM,
    [_OVER] = KEYMAP_OVER,
    [_FUNC] = KEYMAP_FUNC,
    [_LOCK] = KEYMAP_LOCK,
    [_RSET] = KEYMAP_RSET
};

/*----------------------------------------------------------
 * Functions
 */

void keyboard_post_init_user(void) {
    #if defined(RGBLIGHT_ENABLE)
        rgblight_enable();
        rgblight_sethsv(HSV_WHITE);
        // #if defined(RGBLIGHT_EFFECT_RAINBOW_SWIRL)
        //     rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
        // #else
        //     rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // #endif /* RGBLIGHT_EFFECT_RAINBOW_SWIRL */
    #endif /* RGBLIGHT_ENABLE */
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
#endif
    return (state | (1UL << _COMM));
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
