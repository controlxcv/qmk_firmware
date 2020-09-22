#pragma once

#define KEYMAP_QWERTY LAYOUT_preonic_grid( \
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		XXXXXXX,	\
	XXXXXXX,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	XXXXXXX,	\
	XXXXXXX,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX		\
)

#define KEYMAP_COLEMAK LAYOUT_preonic_grid( \
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	KC_Q,		KC_W,		KC_F,		KC_P,		KC_G,		KC_J,		KC_L,		KC_U,		KC_Y,		KC_SCLN,	XXXXXXX,	\
	XXXXXXX,	KC_A,		KC_R,		KC_S,		KC_T,		KC_D,		KC_H,		KC_N,		KC_E,		KC_I,		KC_O,		XXXXXXX,	\
	XXXXXXX,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_K,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX		\
)

#define KEYMAP_DVORAK LAYOUT_preonic_grid( \
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	KC_SLSH,	KC_COMM,	KC_DOT,		KC_P,		KC_Y,		KC_F,		KC_G,		KC_C,		KC_R,		KC_L,		XXXXXXX,	\
	XXXXXXX,	KC_A,		KC_O,		KC_E,		KC_U,		KC_I,		KC_D,		KC_H,		KC_T,		KC_N,		KC_S,		XXXXXXX,	\
	XXXXXXX,	KC_SCLN,	KC_Q,		KC_J,		KC_K,		KC_X,		KC_B,		KC_M,		KC_W,		KC_V,		KC_Z,		XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX		\
)

#define KEYMAP_COMMON LAYOUT_preonic_grid( \
	KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_BSPC,	\
	KC_BSLS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_EQL,		\
	KC_QUOT,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MINS,	\
	KC_TAB,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_ENT,		\
	KC_LCTL,	KC_LALT,	LOWER,		RAISE,		KC_LGUI,	KC_SPC,		KC_SPC,		KC_LSFT,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT		\
)

#define KEYMAP_RAISE LAYOUT_preonic_grid( \
	KC_ESC,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_DEL,		\
	_______,	KC_F11,		KC_F12,		KC_F13,		KC_F14,		KC_F15,		KC_F16,		KC_F17,		KC_F18,		KC_F19,		_______,	KC_LANG2,	\
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_LANG1,	\
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_LBRC,	KC_RBRC,	_______,	KC_PENT,	\
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END		\
)

#define KEYMAP_LOWER LAYOUT_preonic_grid( \
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	\
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	\
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	\
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MPLY,	\
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MPRV,	KC_VOLD,	KC_VOLU,	KC_MNXT		\
)

#define KEYMAP_ADJUST LAYOUT_preonic_grid( \
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	MO(_RESET),	\
	XXXXXXX,	QWERTY,		COLEMAK,	DVORAK,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	CK_TOGG,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	_______,	_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX		\
)

#define KEYMAP_RESET LAYOUT_preonic_grid( \
	RESET,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	_______,	\
	XXXXXXX,	XXXXXXX,	XXXXXXX,	EEP_RST,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	\
	XXXXXXX,	XXXXXXX,	_______,	_______,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX		\
)
