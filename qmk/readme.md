# PNCATEHO

A compact 10-key keyboard designed for efficient typing with a unique layout optimized for one-handed use.

## Layout

The PNCATEHO features a 4x2 main key grid plus 2 thumb keys:

```
┌───┬───┬───┬───┐
│ Q │ W │ E │ R │
├───┼───┼───┼───┤
│ A │ S │ D │ F │
└───┴───┴───┴───┘
    ┌───┬───┐
    │NUM│CTL│
    └───┴───┘
```

## Features

- **10 keys total**: 8 main keys in a 4x2 grid + 2 thumb keys
- **Multiple layers**: 10 different layers for various functions
- **Layer-based typing**: Main layer for QWER/ASDF, numbers layer for 1-8
- **Navigation layer**: Arrow keys, page up/down, home/end
- **Function keys**: F1-F8 accessible via layer
- **Space/Backspace**: Dedicated thumb keys for common operations

## Layers

1. **COMBO_LAYER**: Space and Backspace on thumb keys
2. **SELECTION_LAYER**: Layer switching controls
3. **NAVIGATION_LAYER**: Arrow keys and navigation
4. **BLUETOOTH_LAYER**: Bluetooth controls (placeholder)
5. **KBCTRL_LAYER**: Keyboard control functions
6. **RGB_LAYER**: RGB lighting controls (placeholder)
7. **LOL_MAIN_LAYER**: Main typing layer (QWER/ASDF)
8. **LOL_NUMBERS_LAYER**: Numbers 1-8
9. **LOL_ADDITIONAL_LAYER**: ESC, TAB, and layer switching
10. **LOL_FN_LAYER**: Function keys F1-F8

## Hardware

* Keyboard Maintainer: [Andrew Rudenko](https://github.com/Andrew Rudenko)
* Hardware Supported: PNCATEHO PCB with Pro Micro/Elite-C
* Hardware Availability: Custom PCB design

## Build Instructions

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb pncateho -km default

Flashing example for this keyboard:

    qmk flash -kb pncateho -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## Pin Configuration

Based on Pro Micro pinout:
- **Rows**: D1, D0, C6
- **Columns**: F4, F5, F6, F7, B1, B3, B2, B6

## Usage

The keyboard is designed for efficient one-handed typing with layer-based access to all necessary keys. The main layer provides the core QWER/ASDF layout, while additional layers provide numbers, navigation, and function keys.
