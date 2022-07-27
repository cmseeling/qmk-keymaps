/* Copyright 2021 Sadek Baroudi
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

void eeconfig_init_user(void) {  // EEPROM is getting reset!
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable();
    rgb_matrix_sethsv(HSV_BLUE);
#endif
}

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ ESC  │   1  │   2  │   3  │   4  │   5  │   [  │  │   =  │   6  │   7  │   8  │   9  │   0  │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │   ]  │  │   -  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Caps │   A  │   S  │   D  │   F  │   G  │  F6  │  │   `  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │  F5  │  │PrntSn│   N  │   M  │   ,  │   .  │   /  │Shift │
 * └──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┘
 *               │ Ctrl │  Win │ Alt^ │ Space│ Raise│  │ BkSp │ Enter│ Raise│ Home │  End │
 *               └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
 */

 /* Nav
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │      │  │      │      │   7  │   8  │   9  │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Home │  Up  │  End │ PgUp │      │      │  │      │      │   4  │   5  │   6  │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Left │ Down │ Right│ PgDn │      │      │  │      │      │   1  │   2  │   3  │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │      │   0  │      │      │      │      │
 * └──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┘
 *               │      │      │      │      │      │  │      │      │      │      │      │
 *               └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
 */

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _RAISE,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    RAISE,
    COLOR
};

bool is_caps_lock_on;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_pinkiesout(
    KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_LBRC,           KC_EQL,    KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_DEL,
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_RBRC,           KC_MINS,   KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_F6,             KC_GRAVE,  KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_F5,             KC_PSCR,   KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSHIFT,
                          KC_LCTL,   KC_LGUI,   KC_LALT,   KC_SPC,    RAISE,             KC_BSPC,   KC_ENT,    RAISE,     KC_HOME,   KC_END
),


[_RAISE] = LAYOUT_pinkiesout(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   KC_HOME,   KC_UP,     KC_END,    KC_PGUP,   _______,   _______,           _______,   _______,   KC_4,      KC_5,      KC_6,      _______,   _______,
    _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,   _______,   _______,           _______,   _______,   KC_1,      KC_2,      KC_3,      _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,           COLOR,     _______,   KC_0,      _______,   _______,   _______,   _______,
                          _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______
)
};

void keyboard_post_init_user(void) {
    is_caps_lock_on = false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        extern uint32_t oled_tap_timer;
        oled_tap_timer = timer_read32();
    }

    switch (keycode) {
        case KC_CAPS:
            if (record->event.pressed) {
                if (is_caps_lock_on) {
                    is_caps_lock_on = false;
                } else {
                    is_caps_lock_on = true;
                }
            }
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                // update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                // update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case COLOR:
            #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv(HSV_BLUE);
            #endif
            break;
        default:
            break;
    }

    return true;
}

#ifdef OLED_ENABLE
void render_mod_status(void) {
    oled_set_cursor(17,5);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPS ") : PSTR("       "), false);

    oled_set_cursor(16,6);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(" Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        default:
            oled_write_P(PSTR("?????\n"), false);
    }
}

#endif
