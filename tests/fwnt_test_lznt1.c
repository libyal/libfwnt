/*
 * Library LZNT1 decompression testing program
 *
 * Copyright (C) 2009-2019, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwnt_test_libcerror.h"
#include "fwnt_test_libcnotify.h"
#include "fwnt_test_libfwnt.h"
#include "fwnt_test_macros.h"
#include "fwnt_test_unused.h"

#include "../libfwnt/libfwnt_lznt1.h"

/* Define to make fwnt_test_lznt1 generate verbose output
#define FWNT_TEST_LZNT1
 */

uint8_t fwnt_test_lznt1_compressed_byte_stream[ 4135 ] = {
	0x9a, 0xb7, 0x00, 0x09, 0x09, 0x20, 0x20, 0x20, 0x47, 0x4e, 0x55, 0x00, 0x20, 0x4c, 0x45, 0x53, 
	0x53, 0x45, 0x52, 0x20, 0x00, 0x47, 0x45, 0x4e, 0x45, 0x52, 0x41, 0x4c, 0x20, 0x80, 0x50, 0x55, 
	0x42, 0x4c, 0x49, 0x43, 0x20, 0x00, 0x18, 0x60, 0x45, 0x4e, 0x53, 0x45, 0x0a, 0x00, 0x90, 0x11, 
	0x00, 0x56, 0x00, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x20, 0x33, 0x00, 0x2c, 0x20, 0x32, 0x39, 
	0x20, 0x4a, 0x75, 0x6e, 0x00, 0x65, 0x20, 0x32, 0x30, 0x30, 0x37, 0x0a, 0x0a, 0x00, 0x20, 0x43, 
	0x6f, 0x70, 0x79, 0x72, 0x69, 0x67, 0x40, 0x68, 0x74, 0x20, 0x28, 0x43, 0x29, 0x02, 0x28, 0x20, 
	0x00, 0x46, 0x72, 0x65, 0x65, 0x20, 0x53, 0x6f, 0x66, 0x00, 0x74, 0x77, 0x61, 0x72, 0x65, 0x20, 
	0x46, 0x6f, 0x20, 0x75, 0x6e, 0x64, 0x61, 0x74, 0x00, 0x7a, 0x2c, 0x20, 0x00, 0x49, 0x6e, 0x63, 
	0x2e, 0x20, 0x3c, 0x68, 0x74, 0x00, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x66, 0x73, 0x66, 0x00, 0x2e, 
	0x6f, 0x72, 0x67, 0x2f, 0x3e, 0x0a, 0x20, 0x40, 0x45, 0x76, 0x65, 0x72, 0x79, 0x6f, 0x00, 0x54, 
	0x69, 0x00, 0x73, 0x20, 0x70, 0x65, 0x72, 0x6d, 0x69, 0x74, 0x00, 0x74, 0x65, 0x64, 0x20, 0x74, 
	0x6f, 0x20, 0x63, 0x01, 0x00, 0x5d, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x64, 0x69, 0x00, 0x73, 0x74, 
	0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x2a, 0x20, 0x00, 0x2b, 0x62, 0x00, 0x4f, 0x6d, 0x01, 0x1c, 
	0x69, 0x65, 0x00, 0x73, 0x0a, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x01, 0x00, 0x39, 0x6c, 0x69, 
	0x63, 0x65, 0x6e, 0x73, 0x65, 0x00, 0x20, 0x64, 0x6f, 0x63, 0x75, 0x6d, 0x65, 0x6e, 0x08, 0x74, 
	0x2c, 0x20, 0x00, 0x2f, 0x20, 0x63, 0x68, 0x61, 0x00, 0x6e, 0x67, 0x69, 0x6e, 0x67, 0x20, 0x69, 
	0x74, 0x01, 0x01, 0x2f, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x6c, 0x6c, 0x40, 0x6f, 0x77, 0x65, 0x64, 
	0x2e, 0x0a, 0x80, 0x5f, 0x20, 0x5e, 0x54, 0x01, 0x1d, 0x80, 0x29, 0x82, 0x6f, 0x02, 0x25, 0x65, 
	0x83, 0x93, 0x65, 0x00, 0x73, 0x73, 0x65, 0x72, 0x20, 0x47, 0x65, 0x6e, 0x00, 0x65, 0x72, 0x61, 
	0x6c, 0x20, 0x50, 0x75, 0x62, 0x09, 0x80, 0x2f, 0x20, 0x4c, 0x84, 0x31, 0x69, 0x6e, 0x63, 0x6f, 
	0xc0, 0x72, 0x70, 0x6f, 0x72, 0x61, 0x74, 0x80, 0x40, 0x01, 0x19, 0x0a, 0x74, 0x00, 0x5b, 0x73, 
	0x02, 0x55, 0x63, 0x6f, 0x6e, 0x64, 0xda, 0x69, 0x81, 0x77, 0x73, 0x01, 0x27, 0x85, 0x2c, 0x33, 
	0x89, 0x2d, 0x0b, 0x2a, 0x02, 0x0a, 0x04, 0x2a, 0x2c, 0x20, 0x73, 0x75, 0x70, 0x70, 0x4c, 0x6c, 
	0x65, 0x81, 0x5d, 0x00, 0x7f, 0x62, 0x79, 0x82, 0x17, 0x61, 0x6e, 0x64, 0x83, 0x26, 0x00, 0x17, 
	0x02, 0x8d, 0x73, 0x01, 0x27, 0x01, 0x76, 0x73, 0x0d, 0x02, 0x12, 0x65, 0x00, 0x65, 0x00, 0x64, 
	0x20, 0x20, 0x30, 0x2e, 0x04, 0x20, 0x41, 0x07, 0x15, 0x44, 0x65, 0x66, 0x69, 0x6e, 0x09, 0x83, 
	0x42, 0x2e, 0x20, 0x01, 0x0f, 0x41, 0x73, 0x20, 0x75, 0x82, 0x73, 0x00, 0x0c, 0x68, 0x65, 0x72, 
	0x65, 0x69, 0x80, 0x62, 0x06, 0x22, 0x82, 0x4c, 0x44, 0x1e, 0x22, 0x20, 0x72, 0x65, 0x66, 0xaf, 
	0x00, 0x2a, 0x81, 0x5c, 0x12, 0x2c, 0x03, 0x43, 0x0a, 0x13, 0x43, 0x2c, 0x82, 0x3d, 0xe5, 0x81, 
	0x0a, 0x22, 0x02, 0x37, 0x50, 0x4c, 0xdd, 0x13, 0x14, 0x12, 0xc2, 0x31, 0x04, 0x22, 0x54, 0xc0, 
	0x08, 0x4c, 0x69, 0x62, 0x72, 0x61, 0x74, 0x72, 0x79, 0xc9, 0x11, 0x61, 0x00, 0x56, 0xc0, 0x12, 
	0x80, 0x30, 0x77, 0xa0, 0x6f, 0x72, 0x6b, 0x20, 0x67, 0x01, 0x03, 0x6e, 0x85, 0x49, 0x51, 0x87, 
	0x32, 0x2c, 0x0a, 0x6f, 0x00, 0x19, 0x72, 0xc0, 0x04, 0x61, 0x92, 0x6e, 0xc0, 0x25, 0x20, 0x41, 
	0x40, 0x54, 0x69, 0x63, 0xc2, 0x9f, 0x08, 0x20, 0x6f, 0x72, 0x40, 0x11, 0x43, 0x6f, 0x6d, 0x62, 
	0x0a, 0x69, 0x01, 0x0e, 0x57, 0x81, 0x11, 0x61, 0x73, 0x20, 0x64, 0x43, 0x81, 0x4a, 0x8a, 0x52, 
	0x41, 0x6e, 0x20, 0x22, 0xc8, 0x0d, 0x22, 0x31, 0xc1, 0x8d, 0x61, 0x6e, 0x79, 0x03, 0x1e, 0x00, 
	0x16, 0x74, 0x20, 0x70, 0x6d, 0x61, 0x6b, 0x65, 0x02, 0x54, 0x01, 0x35, 0x40, 0x19, 0x69, 0x01, 
	0x40, 0x6c, 0x72, 0x66, 0x61, 0x63, 0x65, 0x20, 0x70, 0x00, 0x72, 0x6f, 0x76, 0x69, 0x64, 0x65, 
	0x64, 0x0a, 0x07, 0x84, 0x6f, 0x44, 0x32, 0xc3, 0xa2, 0x77, 0x68, 0x69, 0x63, 0x68, 0x93, 0x45, 
	0xa1, 0xc2, 0x29, 0x77, 0x69, 0xc0, 0x10, 0x62, 0x61, 0x41, 0x66, 0xb3, 0x00, 0x28, 0x08, 0x0c, 
	0x2e, 0x0a, 0x83, 0x70, 0x00, 0xae, 0x61, 0xc0, 0x85, 0xe0, 0x62, 0x63, 0x6c, 0x61, 0x73, 0x02, 
	0x94, 0xc0, 0x41, 0x82, 0x02, 0xa7, 0x86, 0x2d, 0xca, 0x19, 0x01, 0x17, 0x64, 0x65, 0x80, 0x90, 
	0x64, 0x00, 0x0a, 0x20, 0x6d, 0x6f, 0x64, 0x65, 0x0a, 0x80, 0x0c, 0x75, 0x73, 0xcf, 0x82, 0x11, 
	0xd1, 0x14, 0xcc, 0x07, 0xc3, 0x1f, 0x20, 0x22, 0x8a, 0x24, 0xe3, 0x1f, 0xa3, 0xa3, 0x1f, 0xe0, 
	0x06, 0x64, 0x75, 0x63, 0xe3, 0x06, 0x63, 0x82, 0x04, 0x43, 0x41, 0x0b, 0x00, 0x2b, 0x6c, 0x69, 
	0x6e, 0x6b, 0xa3, 0x0c, 0x0a, 0xe1, 0x49, 0x2e, 0x77, 0x69, 0x74, 0x68, 0x0a, 0x0c, 0x01, 0x6e, 
	0xc0, 0x0f, 0x00, 0x61, 0x72, 0x74, 0x69, 0x63, 0x75, 0x6c, 0x61, 0xf6, 0x72, 0x4d, 0x6f, 0xe4, 
	0x04, 0x0a, 0x02, 0x07, 0xe3, 0x25, 0xc1, 0x02, 0xab, 0x36, 0x22, 0x77, 0xc0, 0x36, 0x6d, 0x61, 
	0x64, 0xe2, 0x85, 0x61, 0x6c, 0xde, 0x73, 0xe0, 0x84, 0x40, 0x7a, 0x21, 0x86, 0x61, 0x50, 0x4c, 
	0x20, 0x11, 0xe0, 0x2f, 0x4d, 0x44, 0x96, 0x22, 0x42, 0x1a, 0x61, 0x0e, 0x22, 0x4d, 0x80, 0x15, 
	0x6d, 0x01, 0x80, 0x4e, 0x43, 0x6f, 0x72, 0x72, 0x65, 0x73, 0x70, 0x83, 0xc1, 0x74, 0x00, 0x16, 
	0x53, 0x6f, 0x75, 0x72, 0x63, 0x20, 0x60, 0x62, 0x66, 0xb0, 0x43, 0x6d, 0x65, 0x61, 0x40, 0x6d, 
	0xa0, 0x0a, 0x0a, 0x07, 0x71, 0x06, 0x42, 0x06, 0x8e, 0x13, 0x2c, 0x20, 0x65, 0x78, 0x63, 0xac, 
	0x6c, 0x75, 0xe2, 0x04, 0x81, 0x46, 0x73, 0x63, 0x05, 0x63, 0x61, 0x31, 0x5f, 0x01, 0x06, 0x80, 
	0x86, 0x86, 0x83, 0x2f, 0x1b, 0xa1, 0x4b, 0x2c, 0x41, 0x88, 0x73, 0x8b, 0xa0, 0x33, 0x81, 0x5d, 
	0x69, 0xa0, 0x36, 0x73, 0x6f, 0x6c, 0x04, 0xa8, 0xfd, 0x00, 0xaa, 0x0a, 0xaa, 0x45, 0x68, 0x2d, 
	0xc3, 0x70, 0x22, 0x4b, 0x25, 0x49, 0x01, 0x21, 0x6f, 0x65, 0xb7, 0xe7, 0x20, 0x6b, 0x19, 0xa9, 
	0x35, 0x43, 0x80, 0x14, 0x3d, 0x21, 0x6f, 0x70, 0x62, 0x6a, 0x65, 0x63, 0xc0, 0xaa, 0x40, 0x05, 
	0x01, 0x0e, 0x2f, 0x7f, 0x80, 0x05, 0x48, 0x1c, 0x66, 0x22, 0x0a, 0x13, 0xa0, 0xa5, 0x28, 0x22, 
	0xa0, 0xc1, 0x61, 0x02, 0x0a, 0x61, 0x15, 0x75, 0x74, 0x69, 0x6c, 0x69, 0x74, 0x22, 0x79, 0x81, 
	0x4a, 0x67, 0x72, 0x61, 0xc0, 0xa7, 0x6e, 0x65, 0xe6, 0x65, 0x61, 0x52, 0x61, 0x08, 0x72, 0x65, 
	0x43, 0x4d, 0x81, 0x06, 0xcf, 0x24, 0xf0, 0x66, 0x72, 0x6f, 0x6d, 0xa2, 0x11, 0xca, 0x0c, 0x41, 
	0x6c, 0x87, 0x2f, 0xe9, 0xa1, 0x06, 0x53, 0x79, 0xa0, 0xa4, 0x6d, 0x84, 0x4a, 0x80, 0xc5, 0x92, 
	0x2e, 0x01, 0x22, 0x23, 0x31, 0x2e, 0x20, 0x45, 0x78, 0x63, 0x65, 0x36, 0x70, 0xe2, 0x20, 0xc0, 
	0x8d, 0x53, 0x80, 0x1c, 0xef, 0xb6, 0x50, 0x4c, 0x31, 0x82, 0x05, 0x59, 0x6f, 0x75, 0xe0, 0x4f, 
	0x21, 0x60, 0x6e, 0x76, 0x5e, 0x65, 0x00, 0xd4, 0x4b, 0x93, 0xe0, 0xdd, 0x00, 0x90, 0x73, 0x03, 
	0x08, 0x73, 0xbb, 0x20, 0x08, 0x61, 0x1d, 0x34, 0xc6, 0xd4, 0x04, 0x95, 0x22, 0x5c, 0x6f, 0x20, 
	0x16, 0xe2, 0x62, 0xe0, 0xb1, 0x67, 0x20, 0x62, 0xc1, 0xe4, 0xa1, 0x6a, 0xe4, 0x06, 0x39, 0x13, 
	0x0f, 0x32, 0x2e, 0x40, 0x17, 0x61, 0x0e, 0x41, 0x06, 0x4d, 0x6f, 0x50, 0x64, 0x69, 0x66, 0x69, 
	0x27, 0x3c, 0x73, 0x42, 0x04, 0x49, 0xf8, 0x66, 0x20, 0x79, 0xc1, 0x13, 0x81, 0x03, 0x43, 0x13, 
	0x40, 0xe8, 0x8b, 0x6b, 0xb7, 0x92, 0x22, 0x51, 0x19, 0x91, 0x02, 0x72, 0xa3, 0x02, 0x44, 0x14, 
	0x73, 0xb0, 0x01, 0x8e, 0x0a, 0x10, 0x42, 0x83, 0x19, 0xd9, 0x57, 0x66, 0x75, 0x6e, 0x83, 0x09, 
	0xe7, 0xc0, 0x19, 0x11, 0x1c, 0x51, 0x01, 0x62, 0x65, 0x23, 0x6b, 0x41, 0x08, 0xa0, 0x0b, 0x5f, 
	0xeb, 0x56, 0x60, 0x71, 0x90, 0x52, 0x30, 0x52, 0x72, 0x23, 0x20, 0x46, 0x05, 0x28, 0xf7, 0x09, 
	0x5a, 0x81, 0x55, 0x50, 0x2d, 0x67, 0x02, 0x7b, 0x60, 0x41, 0x60, 0x66, 0x50, 0x14, 0x1c, 0x68, 
	0x65, 0x12, 0x2c, 0x87, 0x08, 0x60, 0x13, 0x69, 0x6e, 0x76, 0xf2, 0x6f, 0xe0, 0x2c, 0x29, 0x2c, 
	0x91, 0x01, 0x92, 0x0b, 0x2d, 0x18, 0x77, 0x0e, 0x17, 0x13, 0x0d, 0x40, 0x40, 0xc4, 0x45, 0x3a, 
	0x81, 0x11, 0x20, 0x61, 0x29, 0xdf, 0xa4, 0x19, 0xfa, 0x62, 0xa7, 0x50, 0xf2, 0x0a, 0x73, 0x05, 
	0x6b, 0xb0, 0x2d, 0x20, 0x66, 0x4a, 0x6f, 0xb0, 0x28, 0x61, 0x81, 0x48, 0x65, 0x66, 0x30, 0x29, 
	0x74, 0xf7, 0x20, 0x0f, 0x71, 0x04, 0x60, 0x03, 0x75, 0x80, 0x8d, 0xa3, 0x3a, 0x40, 0x14, 0x11, 
	0x07, 0xcc, 0x65, 0x76, 0xf1, 0x0b, 0xfc, 0x66, 0x64, 0x6f, 0xb0, 0x0f, 0x01, 0x39, 0xbf, 0x42, 
	0x12, 0x82, 0x56, 0xf1, 0x03, 0x9d, 0x14, 0x12, 0x0d, 0xf7, 0x11, 0x73, 0x50, 0x31, 0xf8, 0x6c, 
	0x20, 0x6f, 0xc0, 0x7e, 0xc1, 0x85, 0x53, 0x3d, 0xc0, 0x00, 0x00, 0x08, 0xfa, 0x6d, 0xc0, 0x8e, 
	0x20, 0xd0, 0x11, 0x70, 0x01, 0x80, 0x0d, 0x42, 0x54, 0x11, 0x0f, 0x34, 0x69, 0x74, 0x50, 0x93, 
	0x75, 0xd0, 0x88, 0xa0, 0x64, 0x72, 0x65, 0x38, 0x6d, 0x61, 0x69, 0x40, 0x27, 0xf1, 0x3a, 0x30, 
	0x22, 0x66, 0x75, 0x6c, 0x6c, 0x2c, 0x60, 0x06, 0xe2, 0x0f, 0x62, 0xe7, 0x0f, 0x46, 0x25, 0x2c, 
	0xfd, 0x03, 0x5a, 0x6e, 0xb1, 0x97, 0xb4, 0x13, 0xff, 0x86, 0xd4, 0x4a, 0x31, 0x04, 0x99, 0x13, 
	0xa4, 0x20, 0x61, 0xa3, 0x0e, 0x62, 0x6c, 0xb0, 0x10, 0x6f, 0xd3, 0x13, 0xc3, 0x41, 0x18, 0x52, 
	0x28, 0x33, 0x2e, 0x20, 0x4f, 0x83, 0x42, 0x31, 0x45, 0xcf, 0x81, 0x9f, 0xe4, 0x92, 0x82, 0x2b, 
	0x00, 0x0c, 0x72, 0x69, 0x00, 0x06, 0x62, 0x3c, 0x09, 0x95, 0x6b, 0x48, 0x65, 0x10, 0x5d, 0x72, 
	0x20, 0x46, 0x69, 0xfc, 0x6c, 0x65, 0x93, 0x2c, 0xc1, 0x4a, 0xd9, 0x46, 0x11, 0x10, 0xf4, 0x76, 
	0x59, 0x16, 0xcf, 0x51, 0x20, 0xe8, 0x98, 0xf0, 0x00, 0xd8, 0x05, 0x0a, 0x61, 0x10, 0x8f, 0x72, 
	0x05, 0x7e, 0x66, 0x70, 0x05, 0x43, 0x0a, 0x41, 0xa6, 0xa4, 0x13, 0x9b, 0x69, 0x6c, 0x3d, 0x73, 
	0xf6, 0x75, 0xc0, 0x67, 0x03, 0x08, 0x0a, 0x02, 0x08, 0xe4, 0x13, 0x92, 0x9e, 0xc0, 0x03, 0xf1, 
	0xc2, 0x33, 0x63, 0x68, 0x6f, 0xe0, 0x10, 0x5c, 0x24, 0x60, 0x21, 0xb3, 0x05, 0x99, 0x78, 0x09, 
	0x64, 0x0a, 0x86, 0x09, 0x04, 0x80, 0x6c, 0x69, 0x80, 0xae, 0xb5, 0x73, 0xae, 0x6e, 0xf0, 0x2f, 
	0x72, 0x00, 0x0d, 0x30, 0x17, 0x61, 0x90, 0x50, 0x1e, 0x65, 0x80, 0x02, 0x90, 0x1f, 0x62, 0x36, 
	0x70, 0xaf, 0x75, 0x63, 0x74, 0x71, 0x00, 0x27, 0x0a, 0x6c, 0x61, 0x10, 0x07, 0xb0, 0x1e, 0x01, 
	0x21, 0x61, 0x74, 0x63, 0x63, 0x20, 0x99, 0x6f, 0x51, 0x02, 0x01, 0x58, 0x60, 0x6d, 0x6c, 0x91, 
	0xa0, 0x0b, 0x63, 0x72, 0x6f, 0x00, 0x01, 0x69, 0x6e, 0xc0, 0x78, 0x6f, 0xe0, 0x12, 0x64, 0x26, 
	0x03, 0x03, 0x60, 0x50, 0x70, 0x50, 0x64, 0xd0, 0xaa, 0x28, 0xc6, 0x74, 0xe0, 0x33, 0x40, 0x03, 
	0x66, 0x65, 0x77, 0xd0, 0x0c, 0xa1, 0x02, 0x01, 0xc1, 0x35, 0x20, 0x6c, 0x65, 0x6e, 0x67, 0x74, 
	0x68, 0x3b, 0xe0, 0x35, 0x11, 0x30, 0x64, 0xb0, 0x3d, 0x60, 0x3a, 0x25, 0x12, 0x66, 0x6f, 0x47, 
	0x11, 0xb3, 0xa0, 0x1b, 0x86, 0x34, 0x47, 0x69, 0x76, 0x42, 0x84, 0x6d, 0x9f, 0xe0, 0x03, 0x80, 
	0x2f, 0xe0, 0x0c, 0x50, 0x10, 0xc3, 0x24, 0x65, 0x61, 0x60, 0x13, 0xff, 0xd9, 0x38, 0x39, 0x1c, 
	0x02, 0x18, 0x74, 0x30, 0x28, 0x8b, 0xa2, 0xa9, 0xa1, 0x6e, 0x31, 0x34, 0xff, 0x94, 0x38, 0x59, 
	0x8d, 0x41, 0x01, 0x61, 0x2e, 0x11, 0x97, 0x31, 0x70, 0xd0, 0x03, 0x25, 0x57, 0xa7, 0xfc, 0x9f, 
	0x92, 0x23, 0xb1, 0x2e, 0x41, 0x63, 0xf0, 0x89, 0x70, 0xf1, 0x66, 0xff, 0x3d, 0x08, 0x52, 0x0a, 
	0x0b, 0x43, 0xe4, 0x30, 0xc4, 0x07, 0xb7, 0xc4, 0xb1, 0x04, 0xe5, 0xc4, 0xfd, 0x92, 0x05, 0x34, 
	0x01, 0x58, 0xb8, 0x63, 0x93, 0x2a, 0xfe, 0x60, 0xdb, 0x6a, 0x7f, 0x23, 0x33, 0x75, 0x23, 0xd3, 
	0x22, 0x0a, 0x74, 0x00, 0x47, 0x51, 0x67, 0x67, 0x65, 0x93, 0xa1, 0x51, 0x10, 0x84, 0x66, 0x66, 
	0x51, 0x60, 0x76, 0x65, 0x40, 0x43, 0x7f, 0xa0, 0x18, 0xc1, 0x22, 0x10, 0x7b, 0x00, 0xd0, 0x20, 
	0x0c, 0xd9, 0x5a, 0xe4, 0x0b, 0x0a, 0xf7, 0x3d, 0x85, 0x65, 0x13, 0xf0, 0x08, 0x74, 0xe0, 0x40, 
	0xb3, 0x15, 0x5f, 0x74, 0xd1, 0x0e, 0xfe, 0x72, 0xa1, 0x44, 0x80, 0x0e, 0xd0, 0x1f, 0x80, 0x01, 
	0x40, 0x28, 0xf0, 0x39, 0xf1, 0x77, 0xe0, 0x64, 0x65, 0x62, 0x75, 0x67, 0x72, 0xd3, 0x62, 0x30, 
	0x3c, 0x62, 0xff, 0xe0, 0x2d, 0x61, 0x22, 0xb2, 0x97, 0x00, 0x0a, 0x22, 0x1f, 0x10, 0x42, 0xbf, 
	0x22, 0xbf, 0x22, 0xff, 0xbf, 0x22, 0x89, 0x18, 0xdf, 0x90, 0x63, 0x47, 0x0a, 0xae, 0xdf, 0x22, 
	0xdf, 0x22, 0xdf, 0x22, 0xff, 0xdf, 0x22, 0xdf, 0x22, 0xd4, 0x22, 0xdc, 0xa6, 0xff, 0x22, 0xff, 
	0x22, 0xff, 0x22, 0xb3, 0x05, 0x7c, 0x63, 0x29, 0x10, 0xf0, 0xff, 0x94, 0x32, 0x0b, 0x40, 0xed, 
	0x30, 0x39, 0x79, 0xde, 0x73, 0xa2, 0x05, 0x43, 0xf4, 0xc3, 0x11, 0x30, 0xbc, 0x75, 0x91, 0x18, 
	0xd2, 0x66, 0xf8, 0x78, 0x65, 0x63, 0x80, 0x92, 0x67, 0x94, 0x41, 0x23, 0xc1, 0x96, 0x2b, 0x03, 
	0x73, 0x86, 0x97, 0x46, 0x10, 0x6d, 0x6f, 0x03, 0x04, 0x40, 0x01, 0x70, 0x10, 0x57, 0xb6, 0x00, 
	0x6e, 0x6f, 0x74, 0x69, 0x63, 0x65, 0x73, 0x2c, 0x00, 0x20, 0x61, 0x73, 0x20, 0x77, 0x65, 0x6c, 
	0x6c, 0x01, 0x01, 0x70, 0x61, 0x20, 0x72, 0x65, 0x66, 0x65, 0x72, 0x00, 0x65, 0x6e, 0x63, 0x65, 
	0x20, 0x64, 0x69, 0x72, 0x00, 0x65, 0x63, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x00, 0x68, 0x65, 
	0x20, 0x75, 0x73, 0x65, 0x72, 0x20, 0x04, 0x74, 0x6f, 0x01, 0x2c, 0x0a, 0x20, 0x20, 0x20, 0x63, 
	0x00, 0x6f, 0x70, 0x69, 0x65, 0x73, 0x20, 0x6f, 0x66, 0x01, 0x02, 0x38, 0x47, 0x4e, 0x55, 0x20, 
	0x47, 0x50, 0x4c, 0x10, 0x20, 0x61, 0x6e, 0x64, 0x00, 0x1e, 0x69, 0x73, 0x20, 0x12, 0x6c, 0x00, 
	0xb2, 0x6e, 0x73, 0x00, 0x86, 0x6f, 0x63, 0x75, 0x40, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x0a, 0x01, 
	0x68, 0x64, 0x00, 0x29, 0x20, 0x44, 0x6f, 0x20, 0x6f, 0x6e, 0x65, 0x81, 0x05, 0x6e, 0x66, 0x6f, 
	0x6c, 0x6c, 0x6f, 0x77, 0x00, 0x62, 0x06, 0x3a, 0x02, 0x1f, 0x01, 0x00, 0x30, 0x29, 0x20, 0x43, 
	0x6f, 0x10, 0x6e, 0x76, 0x65, 0x79, 0x02, 0x20, 0x4d, 0x69, 0x6e, 0x10, 0x69, 0x6d, 0x61, 0x6c, 
	0x00, 0x12, 0x72, 0x72, 0x65, 0x20, 0x73, 0x70, 0x6f, 0x6e, 0x64, 0x01, 0x8f, 0x53, 0x6f, 0xc4, 
	0x75, 0x72, 0x00, 0xa0, 0x75, 0x6e, 0x64, 0x01, 0x93, 0x00, 0x26, 0x90, 0x74, 0x65, 0x72, 0x6d, 
	0x04, 0x8c, 0x69, 0x73, 0x05, 0x49, 0x2e, 0x4c, 0x03, 0x83, 0x00, 0xdf, 0x02, 0x95, 0x65, 0x0c, 
	0x44, 0x41, 0x70, 0x82, 0x70, 0x80, 0x52, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x80, 0x0c, 0x20, 0x64, 
	0x65, 0x20, 0x69, 0x6e, 0x00, 0x7f, 0x66, 0x6f, 0x04, 0x72, 0x6d, 0x05, 0x20, 0x73, 0x75, 0x69, 
	0x74, 0x61, 0x74, 0x62, 0x6c, 0x01, 0x53, 0x72, 0x83, 0x22, 0x84, 0x38, 0x82, 0x36, 0x74, 0x20, 
	0x68, 0x61, 0x74, 0x20, 0x70, 0x00, 0x05, 0x69, 0x74, 0x0e, 0x2c, 0x89, 0x90, 0x85, 0x1e, 0x00, 
	0x9e, 0x6f, 0x6d, 0x62, 0x69, 0x85, 0x01, 0x76, 0x72, 0x00, 0x06, 0x6c, 0x69, 0x6e, 0x6b, 0x02, 
	0x13, 0x21, 0x89, 0x3b, 0x77, 0x69, 0x74, 0x68, 0x00, 0x3a, 0x6d, 0x6f, 0x00, 0x64, 0x69, 0x66, 
	0x69, 0x65, 0x64, 0x20, 0x76, 0xc8, 0x65, 0x72, 0x73, 0x81, 0x0b, 0x6f, 0x66, 0x85, 0x22, 0x81, 
	0x18, 0x36, 0x4c, 0x00, 0x1d, 0x00, 0x0e, 0x56, 0x04, 0x0e, 0x00, 0xc2, 0x70, 0x72, 0x58, 0x6f, 
	0x64, 0x75, 0x80, 0x80, 0x08, 0x1d, 0x43, 0x03, 0x36, 0x64, 0xc0, 0x20, 0x57, 0x6f, 0x72, 0x6b, 
	0x2c, 0x01, 0x66, 0x84, 0xd4, 0x21, 0x01, 0x00, 0x6d, 0x61, 0x6e, 0x6e, 0x00, 0x4e, 0x73, 0x70, 
	0x84, 0x65, 0x63, 0x83, 0x16, 0x62, 0x79, 0x20, 0x73, 0x01, 0xee, 0xfd, 0x80, 0x13, 0x36, 0x0d, 
	0x71, 0x40, 0x3b, 0x80, 0x77, 0x81, 0x60, 0x80, 0x49, 0x45, 0x10, 0x87, 0x11, 0x60, 0x03, 0x75, 
	0x01, 0x00, 0x31, 0x29, 0x20, 0x55, 0x40, 0x7b, 0x42, 0x61, 0x87, 0x4c, 0x73, 0x68, 0x61, 0x72, 
	0xc0, 0x19, 0x6c, 0x00, 0x69, 0x62, 0x72, 0x61, 0x72, 0x79, 0x20, 0x6d, 0x00, 0x65, 0x63, 0x68, 
	0x61, 0x6e, 0x69, 0x73, 0x6d, 0x5f, 0x42, 0x17, 0xc1, 0x42, 0x81, 0x11, 0x82, 0x3f, 0x88, 0x29, 
	0x4c, 0x43, 0x0b, 0x2e, 0xf8, 0x20, 0x20, 0x41, 0x47, 0x12, 0x87, 0x0e, 0xc0, 0x95, 0xc1, 0x8e, 
	0x02, 0x5e, 0x18, 0x28, 0x61, 0x29, 0x01, 0x5c, 0x40, 0xac, 0x74, 0x20, 0x72, 0x52, 0x75, 0x00, 
	0x3b, 0x69, 0x6d, 0x86, 0x11, 0x61, 0x41, 0xa7, 0x79, 0x03, 0x85, 0x35, 0x04, 0x15, 0x20, 0x61, 
	0x6c, 0x72, 0x65, 0x61, 0xe4, 0x64, 0x79, 0xc0, 0x4e, 0x65, 0x73, 0x40, 0xa4, 0x80, 0x12, 0x46, 
	0x6d, 0xc4, 0x27, 0x73, 0x40, 0x0c, 0x6d, 0x70, 0x75, 0x00, 0x76, 0xc6, 0x7e, 0x20, 0x79, 0x73, 
	0x74, 0x65, 0x6d, 0x43, 0x7d, 0x28, 0x62, 0x16, 0x29, 0x80, 0x2a, 0x00, 0xc8, 0x6f, 0x80, 0x7b, 
	0x61, 0x74, 0x65, 0xf3, 0x81, 0x5f, 0x40, 0x02, 0x6c, 0x79, 0xd5, 0x6f, 0x05, 0x11, 0x4c, 0x20, 
	0x02, 0x2e, 0x09, 0x00, 0x31, 0x69, 0x6e, 0x00, 0x1a, 0x66, 0x61, 0x63, 0x65, 0xfe, 0x2d, 0x41, 
	0x1d, 0x40, 0x82, 0x81, 0x39, 0xc5, 0x42, 0x44, 0x7b, 0x85, 0x10, 0x04, 0x7d, 0x04, 0x2e, 0x20, 
	0xc2, 0x5a, 0x65, 0x29, 0x20, 0x50, 0x72, 0x08, 0x6f, 0x76, 0x69, 0x40, 0xab, 0x49, 0x6e, 0x73, 
	0x74, 0xc8, 0x61, 0x6c, 0x6c, 0xc3, 0x91, 0x49, 0x6e, 0xc1, 0xad, 0xc2, 0x02, 0x30, 0x2c, 0x20, 
	0x62, 0x75, 0x01, 0x37, 0x40, 0x27, 0x69, 0x66, 0x00, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x77, 0x6f, 
	0x75, 0x10, 0x6c, 0x64, 0x20, 0x6f, 0xc0, 0x16, 0x72, 0x77, 0x69, 0x92, 0x73, 0x42, 0x49, 0x62, 
	0x65, 0x40, 0xa4, 0x71, 0x75, 0x00, 0x7c, 0x87, 0x20, 0x63, 0xc2, 0x49, 0x62, 0x0a, 0x73, 0x75, 
	0x63, 0x68, 0xa0, 0x13, 0xff, 0x66, 0x09, 0xe4, 0x5d, 0x2d, 0x45, 0x21, 0x08, 0x84, 0x45, 0x03, 
	0x24, 0xa2, 0x0d, 0x63, 0x83, 0xf0, 0x20, 0x65, 0x78, 0x74, 0xa1, 0x2b, 0x62, 0x1d, 0xee, 0x09, 
	0x83, 0x73, 0xd4, 0x6e, 0x65, 0xc0, 0x8e, 0x73, 0x22, 0x22, 0x6f, 0xc0, 0x03, 0xe2, 0x18, 0xe1, 
	0xe2, 0x08, 0x65, 0x78, 0x65, 0x63, 0x80, 0x30, 0x33, 0x62, 0x25, 0x0f, 0xff, 0x0a, 0x5d, 0x25, 
	0x61, 0x22, 0x5a, 0x25, 0x6e, 0x41, 0x4b, 0x66, 0x6e, 0xe4, 0x97, 0x21, 0x07, 0x87, 0x3f, 0x6f, 
	0xe5, 0x0c, 0x4c, 0x6e, 0x2e, 0x20, 0x28, 0x49, 0x22, 0x72, 0x8f, 0xc1, 0x29, 0x00, 0x46, 0x00, 
	0x41, 0x82, 0x08, 0x34, 0x64, 0x30, 0x43, 0x7f, 0x01, 0x95, 0x31, 0x20, 0x6d, 0x75, 0x73, 0x74, 
	0x20, 0x61, 0xf2, 0x63, 0xe2, 0x3c, 0x6e, 0x79, 0x41, 0x08, 0xbe, 0x9a, 0x01, 0x21, 0x36, 0x95, 
	0xc1, 0x03, 0x20, 0x64, 0x65, 0x2e, 0x20, 0x49, 0x83, 0x3b, 0xaa, 0x11, 0xfc, 0x31, 0x2c, 0x62, 
	0x02, 0x82, 0x0e, 0x65, 0x3a, 0xcd, 0x13, 0x21, 0x08, 0x29, 0x14, 0xbf, 0x03, 0x85, 0x3f, 0x84, 
	0x28, 0x84, 0x41, 0x08, 0x8a, 0x84, 0xb3, 0x83, 0x29, 0x41, 0x56, 0xbc, 0x35, 0x2e, 0x07, 0x36, 
	0xe3, 0x60, 0xc0, 0xc6, 0x02, 0x87, 0x59, 0x21, 0x15, 0x3a, 0x61, 0xe0, 0x71, 0x6c, 0x20, 0x61, 
	0x06, 0x85, 0xc0, 0x62, 0x69, 0x6c, 0xbc, 0x69, 0x74, 0x61, 0xcb, 0x42, 0x48, 0xa0, 0x88, 0xc0, 
	0x34, 0x77, 0x41, 0x3d, 0x58, 0x62, 0x61, 0x73, 0x80, 0x08, 0xc3, 0x76, 0x0a, 0x65, 0x6a, 0x73, 
	0xef, 0x61, 0x1c, 0x61, 0x15, 0xe1, 0x00, 0x22, 0xb8, 0x73, 0x40, 0x10, 0xe0, 0x69, 0x05, 0x0a, 
	0xf0, 0x74, 0x6f, 0x67, 0x65, 0x41, 0x5f, 0x23, 0x3e, 0xa2, 0x60, 0x65, 0x03, 0x7e, 0x0a, 0x91, 
	0x0d, 0xa0, 0xe2, 0x09, 0x2e, 0x00, 0x8c, 0xe0, 0x31, 0x05, 0x03, 0x63, 0xfe, 0x6f, 0xe0, 0x44, 
	0x83, 0x23, 0x22, 0xcd, 0x4a, 0xcc, 0xc3, 0x21, 0x83, 0x5e, 0x41, 0x90, 0x1f, 0xa4, 0x1e, 0x05, 
	0x11, 0x69, 0xc7, 0xe0, 0x29, 0x00, 0x35, 0x72, 0x0a, 0x63, 0x1c, 0x68, 0x6f, 0x20, 0x08, 0xa0, 
	0xb5, 0x83, 0x39, 0x64, 0x6f, 0x20, 0xee, 0x62, 0x20, 0x14, 0xb4, 0xe3, 0x20, 0x9e, 0x41, 0x25, 
	0x49, 0xe2, 0x03, 0x4e, 0x0c, 0xe3, 0x84, 0x5a, 0xa9, 0x9f, 0x73, 0x61, 0x6d, 0x60, 0x8b, 0xc6, 
	0x27, 0xe1, 0x08, 0xfb, 0x04, 0x9f, 0x24, 0x28, 0x2c, 0x80, 0x09, 0x86, 0x04, 0x03, 0x04, 0xe0, 
	0x05, 0x7a, 0x12, 0xfd, 0x48, 0x19, 0x2c, 0xb3, 0x7f, 0x81, 0x0e, 0xe0, 0x02, 0x0f, 0x78, 0xd3, 
	0x7f, 0x64, 0x11, 0xa3, 0xf3, 0x61, 0xc0, 0x53, 0x47, 0x69, 0x76, 0x42, 0x53, 0x6d, 0x40, 0x06, 
	0x9f, 0xb0, 0x41, 0x83, 0x87, 0x17, 0x4f, 0x7e, 0x0c, 0xa3, 0x75, 0x61, 0x72, 0x70, 0x4c, 0xf0, 
	0x66, 0x20, 0x69, 0x74, 0x51, 0x04, 0x50, 0x05, 0x6f, 0x20, 0x48, 0x0c, 0x37, 0xe3, 0x43, 0xb0, 
	0x24, 0xe3, 0x3f, 0x77, 0xe0, 0x0b, 0x50, 0x09, 0x6f, 0x20, 0xfc, 0x66, 0x69, 0xc3, 0x7f, 0x02, 
	0x14, 0xd5, 0x13, 0x11, 0x02, 0x58, 0x0f, 0xc1, 0x30, 0x03, 0xfe, 0x12, 0xc2, 0x0b, 0x36, 0x2e, 
	0x20, 0x52, 0x65, 0x76, 0x37, 0x40, 0x53, 0xa6, 0x40, 0x2a, 0x8f, 0x4c, 0x60, 0x4c, 0x00, 0x10, 
	0x47, 0x65, 0x63, 0xa0, 0x33, 0xe0, 0x3c, 0x50, 0x75, 0x62, 0x60, 0x23, 0xda, 0x0f, 0x54, 0x21, 
	0x90, 0x02, 0x46, 0x72, 0x65, 0x65, 0x30, 0x31, 0x66, 0x74, 0xf2, 0x77, 0x61, 0x24, 0x46, 0x6f, 
	0x50, 0x13, 0xc4, 0x41, 0xd1, 0x2f, 0x31, 0x03, 0x5c, 0x73, 0x68, 0xc0, 0x4a, 0x63, 0x06, 0x70, 
	0x0c, 0x2f, 0xa0, 0x35, 0x6e, 0xe4, 0x65, 0x77, 0x25, 0x49, 0x73, 0x0a, 0x1f, 0x07, 0x1f, 0x07, 
	0xd2, 0x96, 0x1e, 0x66, 0x20, 0x16, 0x92, 0x70, 0xc2, 0x58, 0x70, 0x00, 0x2e, 0x20, 0x53, 0x3b, 
	0xd1, 0x28, 0xd0, 0x04, 0x0a, 0xd5, 0x04, 0x93, 0x6c, 0x00, 0x60, 0x73, 0x69, 0x20, 0x6d, 0x69, 
	0x6c, 0x61, 0x72, 0x41, 0x33, 0x73, 0x70, 0xf8, 0x69, 0x72, 0x69, 0x30, 0x5b, 0x13, 0x5c, 0x05, 
	0x72, 0x14, 0x03, 0x03, 0x65, 0x1d, 0xb0, 0x0a, 0x0a, 0xa0, 0x52, 0xb0, 0xa1, 0x01, 0x03, 0x64, 
	0x65, 0x74, 0x88, 0x61, 0x69, 0x6c, 0x01, 0x03, 0x61, 0x64, 0x64, 0xe0, 0x02, 0x3e, 0x73, 0x02, 
	0x0b, 0x10, 0x1e, 0x90, 0x6c, 0x71, 0x20, 0xb2, 0x41, 0x63, 0x65, 0xe4, 0x72, 0x6e, 0xa3, 0x3e, 
	0x45, 0x61, 0x40, 0x08, 0x15, 0x56, 0x90, 0x1c, 0x46, 0x67, 0xf0, 0x20, 0xa1, 0x3a, 0x64, 0x69, 
	0x73, 0xf1, 0xa5, 0x75, 0x07, 0x00, 0x10, 0x21, 0x19, 0x15, 0x02, 0x6e, 0x75, 0x6d, 0x62, 0x65, 
	0xbe, 0x72, 0x22, 0x4e, 0xa9, 0x3e, 0xe0, 0xa9, 0x41, 0x32, 0x50, 0x5e, 0x65, 0xf0, 0x03, 0xee, 
	0x64, 0x80, 0x21, 0xe6, 0x4a, 0xf5, 0x3b, 0x20, 0x30, 0x07, 0x90, 0x09, 0x25, 0x04, 0xef, 0x18, 
	0x79, 0x3f, 0x14, 0x3f, 0x14, 0x32, 0x14, 0x22, 0xc0, 0x0b, 0x11, 0x30, 0xd0, 0x52, 0xe3, 0x40, 
	0x02, 0xe4, 0x03, 0x22, 0x0a, 0x61, 0x21, 0x41, 0x71, 0x06, 0x10, 0x6b, 0xf3, 0xf0, 0x9e, 0x81, 
	0x08, 0x68, 0x61, 0x50, 0x2d, 0x41, 0x05, 0xf4, 0x57, 0x20, 0x06, 0xd7, 0x16, 0x3b, 0x48, 0x31, 
	0x10, 0x1d, 0x0a, 0xd0, 0x10, 0x64, 0xf0, 0x33, 0xe1, 0x17, 0xfe, 0x65, 0x50, 0x2f, 0x80, 0x05, 
	0xf2, 0x08, 0x51, 0x2e, 0xf3, 0x1f, 0x19, 0x68, 0xc2, 0x01, 0xfd, 0x2e, 0x08, 0x0a, 0x97, 0x02, 
	0xd2, 0x47, 0x7f, 0x25, 0x75, 0x25, 0x85, 0x13, 0x97, 0x8f, 0xe5, 0x82, 0x13, 0x0a, 0x89, 0x13, 
	0x64, 0x6f, 0xb0, 0x0c, 0x11, 0x4d, 0x13, 0x14, 0xf7, 0x30, 0x02, 0xdc, 0x17, 0x6f, 0x2e, 0x0a, 
	0x0f, 0x13, 0xb3, 0x4f, 0x22, 0x67, 0xa0, 0x2c, 0x7d, 0xc0, 0x4c, 0x6f, 0x41, 0xa0, 0x90, 0x0b, 
	0xdc, 0x74, 0x4f, 0x04, 0x5d, 0x17, 0x65, 0xff, 0x10, 0x03, 0xb8, 0x10, 0x1f, 0x0e, 0x1b, 0x0e, 
	0x41, 0x25, 0x4f, 0x0e, 0xdf, 0x21, 0xdc, 0x21, 0x55, 0x00, 0x2a, 0x78, 0x70, 0x0a, 0x61, 0x01, 
	0x2c, 0x63, 0x00, 0x63, 0x0a, 0xc3, 0x60, 0x42, 0xd2, 0x18, 0x66, 0x75, 0x74, 0x75, 0x10, 0x06, 
	0x36, 0x32, 0xcf, 0xdf, 0x22, 0x7f, 0x0b, 0x72, 0x0b, 0x60, 0xae, 0x6c, 0x6c, 0xc2, 0x21, 0x30, 
	0x48, 0xcf, 0x03, 0x1d, 0x31, 0x06, 0x00, 0xa5, 0xc2, 0x0c, 0x63, 0x20, 0x80, 0x77, 0x70, 0xa4, 
	0x03, 0xf2, 0xa6, 0x40, 0x1d, 0x63, 0x63, 0x65, 0x70, 0x74, 0x61, 0x57, 0xc1, 0xd5, 0x24, 0x1e, 
	0x47, 0x31, 0x0a, 0xa1, 0xc4, 0x61, 0xf2, 0x51, 0x61, 0x80, 0x75, 0x74, 0x68, 0x6f, 0x72, 0x69, 
	0x7a, 0x53, 0x42, 0xff, 0x91, 0x76, 0x91, 0x0d, 0x90, 0x27, 0x14, 0x16, 0x72, 0x06, 0x95, 0x03, 
	0xe1, 0x01, 0x58, 0x32, 0x01, 0xa0, 0x11, 0x72, 0x34, 0x03, 0x38, 0x06, 0x2f, 0xac, 0xe1, 0x3a, 
	0x01, 0x6f, 0x72, 0x20, 0x6e, 0x65, 0x77, 0x20, 0x94, 0x24, 0x73, 0x0a, 0xd4, 0x04, 0x52, 0xcd, 
	0x8f, 0x03, 0xff, 0x03, 0x20, 0x1b, 0x98, 0x69, 0x88, 0x0f, 0x61, 0x2c, 0x38, 0x00, 0x2e, 0x20, 
	0x53, 0x75, 0x10, 0x2c, 0x68, 0x02, 0x0a, 0x6d, 0x02, 0x20, 0x4a, 0x36, 0x31, 0x8d, 0x69, 0x6d, 
	0x0c, 0x0e, 0x60, 0x30, 0x69, 0x6c, 0x68, 0xab, 0xa0, 0x19, 0x73, 0x70, 0x69, 0x72, 0x69, 0x59, 
	0x86, 0x98, 0x1b, 0x65, 0x20, 0x70, 0x72, 0x65, 0x73, 0x65, 0x6e, 0x74, 0xfd, 0x03, 0x83, 0x32, 
	0x58, 0x05, 0x0a, 0x64, 0x69, 0x66, 0x66, 0x40, 0x1a, 0x80, 0x01, 0x64, 0x65, 0xd0, 0x04, 0xbe, 
	0x08, 0x74, 0x61, 0x69, 0x6c, 0xf1, 0x2d, 0x61, 0x64, 0x64, 0x70, 0x01, 0x73, 0x82, 0x05, 0x90, 
	0x23, 0x48, 0x36, 0x41, 0x4c, 0x20, 0x78, 0x6f, 0x6e, 0x63, 0x65, 0x72, 0x6e, 0x53, 0x1f, 0x45, 
	0x61, 0x20, 0x04, 0x04, 0x04, 0x20, 0x48, 0x0e, 0x67, 0x69, 0x76, 0x65, 0x84, 0x32, 0x30, 0x84, 
	0x61, 0x4b, 0x64, 0x69, 0x73, 0x74, 0x58, 0x0c, 0x75, 0x69, 0x73, 0x68, 0x91, 0x0c, 0x0d, 0x01, 
	0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x12, 0x27, 0xc9, 0x0d, 0x4c, 0x69, 0xf4, 0x55, 0x73, 0xea, 
	0x26, 0x72, 0x65, 0x63, 0x65, 0xf8, 0x01, 0x64, 0x20, 0x18, 0xa8, 0x87, 0x0c, 0x69, 0x74, 0x20, 
	0x73, 0x84, 0x46, 0x79, 0x92, 0x61, 0x74, 0xa9, 0x9b, 0x65, 0x72, 0x74, 0x61, 0x00, 0x05, 0x13, 
	0x02, 0x10, 0x15, 0x9c, 0x02, 0x0a, 0x1f, 0x0a, 0x10, 0x22, 0xa1, 0xaf, 0x6e, 0x79, 0x20, 0x6c, 
	0x61, 0x74, 0x58, 0x07, 0xf4, 0x01, 0x22, 0x0a, 0x61, 0x00, 0x3c, 0x2e, 0x0b, 0x70, 0x70, 0x6c, 
	0x69, 0x39, 0x21, 0x6f, 0xb8, 0x03, 0x33, 0x2b, 0x68, 0x61, 0xa8, 0x16, 0x74, 0x89, 0x84, 0x6b, 
	0x30, 0x10, 0x03, 0x66, 0x6f, 0x6c, 0x8b, 0x1d, 0x42, 0x0a, 0x00, 0x02, 0x60, 0x08, 0x61, 0x6e, 
	0x64, 0x0a, 0x63, 0x6f, 0x6e, 0x64, 0x69, 0x74, 0x13, 0xfc, 0xda, 0x27, 0x69, 0x6f, 0x30, 0x8c, 
	0x65, 0x69, 0x6a, 0x24, 0x7a, 0x04, 0x90, 0x05, 0xfc, 0x0f, 0x4f, 0x05, 0x60, 0x20, 0xf8, 0x03, 
	0xe0, 0x00, 0x61, 0x17, 0x04, 0x0a, 0x4f, 0x01, 0xe0, 0x04, 0xbd, 0xbf, 0x12, 0xc5, 0x09, 0xbe, 
	0x43, 0xb8, 0x5e, 0x79, 0x6f, 0x75, 0x0a, 0x72, 0xc7, 0x09, 0x71, 0x64, 0x6f, 0x58, 0x06, 0x51, 
	0x27, 0xfc, 0xf2, 0xf0, 0x5a, 0x73, 0x0a, 0x0a, 0x79, 0xd0, 0x09, 0x54, 0x07, 0x20, 0xd3, 0x09, 
	0x20, 0x87, 0x09, 0x0f, 0xcd, 0xfd, 0x5b, 0x08, 0x51, 0x16, 0x63, 0x68, 0x6f, 0x6f, 0x68, 0x34, 
	0xc9, 0x05, 0x5d, 0x02, 0x27, 0x02, 0x0f, 0x20, 0x65, 0x88, 0x01, 0x20, 0x0f, 0x07, 0xff, 0x11, 
	0xc9, 0x32, 0x00, 0x38, 0xe3, 0x58, 0xef, 0x10, 0x11, 0x00, 0x15, 0x78, 0x79, 0x21, 0x73, 0x43, 
	0x2c, 0x20, 0x63, 0x68, 0x91, 0x64, 0x40, 0x58, 0xe8, 0xbb, 0x77, 0x68, 0x65, 0x6a, 0x0c, 0x66, 
	0x75, 0x74, 0x75, 0x78, 0x21, 0xb4, 0x05, 0x73, 0xe7, 0x07, 0xe8, 0xa7, 0xdf, 0x30, 0x57, 0x6c, 
	0x6c, 0xe2, 0x10, 0x10, 0xaa, 0x74, 0x68, 0x81, 0x0e, 0x72, 0x6f, 0x78, 0x79, 0x80, 0x52, 0x01, 
	0x38, 0x40, 0x84, 0x62, 0x06, 0x63, 0x20, 0x73, 0x74, 0x38, 0x12, 0x6d, 0x65, 0x6e, 0x52, 0x26, 
	0x61, 0x63, 0x63, 0x65, 0x70, 0x74, 0x61, 0x6e, 0x78, 0x37, 0x14, 0x0f, 0x8c, 0x03, 0x20, 0x69, 
	0x73, 0x0a, 0x70, 0x65, 0x72, 0x6d, 0x61, 0x6e, 0x9a, 0xa1, 0x00, 0x00, 0xf0, 0x00, 0x75, 0x74, 
	0x68, 0x6f, 0x72, 0x69, 0x7a, 0x61, 0x89, 0x11, 0x82, 0x59, 0xb9, 0x43, 0xd9, 0xe7, 0x68, 0x6f, 
	0x6f, 0x73, 0x65, 0x20, 0x74, 0x68, 0x61, 0x74, 0x20, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 
	0x20, 0x66, 0xff, 0x7f, 0x00, 0x00, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x0a, 0x4c, 0x69, 0x62, 
	0x72, 0x61, 0x72, 0x79, 0x2e, 0x0a, 0x0a };

