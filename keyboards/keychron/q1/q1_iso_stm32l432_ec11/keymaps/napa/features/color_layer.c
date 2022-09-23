#include QMK_KEYBOARD_H
#include "color_layer.h"

static HSV hsv_save;

void color_layer_set(uint8_t h, uint8_t s) {
    hsv_save = rgb_matrix_get_hsv();
    rgb_matrix_sethsv_noeeprom(h, s, hsv_save.v);
}

void color_layer_restore() {
    rgb_matrix_sethsv_noeeprom(hsv_save.h, hsv_save.s, hsv_save.v);
}
