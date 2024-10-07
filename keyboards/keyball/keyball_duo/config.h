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

#pragma once

// Key matrix parameters
#define MATRIX_ROWS         (4 * 2)  // split keyboard
#define MATRIX_COLS         6
#define MATRIX_ROW_PINS     { GP29, GP28, GP27, GP26 }
#define MATRIX_COL_PINS     { GP4, GP5, GP6, GP7, GP8, GP9}
#define MATRIX_MASKED
#define DEBOUNCE            5
#define DIODE_DIRECTION     COL2ROW

// Split parameters
#define SOFT_SERIAL_PIN         GP1
#define SPLIT_HAND_MATRIX_GRID  GP27, GP9
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

#if !defined(LAYER_STATE_8BIT) && !defined(LAYER_STATE_16BIT) && !defined(LAYER_STATE_32BIT)
#    define LAYER_STATE_8BIT
#endif

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23

#define POINTING_DEVICE_CS_PIN GP21

// Enable dual trackball
#define POINTING_DEVICE_COMBINED
#define SPLIT_POINTING_ENABLE

// Left-side trackball orientation correction
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_Y

// Right-side trackball orientation correction
#define POINTING_DEVICE_ROTATION_270_RIGHT
#define POINTING_DEVICE_INVERT_Y_RIGHT