#include QMK_KEYBOARD_H

#include "_defs.h"
#include "_layers.h"

enum preonic_layers {
    _QWER = 0,
    _COLE,
    _DVOR,
    _COMM = 8,
    _LOWR,
    _RISE,
    _LOCK = 13,
    _CONF,
    _RSET
};

enum preonic_keycodes {
    _KC_NULL = SAFE_RANGE,
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

/* QMK functions */

void keyboard_post_init_user(void) {
    layer_clear();
    default_layer_set(1UL << _QWER);
    clicky_off();
}

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
    layer_on(_COMM);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWR, _RISE, _CONF);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _KC_NULL:
            if (record->event.pressed) {
            } else {
            }
            return false;
            break;
      }
    return true;
};
