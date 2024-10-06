/*
This is the c configuration file for the keymap

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

#pragma once

// Pointer support
#define POINTING_DEVICE_COMBINED
#define SPLIT_POINTING_ENABLE

#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_ROTATION_270_RIGHT
#define POINTING_DEVICE_INVERT_Y_RIGHT

// Personal defines
#define POINTER_CPI 2000
#define SCROLL_DIVISOR 24.0
//#define HORIZONTAL_SCROLL_ENABLE

// Behaviors
#define TAP_CODE_DELAY 5
#define COMBO_TERM 25                   // Timer for how fast you need to be to trigger a combo
#define COMBO_STRICT_TIMER              // Prevent the combo timer from restarting at each key in a combo sequence
#define ONESHOT_TIMEOUT 0               // Disable One-Shot timeouts
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD