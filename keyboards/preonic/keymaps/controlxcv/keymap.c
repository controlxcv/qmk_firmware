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
    KC_MCTL = SAFE_RANGE,
    KC_LPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer: keyboard layouts */
    [_QWER] = KEYMAP_QWER,
    [_COLE] = KEYMAP_COLE,
    [_DVOR] = KEYMAP_DVOR,
    /* Default layer: common keys */
    [_COMM] = KEYMAP_COMM,
    /* Alternate keys */
    [_LOWR] = KEYMAP_LOWR,
    [_RISE] = KEYMAP_RISE,
    /* Key lock */
    [_LOCK] = KEYMAP_LOCK,
    /* Configuration */
    [_CONF] = KEYMAP_CONF,
    [_RSET] = KEYMAP_RSET
};

void keyboard_post_init_user(void) {
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
    return (state | (1UL << _COMM));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWR, _RISE, _CONF);
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
  }
  if (mods & MOD_MASK_CTRL) {
  }
  if (mods & MOD_MASK_ALT) {
  }
  if (mods & MOD_MASK_GUI) {
  }
  if (!mods) {
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_NULL:
            if (record->event.pressed) {
            } else {
            }
            return false;
            break;
      }
    return true;
};
