// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 5

// Tapping term for layer tap keys
#define TAPPING_TERM 200

// Enable rapid switch from layer to layer
#define TAPPING_FORCE_HOLD

// Enable per-key tapping term
#define TAPPING_TERM_PER_KEY

// Enable combos
#define COMBO_ENABLE

// Combo timeout
#define COMBO_TERM 70

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

// Enable RGB Matrix (if supported)
// #define RGB_MATRIX_ENABLE

// Enable RGB Light (if supported)
// #define RGBLIGHT_ENABLE

// Enable audio (if supported)
// #define AUDIO_ENABLE

// Enable backlight (if supported)
// #define BACKLIGHT_ENABLE 