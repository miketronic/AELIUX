// Copyright 2025
// miketronic@github
// instagram.com/mkbrrd
// SPDX-License-Identifier: GPL-2.0+

#pragma once

#    define DEBOUNCE 2
#    define TAPPING_TERM 170
#    define MACRO_TIMER 3

// Enable rapid switch from tap to hold, setting to 0 disables double tap hold auto-repeat.
#    define QUICK_TAP_TERM 0

// Mouse key speed and acceleration.
#    undef MOUSEKEY_DELAY
#    define MOUSEKEY_DELAY          0
#    undef MOUSEKEY_INTERVAL
#    define MOUSEKEY_INTERVAL       16
#    undef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY    0
#    undef MOUSEKEY_MAX_SPEED
#    define MOUSEKEY_MAX_SPEED      6
#    undef MOUSEKEY_TIME_TO_MAX
#    define MOUSEKEY_TIME_TO_MAX    64
