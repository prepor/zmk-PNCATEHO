// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 5

// Enable per-key tapping term
#define TAPPING_TERM_PER_KEY

// Only process combos on the COMBO_LAYER (layer 0)
#define COMBO_ONLY_FROM_LAYER 0

// Mouse key settings
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_MAX_SPEED 6
#define MOUSEKEY_TIME_TO_MAX 64

// Enable bootmagic
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// Matrix configuration (using keyboard.json direct pins)
#define MATRIX_ROWS 1
#define MATRIX_COLS 10

// Sticky key timeout (matching ZMK)
#define ONESHOT_TIMEOUT 500

// Enable RGB Matrix (if supported)
// #define RGB_MATRIX_ENABLE

// Enable RGB Light (if supported)
// #define RGBLIGHT_ENABLE

// Enable audio (if supported)
// #define AUDIO_ENABLE

// Enable backlight (if supported)
// #define BACKLIGHT_ENABLE 