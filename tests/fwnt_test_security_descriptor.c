/*
 * Library security_descriptor type testing program
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
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
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwnt_test_libcerror.h"
#include "fwnt_test_libcstring.h"
#include "fwnt_test_libfwnt.h"
#include "fwnt_test_macros.h"
#include "fwnt_test_memory.h"
#include "fwnt_test_unused.h"

/* Tests the libfwnt_security_descriptor_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_initialize(
     void )
{
	libcerror_error_t *error = NULL;
	libfwnt_security_descriptor_t *security_descriptor      = NULL;
	int result               = 0;

	/* Test libfwnt_security_descriptor_initialize
	 */
	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NOT_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwnt_security_descriptor_free(
	          &security_descriptor,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWNT_TEST_ASSERT_IS_NULL(
         "security_descriptor",
         security_descriptor );

        FWNT_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_initialize(
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

	security_descriptor = (libfwnt_security_descriptor_t *) 0x12345678UL;

	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
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

	security_descriptor = NULL;

#if defined( HAVE_FWNT_TEST_MEMORY )

	/* Test libfwnt_security_descriptor_initialize with malloc failing
	 */
	fwnt_test_malloc_attempts_before_fail = 0;

	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	if( fwnt_test_malloc_attempts_before_fail != -1 )
	{
		fwnt_test_malloc_attempts_before_fail = -1;

		if( security_descriptor != NULL )
		{
			libfwnt_security_descriptor_free(
			 &security_descriptor,
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
		 "security_descriptor",
		 security_descriptor );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfwnt_security_descriptor_initialize with memset failing
	 */
	fwnt_test_memset_attempts_before_fail = 0;

	result = libfwnt_security_descriptor_initialize(
	          &security_descriptor,
	          &error );

	if( fwnt_test_memset_attempts_before_fail != -1 )
	{
		fwnt_test_memset_attempts_before_fail = -1;

		if( security_descriptor != NULL )
		{
			libfwnt_security_descriptor_free(
			 &security_descriptor,
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
		 "security_descriptor",
		 security_descriptor );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FWNT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( security_descriptor != NULL )
	{
		libfwnt_security_descriptor_free(
		 &security_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_security_descriptor_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_security_descriptor_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_security_descriptor_free(
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

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
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

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_initialize",
	 fwnt_test_security_descriptor_initialize );

	FWNT_TEST_RUN(
	 "libfwnt_security_descriptor_free",
	 fwnt_test_security_descriptor_free );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

