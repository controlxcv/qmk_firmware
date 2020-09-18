#include QMK_KEYBOARD_H
#include "layers.h"

/*----------------------------------------------------------
 * Key codes
 * https://www.usb.org/sites/default/files/hut1_2.pdf
 */

#define _KC_MCON _KC_SHOW_ALL_WINDOWS
#define _KC_LPAD _KC_SHOW_ALL_APPS

enum my_keycodes {
	_KC_SHOW_ALL_WINDOWS = SAFE_RANGE,
	_KC_SHOW_ALL_APPS
};

enum my_consumer_usages {
    _AC_SHOW_ALL_WINDOWS = 0x29F,
    _AC_SHOW_ALL_APPS    = 0x2A0
};

/*----------------------------------------------------------
 * Layers
 */

enum my_layers {
    _BASE = 0,
    _EDIT,
    _NPAD,
    _FUNC,
    _TEST = 13,
    _MODE, /* 14 */
    _DEV   /* 15 */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE]  = KEYMAP_BASE,
    [_EDIT]  = KEYMAP_EDIT,
    [_NPAD]  = KEYMAP_NPAD,
    [_FUNC]  = KEYMAP_FUNC,
    [_TEST]  = KEYMAP_TEST,
    [_MODE]  = KEYMAP_MODE,
    [_DEV]   = KEYMAP_DEV
};

/*----------------------------------------------------------
 * Functions
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case _KC_SHOW_ALL_WINDOWS:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_WINDOWS);
            } else {
                host_consumer_send(0);
            }
            return false; /* Skip all further processing of this key */

        case _KC_SHOW_ALL_APPS:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_APPS);
            } else {
                host_consumer_send(0);
            }
            return false; /* Skip all further processing of this key */

        default:
            return true; /* Process all other keycodes normally */

    }
}
