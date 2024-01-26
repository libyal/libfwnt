/*
 * Library huffman_tree type test program
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
#include "../libfwnt/libfwnt_huffman_tree.h"

/* Define to make fwnt_test_huffman_tree generate verbose output
#define FWNT_TEST_HUFFMAN_TREE_VERBOSE
 */

/* The sequence: abcdefghijklmnopqrstuvwxyz compressed in LZXpress-Huffman
 */
uint8_t fwnt_test_huffman_tree_data1[ 276 ] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x50, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x45, 0x44, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xd8, 0x52, 0x3e, 0xd7, 0x94, 0x11, 0x5b, 0xe9, 0x19, 0x5f, 0xf9, 0xd6, 0x7c, 0xdf, 0x8d, 0x04,
	0x00, 0x00, 0x00, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

/* Tests the libfwnt_huffman_tree_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_huffman_tree_initialize(
     void )
{
	libcerror_error_t *error             = NULL;
	libfwnt_huffman_tree_t *huffman_tree = NULL;
	int result                           = 0;

	/* Test libfwnt_huffman_tree_initialize
	 */
	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          512,
	          15,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "huffman_tree",
	 huffman_tree );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_huffman_tree_free(
	          &huffman_tree,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "huffman_tree",
	 huffman_tree );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwnt_huffman_tree_initialize(
	          NULL,
	          512,
	          15,
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

	huffman_tree = (libfwnt_huffman_tree_t *) 0x12345678UL;

	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          512,
	          15,
	          &error );

	huffman_tree = NULL;

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          9999,
	          15,
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

	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          512,
	          99,
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

	/* Test libfwnt_huffman_tree_initialize with malloc failing
	 */
	fwnt_test_malloc_attempts_before_fail = 0;

	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          512,
	          15,
	          &error );

	if( fwnt_test_malloc_attempts_before_fail != -1 )
	{
		fwnt_test_malloc_attempts_before_fail = -1;

		if( huffman_tree != NULL )
		{
			libfwnt_huffman_tree_free(
			 &huffman_tree,
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
		 "huffman_tree",
		 huffman_tree );

		FWNT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfwnt_huffman_tree_initialize with memset failing
	 */
	fwnt_test_memset_attempts_before_fail = 0;

	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          512,
	          15,
	          &error );

	if( fwnt_test_memset_attempts_before_fail != -1 )
	{
		fwnt_test_memset_attempts_before_fail = -1;

		if( huffman_tree != NULL )
		{
			libfwnt_huffman_tree_free(
			 &huffman_tree,
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
		 "huffman_tree",
		 huffman_tree );

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
	if( huffman_tree != NULL )
	{
		libfwnt_huffman_tree_free(
		 &huffman_tree,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_huffman_tree_free function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_huffman_tree_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwnt_huffman_tree_free(
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

/* Tests the libfwnt_huffman_tree_build function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_huffman_tree_build(
     void )
{
	uint8_t code_size_array[ 512 ];

	libcerror_error_t *error             = NULL;
	libfwnt_huffman_tree_t *huffman_tree = NULL;
	size_t byte_offset                   = 0;
	uint32_t symbol                      = 0;
	uint8_t byte_value                   = 0;
	int result                           = 0;

	/* Initialize test
	 */
	for( byte_offset = 0;
	     byte_offset < 256;
	     byte_offset++ )
	{
		byte_value = fwnt_test_huffman_tree_data1[ byte_offset ];

		code_size_array[ symbol++ ] = byte_value & 0x0f;

		byte_value >>= 4;

		code_size_array[ symbol++ ] = byte_value & 0x0f;
	}
	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          512,
	          15,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "huffman_tree",
	 huffman_tree );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwnt_huffman_tree_build(
	          huffman_tree,
	          code_size_array,
	          512,
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
	result = libfwnt_huffman_tree_build(
	          NULL,
	          code_size_array,
	          512,
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

	result = libfwnt_huffman_tree_build(
	          huffman_tree,
	          NULL,
	          512,
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

	result = libfwnt_huffman_tree_build(
	          huffman_tree,
	          code_size_array,
	          -1,
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

	/* Test libfwnt_huffman_tree_build with malloc failing
	 */
	fwnt_test_malloc_attempts_before_fail = 0;

	result = libfwnt_huffman_tree_build(
	          huffman_tree,
	          code_size_array,
	          512,
	          &error );

	if( fwnt_test_malloc_attempts_before_fail != -1 )
	{
		fwnt_test_malloc_attempts_before_fail = -1;
	}
	else
	{
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
#if defined( OPTIMIZATION_DISABLED )

	/* Test libfwnt_huffman_tree_build with memset failing
	 */
	fwnt_test_memset_attempts_before_fail = 0;

	result = libfwnt_huffman_tree_build(
	          huffman_tree,
	          code_size_array,
	          512,
	          &error );

	if( fwnt_test_memset_attempts_before_fail != -1 )
	{
		fwnt_test_memset_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( OPTIMIZATION_DISABLED ) */
#endif /* defined( HAVE_FWNT_TEST_MEMORY ) */

	/* TODO test errornous data */

	/* Clean up
	 */
	result = libfwnt_huffman_tree_free(
	          &huffman_tree,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "huffman_tree",
	 huffman_tree );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( huffman_tree != NULL )
	{
		libfwnt_huffman_tree_free(
		 &huffman_tree,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwnt_huffman_tree_get_symbol_from_bit_stream function
 * Returns 1 if successful or 0 if not
 */
int fwnt_test_huffman_tree_get_symbol_from_bit_stream(
     void )
{
	uint8_t code_size_array[ 512 ];

	libcerror_error_t *error             = NULL;
	libfwnt_bit_stream_t *bit_stream     = NULL;
	libfwnt_huffman_tree_t *huffman_tree = NULL;
	size_t byte_offset                   = 0;
	uint32_t symbol                      = 0;
	uint8_t byte_value                   = 0;
	int result                           = 0;

	/* Initialize test
	 */
	for( byte_offset = 0;
	     byte_offset < 256;
	     byte_offset++ )
	{
		byte_value = fwnt_test_huffman_tree_data1[ byte_offset ];

		code_size_array[ symbol++ ] = byte_value & 0x0f;

		byte_value >>= 4;

		code_size_array[ symbol++ ] = byte_value & 0x0f;
	}
	result = libfwnt_huffman_tree_initialize(
	          &huffman_tree,
	          512,
	          15,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NOT_NULL(
	 "huffman_tree",
	 huffman_tree );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_huffman_tree_build(
	          huffman_tree,
	          code_size_array,
	          512,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwnt_bit_stream_initialize(
	          &bit_stream,
	          &( fwnt_test_huffman_tree_data1[ 256 ] ),
	          277 - 256,
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

	/* Test regular cases
	 */
	symbol = 0;

	result = libfwnt_huffman_tree_get_symbol_from_bit_stream(
	          huffman_tree,
	          bit_stream,
	          &symbol,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_EQUAL_UINT32(
	 "symbol",
	 symbol,
	 (uint32_t) 97 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	symbol = 0;

	result = libfwnt_huffman_tree_get_symbol_from_bit_stream(
	          NULL,
	          bit_stream,
	          &symbol,
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

	result = libfwnt_huffman_tree_get_symbol_from_bit_stream(
	          huffman_tree,
	          NULL,
	          &symbol,
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

	result = libfwnt_huffman_tree_get_symbol_from_bit_stream(
	          huffman_tree,
	          bit_stream,
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

	/* Clean up
	 */
	result = libfwnt_huffman_tree_free(
	          &huffman_tree,
	          &error );

	FWNT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWNT_TEST_ASSERT_IS_NULL(
	 "huffman_tree",
	 huffman_tree );

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

	return( 1 );

on_error:
	if( huffman_tree != NULL )
	{
		libfwnt_huffman_tree_free(
		 &huffman_tree,
		 NULL );
	}
	if( bit_stream != NULL )
	{
		libfwnt_bit_stream_free(
		 &bit_stream,
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
	FWNT_TEST_UNREFERENCED_PARAMETER( argc )
	FWNT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( HAVE_DEBUG_OUTPUT ) && defined( FWNT_TEST_HUFFMAN_TREE_VERBOSE )
	libcnotify_verbose_set(
	 1 );
	libcnotify_stream_set(
	 stderr,
	 NULL );
#endif

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )

	FWNT_TEST_RUN(
	 "libfwnt_huffman_tree_initialize",
	 fwnt_test_huffman_tree_initialize );

	FWNT_TEST_RUN(
	 "libfwnt_huffman_tree_free",
	 fwnt_test_huffman_tree_free );

	FWNT_TEST_RUN(
	 "libfwnt_huffman_tree_build",
	 fwnt_test_huffman_tree_build );

	FWNT_TEST_RUN(
	 "libfwnt_huffman_tree_get_symbol_from_bit_stream",
	 fwnt_test_huffman_tree_get_symbol_from_bit_stream );

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT )
on_error:
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBFWNT_DLL_IMPORT ) */
}

