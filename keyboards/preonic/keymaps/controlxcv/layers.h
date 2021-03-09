#pragma once

#define KEYMAP_COLE LAYOUT_preonic_1x2uC( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    XXXXXXX, \
    XXXXXXX,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       XXXXXXX, \
    XXXXXXX,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_K,       KC_M,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX \
)

#define KEYMAP_QWER LAYOUT_preonic_1x2uC( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX, \
    XXXXXXX,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    XXXXXXX, \
    XXXXXXX,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX \
)

#define KC_SYS_1 KC_LALT
#define KC_SYS_2 KC_LGUI
#define KC_SYS_3 KC_LCTL
#define KEYMAP_COMM LAYOUT_preonic_1x2uC( \
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC, \
    KC_TAB,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_DEL, \
    KC_BSLS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_QUOT, \
    KC_LSFT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT, \
    MO(_FUNC),  KC_SYS_1,   KC_SYS_2,   KC_SYS_3,   MO(_OVER),        KC_SPC,           KC_ENT,     KC_LEFT,    KC_RGHT,    KC_DOWN,    KC_UP \
)

#define KEYMAP_OVER LAYOUT_preonic_1x2uC( \
    KC_PAUS,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MINS,    KC_EQL,     KC_NLCK, \
    KC_SLCK,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_INS, \
    KC_PSCR,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_CLCK, \
    _______,    KC_VOLD,    KC_VOLU,    KC_LANG1,   KC_LANG2,   XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_GRV,     _______, \
    XXXXXXX,    _______,    _______,    _______,    _______,          XXXXXXX,          XXXXXXX,    KC_HOME,    KC_END,     KC_PGDN,    KC_PGUP \
)

// Key lock
#define KEYMAP_LOCK LAYOUT_preonic_1x2uC( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX \
)

// QMK functions
#define KEYMAP_FUNC LAYOUT_preonic_1x2uC( \
    MO(_RSET),  DF(_COLE),  DF(_QWER),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_M_P,    RGB_M_R,    RGB_M_SW,   RGB_M_T, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SAD,    RGB_SAI,    XXXXXXX,    XXXXXXX, \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          TG(_LOCK),        RGB_TOG,    RGB_HUD,    RGB_HUI,    RGB_VAD,    RGB_VAI \
)

// Reset
#define KEYMAP_RSET LAYOUT_preonic_1x2uC( \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          EEP_RST,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX \
)
 