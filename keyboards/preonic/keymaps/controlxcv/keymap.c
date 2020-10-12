#include QMK_KEYBOARD_H

#include "_diagnostics.h"
#include "_keymaps.h"

/*----------------------------------------------------------
 * Key codes
 * https://www.usb.org/sites/default/files/hut1_2.pdf
 */

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

/*----------------------------------------------------------
 * Layers
 */

enum my_layers {
    _QWER,
    _COLE,
    _DVOR,
    _COMM,
    _LOWR,
    _RISE,
    _CONF,
    _LOCK,
    _RSET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWER] = KEYMAP_QWER,
    [_COLE] = KEYMAP_COLE,
    [_DVOR] = KEYMAP_DVOR,
    [_COMM] = KEYMAP_COMM,
    [_LOWR] = KEYMAP_LOWR,
    [_RISE] = KEYMAP_RISE,
    [_LOCK] = KEYMAP_LOCK,
    [_CONF] = KEYMAP_CONF,
    [_RSET] = KEYMAP_RSET
};

/*----------------------------------------------------------
 * Functions
 */

void keyboard_post_init_user(void) {

#if defined(RGBLIGHT_ENABLE)
    rgblight_enable();
#if defined(RGBLIGHT_EFFECT_RAINBOW_SWIRL)
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
#else
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
#endif /* RGBLIGHT_EFFECT_RAINBOW_SWIRL */
#endif /* RGBLIGHT_ENABLE */

}

#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
    extern float default_layer_songs[][16][2];
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
    if (layer_state_cmp(state, _QWER)) {
        PLAY_SONG(default_layer_songs[_QWER]);
    }
    else if (layer_state_cmp(state, _COLE)) {
        PLAY_SONG(default_layer_songs[_COLE]);
    }
    else if (layer_state_cmp(state, _DVOR)) {
        PLAY_SONG(default_layer_songs[_DVOR]);
    }
#endif
    return (state | (1UL << _COMM));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWR, _RISE, _CONF);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

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

        default:
            return true; /* Process all other keycodes normally */

    }
}
