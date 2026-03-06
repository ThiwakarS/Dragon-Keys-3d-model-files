// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "virtser.h"   // for virtser_send_string
#include <stdio.h>     // for snprintf
#include "analog.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,  KC_ENT,  KC_MUTE,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,  KC_UP,   KC_PSCR,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                              KC_SPC,  KC_RALT, MO(1),    KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  KC_PAUS, KC_PGUP, KC_INS,
        _______, _______, _______, _______,                             _______, _______, XXXXXXX,  KC_SCRL,  KC_HOME, KC_PGDN, KC_END
    ),


};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLU, KC_VOLD),},
    [1] = {ENCODER_CCW_CW(_______, _______),}
};
#endif

void matrix_scan_user(void) {

    if (is_keyboard_master()) {
        static uint16_t last_timer = 0;
        static char buffer[64];
        static uint16_t f1 = 0, f2 = 0, f3 = 0;

        const float alpha = 0.2f;

        if (timer_elapsed(last_timer) > 100) {
            last_timer = timer_read();

            uint16_t raw1 = analogReadPin(GP26) * 1023 / 4095;
            uint16_t raw2 = analogReadPin(GP27) * 1023 / 4095;
            uint16_t raw3 = analogReadPin(GP28) * 1023 / 4095;

            if (raw1 < 10) {
                f1 = 0;
            } else if (raw1 > 1005) {
                f1 = 1023;
            } else {
                f1 = (uint16_t)(alpha * raw1 + (1.0f - alpha) * f1);
            }

            if (raw2 < 10) {
                f2 = 0;
            } else if (raw2 > 1005) {
                f2 = 1023;
            } else {
                f2 = (uint16_t)(alpha * raw2 + (1.0f - alpha) * f2);
            }

            if (raw3 < 10) {
                f3 = 0;
            } else if (raw3 > 1005) {
                f3 = 1023;
            } else {
                f3 = (uint16_t)(alpha * raw3 + (1.0f - alpha) * f3);
            }

            snprintf(buffer, sizeof(buffer), "%u|%u|%u\r\n", f1, f2, f3);
            virtser_send_string(buffer);
        }
    }
}
