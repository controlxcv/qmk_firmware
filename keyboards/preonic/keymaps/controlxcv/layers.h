#pragma once

#include "macros.h"

#define ___X___ XXXXXXX

#define KEYMAP_QWERTY LAYOUT_preonic_grid_vertical(             \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    KC_Z,       KC_A,       KC_Q,       ___X___,    \
    ___X___,    KC_X,       KC_S,       KC_W,       ___X___,    \
    ___X___,    KC_C,       KC_D,       KC_E,       ___X___,    \
    ___X___,    KC_V,       KC_F,       KC_R,       ___X___,    \
    ___X___,    KC_B,       KC_G,       KC_T,       ___X___,    \
    ___X___,    KC_N,       KC_H,       KC_Y,       ___X___,    \
    ___X___,    KC_M,       KC_J,       KC_U,       ___X___,    \
    ___X___,    KC_COMM,    KC_K,       KC_I,       ___X___,    \
    ___X___,    KC_DOT,     KC_L,       KC_O,       ___X___,    \
    ___X___,    KC_SLSH,    KC_SCLN,    KC_P,       ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___     \
)

#define KEYMAP_COLEMAK LAYOUT_preonic_grid_vertical(            \
    ___X___,    ___X___,    ___X___,     ___X___,   ___X___,    \
    ___X___,    KC_Z,       KC_A,       KC_Q,       ___X___,    \
    ___X___,    KC_X,       KC_R,       KC_W,       ___X___,    \
    ___X___,    KC_C,       KC_S,       KC_F,       ___X___,    \
    ___X___,    KC_V,       KC_T,       KC_P,       ___X___,    \
    ___X___,    KC_B,       KC_D,       KC_G,       ___X___,    \
    ___X___,    KC_K,       KC_H,       KC_J,       ___X___,    \
    ___X___,    KC_M,       KC_N,       KC_L,       ___X___,    \
    ___X___,    KC_COMM,    KC_E,       KC_U,       ___X___,    \
    ___X___,    KC_DOT,     KC_I,       KC_Y,       ___X___,    \
    ___X___,    KC_SLSH,    KC_O,       KC_SCLN,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___     \
)

#define KEYMAP_DVORAK LAYOUT_preonic_grid_vertical(             \
    ___X___,    ___X___,    ___X___,     ___X___,   ___X___,    \
    ___X___,    KC_SCLN,    KC_A,       KC_SLSH,    ___X___,    \
    ___X___,    KC_Q,       KC_O,       KC_COMM,    ___X___,    \
    ___X___,    KC_J,       KC_E,       KC_DOT,     ___X___,    \
    ___X___,    KC_K,       KC_U,       KC_P,       ___X___,    \
    ___X___,    KC_X,       KC_I,       KC_Y,       ___X___,    \
    ___X___,    KC_B,       KC_D,       KC_F,       ___X___,    \
    ___X___,    KC_M,       KC_H,       KC_G,       ___X___,    \
    ___X___,    KC_W,       KC_T,       KC_C,       ___X___,    \
    ___X___,    KC_V,       KC_N,       KC_R,       ___X___,    \
    ___X___,    KC_Z,       KC_S,       KC_L,       ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___     \
)

#define KEYMAP_COMMON LAYOUT_preonic_grid_vertical(             \
    RAISE,      KC_LSFT,    KC_TAB,     KC_BSLS,    KC_GRV,     \
    KC_LCTL,    _______,    _______,    _______,    KC_1,       \
    KC_LALT,    _______,    _______,    _______,    KC_2,       \
    KC_LGUI,    _______,    _______,    _______,    KC_3,       \
    LOWER,      _______,    _______,    _______,    KC_4,       \
    KC_SPC,     _______,    _______,    _______,    KC_5,       \
    KC_SPC,     _______,    _______,    _______,    KC_6,       \
    KC_ENT,     _______,    _______,    _______,    KC_7,       \
    KC_LEFT,    _______,    _______,    _______,    KC_8,       \
    KC_DOWN,    _______,    _______,    _______,    KC_9,       \
    KC_UP,      _______,    _______,    _______,    KC_0,       \
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
    KC_BSPC,    _______,    _______,    KC_F18,     KC_F8,      \
    KC_LEFT,    _______,    _______,    KC_F19,     KC_F9,      \
    KC_RGHT,    _______,    _______,    KC_NLCK,    KC_F10,     \
    KC_DEL,     _______,    KC_RBRC,    KC_LBRC,    KC_DEL      \
)

#define KEYMAP_RAISE LAYOUT_preonic_grid_vertical( \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    KC_MPLY,    _______,    _______,    _______,    _______,    \
    KC_MPLY,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    KC_MRWD,    _______,    _______,    _______,    _______,    \
    KC_MPRV,    _______,    _______,    _______,    _______,    \
    KC_MNXT,    _______,    _______,    _______,    _______,    \
    KC_MFFD,    _______,    KC_VOLD,    KC_VOLU,    KC_MUTE     \
)

#define KEYMAP_ADJUST LAYOUT_preonic_grid_vertical( \
    _______,    ___X___,    ___X___,    ___X___,    ___X___,    \
    QWERTY,     ___X___,    ___X___,    RESET,      ___X___,    \
    COLEMAK,    ___X___,    ___X___,    ___X___,    ___X___,    \
    DVORAK,     ___X___,    ___X___,    ___X___,    ___X___,    \
    _______,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___,    \
    ___X___,    ___X___,    ___X___,    ___X___,    ___X___     \
)
