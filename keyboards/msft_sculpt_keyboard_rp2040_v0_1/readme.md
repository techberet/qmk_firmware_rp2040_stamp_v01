# msft_sculpt_keyboard_rp2040_initial

![msft_sculpt_keyboard_rp2040_initial](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [TechBeret](https://github.com/TechBeret)
* Hardware Supported: Microsoft Sculpt Ergonomic Keyboard, Custom PCB using RP2040 Stamp
* Hardware Availability: eBay for Sculpt keyboards without USB dongles, see article for links to PCB
* Original commit based off: d09ea04fa1b42b362a81218785ff41d3004df081

Make example for this keyboard (after setting up your build environment):

    make msft_sculpt_keyboard_rp2040_v0_1:default

Flashing example for this keyboard:

    make msft_sculpt_keyboard_rp2040_v0_1:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
