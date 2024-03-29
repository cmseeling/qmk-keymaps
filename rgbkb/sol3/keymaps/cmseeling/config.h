/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/cmseeling> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. Chris Seeling
 * ----------------------------------------------------------------------------
 */

#pragma once

// No need for the single versions when multi performance isn't a problem =D
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_HUE 168
#define RGB_MATRIX_STARTUP_SAT 255
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS

// 20m timeout (20m * 60s * 1000mil)
// #define RGB_DISABLE_TIMEOUT 1200000
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define STM32_ONBOARD_EEPROM_SIZE 2048

#undef TAPPING_TERM
#define TAPPING_TERM 160
