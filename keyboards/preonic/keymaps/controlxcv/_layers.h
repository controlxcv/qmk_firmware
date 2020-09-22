#pragma once

#define KEYMAP_QWERTY LAYOUT_preonic_grid_vertical( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    KC_Z,       KC_A,       KC_Q,       XXXXXXX,    \
    XXXXXXX,    KC_X,       KC_S,       KC_W,       XXXXXXX,    \
    XXXXXXX,    KC_C,       KC_D,       KC_E,       XXXXXXX,    \
    XXXXXXX,    KC_V,       KC_F,       KC_R,       XXXXXXX,    \
    XXXXXXX,    KC_B,       KC_G,       KC_T,       XXXXXXX,    \
    XXXXXXX,    KC_N,       KC_H,       KC_Y,       XXXXXXX,    \
    XXXXXXX,    KC_M,       KC_J,       KC_U,       XXXXXXX,    \
    XXXXXXX,    KC_COMM,    KC_K,       KC_I,       XXXXXXX,    \
    XXXXXXX,    KC_DOT,     KC_L,       KC_O,       XXXXXXX,    \
    XXXXXXX,    KC_SLSH,    KC_SCLN,    KC_P,       XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_COLEMAK LAYOUT_preonic_grid_vertical( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    KC_Z,       KC_A,       KC_Q,       XXXXXXX,    \
    XXXXXXX,    KC_X,       KC_R,       KC_W,       XXXXXXX,    \
    XXXXXXX,    KC_C,       KC_S,       KC_F,       XXXXXXX,    \
    XXXXXXX,    KC_V,       KC_T,       KC_P,       XXXXXXX,    \
    XXXXXXX,    KC_B,       KC_D,       KC_G,       XXXXXXX,    \
    XXXXXXX,    KC_K,       KC_H,       KC_J,       XXXXXXX,    \
    XXXXXXX,    KC_M,       KC_N,       KC_L,       XXXXXXX,    \
    XXXXXXX,    KC_COMM,    KC_E,       KC_U,       XXXXXXX,    \
    XXXXXXX,    KC_DOT,     KC_I,       KC_Y,       XXXXXXX,    \
    XXXXXXX,    KC_SLSH,    KC_O,       KC_SCLN,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_DVORAK LAYOUT_preonic_grid_vertical( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    KC_SCLN,    KC_A,       KC_SLSH,    XXXXXXX,    \
    XXXXXXX,    KC_Q,       KC_O,       KC_COMM,    XXXXXXX,    \
    XXXXXXX,    KC_J,       KC_E,       KC_DOT,     XXXXXXX,    \
    XXXXXXX,    KC_K,       KC_U,       KC_P,       XXXXXXX,    \
    XXXXXXX,    KC_X,       KC_I,       KC_Y,       XXXXXXX,    \
    XXXXXXX,    KC_B,       KC_D,       KC_F,       XXXXXXX,    \
    XXXXXXX,    KC_M,       KC_H,       KC_G,       XXXXXXX,    \
    XXXXXXX,    KC_W,       KC_T,       KC_C,       XXXXXXX,    \
    XXXXXXX,    KC_V,       KC_N,       KC_R,       XXXXXXX,    \
    XXXXXXX,    KC_Z,       KC_S,       KC_L,       XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_COMMON LAYOUT_preonic_grid_vertical( \
    KC_LCTL,    KC_TAB,     KC_QUOT,    KC_BSLS,    KC_GRV,     \
    KC_LALT,    _______,    _______,    _______,    KC_1,       \
    LOWER,      _______,    _______,    _______,    KC_2,       \
    RAISE,      _______,    _______,    _______,    KC_3,       \
    KC_LGUI,    _______,    _______,    _______,    KC_4,       \
    KC_SPC,     _______,    _______,    _______,    KC_5,       \
    KC_SPC,     _______,    _______,    _______,    KC_6,       \
    KC_LSFT,    _______,    _______,    _______,    KC_7,       \
    KC_LEFT,    _______,    _______,    _______,    KC_8,       \
    KC_DOWN,    _______,    _______,    _______,    KC_9,       \
    KC_UP,      _______,    _______,    _______,    KC_0,       \
    KC_RGHT,    KC_ENT,     KC_MINS,    KC_EQL,     KC_BSPC     \
)

#define KEYMAP_RAISE LAYOUT_preonic_grid_vertical( \
    _______,    _______,    _______,    _______,    KC_ESC,     \
    _______,    _______,    _______,    KC_F11,     KC_F1,      \
    _______,    _______,    _______,    KC_F12,     KC_F2,      \
    _______,    _______,    _______,    KC_F13,     KC_F3,      \
    _______,    _______,    _______,    KC_F14,     KC_F4,      \
    _______,    _______,    _______,    KC_F15,     KC_F5,      \
    _______,    _______,    _______,    KC_F16,     KC_F6,      \
    _______,    _______,    _______,    KC_F17,     KC_F7,      \
    KC_HOME,    KC_LBRC,    _______,    KC_F18,     KC_F8,      \
    KC_PGDN,    KC_RBRC,    _______,    KC_F19,     KC_F9,      \
    KC_PGUP,    _______,    _______,    _______,    KC_F10,     \
    KC_END,     KC_PENT,    KC_LANG1,   KC_LANG2,   KC_DEL      \
)

#define KEYMAP_LOWER LAYOUT_preonic_grid_vertical( \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    \
    KC_MPRV,    _______,    _______,    _______,    _______,    \
    KC_VOLD,    _______,    _______,    _______,    _______,    \
    KC_VOLU,    _______,    _______,    _______,    _______,    \
    KC_MNXT,    KC_MPLY,    _______,    _______,    _______     \
)

#define KEYMAP_ADJUST LAYOUT_preonic_grid_vertical( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    CK_TOGG,    QWERTY,     XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    COLEMAK,    XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    DVORAK,     XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    MO(_RESET)  \
)

#define KEYMAP_RESET LAYOUT_preonic_grid_vertical( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,      \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    EEP_RST,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______     \
)
