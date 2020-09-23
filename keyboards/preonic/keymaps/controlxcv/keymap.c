#include QMK_KEYBOARD_H

#include "_defs.h"
#include "_layers.h"

enum preonic_layers {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _COMMON,
    _LOWER = 8,
    _RAISE,
    _LOCK = 13,
    _CONFIG,
    _RESET
};

enum preonic_keycodes {
    _KC_QWERTY = SAFE_RANGE,
    _KC_COLMAK,
    _KC_DVORAK,
    _KC_LOWER,
    _KC_RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP_QWERTY,
    [_COLEMAK] = KEYMAP_COLEMAK,
    [_DVORAK] = KEYMAP_DVORAK,
    [_COMMON] = KEYMAP_COMMON,
    [_LOWER] = KEYMAP_LOWER,
    [_RAISE] = KEYMAP_RAISE,
    [_LOCK] = KEYMAP_LOCK,
    [_CONFIG] = KEYMAP_CONFIG,
    [_RESET] = KEYMAP_RESET
};

/* Local functions */

void use_default_layer(uint8_t default_layer) {
    default_layer_set(1U << default_layer);
}

/* QMK functions */

void keyboard_post_init_user(void) {
    layer_clear();
    default_layer_set(1U << _QWERTY);
    layer_on(_COMMON);
    clicky_off();
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
    /* Play a tune when a keyboard layout is activated */
    if (layer_state_cmp(state, _QWERTY)) {
        PLAY_SONG(default_layer_songs[_QWERTY]);
    }
    else if (layer_state_cmp(state, _COLEMAK)) {
        PLAY_SONG(default_layer_songs[_COLEMAK]);
    }
    else if (layer_state_cmp(state, _DVORAK)) {
        PLAY_SONG(default_layer_songs[_DVORAK]);
    }
#endif
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _KC_QWERTY:
            if (record->event.pressed) {
                use_default_layer(_QWERTY);
            }
            return false;
            break;
        case _KC_COLMAK:
            if (record->event.pressed) {
                use_default_layer(_COLEMAK);
            }
            return false;
            break;
        case _KC_DVORAK:
            if (record->event.pressed) {
                use_default_layer(_DVORAK);
            }
            return false;
            break;
        case _KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _CONFIG);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _CONFIG);
            }
            return false;
            break;
        case _KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _CONFIG);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _CONFIG);
            }
            return false;
            break;
      }
    return true;
};
