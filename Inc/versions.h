/*
 * version.h
 *
 *  Created on: Apr 25, 2024
 *      Author: majid
 */

#ifndef INCLUDE_VERSIONS_H_
#define INCLUDE_VERSIONS_H_

#include "globals.h"

#define COMMIT_HASH			"1106c1e"
#define REVISION			50
#define DEVICE_CAT			"FC22"

#if RECLOSER
#define DEVICE_TYPE			"AR"
#define FIRMWARE_VERSION	100
#else
#define DEVICE_TYPE			"S"
#define FIRMWARE_VERSION	108
#endif

#ifdef CHANGE_OVER
#undef  DEVICE_TYPE
#define DEVICE_TYPE			"CO"
#endif

#ifdef DISJONCTEUR
#undef  DEVICE_TYPE
#define DEVICE_TYPE			"D"
#endif

#ifndef MAIN_RELEASE
#undef COMMIT_HASH
#define COMMIT_HASH			"xxTESTxx"
#endif

#define DEVICE_MODEL		DEVICE_CAT DEVICE_TYPE

#define DFHB_VERSION		"DFHB-VER." DEVICE_MODEL "." STR(FIRMWARE_VERSION) "." STR(HARDWARE_VERSION) \
	"." STR(REVISION) "." COMMIT_HASH

#endif /* INCLUDE_VERSIONS_H_ */


