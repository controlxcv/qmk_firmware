#pragma once

#include "macros.h"

#define KEYMAP_QWERTY LAYOUT_preonic_grid_vertical(             \
    RAISE,      KC_LSFT,    KC_BSLS,    KC_TAB,     KC_GRV,     \
    KC_LCTL,    KC_Z,       KC_A,       KC_Q,       KC_1,       \
    KC_LALT,    KC_X,       KC_S,       KC_W,       KC_2,       \
    KC_LGUI,    KC_C,       KC_D,       KC_E,       KC_3,       \
    LOWER,      KC_V,       KC_F,       KC_R,       KC_4,       \
    KC_SPC,     KC_B,       KC_G,       KC_T,       KC_5,       \
    KC_SPC,     KC_N,       KC_H,       KC_Y,       KC_6,       \
    KC_ENT,     KC_M,       KC_J,       KC_U,       KC_7,       \
    KC_LEFT,    KC_COMM,    KC_K,       KC_I,       KC_8,       \
    KC_DOWN,    KC_DOT,     KC_L,       KC_O,       KC_9,       \
    KC_UP,      KC_SLSH,    KC_SCLN,    KC_P,       KC_0,       \
    KC_RGHT,    KC_QUOT,    KC_MINS,    KC_EQL,     KC_BSPC     \
)

#define KEYMAP_DVORAK LAYOUT_preonic_grid_vertical(             \
    RAISE,      KC_LSFT,    KC_BSLS,    KC_TAB,     KC_GRV,     \
    KC_LCTL,    KC_Z,       KC_A,       KC_Q,       KC_1,       \
    KC_LALT,    KC_X,       KC_R,       KC_W,       KC_2,       \
    KC_LGUI,    KC_C,       KC_S,       KC_F,       KC_3,       \
    LOWER,      KC_V,       KC_T,       KC_P,       KC_4,       \
    KC_SPC,     KC_B,       KC_D,       KC_G,       KC_5,       \
    KC_SPC,     KC_K,       KC_H,       KC_J,       KC_6,       \
    KC_ENT,     KC_M,       KC_N,       KC_L,       KC_7,       \
    KC_LEFT,    KC_COMM,    KC_E,       KC_U,       KC_8,       \
    KC_DOWN,    KC_DOT,     KC_I,       KC_Y,       KC_9,       \
    KC_UP,      KC_SLSH,    KC_O,       KC_SCLN,    KC_0,       \
    KC_RGHT,    KC_QUOT,    KC_MINS,    KC_EQL,     KC_BSPC     \
)

#define KEYMAP_COLEMAK LAYOUT_preonic_grid_vertical(            \
    RAISE,      KC_LSFT,    KC_BSLS,    KC_TAB,     KC_GRV,     \
    KC_LCTL,    KC_SCLN,    KC_A,       KC_SLSH,    KC_1,       \
    KC_LALT,    KC_Q,       KC_O,       KC_COMM,    KC_2,       \
    KC_LGUI,    KC_J,       KC_E,       KC_DOT,     KC_3,       \
    LOWER,      KC_K,       KC_U,       KC_P,       KC_4,       \
    KC_SPC,     KC_X,       KC_I,       KC_Y,       KC_5,       \
    KC_SPC,     KC_B,       KC_D,       KC_F,       KC_6,       \
    KC_ENT,     KC_M,       KC_H,       KC_G,       KC_7,       \
    KC_LEFT,    KC_W,       KC_T,       KC_C,       KC_8,       \
    KC_DOWN,    KC_V,       KC_N,       KC_R,       KC_9,       \
    KC_UP,      KC_Z,       KC_S,       KC_L,       KC_0,       \
    KC_RGHT,    KC_QUOT,    KC_MINS,    KC_EQL,     KC_BSPC     \
)

#define KEYMAP_LOWER LAYOUT_preonic_grid_vertical(              \
    _______,    _______,    KC_LANG1,   KC_LANG2,   KC_ESC,     \
    _______,    _______,    _______,    KC_F11,     KC_F1,      \
    _______,    _______,    _______,    KC_F12,     KC_F2,      \
    _______,    _______,    _______,    KC_F13,     KC_F3,      \
    _______,    _______,    _______,    KC_F14,     KC_F4,      \
    _______,    _______,    _______,    KC_F15,     KC_F5,      \
    _______,    _______,    _______,    KC_F16,     KC_F6,      \
    KC_PENT,    _______,    _______,    KC_F17,     KC_F7,      \
    KC_HOME,    _______,    _______,    KC_F18,     KC_F8,      \
    KC_PGDN,    _______,    _______,    KC_F19,     KC_F9,      \
    KC_PGUP,    _______,    _______,    KC_NLCK,    KC_F10,     \
    KC_END,     _______,    KC_RBRC,    KC_LBRC,    KC_DEL      \
)

#define KEYMAP_RAISE LAYOUT_preonic_grid_vertical( \
    _______,    _______,    _______,        _______,        _______,    \
    _______,    _______,    _______,        _______,        _______,    \
    _______,    _______,    _______,        _______,        _______,    \
    _______,    _______,    _______,        _______,        _______,    \
    _______,    _______,    _______,        _______,        _______,    \
    KC_MPLY,    _______,    _______,        _______,        _______,    \
    KC_MPLY,    _______,    _______,        _______,        _______,    \
    _______,    _______,    _______,        _______,        _______,    \
    KC_MRWD,    _______,    _______,        _______,        _______,    \
    KC_MPRV,    _______,    _______,        _______,        _______,    \
    KC_MNXT,    _______,    _______,        _______,        _______,    \
    KC_MFFD,    _______,    S(A(KC_VOLD)),  S(A(KC_VOLU)),  KC_MUTE     \
)

#define KEYMAP_ADJUST LAYOUT_preonic_grid_vertical( \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    QWERTY,     XXXXXXX,    XXXXXXX,    RESET,      XXXXXXX,    \
    COLEMAK,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    DVORAK,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)
