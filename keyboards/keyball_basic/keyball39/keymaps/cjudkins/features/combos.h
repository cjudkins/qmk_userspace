/*
Copyright 2024 @cjudkins 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

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
    COMBO(combo_hcomma, LSFT(KC_BTN1)),
    COMBO(combo_hdot, LSFT(KC_BTN2)),
    COMBO(combo_hcommadot, LSFT(KC_BTN3)),
    COMBO(combo_cd, LSFT(KC_BTN1)),
    COMBO(combo_xd, LSFT(KC_BTN2)),
    COMBO(combo_xcd, LSFT(KC_BTN3)),
};