// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 5

// Tapping term for layer tap keys (matching ZMK)
#define TAPPING_TERM 200

// Enable rapid switch from layer to layer
#define TAPPING_FORCE_HOLD

// Enable per-key tapping term
#define TAPPING_TERM_PER_KEY

// Enable tap dance
#define TAP_DANCE_ENABLE

// Enable combos (matching ZMK combo timeout)
#define COMBO_TERM 70
#define COMBO_COUNT 100

// Only process combos on the COMBO_LAYER (layer 0)
#define COMBO_ONLY_FROM_LAYER 0

// Enable mouse keys
#define MOUSEKEY_ENABLE

// Mouse key settings
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_MAX_SPEED 6
#define MOUSEKEY_TIME_TO_MAX 64

// Enable extra keys
#define EXTRAKEY_ENABLE

// Enable NKRO
#define FORCE_NKRO

// Enable bootmagic
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// Direct pin configuration (matching ZMK pin order)
#define DIRECT_PINS { \
    { F7, F6, F5, F4, B6, B2, B3, B1, E6, B4 } \
}

// No matrix needed for direct pins
#undef MATRIX_ROWS
#undef MATRIX_COLS
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