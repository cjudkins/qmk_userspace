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

// QMK Behaviors
#define TAP_CODE_DELAY 5
#define COMBO_TERM 35                   // Timer for how fast you need to be to trigger a combo
#define COMBO_STRICT_TIMER              // Prevent the combo timer from restarting at each key in a combo sequence
#define COMBO_ONLY_FROM_LAYER 0
#define ONESHOT_TIMEOUT 0               // Disable One-Shot timeouts
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD