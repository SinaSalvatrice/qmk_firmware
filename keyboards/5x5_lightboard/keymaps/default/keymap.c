#include QMK_KEYBOARD_H
#include "timer.h"
#include "gpio.h"


#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
    rgblight_set_speed_noeeprom(128);
    rgblight_sethsv_noeeprom(170, 255, 80);
}
#endif



enum layers {
    _BASE,
    _NAV,
    _EDIT,
    _MEDIA,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        LGUI(KC_TAB),  KC_UP,    LALT(KC_TAB),
        KC_LEFT,       KC_ENT,   KC_RGHT,
        LCTL(KC_Z),    KC_DOWN,  LCTL(KC_R)
    ),
    [_NAV] = LAYOUT(
        LGUI(KC_TAB),  KC_UP,    LALT(KC_TAB),
        KC_LEFT,       KC_ENT,   KC_RGHT,
        LCTL(KC_Z),    KC_DOWN,  LCTL(KC_R)
    ),
    [_EDIT] = LAYOUT(
        LCTL(KC_A),         LCTL(KC_C),   LCTL(KC_V),
        LCTL(KC_X),         LCTL(KC_ENT), KC_NO,
        LCTL(LSFT(KC_Z)),   KC_SPC,       KC_BSPC
    ),
    [_MEDIA] = LAYOUT(
        KC_MPRV,  KC_MSEL,  KC_MNXT,
        KC_MRWD,  KC_MPLY,  KC_MFFD,
        KC_DOWN,  KC_MSTP,  KC_UP
    ),

};
