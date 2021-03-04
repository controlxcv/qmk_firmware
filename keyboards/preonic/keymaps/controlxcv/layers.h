#pragma once

#define KEYMAP_COLE LAYOUT_preonic_1x2uC( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    XXXXXXX, \
    XXXXXXX,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       XXXXXXX, \
    XXXXXXX,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX \
)

#define KEYMAP_QWER LAYOUT_preonic_1x2uC( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX, \
    XXXXXXX,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    XXXXXXX, \
    XXXXXXX,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX \
)

#define KC_SYS_L KC_LGUI
#define KC_SYS_R KC_LCTL
#define KEYMAP_COMM LAYOUT_preonic_1x2uC( \
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC, \
    KC_TAB,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_EQL, \
    KC_QUOT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MINS, \
    KC_LSFT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_RSFT, \
    MO(_OVER),  MO(_FUNC),  KC_LALT,    KC_SYS_L,   KC_SYS_R,         KC_SPC,           KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_ENT \
)

#define KEYMAP_OVER LAYOUT_preonic_1x2uC( \
    KC_LANG1,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL, \
    KC_LANG2,   KC_F11,     KC_F12,     KC_PSCR,    KC_SLCK,    KC_PAUS,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_CLCK, \
    KC_GRV,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_NLCK, \
    _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_BSLS,    _______, \
    _______,    XXXXXXX,    _______,    _______,    _______,          XXXXXXX,          KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS \
)

// Key lock
#define KEYMAP_LOCK LAYOUT_preonic_1x2uC( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX \
)

// QMK functions
#define KEYMAP_FUNC LAYOUT_preonic_1x2uC( \
    MO(_RSET),  DF(_COLE),  DF(_QWER),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_M_P,    RGB_M_R,    RGB_M_SW,   RGB_TOG, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SAI, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SAD, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,          TG(_LOCK),        RGB_HUD,    RGB_VAD,    RGB_VAI,    RGB_HUI,    XXXXXXX \
)

// Reset
#define KEYMAP_RSET LAYOUT_preonic_1x2uC( \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_M_T, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,          EEP_RST,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET \
)
