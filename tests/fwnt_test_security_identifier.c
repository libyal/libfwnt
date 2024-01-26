/*
 * Library security_identifier type test program
 *
 * Copyright (C) 2009-2024, Joachim Metz <joachim.metz@gmail.com>
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
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwnt_test_libcerror.h"
#include "fwnt_test_libfwnt.h"
#include "fwnt_test_macros.h"
#include "fwnt_test_memory.h"
#include "fwnt_test_unused.h"

#include "../libfwnt/libfwnt_security_identifier.h"

uint8_t fwnt_test_security_identifier_data1[ 28 ] = {
	0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x15, 0x00, 0x00, 0x00, 0xc7, 0x99, 0x2e, 0x25,
	0x7c, 0x57, 0x85, 0xc0, 0x94, 0x5a, 0xce, 0x01, 0xf5, 0x03, 0x00, 0x00 };

/* Tests the libfwnt_security_identifier_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_initialize(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	int result                                         = 0;

#if defined( HAVE_FWNT_TEST_MEMORY )
	int number_of_malloc_fail_tests                    = 1;
	int number_of_memset_fail_tests                    = 1;
	int test_number                                    = 0;
#endif

	/* Test regular cases
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "security_identifier",
	 security_identifier );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "security_identifier",
	 security_identifier );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_initialize(
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

	security_identifier = (libfwnt_security_identifier_t *) 0x12345678UL;

	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	security_identifier = NULL;

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FWNT_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwnt_security_identifier_initialize with malloc failing
		 */
		fwnt_test_malloc_attempts_before_fail = test_number;

		result = libfwnt_security_identifier_initialize(
		          &security_identifier,
		          &error );

		if( fwnt_test_malloc_attempts_before_fail != -1 )
		{
			fwnt_test_malloc_attempts_before_fail = -1;

			if( security_identifier != NULL )
			{
				libfwnt_security_identifier_free(
				 &security_identifier,
				 NULL );
			}
		}
		else
		{
			FWNT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWNT_TEST_ASSERT_IS_NULL(
			 "security_identifier",
			 security_identifier );

			FWNT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfwnt_security_identifier_initialize with memset failing
		 */
		fwnt_test_memset_attempts_before_fail = test_number;

		result = libfwnt_security_identifier_initialize(
		          &security_identifier,
		          &error );

		if( fwnt_test_memset_attempts_before_fail != -1 )
		{
			fwnt_test_memset_attempts_before_fail = -1;

			if( security_identifier != NULL )
			{
				libfwnt_security_identifier_free(
				 &security_identifier,
				 NULL );
			}
		}
		else
		{
			FWNT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWNT_TEST_ASSERT_IS_NULL(
			 "security_identifier",
			 security_identifier );

			FWNT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FWNT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_security_identifier_free(
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}
#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

/* Tests the libfwnt_internal_security_identifier_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_internal_security_identifier_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_internal_security_identifier_free(
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

/* Tests the libfwnt_security_identifier_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "security_identifier",
	 security_identifier );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to copy security identifier from byte stream
	 */
	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_data1,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_from_byte_stream(
	          NULL,
	          fwnt_test_security_identifier_data1,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
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

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          NULL,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
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

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_data1,
	          0,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_data1,
	          (size_t) SSIZE_MAX + 1,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_data1,
	          8,
	          LIBFWNT_ENDIAN_LITTLE,
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

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_data1,
	          28,
	          (uint8_t) 'X',
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

	/* Clean up
	 */
	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "security_identifier",
	 security_identifier );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_get_string_size function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_get_string_size(
     libfwnt_security_identifier_t *security_identifier )
{
	libcerror_error_t *error = NULL;
	size_t string_size       = 0;
	int result               = 0;

	/* Test retrieve string size
	 */
	result = libfwnt_security_identifier_get_string_size(
	          security_identifier,
	          &string_size,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_get_string_size(
	          NULL,
	          &string_size,
	          0,
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

	result = libfwnt_security_identifier_get_string_size(
	          security_identifier,
	          NULL,
	          0,
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

	result = libfwnt_security_identifier_get_string_size(
	          security_identifier,
	          &string_size,
	          0xffffffffUL,
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf8_string function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf8_string(
     libfwnt_security_identifier_t *security_identifier )
{
	uint8_t utf8_string[ 64 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test copy to UTF-8 string
	 */
	result = libfwnt_security_identifier_copy_to_utf8_string(
	          security_identifier,
	          utf8_string,
	          47,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf8_string(
	          NULL,
	          utf8_string,
	          47,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf8_string(
	          security_identifier,
	          NULL,
	          47,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf8_string(
	          security_identifier,
	          utf8_string,
	          18,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf8_string(
	          security_identifier,
	          utf8_string,
	          47,
	          0xffffffffUL,
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf8_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf8_string_with_index(
     libfwnt_security_identifier_t *security_identifier )
{
	uint8_t utf8_string[ 64 ];

	libcerror_error_t *error = NULL;
	size_t utf8_string_index = 0;
	int result               = 0;

	/* Test copy to UTF-8 string
	 */
	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          47,
	          &utf8_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          NULL,
	          utf8_string,
	          47,
	          &utf8_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          NULL,
	          47,
	          &utf8_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          18,
	          &utf8_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          47,
	          NULL,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf8_string_with_index(
	          security_identifier,
	          utf8_string,
	          47,
	          &utf8_string_index,
	          0xffffffffUL,
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf16_string function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf16_string(
     libfwnt_security_identifier_t *security_identifier )
{
	uint16_t utf16_string[ 64 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test copy to UTF-16 string
	 */
	result = libfwnt_security_identifier_copy_to_utf16_string(
	          security_identifier,
	          utf16_string,
	          47,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf16_string(
	          NULL,
	          utf16_string,
	          47,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf16_string(
	          security_identifier,
	          NULL,
	          47,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf16_string(
	          security_identifier,
	          utf16_string,
	          18,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf16_string(
	          security_identifier,
	          utf16_string,
	          47,
	          0xffffffffUL,
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf16_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf16_string_with_index(
     libfwnt_security_identifier_t *security_identifier )
{
	uint16_t utf16_string[ 64 ];

	libcerror_error_t *error  = NULL;
	size_t utf16_string_index = 0;
	int result                = 0;

	/* Test copy to UTF-16 string
	 */
	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          47,
	          &utf16_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          NULL,
	          utf16_string,
	          47,
	          &utf16_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          NULL,
	          47,
	          &utf16_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          18,
	          &utf16_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          47,
	          NULL,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf16_string_with_index(
	          security_identifier,
	          utf16_string,
	          47,
	          &utf16_string_index,
	          0xffffffffUL,
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf32_string function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf32_string(
     libfwnt_security_identifier_t *security_identifier )
{
	uint32_t utf32_string[ 64 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test copy to UTF-32 string
	 */
	result = libfwnt_security_identifier_copy_to_utf32_string(
	          security_identifier,
	          utf32_string,
	          47,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf32_string(
	          NULL,
	          utf32_string,
	          47,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf32_string(
	          security_identifier,
	          NULL,
	          47,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf32_string(
	          security_identifier,
	          utf32_string,
	          18,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf32_string(
	          security_identifier,
	          utf32_string,
	          47,
	          0xffffffffUL,
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_security_identifier_copy_to_utf32_string_with_index function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_identifier_copy_to_utf32_string_with_index(
     libfwnt_security_identifier_t *security_identifier )
{
	uint32_t utf32_string[ 64 ];

	libcerror_error_t *error  = NULL;
	size_t utf32_string_index = 0;
	int result                = 0;

	/* Test copy to UTF-32 string
	 */
	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          47,
	          &utf32_string_index,
	          0,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          NULL,
	          utf32_string,
	          47,
	          &utf32_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          NULL,
	          47,
	          &utf32_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          18,
	          &utf32_string_index,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          47,
	          NULL,
	          0,
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

	result = libfwnt_security_identifier_copy_to_utf32_string_with_index(
	          security_identifier,
	          utf32_string,
	          47,
	          &utf32_string_index,
	          0xffffffffUL,
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
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
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
	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	int result                                         = 0;

	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_initialize",
	 fwnt_test_security_identifier_initialize );

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_free",
	 fwnt_test_security_identifier_free );

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	FWNT_TEST_RUN(
	 "libfwnt_internal_security_identifier_free",
	 fwnt_test_internal_security_identifier_free );

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	FWNT_TEST_RUN(
	 "libfwnt_security_identifier_copy_from_byte_stream",
	 fwnt_test_security_identifier_copy_from_byte_stream );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize security_identifier for tests
	 */
	result = libfwnt_security_identifier_initialize(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "security_identifier",
	 security_identifier );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_security_identifier_copy_from_byte_stream(
	          security_identifier,
	          fwnt_test_security_identifier_data1,
	          28,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_security_identifier_get_string_size",
	 fwnt_test_security_identifier_get_string_size,
	 security_identifier );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_security_identifier_copy_to_utf8_string",
	 fwnt_test_security_identifier_copy_to_utf8_string,
	 security_identifier );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_security_identifier_copy_to_utf8_string_with_index",
	 fwnt_test_security_identifier_copy_to_utf8_string_with_index,
	 security_identifier );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_security_identifier_copy_to_utf16_string",
	 fwnt_test_security_identifier_copy_to_utf16_string,
	 security_identifier );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_security_identifier_copy_to_utf16_string_with_index",
	 fwnt_test_security_identifier_copy_to_utf16_string_with_index,
	 security_identifier );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_security_identifier_copy_to_utf32_string",
	 fwnt_test_security_identifier_copy_to_utf32_string,
	 security_identifier );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_security_identifier_copy_to_utf32_string_with_index",
	 fwnt_test_security_identifier_copy_to_utf32_string_with_index,
	 security_identifier );

	/* Clean up
	 */
	result = libfwnt_security_identifier_free(
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "security_identifier",
	 security_identifier );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( EXIT_FAILURE );
}

