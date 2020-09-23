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
    _KC_QWER = SAFE_RANGE,
    _KC_COLE,
    _KC_DVOR,
    _KC_LOWR,
    _KC_RISE
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

/* Local functions */

void use_default_layer(uint8_t default_layer) {
    default_layer_set(1U << default_layer);
    layer_on(_COMM);
}

/* QMK functions */

void keyboard_post_init_user(void) {
    layer_clear();
    default_layer_set(1U << _QWER);
    layer_on(_COMM);
    clicky_off();
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
    /* Play a tune when a keyboard layout is activated */
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
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _KC_QWER:
            if (record->event.pressed) {
                use_default_layer(_QWER);
            }
            return false;
            break;
        case _KC_COLE:
            if (record->event.pressed) {
                use_default_layer(_COLE);
            }
            return false;
            break;
        case _KC_DVOR:
            if (record->event.pressed) {
                use_default_layer(_DVOR);
            }
            return false;
            break;
        case _KC_LOWR:
            if (record->event.pressed) {
                layer_on(_LOWR);
                update_tri_layer(_LOWR, _RISE, _CONF);
            } else {
                layer_off(_LOWR);
                update_tri_layer(_LOWR, _RISE, _CONF);
            }
            return false;
            break;
        case _KC_RISE:
            if (record->event.pressed) {
                layer_on(_RISE);
                update_tri_layer(_LOWR, _RISE, _CONF);
            } else {
                layer_off(_RISE);
                update_tri_layer(_LOWR, _RISE, _CONF);
            }
            return false;
            break;
      }
    return true;
};
