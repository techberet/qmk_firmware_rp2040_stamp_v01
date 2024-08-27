// Copyright 2024 TechBeret (@TechBeret)
// SPDX-License-Identifier: GPL-2.0-or-later

// modified version of https://github.com/qmk/qmk_firmware/blob/master/keyboards/ms_sculpt/keymaps/default/keymap.c

#include QMK_KEYBOARD_H

#define ______ KC_TRNS


void keyboard_post_init_kb(void) {
    // Since we're using an external voltage divider, turn off pull up resistors
    // on the "DIP switch" (actually the Fn switch), which is connected to GP0.
    // If you don't set it to input the pull up resistors overwhelm the circuit.
    setPinInput(GP0);
}

bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) { return false; }
    if (index == 0) {
        default_layer_set(1UL << (active ? 0 : 1));
    }
    return true;
}

enum custom_layers {
    _BASE,
    _MULTIMEDIA_ENABLED
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
  [_BASE] = LAYOUT_iso(
    /*  0      1        2        3        4        5         6        7       8        9         10      11          12         13         14        15       16   */
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  KC_PSCR,    KC_SCRL,  KC_PAUSE, KC_CALC,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,              KC_BSPC,  KC_DEL,   KC_HOME,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,             KC_BSLS,            KC_END,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_NUHS, KC_ENT,     KC_INS,   KC_PGUP,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,             KC_UP,    KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,  KC_SPC,           KC_RALT, KC_APP, KC_RCTL,     KC_LEFT,             KC_DOWN,  KC_RGHT
  ),
  [_MULTIMEDIA_ENABLED] = LAYOUT_iso(
    // A bunch of the keys use weird Windows key combos. Instead adding the ones which are valid across platforms.
    // I also replaced F7/F8 with Brightness down / up respectively. F2 was replaced with Launchpad.
    /*  0      1        2        3        4        5         6        7       8        9         10      11          12         13         14        15       16   */
    ______,  KC_WHOM, KC_LPAD, KC_F3,   KC_F4,   KC_WSCH, KC_F6,   KC_BRID, KC_BRIU, KC_MPLY, KC_MUTE, KC_VOLD,    KC_VOLU, ______,     ______,   ______,   ______,
    ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,     ______,              ______,   ______,   ______,
    ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,     ______,              ______,             ______,
    ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,     ______,  ______,     ______,   ______,
    ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,     ______,              ______,   ______,
    ______,  ______,  ______,                             ______,  ______,           ______,  ______,  ______,     ______,              ______,   ______
  ),
};