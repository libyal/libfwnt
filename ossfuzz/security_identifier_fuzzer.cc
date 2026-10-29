/*
 * OSS-Fuzz target for libfwnt security identifier type
 *
 * Copyright (C) 2009-2026, Joachim Metz <joachim.metz@gmail.com>
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

#include <stddef.h>
#include <stdint.h>

/* Note that some of the OSS-Fuzz engines use C++
 */
extern "C" {

#include "ossfuzz_libfwnt.h"

int LLVMFuzzerTestOneInput(
     const uint8_t *data,
     size_t size )
{
	uint8_t utf8_string[ 128 ];
	uint16_t utf16_string[ 128 ];
	uint32_t utf32_string[ 128 ];

	libfwnt_security_identifier_t *security_identifier = NULL;
	size_t string_size                                 = 0;
	size_t utf8_string_index                           = 0;
	size_t utf16_string_index                          = 0;
	size_t utf32_string_index                          = 0;

	if( libfwnt_security_identifier_initialize(
	     &security_identifier,
	     NULL ) != 1 )
	{
		return( 0 );
	}
	libfwnt_security_identifier_copy_from_byte_stream(
	 security_identifier,
	 data,
	 size,
	 LIBFWNT_ENDIAN_BIG,
	 NULL );

	libfwnt_security_identifier_copy_from_byte_stream(
	 security_identifier,
	 data,
	 size,
	 LIBFWNT_ENDIAN_LITTLE,
	 NULL );

	libfwnt_security_identifier_get_string_size(
	 security_identifier,
	 &string_size,
	 0,
	 NULL );

	libfwnt_security_identifier_copy_to_utf8_string(
	 security_identifier,
	 utf8_string,
	 128,
	 0,
	 NULL );

	libfwnt_security_identifier_copy_to_utf8_string_with_index(
	 security_identifier,
	 utf8_string,
	 128,
	 &utf8_string_index,
	 0,
	 NULL );

	libfwnt_security_identifier_copy_to_utf16_string(
	 security_identifier,
	 utf16_string,
	 128,
	 0,
	 NULL );

	libfwnt_security_identifier_copy_to_utf16_string_with_index(
	 security_identifier,
	 utf16_string,
	 128,
	 &utf16_string_index,
	 0,
	 NULL );

	libfwnt_security_identifier_copy_to_utf32_string(
	 security_identifier,
	 utf32_string,
	 128,
	 0,
	 NULL );

	libfwnt_security_identifier_copy_to_utf32_string_with_index(
	 security_identifier,
	 utf32_string,
	 128,
	 &utf32_string_index,
	 0,
	 NULL );

	libfwnt_security_identifier_free(
	 &security_identifier,
	 NULL );

	return( 0 );
}

} /* extern "C" */
