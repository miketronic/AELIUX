// Copyright 2025
// miketronic@github
// instagram.com/mkbrrd
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

enum layers {
  _ALPHA,
  _MACRO,
  _NUM,
  _MOUSE,
  _FN,
  _SYMB
};

// Layer macros
#define QSYM    LT(_SYMB, KC_Q)         // Tap for "Q", hold for Symbols layer
#define ZFN     LT(_FN, KC_Z)           // Tap for "Z", hold for FN layer
#define ENUM    LT(_NUM, KC_ESC)        // Tap for "Esc", hold for Numbers layer
#define PMOUSE  LT(_MOUSE, KC_P)        // Tap for "P", hold for Mouse layer
#define AMACRO  LT(_MACRO, KC_A)        // Tap for "A", hold for Macro layer
#define SFTSPC  SFT_T(KC_SPC)           // Tap for "Space", hold for Shift
#define SFTENT  SFT_T(KC_ENT)           // Tap for "Enter", hold for Shift


// MISC
#define CALTDEL LCTL(LALT(KC_DEL))	        // Ctrl Alt Del
#define TSKMGR  LCTL(LSFT(KC_ESC))	        // Task Manager
#define CLIP    LCTL(LALT(KC_Q))	    	// Clipboard (Ditto)
#define SS      LCTL(LALT(KC_G))		    // Greenshot region
#define DELWORD LCTL(KC_BSPC)         
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define ____    KC_TRNS
#define XXXX    KC_NO
#define XXXXXXX KC_NO


// Tap Dance
enum tapdance_id{
  T_20 = 0,
  T_BRACES,
  T_PAREN,
  T_ANGLE
};

#define TD_20    TD(T_20)
#define TD_BRACES TD(T_BRACES)
#define TD_PAREN TD(T_PAREN)
#define TD_ANGLE TD(T_ANGLE)

tap_dance_action_t tap_dance_actions[] = {
  [T_20] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_0),                         // "2", "0"
  [T_BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),               // "[", "]"
  [T_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),                // "(", ")"
  [T_ANGLE] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),                    // "<", ">"
};

