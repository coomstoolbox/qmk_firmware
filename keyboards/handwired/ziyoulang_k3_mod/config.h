// Copyright 2023 Coom (@coomstoolbox)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

// A0-A15 (10)
// A1 led *
// A8 key *
// A11 USB-
// A12 USB+
// A13 SWCLT
// A14 SWDIO
// B0-B15 (13)
// PB2 boot1 *
// PB6,PB7 i2c sck,sda
// B10,B11 i2c sck,sda
// C13-C15 (3)

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