/* Tests the libfwnt_lznt1_decompress function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_lznt1_decompress(
     void )
{
	uint8_t uncompressed_data[ 8192 ];

	libcerror_error_t *error      = NULL;
	size_t uncompressed_data_size = 7640;
	int result                    = 0;

	result = libfwnt_lznt1_decompress(
	          fwnt_test_lznt1_compressed_byte_stream,
	          4135,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	FWNT_TEST_FPRINT_ERROR( error )

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_EQUAL_SIZE(
	 "uncompressed_data_size",
	 uncompressed_data_size,
	 (size_t) 7640 );

	/* Test error cases
	 */
	result = libfwnt_lznt1_decompress(
	          NULL,
	          4135,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwnt_lznt1_decompress(
	          fwnt_test_lznt1_compressed_byte_stream,
	          (size_t) SSIZE_MAX + 1,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwnt_lznt1_decompress(
	          fwnt_test_lznt1_compressed_byte_stream,
	          4135,
	          NULL,
	          &uncompressed_data_size,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwnt_lznt1_decompress(
	          fwnt_test_lznt1_compressed_byte_stream,
	          4135,
	          uncompressed_data,
	          NULL,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWNT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWNT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( HAVE_DEBUG_OUTPUT ) && defined( FWNT_TEST_LZNT1 )
	libcnotify_verbose_set(
	 1 );
	libcnotify_stream_set(
	 stderr,
	 NULL );
#endif

	/* TODO add tests for libfwnt_lznt1_compress */

	FWNT_TEST_RUN(
	 "libfwnt_lznt1_decompress",
	 fwnt_test_lznt1_decompress );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

