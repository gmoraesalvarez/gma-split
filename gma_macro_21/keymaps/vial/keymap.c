#include "gma_macro_21.h"
//#include QMK_KEYBOARD_H

enum layers {
  NORMAL_LAYER = 0,
  SECOND_LAYER,
  THIRD_LAYER,
  FOURTH_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[NORMAL_LAYER] = LAYOUT( 
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_GRV, 
		KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, 
		RGUI_T(KC_SPC), TT(1), TT(2), KC_NO, KC_NO, KC_NO),
	[SECOND_LAYER] = LAYOUT(
		KC_7, KC_8, KC_9, KC_ASTR, KC_VOLD, KC_VOLU, 
		KC_4, KC_5, KC_6, KC_PLUS, KC_TRNS, KC_EQL, 
		KC_1, KC_2, KC_3, KC_TRNS, KC_BSLS, KC_TRNS,  
		KC_TRNS, KC_TRNS, KC_0, KC_NO, KC_NO, KC_NO),
	[THIRD_LAYER] = LAYOUT(
		KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
		KC_F4, KC_F5, KC_F6, KC_HOME, KC_UP, KC_END, 
		KC_F1, KC_F2, KC_F3, KC_LEFT, KC_DOWN, KC_RGHT, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO),
	[FOURTH_LAYER] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
		KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO)
};


/*void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

} */
