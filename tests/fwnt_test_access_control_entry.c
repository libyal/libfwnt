/*
 * Library access_control_entry type test program
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

#include "../libfwnt/libfwnt_access_control_entry.h"

uint8_t fwnt_test_access_control_entry_data1[ 20 ] = {
	0x00, 0x00, 0x14, 0x00, 0x9f, 0x01, 0x12, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
	0x12, 0x00, 0x00, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

/* Tests the libfwnt_access_control_entry_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_entry_initialize(
     void )
{
	libcerror_error_t *error                             = NULL;
	libfwnt_access_control_entry_t *access_control_entry = NULL;
	int result                                           = 0;

#if defined( HAVE_FWNT_TEST_MEMORY )
	int number_of_malloc_fail_tests                      = 1;
	int number_of_memset_fail_tests                      = 1;
	int test_number                                      = 0;
#endif

	/* Test regular cases
	 */
	result = libfwnt_access_control_entry_initialize(
	          &access_control_entry,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "access_control_entry",
	 access_control_entry );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_internal_access_control_entry_free(
	          (libfwnt_internal_access_control_entry_t **) &access_control_entry,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "access_control_entry",
	 access_control_entry );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_access_control_entry_initialize(
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

	access_control_entry = (libfwnt_access_control_entry_t *) 0x12345678UL;

	result = libfwnt_access_control_entry_initialize(
	          &access_control_entry,
	          &error );

	access_control_entry = NULL;

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
		/* Test libfwnt_access_control_entry_initialize with malloc failing
		 */
		fwnt_test_malloc_attempts_before_fail = test_number;

		result = libfwnt_access_control_entry_initialize(
		          &access_control_entry,
		          &error );

		if( fwnt_test_malloc_attempts_before_fail != -1 )
		{
			fwnt_test_malloc_attempts_before_fail = -1;

			if( access_control_entry != NULL )
			{
				libfwnt_internal_access_control_entry_free(
				 (libfwnt_internal_access_control_entry_t **) &access_control_entry,
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
			 "access_control_entry",
			 access_control_entry );

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
		/* Test libfwnt_access_control_entry_initialize with memset failing
		 */
		fwnt_test_memset_attempts_before_fail = test_number;

		result = libfwnt_access_control_entry_initialize(
		          &access_control_entry,
		          &error );

		if( fwnt_test_memset_attempts_before_fail != -1 )
		{
			fwnt_test_memset_attempts_before_fail = -1;

			if( access_control_entry != NULL )
			{
				libfwnt_internal_access_control_entry_free(
				 (libfwnt_internal_access_control_entry_t **) &access_control_entry,
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
			 "access_control_entry",
			 access_control_entry );

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
	if( access_control_entry != NULL )
	{
		libfwnt_internal_access_control_entry_free(
		 (libfwnt_internal_access_control_entry_t **) &access_control_entry,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

/* Tests the libfwnt_access_control_entry_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_entry_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_access_control_entry_free(
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

/* Tests the libfwnt_internal_access_control_entry_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_internal_access_control_entry_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_internal_access_control_entry_free(
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

/* Tests the libfwnt_access_control_entry_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_entry_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error                             = NULL;
	libfwnt_access_control_entry_t *access_control_entry = NULL;
	int result                                           = 0;

	/* Initialize test
	 */
	result = libfwnt_access_control_entry_initialize(
	          &access_control_entry,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "access_control_entry",
	 access_control_entry );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to copy security descriptor from byte stream
	 */
	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          access_control_entry,
	          fwnt_test_access_control_entry_data1,
	          20,
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
	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          NULL,
	          fwnt_test_access_control_entry_data1,
	          20,
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

	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          access_control_entry,
	          NULL,
	          20,
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

	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          access_control_entry,
	          fwnt_test_access_control_entry_data1,
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

	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          access_control_entry,
	          fwnt_test_access_control_entry_data1,
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

	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          access_control_entry,
	          fwnt_test_access_control_entry_data1,
	          4,
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

	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          access_control_entry,
	          fwnt_test_access_control_entry_data1,
	          20,
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
	result = libfwnt_internal_access_control_entry_free(
	          (libfwnt_internal_access_control_entry_t **) &access_control_entry,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "access_control_entry",
	 access_control_entry );

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
	if( access_control_entry != NULL )
	{
		libfwnt_internal_access_control_entry_free(
		 (libfwnt_internal_access_control_entry_t **) &access_control_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_access_control_entry_get_type function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_entry_get_type(
     libfwnt_access_control_entry_t *access_control_entry )
{
	libcerror_error_t *error = NULL;
	uint8_t type             = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwnt_access_control_entry_get_type(
	          access_control_entry,
	          &type,
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
	result = libfwnt_access_control_entry_get_type(
	          NULL,
	          &type,
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

	result = libfwnt_access_control_entry_get_type(
	          access_control_entry,
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

/* Tests the libfwnt_access_control_entry_get_flags function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_entry_get_flags(
     libfwnt_access_control_entry_t *access_control_entry )
{
	libcerror_error_t *error = NULL;
	uint8_t flags            = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwnt_access_control_entry_get_flags(
	          access_control_entry,
	          &flags,
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
	result = libfwnt_access_control_entry_get_flags(
	          NULL,
	          &flags,
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

	result = libfwnt_access_control_entry_get_flags(
	          access_control_entry,
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

/* Tests the libfwnt_access_control_entry_get_access_mask function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_entry_get_access_mask(
     libfwnt_access_control_entry_t *access_control_entry )
{
	libcerror_error_t *error = NULL;
	uint32_t access_mask     = 0;
	int access_mask_is_set   = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwnt_access_control_entry_get_access_mask(
	          access_control_entry,
	          &access_mask,
	          &error );

	FWNT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	access_mask_is_set = result;

	/* Test error cases
	 */
	result = libfwnt_access_control_entry_get_access_mask(
	          NULL,
	          &access_mask,
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

	if( access_mask_is_set != 0 )
	{
		result = libfwnt_access_control_entry_get_access_mask(
		          access_control_entry,
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwnt_access_control_entry_get_security_identifier function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_entry_get_security_identifier(
     libfwnt_access_control_entry_t *access_control_entry )
{
	libcerror_error_t *error                                  = NULL;
	libfwnt_security_identifier_t *backup_security_identifier = 0;
	libfwnt_security_identifier_t *security_identifier        = 0;
	int result                                                = 0;
	int security_identifier_is_set                            = 0;

	/* Test regular cases
	 */
	result = libfwnt_access_control_entry_get_security_identifier(
	          access_control_entry,
	          &security_identifier,
	          &error );

	FWNT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	security_identifier_is_set = result;

	if( security_identifier_is_set != 0 )
	{
		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "security_identifier",
		 security_identifier );

		result = libfwnt_security_identifier_free(
		          &security_identifier,
		          &error );

		FWNT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		FWNT_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	backup_security_identifier = ( (libfwnt_internal_access_control_entry_t *) access_control_entry )->security_identifier;

	( (libfwnt_internal_access_control_entry_t *) access_control_entry )->security_identifier = NULL;

	result = libfwnt_access_control_entry_get_security_identifier(
	          access_control_entry,
	          &security_identifier,
	          &error );

	( (libfwnt_internal_access_control_entry_t *) access_control_entry )->security_identifier = backup_security_identifier;

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_access_control_entry_get_security_identifier(
	          NULL,
	          &security_identifier,
	          &error );

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

	if( security_identifier_is_set != 0 )
	{
		result = libfwnt_access_control_entry_get_security_identifier(
		          access_control_entry,
		          NULL,
		          &error );

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

		security_identifier = (libfwnt_security_identifier_t *) 0x12345678UL;

		result = libfwnt_access_control_entry_get_security_identifier(
		          access_control_entry,
		          &security_identifier,
		          &error );

		security_identifier = NULL;

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

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

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
#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	libcerror_error_t *error                             = NULL;
	libfwnt_access_control_entry_t *access_control_entry = NULL;
	int result                                           = 0;

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	FWNT_TEST_RUN(
	 "libfwnt_access_control_entry_initialize",
	 fwnt_test_access_control_entry_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	FWNT_TEST_RUN(
	 "libfwnt_access_control_entry_free",
	 fwnt_test_access_control_entry_free );

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	FWNT_TEST_RUN(
	 "libfwnt_internal_access_control_entry_free",
	 fwnt_test_internal_access_control_entry_free );

	FWNT_TEST_RUN(
	 "libfwnt_access_control_entry_copy_from_byte_stream",
	 fwnt_test_access_control_entry_copy_from_byte_stream );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize access_control_entry for tests
	 */
	result = libfwnt_access_control_entry_initialize(
	          &access_control_entry,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "access_control_entry",
	 access_control_entry );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_access_control_entry_copy_from_byte_stream(
	          access_control_entry,
	          fwnt_test_access_control_entry_data1,
	          20,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Run tests
	 */
	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_access_control_entry_get_type",
	 fwnt_test_access_control_entry_get_type,
	 access_control_entry );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_access_control_entry_get_flags",
	 fwnt_test_access_control_entry_get_flags,
	 access_control_entry );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_access_control_entry_get_access_mask",
	 fwnt_test_access_control_entry_get_access_mask,
	 access_control_entry );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_access_control_entry_get_security_identifier",
	 fwnt_test_access_control_entry_get_security_identifier,
	 access_control_entry );

	/* Clean up
	 */
	result = libfwnt_internal_access_control_entry_free(
	          (libfwnt_internal_access_control_entry_t **) &access_control_entry,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "access_control_entry",
	 access_control_entry );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */
#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( access_control_entry != NULL )
	{
		libfwnt_internal_access_control_entry_free(
		 (libfwnt_internal_access_control_entry_t **) &access_control_entry,
		 NULL );
	}
#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	return( EXIT_FAILURE );
}

