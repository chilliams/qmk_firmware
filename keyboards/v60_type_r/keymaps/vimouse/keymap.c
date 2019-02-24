/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |FN0   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
     * |-----------------------------------------------------------|
     * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
     * |-----------------------------------------------------------|
     * |Ctrl|Alt |Gui |      Space/L3           |Gui |Alt |Ctrl|Fn1|
     * `-----------------------------------------------------------'
     */
    [0] = LAYOUT_all(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXX, KC_BSPC, \
        KC_TAB,  KC_Q,    M(0),    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,     KC_BSLS, \
        KC_LCTL,   M(1),    M(2),    M(3),    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, \
        KC_LSFT, XXXXX,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXX,  \
        MO(1), KC_LALT, KC_LGUI,               KC_SPC,                          KC_RGUI, KC_RALT, MO(1),  KC_RCTL),
    /* Keymap 1: FN Layer
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |PSc|SLk|Pau| Ins |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   | Lt| Dn| Up| Rt|Hom|PgU|        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |Mut|VDn|VUp|End|PgD|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [1] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _____,  KC_DEL, \
        _____,   _____,   KC_UP,   _____,   _____,   _____,   _____,   _____,  KC_INS,   _____, KC_PSCR, KC_SLCK, KC_PAUS,          _____, \
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT,   _____,   _____,   _____, KC_MPRV, KC_MNXT, KC_MPLY, KC_HOME, KC_PGUP,           _____,          \
        _____,   _____,   _____,   _____,   _____,   _____,   _____, KC_VOLD, KC_VOLU, KC_MUTE,  KC_END, KC_PGDN,           _____,  _____,  \
        _____,   _____,   _____,               _____,                                                      _____,   _____,  _____,  _____),
};

const uint16_t PROGMEM fn_actions[] = {
};

int nmback = 0;
int nmforward = 0;
int nmleft = 0;
int nmright = 0;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // http://wiki.quakeworld.nu/Strafescript
    switch(id) {
        case 0: // W
            if (record->event.pressed) {
                register_code(KC_W);
                nmforward = 1;
                if (nmback > 0) {
                    unregister_code(KC_S);
                }
            } else {
                unregister_code(KC_W);
                nmforward = 0;
                if (nmback > 0) {
                    register_code(KC_S);
                }
            }
            break;
        case 1: // A
            if (record->event.pressed) {
                register_code(KC_A);
                nmleft = 1;
                if (nmright > 0) {
                    unregister_code(KC_D);
                }
            } else {
                unregister_code(KC_A);
                nmleft = 0;
                if (nmright > 0) {
                    register_code(KC_D);
                }
            }
            break;
        case 2: // S
            if (record->event.pressed) {
                register_code(KC_S);
                nmback = 1;
                if (nmforward > 0) {
                    unregister_code(KC_W);
                }
            } else {
                unregister_code(KC_S);
                nmback = 0;
                if (nmforward > 0) {
                    register_code(KC_W);
                }
            }
            break;
        case 3: // D
            if (record->event.pressed) {
                register_code(KC_D);
                nmright = 1;
                if (nmleft > 0) {
                    unregister_code(KC_A);
                }
            } else {
                unregister_code(KC_D);
                nmright = 0;
                if (nmleft > 0) {
                    register_code(KC_A);
                }
            }
            break;
    }
    return MACRO_NONE;
};


void led_set_user(uint8_t usb_led) {

}
