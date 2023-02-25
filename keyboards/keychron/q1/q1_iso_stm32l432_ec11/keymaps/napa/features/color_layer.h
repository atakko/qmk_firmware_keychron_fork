#pragma once

// HSV Colors
// All values (including hue) are scaled to 0-255
// #define HSV_BLACK         0,   0,   0
// #define HSV_BLUE        170, 255, 255
// #define HSV_GREEN        85, 255, 255
// #define HSV_ORANGE       21, 255, 255
// #define HSV_PURPLE      191, 255, 255
// #define HSV_RED           0, 255, 255
// #define HSV_WHITE         0,   0, 255
// #define HSV_YELLOW       43, 255, 255
// #define HSV_OFF         HSV_BLACK
#define HS_GAME      0, 255 // Red
#define HS_WIN       156, 255 // Blue
#define HS_LEADER    8, 255 // Orange
#define HS_CAPS      85, 255 // Green
#define HS_SHUTDOWN  234, 128 // Pink

void color_layer_set(uint8_t h, uint8_t s);
void color_layer_restore(void);
