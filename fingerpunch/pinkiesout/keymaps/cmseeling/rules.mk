OLED_DRIVER_ENABLE = yes
OLED_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
EXTRAFLAGS += -flto
SRC += oled-bongocat.c
OPT_DEFS += -DRIGHTCAT
