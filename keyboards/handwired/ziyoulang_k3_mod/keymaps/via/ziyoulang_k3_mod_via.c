// Copyright 2023 Coom (@coomstoolbox)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdio.h>

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
  #include <print.h>
#endif

void keyboard_post_init_user(void) {

  // Customise these values to desired behaviour
#ifdef CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
#endif
  //debug_keyboard=true;
  //debug_mouse=true;

}

static uint16_t last_keycode = KC_NO;
static uint16_t last_col = 0;
static uint16_t last_row = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // コンソールが有効化されている場合、マトリックス上の位置とキー押下状態を出力します
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
    if (record->event.pressed) {
        if (last_keycode != keycode) {
            last_keycode = keycode;
            last_col = record->event.key.col;
            last_row = record->event.key.row;
        }
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }

bool oled_task_user(void) {

    // render_logo();
    // oled_scroll_left();

    // oled_set_cursor(0, 0);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("2\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("3\n"), false);
            break;
//        case 3:
//            oled_write_P(PSTR("4\n"), false);
//            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    char count_str[32];
    if (last_keycode == 21025) {
      snprintf(count_str, sizeof(count_str), "kc: %s col: %u row: %u", "Fn", last_col, last_row);
    } else {
      snprintf(count_str, sizeof(count_str), "kc: %u col: %u row: %u", last_keycode, last_col, last_row);
    }
    oled_write_ln_P(count_str, false);

    return false;
}
