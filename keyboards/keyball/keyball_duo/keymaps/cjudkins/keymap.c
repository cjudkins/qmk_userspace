/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H
#include "cjudkins.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for personal use
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_F     , KC_P     , KC_B     ,                            KC_J     , KC_L     , KC_U     , KC_Y     , KC_QUOT  ,
    KC_A     , KC_R     , KC_S     , KC_T     , KC_G     ,                            KC_M     , KC_N     , KC_E     , KC_I     , KC_O     ,
    KC_Z     , KC_X     , KC_C     , KC_D     , KC_V     ,                            KC_K     , KC_H     , KC_COMM  , KC_DOT   , KC_QUES  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , MO(1)    , OSFT     ,     KC_SPC    , MO(2)    , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [1] = LAYOUT_universal(
    KC_ESC   , CUT      , COPY     , PASTE    , UNDO     ,                            SW_WIN   , TAB_L    , DSKTP_L  , DSKTP_R  , TAB_R    ,
    OSFT     , OCTL     , OALT     , OGUI     , KC_CAPS  ,                            SW_APP   , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  ,
    OMEH     , S(KC_TAB), KC_TAB   , KC_ENT   , _______  ,                            C(KC_UP) , BACK     , KC_PGDN  , KC_PGUP  , FWRD     ,
    _______  , _______  , _______  , _______  , _______  , LLOCK    ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_BSLS  ,                            KC_DEL   , KC_LPRN  , KC_RPRN  , KC_LBRC  , KC_RBRC  ,
    KC_MINS  , KC_4     , KC_5     , KC_6     , KC_SLSH  ,                            KC_CAPS  , OGUI     , OALT     , OCTL     , OSFT     ,
    KC_EQL   , KC_7     , KC_8     , KC_9     , KC_0     ,                           A(KC_BSPC), KC_BSPC  , _______  , _______  , OMEH     ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      LLOCK    , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    SCLOCK   , KC_INS   , KC_PAUS  , KC_PSCR  , _______  ,                            _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    ,
    FQUIT    , KC_MPRV  , KC_MPLY  , KC_MNXT  , _______  ,                            _______  , KC_F5    , KC_F6    , KC_F7    , KC_F8    ,
    _______  , KC_VOLD  , _______  , KC_VOLU  , _______  ,                            _______  , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  )
}; 
// clang-format on