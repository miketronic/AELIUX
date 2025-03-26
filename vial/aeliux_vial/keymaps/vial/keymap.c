// Copyright 2025
// miketronic@github
// instagram.com/mkbrrd
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _MAC,
  _NUM,
  _MSE,
  _FN,
  _SYM,
  _SIX,
  _SVN
};

// Layer macros
#define QSYM    LT(_SYM, KC_Q)         // Tap for "Q", hold for Symbols layer
#define ZFN     LT(_FN, KC_Z)           // Tap for "Z", hold for FN layer
#define ENUM    LT(_NUM, KC_ESC)        // Tap for "Esc", hold for Numbers layer
#define PMSE    LT(_MSE, KC_P)        // Tap for "P", hold for Mouse layer
#define AMAC    LT(_MAC, KC_A)        // Tap for "A", hold for Macro layer
#define SFTSPC  SFT_T(KC_SPC)           // Tap for "Space", hold for Shift
#define SFTENT  SFT_T(KC_ENT)           // Tap for "Enter", hold for Shift


// MISC
#define CALTDEL LCTL(LALT(KC_DEL))	    // Ctrl Alt Del
#define TSKMGR  LCTL(LSFT(KC_ESC))	    // Task Manager
#define CLIP    LCTL(LALT(KC_Q))	    	// Clipboard (Ditto)
#define SS      LCTL(LALT(KC_G))		    // Greenshot region
#define DELWORD LCTL(KC_BSPC)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define ____    KC_TRNS
#define XXXX    KC_NO
#define XXXXXXX KC_NO



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_ALPHA] = LAYOUT (
      ENUM,     QSYM,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,       PMSE,     KC_BSPC,
      KC_TAB,   AMAC,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,       KC_SCLN,
      KC_LSFT,  ZFN,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,     KC_UP,
      KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,           KC_LEFT,  KC_RIGHT,   KC_DOWN
     ),

    [_MAC] = LAYOUT (
      XXXX,   XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX,
      XXXX,   XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX,
      XXXX,   XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX,
      KC_LCTL,  KC_LGUI, KC_LALT,    SFTSPC,       SFTENT,    XXXX, XXXX, XXXX
     ),


    [_NUM] = LAYOUT (
      XXXX,   KC_1,  KC_2,  KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,  KC_9, KC_0, KC_BSPC,
      XXXX,   XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, KC_4, KC_5,  KC_6, XXXX,
      XXXX,   XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, KC_1, KC_2,  KC_3, XXXX,
      KC_LCTL,  KC_LGUI, KC_LALT,    SFTSPC,       SFTENT,    XXXX, XXXX, XXXX
    ),

    [_MSE] = LAYOUT (
      KC_WH_U,  KC_MS_U,  KC_WH_D, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
      KC_MS_L,  KC_MS_D,  KC_MS_R, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
      KC_BTN3,  KC_BTN2,  KC_BTN1, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
      KC_LCTL,  KC_LGUI, KC_LALT,    SFTSPC,       SFTENT,    XXXX, XXXX, XXXX
    ),

    [_FN] = LAYOUT (
      XXXX,   CLIP,    SS,      XXXX, XXXX, XXXX, XXXX, XXXX, KC_F2,   KC_UP,   KC_DEL, XXXX,
      KC_TAB, DELWORD, XXXX,    XXXX, XXXX, XXXX, XXXX, XXXX, KC_LEFT, KC_DOWN, KC_RGHT,
      XXXX,   XXXX,    XXXX,    XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,  XXXX,      XXXX,
      KC_LCTL,  KC_LGUI, KC_LALT,          SFTSPC,           SFTENT,            XXXX, XXXX, QK_BOOT
    ),

    [_SYM] = LAYOUT (
      XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
      XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
      XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
      KC_LCTL,  KC_LGUI, KC_LALT,    SFTSPC,       SFTENT,    XXXX, XXXX, XXXX
    ),

    [_SIX] = LAYOUT (
      XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX,
      XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX,
      XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX,
      KC_LCTL,  KC_LGUI, KC_LALT,    SFTSPC,       SFTENT,    XXXX, XXXX, XXXX
    ),

    [_SVN] = LAYOUT (
      XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX,
      XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX,
      XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX,  XXXX, XXXX, XXXX,
      KC_LCTL,  KC_LGUI, KC_LALT,    SFTSPC,       SFTENT,    XXXX, XXXX, XXXX
    ),

};
