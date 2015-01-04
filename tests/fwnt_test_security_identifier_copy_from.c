/*
 * Windows NT format library security identifier (SID) copy from testing program
 *
 * Copyright (c) 2009-2012, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <stdio.h>

#include "fwnt_test_libcerror.h"
#include "fwnt_test_libcstring.h"
#include "fwnt_test_libfwnt.h"

/* Tests copying a SID from a byte stream
 * Returns 1 if successful, 0 if not or -1 on error
 */
int fwnt_test_security_identifier_copy_from_byte_stream(
     libfwnt_security_identifier_t *sid,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     uint8_t byte_order,
     int expected_result )
{
	libcerror_error_t *error      = NULL;
	const char *byte_order_string = "unknown";
	int result                    = 0;

	if( byte_order == LIBFWNT_ENDIAN_BIG )
	{
		byte_order_string = "big-endian";
	}
	else if( byte_order == LIBFWNT_ENDIAN_LITTLE )
	{
		byte_order_string = "little-endian";
	}
        fprintf(
         stdout,
         "Testing copying security identifier from byte stream: 0x%08" PRIjx " of size: %" PRIzd " and byte order: %s\t",
         (intptr_t) byte_stream,
         byte_stream_size,
         byte_order_string );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          sid,
	          byte_stream,
	          byte_stream_size,
	          byte_order,
	          &error );

	if( result == expected_result )
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == -1 )
	{
		if( expected_result != -1 )
		{
			libcerror_error_backtrace_fprint(
			 error,
			 stderr );
		}
		libcerror_error_free(
		 &error );
	}
	if( result == expected_result )
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return( result );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] )
#else
int main( int argc, char * const argv[] )
#endif
{
	uint8_t byte_stream[ 28 ] = {
		0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x15, 0x00, 0x00, 0x00, 0xc7, 0x99, 0x2e, 0x25,
		0x7c, 0x57, 0x85, 0xc0, 0x94, 0x5a, 0xce, 0x01, 0xf5, 0x03, 0x00, 0x00 };

	libcerror_error_t *error           = NULL;
	libfwnt_security_identifier_t *sid = NULL;

	if( argc != 1 )
	{
		fprintf(
		 stderr,
		 "This program does not take arguments.\n" );

		return( EXIT_FAILURE );
	}
	if( libfwnt_security_identifier_initialize(
	     &sid,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to create SID.\n" );

		goto on_error;
	}
	/* Case 1: byte stream is NULL, byte stream size is 28 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fwnt_test_security_identifier_copy_from_byte_stream(
	     sid,
	     NULL,
	     28,
	     LIBFWNT_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to SID.\n" );

		goto on_error;
	}
	/* Case 2: byte stream is a buffer, byte stream size is 28 and byte order is big-endian
	 * Expected result: -1
	 */
	if( fwnt_test_security_identifier_copy_from_byte_stream(
	     sid,
	     byte_stream,
	     28,
	     LIBFWNT_ENDIAN_BIG,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to SID.\n" );

		goto on_error;
	}
	/* Case 3: byte stream is a buffer, byte stream size is 28 and byte order is little-endian
	 * Expected result: 1
	 */
	if( fwnt_test_security_identifier_copy_from_byte_stream(
	     sid,
	     byte_stream,
	     28,
	     LIBFWNT_ENDIAN_LITTLE,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to SID.\n" );

		goto on_error;
	}
	/* Case 4: byte stream is a buffer, byte stream size is 28 and byte order is 'X'
	 * Expected result: -1
	 */
	if( fwnt_test_security_identifier_copy_from_byte_stream(
	     sid,
	     byte_stream,
	     28,
	     (uint8_t) 'X',
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to SID.\n" );

		goto on_error;
	}
	/* Case 5: byte stream is a buffer, byte stream size is 8 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fwnt_test_security_identifier_copy_from_byte_stream(
	     sid,
	     byte_stream,
	     8,
	     LIBFWNT_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to SID.\n" );

		goto on_error;
	}
	/* Case 6: byte stream is a buffer, byte stream size is 0 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fwnt_test_security_identifier_copy_from_byte_stream(
	     sid,
	     byte_stream,
	     0,
	     LIBFWNT_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to SID.\n" );

		goto on_error;
	}
	/* Case 7: byte stream is a buffer, byte stream size is -1 and byte order is little-endian
	 * Expected result: -1
	 */
	if( fwnt_test_security_identifier_copy_from_byte_stream(
	     sid,
	     byte_stream,
	     (size_t) -1,
	     LIBFWNT_ENDIAN_LITTLE,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy byte stream to SID.\n" );

		goto on_error;
	}
	if( libfwnt_security_identifier_free(
	     &sid,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to free SID.\n" );

		goto on_error;
	}
	return( EXIT_SUCCESS );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stderr );
		libcerror_error_free(
		 &error );
	}
	if( sid != NULL )
	{
		libfwnt_security_identifier_free(
		 &sid,
		 NULL );
	}
	return( EXIT_FAILURE );
}

