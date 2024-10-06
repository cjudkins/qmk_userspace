// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

/* TRACKPAD */

#undef CIRQUE_PINNACLE_TAP_ENABLE   // I like this feature but I kept accidentally tapping, so I'm sticking to mouse keys

/* MISC */

#define SPLIT_WATCHDOG_ENABLE           // Fixes keyboard not being recognized booting or waking from sleep
#define COMBO_TERM 25                   // Timer for how fast you need to be to trigger a combo
#define COMBO_STRICT_TIMER              // Prevent the combo timer from restarting at each key in a combo sequence
#define ONESHOT_TIMEOUT 0               // Disable One-Shot timeouts
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD