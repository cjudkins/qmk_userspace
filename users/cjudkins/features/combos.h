#pragma once

const uint16_t PROGMEM combo_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_yquot[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_dotques[] = {KC_DOT, KC_QUES, COMBO_END};

// MOUSE KEYS

// Left side
const uint16_t PROGMEM combo_cd[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo_xd[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM combo_xcd[] = {KC_X, KC_C, KC_D, COMBO_END};

// Right sideen
const uint16_t PROGMEM combo_hcomma[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_hdot[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_hcommadot[] = {KC_H, KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_qw, KC_ESC),              // Q+W returns ESC
    COMBO(combo_yquot, KC_ESC),           // Y+QUOTE returns ESC
    COMBO(combo_zx, KC_LPRN),             // Z+X returns Left Parens (
    COMBO(combo_dotques, KC_RPRN),        // .+? returns Right Parens )
    COMBO(combo_hcomma, KC_BTN1),
    COMBO(combo_hdot, KC_BTN2),
    COMBO(combo_hcommadot, KC_BTN3),
    COMBO(combo_cd, KC_BTN1),
    COMBO(combo_xd, KC_BTN2),
    COMBO(combo_xcd, KC_BTN3)
};