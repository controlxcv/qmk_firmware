#pragma once

#define KEYMAP_QWERTY LAYOUT_preonic_grid( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL, \
    KC_BSLS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
    RAISE,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
)

#define KEYMAP_COLEMAK LAYOUT_preonic_grid( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, \
    KC_BSLS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_MINS, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
    RAISE,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
)

#define KEYMAP_DVORAK LAYOUT_preonic_grid( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_SLSH, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_EQL, \
    KC_BSLS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_QUOT, \
    RAISE,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
)

#define KEYMAP_LOWER LAYOUT_preonic_grid( \
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
    KC_LANG2, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_NLCK, KC_LBRC, \
    KC_LANG1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RBRC, \
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,  _______, _______, _______, _______, _______, _______, KC_PENT, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
)

#define KEYMAP_RAISE LAYOUT_preonic_grid( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, S(A(KC_VOLU)), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, S(A(KC_VOLD)), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, KC_MRWD, KC_MPRV, KC_MNXT, KC_MFFD \
)

#define KEYMAP_ADJUST LAYOUT_preonic_grid( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TERM_ON, TERM_OFF,XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  XXXXXXX, XXXXXXX, \
    XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)
