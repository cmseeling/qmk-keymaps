/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/cmseeling> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. Chris Seeling
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ ESC  │   1  │   2  │   3  │   4  │   5  │ tbar │  │   =  │   6  │   7  │   8  │   9  │   0  │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼ tbar ┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │ tbar │  │   -  │   Y  │   U  │   I  │   O  │   P  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼ tbar ┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Sft^ │   A  │   S  │   D  │   F  │   G  │ tbar │  │ oled │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼ tbar ┤  ├ oled ┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   B  │ tbar │  │ oled │   N  │   M  │   ,  │   .  │   /  │Shift │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │ Alt^ │   [  │   ]  │      │  F5  │  │   `  │      │ Left │ Down │ Up   │Right │Layer^|
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Enter├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │  F6  │  │ BkSp │      │
 *                                    └──────┴──────┘  └──────┴──────┘
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
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │      │      │      │      │      │      |
 * └──────┴──────┴──────┴──────┴──────│      ├──────┤  ├──────│      ├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │      │  │      │      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */

 /* RGB
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │      │  │ BrtUp│Static│Breath│Rainbo│ Swirl│      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │ BrtDn│      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │ SatUp│ SatDn│      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │ HueUp│  │ SpdUp│      │      │      │      │      │      |
 * └──────┴──────┴──────┴──────┴──────│      ├──────┤  ├──────│ Mode ├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ HueDn│  │ SpdDn│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 */

typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_SINGLE_TAP
} td_state_t;

enum td_keycodes {
    TD_GRV,
    TD_ALT,
    TD_SHFT,
    TD_LAYR
};

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Function to determine the current tapdance state
uint8_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void TD_GRV_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_ALT_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_ALT_reset(qk_tap_dance_state_t *state, void *user_data);
void TD_SHFT_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_SHFT_reset(qk_tap_dance_state_t *state, void *user_data);
void TD_LAYR_finished(qk_tap_dance_state_t *state, void *user_data);

const key_override_t home_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_HOME, KC_END);
const key_override_t f5_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F5, KC_F1);
const key_override_t f6_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_F6, KC_F12);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &home_key_override,
    &f5_key_override,
    &f6_key_override,
    NULL // Null terminate the array of overrides!
};


enum sol_layers {
    _QWERTY,
    _NAV,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_ESC,      KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_MINS,                  KC_EQL,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,      KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_LBRC,                  KC_MINS,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        TD(TD_SHFT), KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_LPRN,                  KC_MINS,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,     KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,    KC_LCBR,                  KC_EQL,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
        KC_LCTL,     KC_LGUI, TD(TD_ALT), KC_LBRC, KC_RBRC,  KC_SPC,  KC_F5, KC_F6,   KC_BSPC, TD(TD_GRV),  KC_ENT,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, TD(TD_LAYR),

        KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                     KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
        KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_LEFT,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______,                   _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______,                   _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_0,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_RGB] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   RGB_VAI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _______, RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______,                   RGB_VAD, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, RGB_SAI, RGB_SAD, _______, _______,                   _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_HUD, RGB_SPD, RGB_SPI, RGB_MOD, _______, _______, _______,  _______, _______,

        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
};


void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
    }
}

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }

    if (state->count == 2) return DOUBLE_SINGLE_TAP;

    if (state->count == 3) return TRIPLE_SINGLE_TAP;

    else return 100; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

/*
    Send ` on single tap or PrntScrn on double tap
*/
void TD_GRV_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            tap_code(KC_GRAVE);
            break;
        case TRIPLE_SINGLE_TAP:
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_PSCR);
            break;
    }
}

/*
    Double tap to go to NAV layer, otherwise send ALT
*/
void TD_ALT_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            tap_code(KC_LALT);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case TRIPLE_SINGLE_TAP:
        case DOUBLE_SINGLE_TAP:
            if (layer_state_is(_NAV)) {
                //if already set, then switch it off
                layer_off(_NAV);
            } else {
                //if not already set, then switch the layer on
                layer_on(_NAV);
            }
            break;
    }
}

void TD_ALT_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_LALT);
}

/*
    Triple tap to send CAPSLOCK, otherwise, send shift
*/
void TD_SHFT_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    led_t led_state = host_keyboard_led_state();
    switch (td_state) {
        case DOUBLE_SINGLE_TAP:
        case SINGLE_TAP:
            tap_code(KC_LSFT);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case TRIPLE_SINGLE_TAP:
            tap_code(KC_CAPS);
            led_state.caps_lock ? rgblight_increase_hue_noeeprom() : rgblight_decrease_hue_noeeprom();
            break;
    }
}

void TD_SHFT_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code (KC_LSFT);
}

/*
    RGB Layer switch and layer escape key. On single press reset all layers. On double tap, go to RGB layer.
    When activating RGB, increase hue by 2. On reset (if RGB was active), reset hue.
*/
void TD_LAYR_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            if (layer_state_is(_RGB)) {
                rgblight_decrease_hue_noeeprom();
                rgblight_decrease_hue_noeeprom();
            }
            layer_move(0);
            break;
        case TRIPLE_SINGLE_TAP:
        case DOUBLE_SINGLE_TAP:
            if (!layer_state_is(_RGB)) {
                rgblight_increase_hue_noeeprom();
                rgblight_increase_hue_noeeprom();
            }
            layer_on(2);
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GRV]  = ACTION_TAP_DANCE_FN(TD_GRV_finished),
    [TD_ALT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_ALT_finished, TD_ALT_reset),
    [TD_SHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_SHFT_finished, TD_SHFT_reset),
    [TD_LAYR] = ACTION_TAP_DANCE_FN(TD_LAYR_finished)
};