enum custom_keycodes{
  MAKE = QK_USER,
  M01,
  M02,
  M03,
  M04,
  M05,
  M06, 
  M07,
  M08,
  EMAIL,
  ANGLE,
  PAREN,
  BRACES,
  CCCV,
  ENDHOME,
  UNDOER,
  SYM1,
  SYM2,
  SYM3,
  SYM4,
  SYM5,
  SYM6,
  SYM7,
  SYM8
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_ALPHA] = LAYOUT (
    ENUM,     QSYM,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,       PMOUSE,  KC_BSPC,
    KC_TAB,   AMACRO,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,       KC_SCLN,
    KC_LSFT,  ZFN,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,     KC_UP,
    KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,           KC_LEFT,  KC_RIGHT,   KC_DOWN
   ),

  [_MACRO] = LAYOUT (
    XXXX,   XXXX,  M08,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
    XXXX,   XXXX,  M03,  M04,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
    XXXX,   XXXX,  M01,  M02,  M05,  M06,  M07,  XXXX, XXXX, XXXX, XXXX,
    KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,           XXXX, XXXX, XXXX
   ),


  [_NUM] = LAYOUT (
    XXXX,   KC_1,  KC_2,  KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,  KC_9, KC_0, KC_BSPC,
    XXXX,   XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, KC_4, KC_5,  KC_6, XXXX,
    XXXX,   XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, KC_1, TD_20, KC_3, XXXX,
    KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,           XXXX, XXXX, XXXX
  ),

  [_MOUSE] = LAYOUT (
    KC_WH_U,  KC_MS_U,  KC_WH_D, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
    KC_MS_L,  KC_MS_D,  KC_MS_R, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
    KC_BTN3,  KC_BTN2,  KC_BTN1, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
    KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,           XXXX, XXXX, XXXX
  ),

  [_FN] = LAYOUT (
    CCCV,   CLIP,    SS,      XXXX, XXXX, XXXX, XXXX, XXXX, KC_F2,   KC_UP,   KC_DEL, XXXX,
    KC_TAB, DELWORD, XXXX,    XXXX, XXXX, XXXX, XXXX, XXXX, KC_LEFT, KC_DOWN, KC_RGHT,
    XXXX,   XXXX,    XXXX,    XXXX, XXXX, XXXX, XXXX, XXXX, UNDOER,  XXXX,    ENDHOME,
    KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,           XXXX, XXXX, QK_BOOT
  ),

  [_SYMB] = LAYOUT (
   XXXX,  XXXX,  SYM1, XXXX, XXXX, XXXX, XXXX, XXXX, TD_PAREN, TD_BRACES, TD_ANGLE, XXXX,
   XXXX,  XXXX,  SYM2, XXXX, XXXX, XXXX, XXXX, XXXX, SYM3,     SYM4,      SYM5,
   XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, SYM6,     SYM7,      SYM8,
   KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,           XXXX, XXXX, XXXX
  ),

    
};

 

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AMACRO:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case ZFN:
            return false;
        case ENUM:
            return false;
        case QSYM:
            return false;
        case PMOUSE:
            return false;
        case SFTSPC:
            return false;
        case SFTENT:
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
switch (keycode) {
	  case CCCV:
				return 80;
			default:
				return TAPPING_TERM;
		}
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M01:
            if (record->event.pressed) {
                SEND_STRING("//a11");
            }
            return false;
            break;

        case M02:
            if (record->event.pressed) {
                SEND_STRING("//a12");
            }
            return false;
            break;

        case M03:
            if (record->event.pressed) {
                SEND_STRING("//a08");
            }
            return false;
            break;

        case M04:
            if (record->event.pressed) {
                SEND_STRING("//a09");
            }
            return false;
            break;

        case M05:
            if (record->event.pressed) {
                SEND_STRING("//th");
            }
            return false;
            break;

        case M06:
            if (record->event.pressed) {
                SEND_STRING("//re");
            }
            return false;
            break;

        case M07:
            if (record->event.pressed) {
                SEND_STRING("//yw");
            }
            return false;
            break;

        case M08:
            if (record->event.pressed) {
                tap_random_base64();
            }
            return false;
            break;

        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("//email\n");
            }
            return false;
            break;

        case CCCV: // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) { // Hold, copy
                    tap_code16(LCTL(KC_C));
                } else { // Tap, paste
                    tap_code16(LCTL(KC_V));
                }
            }
            return false;
            break;
            
        case ENDHOME:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_HOME);
                } else {
                    tap_code16(KC_END);
                }
            }
            return false;
            break;

        case UNDOER:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    SEND_STRING(SS_LCTL("y"));
                } else {
                    SEND_STRING(SS_LCTL("z"));
                }
            }
            return false;
            break;

        case SYM1:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_CIRC);
                } else {
                    tap_code16(KC_ASTR);
                }
            }
            return false;
            break;

        case SYM2:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_PLUS);
                } else {
                    tap_code16(KC_EQL);
                }
            }
            return false;
            break;

        case SYM3:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_SCLN);
                } else {
                    tap_code16(KC_COLN);
                }
            }
            return false;
            break;

        case SYM4:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_BSLS);
                } else {
                    tap_code16(KC_SLSH);
                }
            }
            return false;
            break;

        case SYM5:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_AMPR);
                } else {
                    tap_code16(KC_PIPE);
                }
            }
            return false;
            break;

        case SYM6:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_DQUO);
                } else {
                    tap_code16(KC_QUOT);
                }
            }
            return false;
            break;

        case SYM7:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_HASH);
                } else {
                    tap_code16(KC_AT);
                }
            }
            return false;
            break;

        case SYM8:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_DLR);
                } else {
                    tap_code16(KC_PERC);
                }
            }
            return false;
            break;

        case ANGLE:
            if (record->event.pressed) {
                SEND_STRING("<>");
                tap_code(KC_LEFT);
            }
            return false;
            break;

        case BRACES:
            if (record->event.pressed) {
                SEND_STRING("[]");
                tap_code(KC_LEFT);
            }
            return false;
            break;

        case PAREN:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            return false;
            break;

    }
    return true;
}
