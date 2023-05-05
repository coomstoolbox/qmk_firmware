# This file intentionally left blank

# https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/ja/config_options.md
LTO_ENABLE = yes

VIA_ENABLE = yes

BOOTMAGIC_ENABLE = lite

# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_oled_driver.md
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

SRC += ziyoulang_k3_mod_via.c

  $(info QMK Build Options)
  $(info -- RGBLIGHT_ENABLE    = $(RGBLIGHT_ENABLE))
  $(info -  OLED_ENABLE        = $(OLED_ENABLE))
  $(info -- OLED_DRIVER        = $(OLED_DRIVER))
  $(info -- OLED_LOCAL_ENABLE  = $(OLED_LOCAL_ENABLE))
  $(info -- CONSOLE_ENABLE     = $(CONSOLE_ENABLE))
  $(info -- OPT_DEFS           = $(OPT_DEFS))
  $(info -- LTO_ENABLE         = $(LTO_ENABLE))
  $(info -- VIA_ENABLE         = $(VIA_ENABLE))
  $(info -- BOOTMAGIC_ENABLE   = $(BOOTMAGIC_ENABLE))
  $(info )
