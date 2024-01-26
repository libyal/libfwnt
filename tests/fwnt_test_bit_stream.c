/*
 * Library bit_stream type test program
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
#include "fwnt_test_libcnotify.h"
#include "fwnt_test_libfwnt.h"
#include "fwnt_test_macros.h"
#include "fwnt_test_memory.h"
#include "fwnt_test_unused.h"

#include "../libfwnt/libfwnt_bit_stream.h"

/* Define to make fwnt_test_bit_stream generate verbose output
#define FWNT_TEST_BIT_STREAM_VERBOSE
 */

uint8_t fwnt_test_bit_stream_data1[ 16 ] = {
	0x78, 0xda, 0xbd, 0x59, 0x6d, 0x8f, 0xdb, 0xb8, 0x11, 0xfe, 0x7c, 0xfa, 0x15, 0xc4, 0x7e, 0xb9 };

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

/* Tests the libfwnt_bit_stream_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_bit_stream_initialize(
     void )
{
	libcerror_error_t *error         = NULL;
	libfwnt_bit_stream_t *bit_stream = NULL;
	int result                       = 0;

	/* Test libfwnt_bit_stream_initialize
	 */
	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          fwnt_test_bit_stream_data1,
	          16,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "bit_stream",
	 bit_stream );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_bit_stream_free(
	          &bit_stream,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "bit_stream",
	 bit_stream );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_bit_stream_initialize(
	          NULL,
	          fwnt_test_bit_stream_data1,
	          16,
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

	bit_stream = (libfwnt_bit_stream_t *) 0x12345678UL;

	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          fwnt_test_bit_stream_data1,
	          16,
	          &error );

	bit_stream = NULL;

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          NULL,
	          16,
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

	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          fwnt_test_bit_stream_data1,
	          (size_t) SSIZE_MAX + 1,
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

#if defined( HAVE_FWNT_TEST_MEMORY )

	/* Test libfwnt_bit_stream_initialize with malloc failing
	 */
	fwnt_test_malloc_attempts_before_fail = 0;

	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          fwnt_test_bit_stream_data1,
	          16,
	          &error );

	if( fwnt_test_malloc_attempts_before_fail != -1 )
	{
		fwnt_test_malloc_attempts_before_fail = -1;

		if( bit_stream != NULL )
		{
			libfwnt_bit_stream_free(
			 &bit_stream,
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
		 "bit_stream",
		 bit_stream );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfwnt_bit_stream_initialize with memset failing
	 */
	fwnt_test_memset_attempts_before_fail = 0;

	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          fwnt_test_bit_stream_data1,
	          16,
	          &error );

	if( fwnt_test_memset_attempts_before_fail != -1 )
	{
		fwnt_test_memset_attempts_before_fail = -1;

		if( bit_stream != NULL )
		{
			libfwnt_bit_stream_free(
			 &bit_stream,
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
		 "bit_stream",
		 bit_stream );

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
	if( bit_stream != NULL )
	{
		libfwnt_bit_stream_free(
		 &bit_stream,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_bit_stream_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_bit_stream_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_bit_stream_free(
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

/* Tests the libfwnt_bit_stream_read function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_bit_stream_read(
     void )
{
	libcerror_error_t *error         = NULL;
	libfwnt_bit_stream_t *bit_stream = NULL;
	int result                       = 0;

	/* Initialize test
	 */
	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          fwnt_test_bit_stream_data1,
	          16,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwnt_bit_stream_read(
	          bit_stream,
	          16,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWNT_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 2 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x0000da78UL );

	FWNT_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 16 );

	/* Test error cases
	 */
	result = libfwnt_bit_stream_read(
	          NULL,
	          32,
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

	result = libfwnt_bit_stream_read(
	          bit_stream,
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

	result = libfwnt_bit_stream_read(
	          bit_stream,
	          64,
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
	result = libfwnt_bit_stream_free(
	          &bit_stream,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( bit_stream != NULL )
	{
		libfwnt_bit_stream_free(
		 &bit_stream,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_bit_stream_get_value function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_bit_stream_get_value(
     libfwnt_bit_stream_t *bit_stream )
{
	libcerror_error_t *error = NULL;
	uint32_t value_32bit     = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwnt_bit_stream_get_value(
	          bit_stream,
	          0,
	          &value_32bit,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x00000000UL );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWNT_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 0 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000000UL );

	FWNT_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 0 );

	result = libfwnt_bit_stream_get_value(
	          bit_stream,
	          4,
	          &value_32bit,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x0000000dUL );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWNT_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 2 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000a78UL );

	FWNT_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 12 );

	result = libfwnt_bit_stream_get_value(
	          bit_stream,
	          12,
	          &value_32bit,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x00000a78UL );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWNT_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 2 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000000UL );

	FWNT_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 0 );

	result = libfwnt_bit_stream_get_value(
	          bit_stream,
	          32,
	          &value_32bit,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "value_32bit",
	 value_32bit,
	 (uint32_t) 0x59bd8f6dUL );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWNT_TEST_ASSERT_EQUAL_SIZE(
	 "bit_stream->byte_stream_offset",
	 bit_stream->byte_stream_offset,
	 (size_t) 6 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "bit_stream->bit_buffer",
	 bit_stream->bit_buffer,
	 (uint32_t) 0x00000000UL );

	FWNT_TEST_ASSERT_EQUAL_UINT8(
	 "bit_stream->bit_buffer_size",
	 bit_stream->bit_buffer_size,
	 (uint8_t) 0 );

	/* Test error cases
	 */
	result = libfwnt_bit_stream_get_value(
	          NULL,
	          32,
	          &value_32bit,
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

	result = libfwnt_bit_stream_get_value(
	          bit_stream,
	          64,
	          &value_32bit,
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

	result = libfwnt_bit_stream_get_value(
	          bit_stream,
	          32,
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

	libcerror_error_t *error         = NULL;
	libfwnt_bit_stream_t *bit_stream = NULL;
	int result                       = 0;

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( HAVE_DEBUG_OUTPUT ) && defined( FWNT_TEST_BIT_STREAM_VERBOSE )
	libcnotify_verbose_set(
	 1 );
	libcnotify_stream_set(
	 stderr,
	 NULL );
#endif

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	FWNT_TEST_RUN(
	 "libfwnt_bit_stream_initialize",
	 fwnt_test_bit_stream_initialize );

	FWNT_TEST_RUN(
	 "libfwnt_bit_stream_free",
	 fwnt_test_bit_stream_free );

	FWNT_TEST_RUN(
	 "libfwnt_bit_stream_read",
	 fwnt_test_bit_stream_read );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize bit_stream for tests
	 */
	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          fwnt_test_bit_stream_data1,
	          16,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "bit_stream",
	 bit_stream );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Run tests
	 */
	FWNT_TEST_RUN_WITH_ARGS(
	 "libfwnt_bit_stream_get_value",
	 fwnt_test_bit_stream_get_value,
	 bit_stream );

	/* Clean up
	 */
	result = libfwnt_bit_stream_free(
	          &bit_stream,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "bit_stream",
	 bit_stream );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */
#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )
on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( bit_stream != NULL )
	{
		libfwnt_bit_stream_free(
		 &bit_stream,
		 NULL );
	}
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */
}

