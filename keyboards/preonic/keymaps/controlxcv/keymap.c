#include QMK_KEYBOARD_H

#include "layout.h"

enum preonic_layers {
    _QWER,
    _COLE,
    _DVOR,
    _COMM,
    _LOWR,
    _RISE,
    _LOCK,
    _CONF,
    _RSET
};

// enum preonic_keycodes {
//     KC_NULL = SAFE_RANGE,
//     KC_MCTL,
//     KC_LPAD
// };

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

// void keyboard_post_init_user(void) {
// }

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

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_NULL:
//             if (record->event.pressed) {
//             } else {
//             }
//             return false;
//             break;
//       }
//     return true;
// };
