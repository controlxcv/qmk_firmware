#pragma once

#define KEYMAP_QWER LAYOUT_preonic_grid( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       XXXXXXX,    \
    XXXXXXX,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    XXXXXXX,    \
    XXXXXXX,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_COLE LAYOUT_preonic_grid( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    XXXXXXX,    \
    XXXXXXX,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       XXXXXXX,    \
    XXXXXXX,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_DVOR LAYOUT_preonic_grid( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    KC_SLSH,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       XXXXXXX,    \
    XXXXXXX,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       XXXXXXX,    \
    XXXXXXX,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_COMM LAYOUT_preonic_grid( \
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSLS,    \
    KC_LBRC,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_EQL,     \
    KC_RBRC,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MINS,    \
    OSM_LSFT,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_QUOT,    \
    MO(_LOWR),  OSM_LCTL,   OSM_LALT,   OSM_LGUI,   MO(_RISE),  KC_SPC,     KC_SPC,     KC_BSPC,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT     \
)

#define KEYMAP_RISE LAYOUT_preonic_grid( \
    KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_NLCK,    \
    KC_TAB,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_F11,     \
    KC_CAPS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_F12,     \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_INS,     \
    _______,    _______,    _______,    _______,    _______,    KC_ENT,     KC_ENT,     KC_DEL,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END      \
)

#define KEYMAP_LOWR LAYOUT_preonic_grid( \
    KC_PWR,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_EJCT,    \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LANG1,   \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LANG2,   \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_APP,     \
    _______,    _______,    _______,    _______,    _______,    KC_MPLY,    KC_MPLY,    KC_MSTP,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT     \
)

#define KEYMAP_LOCK LAYOUT_preonic_grid( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_CONF LAYOUT_preonic_grid( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    DF(_QWER),  DF(_COLE),  DF(_DVOR),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    CK_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    TG(_LOCK),  TG(_LOCK),  MO(_RSET),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)

#define KEYMAP_RSET LAYOUT_preonic_grid( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,      \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    EEP_RST,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX     \
)
