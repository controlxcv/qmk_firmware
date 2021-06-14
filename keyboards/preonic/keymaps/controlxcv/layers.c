#include QMK_KEYBOARD_H

enum my_layers { _COLE, _QWER, _DVOR, _BASE, _XTND, _QMKB, _RSET };

layer_state_t default_layer_state_set_user(layer_state_t state) {
    #if defined AUDIO_ENABLE && defined DEFAULT_LAYER_SONGS
        extern float default_layer_songs[][16][2];
        if (layer_state_cmp(state, _COLE)) {
            PLAY_SONG(default_layer_songs[_COLE]);
        }
        else if (layer_state_cmp(state, _QWER)) {
            PLAY_SONG(default_layer_songs[_QWER]);
        }
        else if (layer_state_cmp(state, _DVOR)) {
            PLAY_SONG(default_layer_songs[_DVOR]);
        }
    #endif /* AUDIO_ENABLE && DEFAULT_LAYER_SONGS */
    return state;
}

#define KC_LCAG    LCAG(KC_NO)
#define KC_IME_ON  KC_LANG1
#define KC_IME_OFF KC_LANG2

#define \
    LAYOUT_preonic_controlxcv( \
                    P_00,       P_01,       P_02,       P_03,       P_04,       P_05,       P_06,       P_07,       P_08,       P_09, \
                    P_10,       P_11,       P_12,       P_13,       P_14,       P_15,       P_16,       P_17,       P_18,       P_19, \
                    P_20,       P_21,       P_22,       P_23,       P_24,       P_25,       P_26,       P_27,       P_28,       P_29) \
    LAYOUT_preonic_1x2uC( \
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC, \
        KC_TAB,     P_00,       P_01,       P_02,       P_03,       P_04,       P_05,       P_06,       P_07,       P_08,       P_09,       KC_EQL, \
        KC_BSLS,    P_10,       P_11,       P_12,       P_13,       P_14,       P_15,       P_16,       P_17,       P_18,       P_19,       KC_MINS, \
        KC_LSFT,    P_20,       P_21,       P_22,       P_23,       P_24,       P_25,       P_26,       P_27,       P_28,       P_29,       KC_QUOT, \
        MO(_QMKB),  KC_LGUI,    KC_LALT,    KC_LCTL,    MO(_XTND),        KC_SPC,           KC_ENT,     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLE] = LAYOUT_preonic_controlxcv(
                    KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,
                    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       KC_H,       KC_N,       KC_E,       KC_I,       KC_O,
                    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH),

    [_QWER] = LAYOUT_preonic_controlxcv(
                    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
                    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,
                    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH),

    [_DVOR] = LAYOUT_preonic_controlxcv(
                    KC_SLSH,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       KC_F,       KC_G,       KC_C,       KC_R,       KC_L,
                    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       KC_D,       KC_H,       KC_T,       KC_N,       KC_S,
                    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_B,       KC_M,       KC_W,       KC_V,       KC_Z),

    [_XTND] = LAYOUT_preonic_1x2uC(
        KC_GRV,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_DEL,
        KC_CLCK,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_PSCR,
        KC_NLCK,    KC_LANG3,   KC_LANG4,   KC_LANG5,   XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_SLCK,
        _______,    KC_LANG1,   KC_LANG2,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PAUS,
        XXXXXXX,    _______,    _______,    _______,    _______,          XXXXXXX,          KC_INS,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END),

    [_QMKB] = LAYOUT_preonic_1x2uC(
        MO(_RSET),  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_M_P,    RGB_M_R,    RGB_M_SW,   RGB_M_T,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DF(_COLE),  DF(_QWER),  DF(_DVOR),  RGB_SAI,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SAD,
        XXXXXXX,    KC_MUTE,    KC_VOLD,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          RGB_TOG,    RGB_HUD,    RGB_VAD,    RGB_VAI,    RGB_HUI),

    [_RSET] = LAYOUT_preonic_1x2uC(
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          XXXXXXX,          DEBUG,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX)

};
