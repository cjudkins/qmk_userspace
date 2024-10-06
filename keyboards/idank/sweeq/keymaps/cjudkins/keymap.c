// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
    #include "features/layer_lock.h"
    #include "features/swapper.h"

enum custom_keycodes {
    LLOCK = SAFE_RANGE,
    SW_WIN,
};

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0

// KEY OVERRIDES

const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t lprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LT);
const key_override_t rprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_GT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_override,    // Shift+, returns ;
    &dot_override,      // Shift+. returns :
    &ques_override,     // Shift+? returns !
    &lprn_override,     // Shift+( returns <
    &rprn_override,     // Shift+) returns >
    NULL
};

// COMBOS

const uint16_t PROGMEM combo_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_yquot[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_dotques[] = {KC_DOT, KC_QUES, COMBO_END};

// MOUSE KEYS
// Right
const uint16_t PROGMEM combo_ne[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM combo_ni[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM combo_nei[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_hcomma[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_hdot[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_hcommadot[] = {KC_H, KC_COMMA, KC_DOT, COMBO_END};

// Left
const uint16_t PROGMEM combo_st[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_rt[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_rst[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_cd[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo_xd[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM combo_xcd[] = {KC_X, KC_C, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_qw, KC_ESC),              // Q+W returns ESC
    COMBO(combo_yquot, KC_ESC),           // Y+QUOTE returns ESC
    COMBO(combo_zx, KC_LPRN),             // Z+X returns Left Parens (
    COMBO(combo_dotques, KC_RPRN),        // .+? returns Right Parens )
    COMBO(combo_ne, KC_BTN1),             // N+E returns left click
    COMBO(combo_ni, KC_BTN2),             // N+I returns right click
    COMBO(combo_nei, KC_BTN3),            // N+E+I returns middle click
    COMBO(combo_st, KC_BTN1),             // Same mouse keys but on the left side
    COMBO(combo_rt, KC_BTN2),
    COMBO(combo_rst, KC_BTN3),
    COMBO(combo_hcomma, KC_BTN1),
    COMBO(combo_hdot, KC_BTN2),
    COMBO(combo_hcommadot, KC_BTN3),
    COMBO(combo_cd, KC_BTN1),
    COMBO(combo_xd, KC_BTN2),
    COMBO(combo_xcd, KC_BTN3),
};

// LAYERS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Alpha layer
*
* ,---------------------------------------.       ,---------------------------------------.
* |   Q   |   W   |   F   |   P   |   B   |       |   J   |   L   |   U   |   Y   |   '   |
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* |   A   |   R   |   S   |   T   |   G   |       |   M   |   N   |   E   |   I   |   O   |
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* |   Z   |   X   |   C   |   D   |   V   |       |   K   |   H   |   ,   |   .   |   ?   |
* `---------------------.---------+-------'-.   .-`-----------------.---------------------'
*                       |  NAVI   |  SHIFT  |   |  SPACE  |   NUM   |
*                       '-------------------'   '-------------------'
*/
[0] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,  KC_U,    KC_Y,   KC_QUOT,
  KC_A, KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,  KC_E,    KC_I,   KC_O,
  KC_Z, KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,  KC_COMM, KC_DOT, KC_QUES,
                                  MO(1), OSM(MOD_LSFT), KC_SPC, MO(2)
),

/* Keymap 2: Navigation Layer
*
* ,---------------------------------------.       ,---------------------------------------.
* |  ESC  |  CUT  | COPY  | PASTE | UNDO  |       | PREV  |PREV TB| VOLDN | VOLUP |NEXT TB|
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* | CAPS  |  CTL  |  ALT  |  GUI  |  MEH  |       |  PLAY | LEFT  | DOWN  |   UP  | RIGHT |
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* |  SFT  |       |       |       | LOCK  |       |  NEXT | BACK  | PGDWN | PGUP  | FRWRD |
* `---------------------.---------+-------'-.   .-`-----------------.---------------------'
*                       |||||||||||         |   |         |         |
*                       '-------------------'   '-------------------'
*/ 
[1] = LAYOUT(
    KC_ESC  , LGUI(KC_X) , LGUI(KC_C) , LGUI(KC_V) , LGUI(KC_Z) ,                   KC_LPAD, LSFT(LCTL(KC_TAB)) ,LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RGHT)) , LCTL(KC_TAB) ,
    OSM(MOD_LSFT) , OSM(MOD_LCTL) , OSM(MOD_LALT) , OSM(MOD_LGUI) , OSM(MOD_MEH),   SW_WIN  , KC_LEFT , KC_DOWN ,   KC_UP , KC_RGHT ,
    KC_CAPS_LOCK , LSFT(KC_TAB) , KC_TAB , KC_ENTER, _______ ,                     C(KC_UP) , LGUI(KC_LBRC) , KC_PGDN , KC_PGUP , LGUI(KC_RBRC) ,
                                  _______ , LLOCK, _______ , _______ 
),

/* Keymap 3: Numeric Layer
*
* ,---------------------------------------.       ,---------------------------------------.
* |   `   |  1 ?  |   2   |   3   |   =   |       |  UNDO | PASTE |  COPY |  CUT  |  ESC  |
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* |   -   |   4   |   5   |   6   |   /   |       |  MEH  |  GUI  |  ALT  |  CTL  | CAPS  |
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* |   |   |   7   |   8   |   9   |   0   |       | LOCK  |       |   <   |   >   | SHIFT |
* `---------------------.---------+-------'-.   .-`-----------------.---------------------'
*                       |         |         |   |         |||||||||||
*                       '-------------------'   '-------------------'
*/ 
[2] = LAYOUT(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_BSLS  ,                              KC_DEL, KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC ,
    KC_MINUS, KC_4    , KC_5    , KC_6    , KC_SLSH ,                              OSM(MOD_MEH) , OSM(MOD_RGUI), OSM(MOD_RALT) , OSM(MOD_RCTL) , OSM(MOD_RSFT) ,
    KC_EQUAL, KC_7    , KC_8    , KC_9    , KC_0     ,                              A(KC_BSPC), KC_BSPC , _______, _______ , KC_CAPS_LOCK ,
                                  _______ , _______ , LLOCK, _______ 
),

/* Keymap 4: System Layer
*
* ,---------------------------------------.       ,---------------------------------------.
* |   F1  |  F2   |  F3   |  F4   |  F5   |       |   F6  |  F7   |  F8   |  F9   |  F10  |
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* |  TAB  |       |       | ENTER |       |       |       |  BSPC |       |       |  DEL  |
* |-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------|
* | CAPS  |       |       |       |       |       |       |       |       |       | CAPS  |
* `---------------------.---------+-------'-.   .-`-----------------.---------------------'
*                       |||||||||||         |   |         |||||||||||
*                       '-------------------'   '-------------------'
*/ 
[3] = LAYOUT(
    KC_SLEP , KC_INS  , KC_PAUS , KC_PSCR , _______,                              _______, KC_F1   , KC_F2   , KC_F3  , KC_F4  ,
    _______ , KC_MPRV , KC_MPLY , KC_MNXT , _______,                              _______, KC_F5   , KC_F6   , KC_F7  , KC_F8  , 
    _______ , KC_VOLD , _______ , KC_VOLU , _______,                              _______ , KC_F9   , KC_F10  , KC_F11 , KC_F12 , 
                                     _______ , _______ , _______ , _______ 
  )
};

bool scrolling_mode = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    // If both layer 1 and 2 are held, activate layer 3
    state = update_tri_layer_state(state, 1, 2, 3);

    // Release auto mouse as soon as we enter other layers
    if (get_highest_layer(state) == 0) {
        scrolling_mode = false;
     } else {
        scrolling_mode = true;
     } 

    return state;
}

bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Process Layer Lock key
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
 
    // Process Swapper (single-key cmd+tab)
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );

    return true;
}

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Prevent the cursor from moving by clearing the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}