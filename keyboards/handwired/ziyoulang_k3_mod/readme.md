# ziyoulang_k3_mod

![ziyoulang_k3_mod](https://i.imgur.com/)

*This is a modifier to replace the Ziyoulang K3 keyboard controller with QMK.*

The SX83099 IC causes some problems. I needed QMK as an alternative, especially since the controller freezes when the backlight is off.

* Keyboard Maintainer: [Coom](https://github.com/coomstoolbox)
* Hardware Supported: Ziyoulang K3,Blue Pill
* Hardware Availability: [Base Keyboard](https://www.aliexpress.com/item/1005005458088199.html), [Blue Pill Board](https://www.aliexpress.com/item/32812837487.html)

Make example for this keyboard (after setting up your build environment):

    make coom\ziyoulang_k3_mod:default # vanilla
    make coom\ziyoulang_k3_mod:oled # with oled
    make coom\ziyoulang_k3_mod:via # with oled and VIA support

Flashing example for this keyboard:

    make coom\ziyoulang_k3_mod:default:flash # vanilla
    make coom\ziyoulang_k3_mod:oled:flash # with oled
    make coom\ziyoulang_k3_mod:via:flash # with oled and VIA support

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Requires manual wiring

![explanation](https://i.imgur.com/)

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
