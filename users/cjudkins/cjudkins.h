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

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/swapper.h"

#ifdef COMBO_ENABLE
    #include "features/combos.h"
#endif

#ifdef KEY_OVERRIDE_ENABLE
    #include "features/overrides.h"
#endif

#ifdef OLED_ENABLE
    #include "features/oled.h"
#endif

// Personal defines
#ifndef POINTER_CPI
    #define POINTER_CPI 2000
#endif

#ifndef POINTER_CPI_RIGHT
    #define POINTER_CPI_RIGHT POINTER_CPI
#endif

#ifndef SCROLL_DIVISOR
    #define SCROLL_DIVISOR 24.0
#endif

//#define HORIZONTAL_SCROLL_ENABLE

// Keymap Shortcuts
#define TAB_L S(C(KC_TAB))      // Switch tab left
#define TAB_R C(KC_TAB)         // Switch tab right
#define DSKTP_L G(C(KC_LEFT))   // Switch desktop (space) left
#define DSKTP_R G(C(KC_RGHT))   // Switch desktop (space) right
#define BACK G(KC_LBRC)         // Go Back in history
#define FWRD G(KC_RBRC)         // Go Forward in history
#define CUT G(KC_X)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define UNDO G(KC_Z)
#define OSFT OSM(MOD_LSFT)
#define OCTL OSM(MOD_LCTL)
#define OALT OSM(MOD_LALT)
#define OGUI OSM(MOD_LGUI)
#define OMEH OSM(MOD_MEH)
#define FQUIT G(A(KC_ESC))      // Force Quit/Task Manager
#define SCLOCK G(C(KC_Q))       // Screen Lock

enum custom_keycodes {
    SW_APP = SAFE_RANGE,    // Single-key cmd+tab for switching apps
    SW_WIN,                 // Single-key cmd+` for switching windows
    LLOCK,                  // Layer Lock
};

bool sw_win_active = false;
bool sw_app_active = false;
bool scrolling_mode = false;
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

__attribute__ ((weak))
void keyboard_post_init_keymap(void) {
    return;
}

void keyboard_post_init_user(void) {
    #ifdef SPLIT_POINTING_ENABLE
    pointing_device_set_cpi_on_side(true, POINTER_CPI); //Set sensitivity on left side
    pointing_device_set_cpi_on_side(false, POINTER_CPI_RIGHT); //Set sensitivity on right side
    #elif POINTING_DEVICE_ENABLE
    pointing_device_set_cpi(POINTER_CPI);
    #endif

    keyboard_post_init_keymap();
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
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

__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
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
    
    return layer_state_set_keymap (state);
}

#ifdef SPLIT_POINTING_ENABLE
    __attribute__ ((weak))
    report_mouse_t pointing_device_task_combined_keymap(report_mouse_t left_report, report_mouse_t right_report) {
        return pointing_device_combine_reports(left_report, right_report);
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

        return pointing_device_task_combined_keymap(left_report, right_report);
    }
#elif POINTING_DEVICE_ENABLE
    __attribute__ ((weak))
    report_mouse_t pointing_device_task_keymap(report_mouse_t mouse_report) {
        return mouse_report;
    }

    report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
        if (scrolling_mode) {
            // Vertical Scroll
            scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR;
            mouse_report.v = (int8_t)scroll_accumulated_v;
            scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

            // Horizontal Scroll
            #ifdef HORIZONTAL_SCROLL_ENABLE
                scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR;
                mouse_report.h = (int8_t)scroll_accumulated_h;
                scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
            #endif

            // Prevent the cursor from moving by clearing the X and Y values of the mouse report
            mouse_report.x = 0;
            mouse_report.y = 0;
        }

        return pointing_device_task_keymap(mouse_report);
    }
#endif