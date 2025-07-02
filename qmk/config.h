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

// Hardware configuration
#define DIRECT_PINS { \
    { F7, F6, F5, F4, B6, B2, B3, B1, E6, B4 } \
}

// USB Configuration
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER "PNCATEHO"
#define PRODUCT      "PNCATEHO"

// Matrix configuration for direct pins
#define MATRIX_ROWS 1
#define MATRIX_COLS 10

// Timing configuration
#define TAPPING_TERM 200
#define COMBO_TERM 70

// Combo buffer configuration - increase limits
#define COMBO_KEY_BUFFER_LENGTH 16    // Increased from default 8
#define COMBO_BUFFER_LENGTH 8         // Increased from default 4
#define EXTRA_LONG_COMBOS             // Allow up to 16 keys per combo

// Sticky key timeout (matching ZMK)
#define ONESHOT_TIMEOUT 500

// Bootmagic configuration
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// Enable RGB Matrix (if supported)
// #define RGB_MATRIX_ENABLE

// Enable RGB Light (if supported)
// #define RGBLIGHT_ENABLE

// Enable audio (if supported)
// #define AUDIO_ENABLE

// Enable backlight (if supported)
// #define BACKLIGHT_ENABLE 