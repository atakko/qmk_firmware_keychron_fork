#pragma once

// Unicode
#define UNICODE_SELECTED_MODES UC_WINC

// Leader
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 400
#define LEADER_NO_TIMEOUT

// Home row mods
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 170
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

// Caps words
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Combos
#define COMBO_COUNT 5
#define COMBO_TERM 30
