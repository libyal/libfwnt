/*
 * Windows NT Access Control Entry (ACE) functions
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwnt_access_control_entry.h"
#include "libfwnt_definitions.h"
#include "libfwnt_libcerror.h"
#include "libfwnt_libcnotify.h"
#include "libfwnt_types.h"

/* Creates an access control entry
 * Make sure the value access_control_entry is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwnt_access_control_entry_initialize(
     libfwnt_access_control_entry_t **access_control_entry,
     libcerror_error_t **error )
{
	libfwnt_internal_access_control_entry_t *internal_access_control_entry = NULL;
	static char *function                                                  = "libfwnt_access_control_entry_initialize";

	if( access_control_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid access control entry.",
		 function );

		return( -1 );
	}
	if( *access_control_entry != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid access control entry value already set.",
		 function );

		return( -1 );
	}
	internal_access_control_entry = memory_allocate_structure(
	                                 libfwnt_internal_access_control_entry_t );

	if( internal_access_control_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create access control entry.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_access_control_entry,
	     0,
	     sizeof( libfwnt_internal_access_control_entry_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear access control entry.",
		 function );

		goto on_error;
	}
	*access_control_entry = (libfwnt_access_control_entry_t *) internal_access_control_entry;

	return( 1 );

on_error:
	if( internal_access_control_entry != NULL )
	{
		memory_free(
		 internal_access_control_entry );
	}
	return( -1 );
}

/* Frees an access control entry
 * Returns 1 if successful or -1 on error
 */
int libfwnt_access_control_entry_free(
     libfwnt_access_control_entry_t **access_control_entry,
     libcerror_error_t **error )
{
	libfwnt_internal_access_control_entry_t *internal_access_control_entry = NULL;
	static char *function                                                  = "libfwnt_access_control_entry_free";
	int result                                                             = 1;

	if( access_control_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid access control entry.",
		 function );

		return( -1 );
	}
	if( *access_control_entry != NULL )
	{
		internal_access_control_entry = (libfwnt_internal_access_control_entry_t *) *access_control_entry;
		*access_control_entry         = NULL;

		memory_free(
		 internal_access_control_entry );
	}
	return( result );
}

/* Converts an access control entry stored in a byte stream into a runtime version
 * Returns 1 if successful or -1 on error
 */
int libfwnt_access_control_entry_copy_from_byte_stream(
     libfwnt_access_control_entry_t *access_control_entry,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int byte_order,
     libcerror_error_t **error )
{
	libfwnt_internal_access_control_entry_t *internal_access_control_entry = NULL;
	static char *function                                                  = "libfwnt_access_control_entry_copy_from_byte_stream";
	uint16_t size                                                          = 0;

	if( access_control_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid access control entry.",
		 function );

		return( -1 );
	}
	internal_access_control_entry = (libfwnt_internal_access_control_entry_t *) access_control_entry;

	if( byte_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid byte stream.",
		 function );

		return( -1 );
	}
	if( byte_stream_size < 8 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: byte stream too small.",
		 function );

		return( -1 );
	}
	if( byte_stream_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: byte stream size exceeds maximum.",
		 function );

		return( -1 );
	}
	if( byte_order != LIBFWNT_ENDIAN_LITTLE )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported byte order.",
		 function );

		return( -1 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: header data:\n",
		 function );
		libcnotify_print_data(
		 byte_stream,
		 8,
		 0 );
	}
#endif
	internal_access_control_entry->type  = byte_stream[ 0 ];
	internal_access_control_entry->flags = byte_stream[ 1 ];

	byte_stream_copy_to_uint16_little_endian(
	 &( byte_stream[ 2 ] ),
	 size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: type\t\t\t\t: %" PRIu8 "\n",
		 function,
		 internal_access_control_entry->type );

		libcnotify_printf(
		 "%s: flags\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 internal_access_control_entry->flags );

		libcnotify_printf(
		 "%s: size\t\t\t\t: %" PRIu16 "\n",
		 function,
		 size );

		libcnotify_printf(
		 "\n" );
	}
#endif

/* TODO read ACE data */

	return( 1 );
}

