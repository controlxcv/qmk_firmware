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
    _COMM,
    _OVER,
    _LOCK,
    _FUNC,
    _RSET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLE] = KEYMAP_COLE,
    [_QWER] = KEYMAP_QWER,
    [_COMM] = KEYMAP_COMM,
    [_OVER] = KEYMAP_OVER,
    [_LOCK] = KEYMAP_LOCK,
    [_FUNC] = KEYMAP_FUNC,
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
    rgblight_mode(RGBLIGHT_DEFAULT_MODE);
    default_layer_or(1UL << _COMM);

    #if defined(AUDIO_ENABLE)
        PLAY_SONG(eeprom_reset);
    #endif /* AUDIO_ENABLE */
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

layer_state_t default_layer_state_set_user(layer_state_t state) {
    #if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
        extern float default_layer_songs[][16][2];
        if (layer_state_cmp(state, _COLE)) {
            PLAY_SONG(default_layer_songs[_COLE]);
        }
        else if (layer_state_cmp(state, _QWER)) {
            PLAY_SONG(default_layer_songs[_QWER]);
        }
    #endif /* AUDIO_ENABLE && DEFAULT_LAYER_SONGS */
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
