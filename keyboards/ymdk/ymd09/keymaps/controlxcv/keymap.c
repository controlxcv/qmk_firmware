#include "keymap.h"

enum ymd09_layers {
    _BASE = 0,
    _FUNC,
    _NPAD,
    _TEST,
    _MODE = 14,
    _DFU  = 15,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE]  = KEYMAP_BASE,
    [_FUNC]  = KEYMAP_FUNC,
    [_NPAD]  = KEYMAP_NPAD,
    [_TEST]  = KEYMAP_TEST,
    [_MODE]  = KEYMAP_MODE,
    [_DFU]   = KEYMAP_DFU
};
