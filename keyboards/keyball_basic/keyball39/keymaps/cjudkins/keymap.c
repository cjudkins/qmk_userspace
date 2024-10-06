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

#include "quantum.h"
    #include "features/combos.h"
    #include "features/overrides.h"
    #include "features/layer_lock.h"
    #include "features/swapper.h"

// Defines to keep the keymap legible
#define TAB_L S(C(KC_TAB))
#define TAB_R C(KC_TAB)
#define DSKTP_L G(C(KC_LEFT))
#define DSKTP_R G(C(KC_RGHT))
#define BACK G(KC_LBRC)
#define FWRD G(KC_RBRC)
#define CUT G(KC_X)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define UNDO G(KC_Z)
#define OSFT OSM(MOD_LSFT)
#define OCTL OSM(MOD_LCTL)
#define OALT OSM(MOD_LALT)
#define OGUI OSM(MOD_LGUI)
#define OMEH OSM(MOD_MEH)
#define FQUIT G(A(KC_ESC))
#define SCLOCK G(C(KC_Q))

enum keycodes {
    SW_APP = SAFE_RANGE,    // Single-key cmd+tab for switching apps
    SW_WIN,                 // Single-key cmd+` for switching windows
    LLOCK,                  // Layer Lock
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for personal use
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_F     , KC_P     , KC_B     ,                            KC_J     , KC_L     , KC_U     , KC_Y     , KC_QUOT  ,
    KC_A     , KC_R     , KC_S     , KC_T     , KC_G     ,                            KC_M     , KC_N     , KC_E     , KC_I     , KC_O     ,
    KC_Z     , KC_X     , KC_C     , KC_D     , KC_V     ,                            KC_K     , KC_H     , KC_COMM  , KC_DOT   , KC_QUES  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , MO(1)    , OSFT     ,        KC_SPC , MO(2)    , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [1] = LAYOUT_universal(
    KC_ESC   , CUT      , COPY     , PASTE    , UNDO     ,                            SW_WIN   , TAB_L    , DSKTP_L  , DSKTP_R  , TAB_R    ,
    OSFT     , OCTL     , OALT     , OGUI     , KC_CAPS  ,                            SW_APP   , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  ,
    OMEH     , S(KC_TAB), KC_TAB   , KC_ENT   , _______  ,                            C(KC_UP) , BACK     , KC_PGDN  , KC_PGUP  , FWRD     ,
    _______  , _______  , _______  , _______  , _______  , LLOCK    ,       _______ , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_BSLS  ,                            KC_DEL   , KC_LPRN  , KC_RPRN  , KC_LBRC  , KC_RBRC  ,
    KC_MINS  , KC_4     , KC_5     , KC_6     , KC_SLSH  ,                            KC_CAPS  , OGUI     , OALT     , OCTL     , OSFT     ,
    KC_EQL   , KC_7     , KC_8     , KC_9     , KC_0     ,                           A(KC_BSPC), KC_BSPC  , _______  , _______  , OMEH     ,
    _______  , _______  , _______  , _______  , _______  , _______  ,         LLOCK , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    SCLOCK   , KC_INS   , KC_PAUS  , KC_PSCR  , _______  ,                            _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    ,
    FQUIT    , KC_MPRV  , KC_MPLY  , KC_MNXT  , _______  ,                            _______  , KC_F5    , KC_F6    , KC_F7    , KC_F8    ,
    _______  , KC_VOLD  , _______  , KC_VOLU  , _______  ,                            _______  , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    _______  , _______  , _______  , _______  , _______  , _______  ,       _______ , _______  , _______  , _______  , _______  , _______
  )
}; 
// clang-format on

bool sw_win_active = false;
bool sw_app_active = false;
bool scrolling_mode = false;
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, POINTER_CPI); //Set sensitivity on left side
    pointing_device_set_cpi_on_side(false, POINTER_CPI); //Set sensitivity on right side
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Process Layer Lock key
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
 
    // Process Swapper
    update_swapper(
        &sw_app_active, KC_LGUI, KC_TAB, SW_APP,
        keycode, record
    );

    update_swapper(
        &sw_win_active, KC_LGUI, KC_GRV, SW_WIN,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // If both layer 1 and 2 are held, activate layer 3
    state = update_tri_layer_state(state, 1, 2, 3);

    // Auto enable scroll mode when the not on the base layer
    if (get_highest_layer(state) == 0) {
        scrolling_mode = false;
    } else {
        scrolling_mode = true;
    }
    
    return state;
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    if (scrolling_mode) {
        // Vertical Scroll
        scroll_accumulated_v += (float)(left_report.y + right_report.y) / SCROLL_DIVISOR;
        left_report.v = (int8_t)scroll_accumulated_v;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Horizontal Scroll
        #ifdef HORIZONTAL_SCROLL_ENABLE
            scroll_accumulated_h += (float)(left_report.x + right_report.x) / SCROLL_DIVISOR;
            left_report.h = (int8_t)scroll_accumulated_h;
            scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        #endif

        // Prevent the cursor from moving by clearing the X and Y values of the mouse report
        left_report.x = 0;
        left_report.y = 0;
        right_report.x = 0;
        right_report.y = 0;
    }

    return pointing_device_combine_reports(left_report, right_report);
}

#ifdef OLED_ENABLE
    #include "features/oled.h"
    
    bool oled_task_user(void) {
        if (is_keyboard_master()) {
            render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        } else {
            render_logo();  // Renders a static logo
            oled_scroll_left();  // Turns on scrolling
        }
        
        return false;
    }
#endif