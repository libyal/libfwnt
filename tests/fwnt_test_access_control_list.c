/*
 * Library access_control_list type test program
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

#include "../libfwnt/libfwnt_access_control_list.h"

uint8_t fwnt_test_access_control_list_data1[ 52 ] = {
	0x02, 0x00, 0x34, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x9f, 0x01, 0x12, 0x00,
	0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00,
	0x9f, 0x01, 0x12, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x20, 0x00, 0x00, 0x00,
	0x20, 0x02, 0x00, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

/* Tests the libfwnt_access_control_list_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_list_initialize(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_access_control_list_t *access_control_list = NULL;
	int result                                         = 0;

#if defined( HAVE_FWNT_TEST_MEMORY )
	int number_of_malloc_fail_tests                    = 1;
	int number_of_memset_fail_tests                    = 1;
	int test_number                                    = 0;
#endif

	/* Test regular cases
	 */
	result = libfwnt_access_control_list_initialize(
	          &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "access_control_list",
	 access_control_list );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_internal_access_control_list_free(
	          (libfwnt_internal_access_control_list_t **) &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "access_control_list",
	 access_control_list );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_access_control_list_initialize(
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

	access_control_list = (libfwnt_access_control_list_t *) 0x12345678UL;

	result = libfwnt_access_control_list_initialize(
	          &access_control_list,
	          &error );

	access_control_list = NULL;

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
		/* Test libfwnt_access_control_list_initialize with malloc failing
		 */
		fwnt_test_malloc_attempts_before_fail = test_number;

		result = libfwnt_access_control_list_initialize(
		          &access_control_list,
		          &error );

		if( fwnt_test_malloc_attempts_before_fail != -1 )
		{
			fwnt_test_malloc_attempts_before_fail = -1;

			if( access_control_list != NULL )
			{
				libfwnt_internal_access_control_list_free(
				 (libfwnt_internal_access_control_list_t **) &access_control_list,
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
			 "access_control_list",
			 access_control_list );

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
		/* Test libfwnt_access_control_list_initialize with memset failing
		 */
		fwnt_test_memset_attempts_before_fail = test_number;

		result = libfwnt_access_control_list_initialize(
		          &access_control_list,
		          &error );

		if( fwnt_test_memset_attempts_before_fail != -1 )
		{
			fwnt_test_memset_attempts_before_fail = -1;

			if( access_control_list != NULL )
			{
				libfwnt_internal_access_control_list_free(
				 (libfwnt_internal_access_control_list_t **) &access_control_list,
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
			 "access_control_list",
			 access_control_list );

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
	if( access_control_list != NULL )
	{
		libfwnt_internal_access_control_list_free(
		 (libfwnt_internal_access_control_list_t **) &access_control_list,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

/* Tests the libfwnt_access_control_list_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_list_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_access_control_list_free(
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

/* Tests the libfwnt_internal_access_control_list_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_internal_access_control_list_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_internal_access_control_list_free(
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

/* Tests the libfwnt_access_control_list_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_list_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error                           = NULL;
	libfwnt_access_control_list_t *access_control_list = NULL;
	int result                                         = 0;

	/* Initialize test
	 */
	result = libfwnt_access_control_list_initialize(
	          &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "access_control_list",
	 access_control_list );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to copy security descriptor from byte stream
	 */
	result = libfwnt_access_control_list_copy_from_byte_stream(
	          access_control_list,
	          fwnt_test_access_control_list_data1,
	          52,
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
	result = libfwnt_access_control_list_copy_from_byte_stream(
	          NULL,
	          fwnt_test_access_control_list_data1,
	          52,
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

	result = libfwnt_access_control_list_copy_from_byte_stream(
	          access_control_list,
	          NULL,
	          52,
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

	result = libfwnt_access_control_list_copy_from_byte_stream(
	          access_control_list,
	          fwnt_test_access_control_list_data1,
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

	result = libfwnt_access_control_list_copy_from_byte_stream(
	          access_control_list,
	          fwnt_test_access_control_list_data1,
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

	result = libfwnt_access_control_list_copy_from_byte_stream(
	          access_control_list,
	          fwnt_test_access_control_list_data1,
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

	result = libfwnt_access_control_list_copy_from_byte_stream(
	          access_control_list,
	          fwnt_test_access_control_list_data1,
	          52,
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
	result = libfwnt_internal_access_control_list_free(
	          (libfwnt_internal_access_control_list_t **) &access_control_list,
	          NULL );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "access_control_list",
	 access_control_list );

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
	if( access_control_list != NULL )
	{
		libfwnt_internal_access_control_list_free(
		 (libfwnt_internal_access_control_list_t **) &access_control_list,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_access_control_list_get_number_of_entries function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_list_get_number_of_entries(
     libfwnt_access_control_list_t *access_control_list )
{
	libcerror_error_t *error = NULL;
	int number_of_entries    = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwnt_access_control_list_get_number_of_entries(
	          access_control_list,
	          &number_of_entries,
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
	result = libfwnt_access_control_list_get_number_of_entries(
	          NULL,
	          &number_of_entries,
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

	result = libfwnt_access_control_list_get_number_of_entries(
	          access_control_list,
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

/* Tests the libfwnt_access_control_list_get_entry_by_index function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_access_control_list_get_entry_by_index(
     libfwnt_access_control_list_t *access_control_list )
{
	libcerror_error_t *error                             = NULL;
	libfwnt_access_control_entry_t *access_control_entry = NULL;
	int result                                           = 0;

	/* Test regular cases
	 */
	result = libfwnt_access_control_list_get_entry_by_index(
	          access_control_list,
	          0,
	          &access_control_entry,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "access_control_entry",
	 access_control_entry );

	result = libfwnt_access_control_entry_free(
	          &access_control_entry,
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
	result = libfwnt_access_control_list_get_entry_by_index(
	          NULL,
	          0,
	          &access_control_entry,
	          &error );

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

	result = libfwnt_access_control_list_get_entry_by_index(
	          access_control_list,
	          -1,
	          &access_control_entry,
	          &error );

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

	result = libfwnt_access_control_list_get_entry_by_index(
	          access_control_list,
	          0,
	          NULL,
	          &error );

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( access_control_entry != NULL )
	{
		libfwnt_access_control_entry_free(
		 &access_control_entry,
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

	libcerror_error_t *error                           = NULL;
	libfwnt_access_control_list_t *access_control_list = NULL;
	int result                                         = 0;

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	FWNT_TEST_RUN(
	 "libfwnt_access_control_list_initialize",
	 fwnt_test_access_control_list_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	FWNT_TEST_RUN(
	 "libfwnt_access_control_list_free",
	 fwnt_test_access_control_list_free );

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	FWNT_TEST_RUN(
	 "libfwnt_internal_access_control_list_free",
	 fwnt_test_internal_access_control_list_free );

	FWNT_TEST_RUN(
	 "libfwnt_access_control_list_copy_from_byte_stream",
	 fwnt_test_access_control_list_copy_from_byte_stream );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize access_control_list for tests
	 */
	result = libfwnt_access_control_list_initialize(
	          &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "access_control_list",
	 access_control_list );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_access_control_list_copy_from_byte_stream(
	          access_control_list,
	          fwnt_test_access_control_list_data1,
	          52,
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
	 "libfwnt_access_control_list_get_number_of_entries",
	 fwnt_test_access_control_list_get_number_of_entries,
	 access_control_list );

	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_access_control_list_get_entry_by_index",
	 fwnt_test_access_control_list_get_entry_by_index,
	 access_control_list );

	/* Clean up
	 */
	result = libfwnt_internal_access_control_list_free(
	          (libfwnt_internal_access_control_list_t **) &access_control_list,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "access_control_list",
	 access_control_list );

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
	if( access_control_list != NULL )
	{
		libfwnt_internal_access_control_list_free(
		 (libfwnt_internal_access_control_list_t **) &access_control_list,
		 NULL );
	}
#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	return( EXIT_FAILURE );
}

