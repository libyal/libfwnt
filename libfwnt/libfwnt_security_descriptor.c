/*
 * Windows NT Security Descriptor functions
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

#include "libfwnt_access_control_list.h"
#include "libfwnt_debug.h"
#include "libfwnt_definitions.h"
#include "libfwnt_libcerror.h"
#include "libfwnt_libcnotify.h"
#include "libfwnt_security_descriptor.h"
#include "libfwnt_security_identifier.h"
#include "libfwnt_types.h"

/* Creates a security descriptor
 * Make sure the value security_descriptor is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwnt_security_descriptor_initialize(
     libfwnt_security_descriptor_t **security_descriptor,
     libcerror_error_t **error )
{
	libfwnt_internal_security_descriptor_t *internal_security_descriptor = NULL;
	static char *function                                                = "libfwnt_security_descriptor_initialize";

	if( security_descriptor == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid security descriptor.",
		 function );

		return( -1 );
	}
	if( *security_descriptor != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid security descriptor value already set.",
		 function );

		return( -1 );
	}
	internal_security_descriptor = memory_allocate_structure(
	                                libfwnt_internal_security_descriptor_t );

	if( internal_security_descriptor == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create security descriptor.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_security_descriptor,
	     0,
	     sizeof( libfwnt_internal_security_descriptor_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear security descriptor.",
		 function );

		goto on_error;
	}
	*security_descriptor = (libfwnt_security_descriptor_t *) internal_security_descriptor;

	return( 1 );

on_error:
	if( internal_security_descriptor != NULL )
	{
		memory_free(
		 internal_security_descriptor );
	}
	return( -1 );
}

/* Frees a security descriptor
 * Returns 1 if successful or -1 on error
 */
int libfwnt_security_descriptor_free(
     libfwnt_security_descriptor_t **security_descriptor,
     libcerror_error_t **error )
{
	libfwnt_internal_security_descriptor_t *internal_security_descriptor = NULL;
	static char *function                                                = "libfwnt_security_descriptor_free";
	int result                                                           = 1;

	if( security_descriptor == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid security descriptor.",
		 function );

		return( -1 );
	}
	if( *security_descriptor != NULL )
	{
		internal_security_descriptor = (libfwnt_internal_security_descriptor_t *) *security_descriptor;
		*security_descriptor         = NULL;

		if( internal_security_descriptor->owner_sid != NULL )
		{
			if( libfwnt_security_identifier_free(
			     &( internal_security_descriptor->owner_sid ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free the owner SID.",
				 function );

				result = -1;
			}
		}
		if( internal_security_descriptor->group_sid != NULL )
		{
			if( libfwnt_security_identifier_free(
			     &( internal_security_descriptor->group_sid ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free the group SID.",
				 function );

				result = -1;
			}
		}
		if( internal_security_descriptor->discretionary_acl != NULL )
		{
			if( libfwnt_access_control_list_free(
			     &( internal_security_descriptor->discretionary_acl ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free the discretionary ACL.",
				 function );

				result = -1;
			}
		}
		if( internal_security_descriptor->system_acl != NULL )
		{
			if( libfwnt_access_control_list_free(
			     &( internal_security_descriptor->system_acl ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free the system ACL.",
				 function );

				result = -1;
			}
		}
		memory_free(
		 internal_security_descriptor );
	}
	return( result );
}

/* Converts a security descriptor stored in a byte stream into a runtime version
 * Returns 1 if successful or -1 on error
 */
int libfwnt_security_descriptor_copy_from_byte_stream(
     libfwnt_security_descriptor_t *security_descriptor,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int byte_order,
     libcerror_error_t **error )
{
	libfwnt_internal_security_descriptor_t *internal_security_descriptor = NULL;
	static char *function                                                = "libfwnt_security_descriptor_copy_from_byte_stream";
	uint32_t discretionary_acl_offset                                    = 0;
	uint32_t group_sid_offset                                            = 0;
	uint32_t owner_sid_offset                                            = 0;
	uint32_t system_acl_offset                                           = 0;
	uint16_t control_flags                                               = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libcstring_system_character_t *sid_string                            = NULL;
	size_t sid_string_size                                               = 0;
	int result                                                           = 0;
#endif

	if( security_descriptor == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid security descriptor.",
		 function );

		return( -1 );
	}
	internal_security_descriptor = (libfwnt_internal_security_descriptor_t *) security_descriptor;

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
	if( byte_stream_size < 20 )
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
		 20,
		 0 );
	}
#endif
	internal_security_descriptor->revision_number = byte_stream[ 0 ];

	byte_stream_copy_to_uint16_little_endian(
	 &( byte_stream[ 2 ] ),
	 control_flags );

	byte_stream_copy_to_uint32_little_endian(
	 &( byte_stream[ 4 ] ),
	 owner_sid_offset );

	byte_stream_copy_to_uint32_little_endian(
	 &( byte_stream[ 8 ] ),
	 group_sid_offset );

	byte_stream_copy_to_uint32_little_endian(
	 &( byte_stream[ 12 ] ),
	 discretionary_acl_offset );

	byte_stream_copy_to_uint32_little_endian(
	 &( byte_stream[ 16 ] ),
	 system_acl_offset );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: revision number:\t\t%" PRIu8 "\n",
		 function,
		 internal_security_descriptor->revision_number );

		libcnotify_printf(
		 "%s: padding:\t\t\t0x%02" PRIx8 "\n",
		 function,
		 byte_stream[ 1 ] );

		libcnotify_printf(
		 "%: control flags:\t\t\t0x%04" PRIx16 "\n",
		 function,
		 control_flags );
		libfwnt_debug_print_security_descriptor_control_flags(
		 control_flags );
		libcnotify_printf(
		 "\n" );

		libcnotify_printf(
		 "%: owner SID offset:\t\t\t0x%08" PRIx32 "\n",
		 function,
		 owner_sid_offset );

		libcnotify_printf(
		 "%: group SID offset:\t\t\t0x%08" PRIx32 "\n",
		 function,
		 group_sid_offset );

		libcnotify_printf(
		 "%: discretionary ACL offset:\t\t0x%08" PRIx32 "\n",
		 function,
		 discretionary_acl_offset );

		libcnotify_printf(
		 "%: system ACL offset:\t\t\t0x%08" PRIx32 "\n",
		 function,
		 system_acl_offset );

		libcnotify_printf(
		 "\n" );
	}
#endif
	if( owner_sid_offset != 0 )
	{
		if( ( owner_sid_offset < 20 )
		 || ( (size_t) owner_sid_offset > byte_stream_size ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: owner SID offset value out of bounds.",
			 function );

			goto on_error;
		}
		if( libfwnt_security_identifier_initialize(
		     &( internal_security_descriptor->owner_sid ),
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create owner SID.",
			 function );

			goto on_error;
		}
		if( libfwnt_security_identifier_copy_from_byte_stream(
		     internal_security_descriptor->owner_sid,
		     &( byte_stream[ owner_sid_offset ] ),
		     byte_stream_size - owner_sid_offset,
		     LIBFWNT_ENDIAN_LITTLE,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy owner SID from byte stream.",
			 function );

			goto on_error;
		}
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwnt_security_identifier_get_string_size(
			     internal_security_descriptor->owner_sid,
			     &sid_string_size,
			     0,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to retrieve owner SID string size.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: owner SID:\t\t\t",
			 function );

			if( sid_string_size > 0 )
			{
				sid_string = libcstring_system_string_allocate(
				              sid_string_size );

				if( sid_string == NULL )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_MEMORY,
					 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
					 "%s: unable to create SID string.",
					 function );

					goto on_error;
				}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
				result = libfwnt_security_identifier_copy_to_utf16_string(
					  internal_security_descriptor->owner_sid,
					  (uint16_t *) sid_string,
					  sid_string_size,
					  0,
					  error );
#else
				result = libfwnt_security_identifier_copy_to_utf8_string(
					  internal_security_descriptor->owner_sid,
					  (uint8_t *) sid_string,
					  sid_string_size,
					  0,
					  error );
#endif
				if( result != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
					 "%s: unable to copy SID to string.",
					 function );

					goto on_error;
				}
				libcnotify_printf(
				 "%" PRIs_LIBCSTRING_SYSTEM "",
				 sid_string );

				memory_free(
				 sid_string );

				sid_string = NULL;
			}
			libcnotify_printf(
			 "\n" );
		}
#endif
	}
	if( group_sid_offset != 0 )
	{
		if( ( group_sid_offset < 20 )
		 || ( (size_t) group_sid_offset > byte_stream_size ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: group SID offset value out of bounds.",
			 function );

			goto on_error;
		}
		if( libfwnt_security_identifier_initialize(
		     &( internal_security_descriptor->group_sid ),
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create group SID.",
			 function );

			goto on_error;
		}
		if( libfwnt_security_identifier_copy_from_byte_stream(
		     internal_security_descriptor->group_sid,
		     &( byte_stream[ group_sid_offset ] ),
		     byte_stream_size - group_sid_offset,
		     LIBFWNT_ENDIAN_LITTLE,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy group SID from byte stream.",
			 function );

			goto on_error;
		}
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwnt_security_identifier_get_string_size(
			     internal_security_descriptor->group_sid,
			     &sid_string_size,
			     0,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to retrieve group SID string size.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: group SID:\t\t\t",
			 function );

			if( sid_string_size > 0 )
			{
				sid_string = libcstring_system_string_allocate(
				              sid_string_size );

				if( sid_string == NULL )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_MEMORY,
					 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
					 "%s: unable to create SID string.",
					 function );

					goto on_error;
				}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
				result = libfwnt_security_identifier_copy_to_utf16_string(
					  internal_security_descriptor->group_sid,
					  (uint16_t *) sid_string,
					  sid_string_size,
					  0,
					  error );
#else
				result = libfwnt_security_identifier_copy_to_utf8_string(
					  internal_security_descriptor->group_sid,
					  (uint8_t *) sid_string,
					  sid_string_size,
					  0,
					  error );
#endif
				if( result != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
					 "%s: unable to copy SID to string.",
					 function );

					goto on_error;
				}
				libcnotify_printf(
				 "%" PRIs_LIBCSTRING_SYSTEM "",
				 sid_string );

				memory_free(
				 sid_string );

				sid_string = NULL;
			}
			libcnotify_printf(
			 "\n" );
		}
#endif
	}
	if( discretionary_acl_offset != 0 )
	{
		if( ( discretionary_acl_offset < 20 )
		 || ( (size_t) discretionary_acl_offset > byte_stream_size ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: discretionary ACL offset value out of bounds.",
			 function );

			goto on_error;
		}
/* TODO */
	}
	if( system_acl_offset != 0 )
	{
		if( ( system_acl_offset < 20 )
		 || ( (size_t) system_acl_offset > byte_stream_size ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: system ACL offset value out of bounds.",
			 function );

			goto on_error;
		}
/* TODO */
	}

#ifdef TODO
/* TODO from libfmapi rewrite note that there 8 unknown bytes in front of data */
/* TODO */
				value_data_pointer = &( value_data[ 20 ] );

				byte_stream_copy_to_uint32_little_endian(
				 value_data_pointer,
				 value_32bit );

				libcnotify_printf(
				 "\tDACL reference:\t\t\t%" PRIu32 "\n",
				 value_32bit );

				value_data_pointer = &( value_data[ 24 ] );

				byte_stream_copy_to_uint32_little_endian(
				 value_data_pointer,
				 value_32bit );

				libcnotify_printf(
				 "\tSACL reference:\t\t\t%" PRIu32 "\n",
				 value_32bit );

				value_data_iterator = value_32bit + 8;

				if( ( value_data_iterator > 0 )
				 && ( value_data_iterator < value_data_size ) )
				{
					libcnotify_printf(
					 "\t\tAccess control list (ACL):\n" );
					libcnotify_printf(
					 "\t\tRevision number:\t%" PRIu8 "\n",
					 value_data[ value_data_iterator ] );
					libcnotify_printf(
					 "\t\tPadding1:\t\t%" PRIu8 "\n",
					 value_data[ value_data_iterator + 1 ] );

					value_data_pointer = &( value_data[ value_data_iterator + 2 ] );

					byte_stream_copy_to_uint16_little_endian(
					 value_data_pointer,
					 value_16bit );

					libcnotify_printf(
					 "\t\tSize:\t\t\t%" PRIu16 "\n",
					 value_16bit );

					value_data_pointer = &( value_data[ value_data_iterator + 4 ] );

					byte_stream_copy_to_uint16_little_endian(
					 value_data_pointer,
					 value_16bit );

					libcnotify_printf(
					 "\t\tCount:\t\t\t%" PRIu16 "\n",
					 value_16bit );

					number_of_values = (uint32_t) value_16bit;

					value_data_pointer = &( value_data[ value_data_iterator + 6 ] );

					byte_stream_copy_to_uint16_little_endian(
					 value_data_pointer,
					 value_16bit );

					libcnotify_printf(
					 "\t\tPadding2:\t\t0x%04" PRIx16 "\n",
					 value_16bit );

					value_data_iterator += 8;

					for( value_iterator = 0;
					     value_iterator < number_of_values;
					     value_iterator++ )
					{
						libcnotify_printf(
						 "\t\tAccess control entry (ACE):\n" );
						libcnotify_printf(
						 "\t\tType:\t\t\t%" PRIu8 "\n",
						 value_data[ value_data_iterator ] );
						libcnotify_printf(
						 "\t\tFlags:\t\t\t%" PRIu8 "\n",
						 value_data[ value_data_iterator + 1 ] );

						value_data_pointer = &( value_data[ value_data_iterator + 2 ] );

						byte_stream_copy_to_uint16_little_endian(
						 value_data_pointer,
						 value_16bit );

						libcnotify_printf(
						 "\t\tSize:\t\t\t%" PRIu16 "\n",
						 value_16bit );

						libcnotify_printf(
						 "\t\tACE data:\n" );

						if( ( value_data[ value_data_iterator ] <= 0x03 )
						 || ( value_data[ value_data_iterator ] == 0x09 )
						 || ( value_data[ value_data_iterator ] == 0x0a )
						 || ( value_data[ value_data_iterator ] == 0x0d )
						 || ( value_data[ value_data_iterator ] == 0x0e )
						 || ( value_data[ value_data_iterator ] == 0x11 ) )
						{
							value_data_pointer = &( value_data[ value_data_iterator + 4 ] );

							byte_stream_copy_to_uint16_little_endian(
							 value_data_pointer,
							 value_32bit );

							libcnotify_printf(
							 "\t\tAccess rights flags:\t0x%08" PRIx32 "\n",
							 value_32bit );

							if( libfwnt_security_identifier_copy_from_byte_stream(
							     sid,
							     &( value_data[ value_data_iterator + 8 ] ),
							     value_data_size - value_data_iterator,
							     0,
							     error ) != 1 )
							{
								libcerror_error_set(
								 error,
								 LIBCERROR_ERROR_DOMAIN_RUNTIME,
								 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
								 "%s: unable to copy byte stream to SID.",
								 function );

								libfwnt_security_identifier_free(
								 &sid,
								 NULL );

								return( -1 );
							}
							result = libfwnt_security_identifier_get_string_size(
								  sid,
								  &sid_string_size,
								  0,
								  error );

							if( result != 1 )
							{
								libcerror_error_set(
								 error,
								 LIBCERROR_ERROR_DOMAIN_RUNTIME,
								 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
								 "%s: unable to retrieve SID string size.",
								 function );

								libfwnt_security_identifier_free(
								 &sid,
								 NULL );

								return( -1 );
							}
							/* It is assumed that the SID string cannot be larger than 127 characters
							 * otherwise using dynamic allocation is more appropriate
							 */
							if( sid_string_size > 128 )
							{
								libcerror_error_set(
								 error,
								 LIBCERROR_ERROR_DOMAIN_RUNTIME,
								 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
								 "%s: SID string size value exceeds maximum.",
								 function );

								libfwnt_security_identifier_free(
								 &sid,
								 NULL );

								return( -1 );
							}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
							result = libfwnt_security_identifier_copy_to_utf16_string(
								  sid,
								  (uint16_t *) sid_string,
								  128,
								  0,
								  error );
#else
							result = libfwnt_security_identifier_copy_to_utf8_string(
								  sid,
								  (uint8_t *) sid_string,
								  128,
								  0,
								  error );
#endif
							if( result != 1 )
							{
								libcerror_error_set(
								 error,
								 LIBCERROR_ERROR_DOMAIN_RUNTIME,
								 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
								 "%s: unable to copy SID to string.",
								 function );

								libfwnt_security_identifier_free(
								 &sid,
								 NULL );

								return( -1 );
							}
							libcnotify_printf(
							 "\t\tSID:\t\t\t%" PRIs_LIBCSTRING_SYSTEM "\n",
							 sid_string );

							libcnotify_printf(
							 "\n" );
						}
						else
						{
							libcnotify_print_data(
							 &( value_data[ value_32bit + 4 ] ),
							 value_16bit - 4,
							 0 );
						}
					}
				}
				libcnotify_printf(
				 "\n" );

				if( libfwnt_security_identifier_free(
				     &sid,
				     error ) != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
					 "%s: unable to free SID.",
					 function );

					return( -1 );
				}
	}
#endif
	return( 1 );

on_error:
#if defined( HAVE_DEBUG_OUTPUT )
	if( sid_string != NULL )
	{
		memory_free(
		 sid_string );
	}
#endif
	if( internal_security_descriptor->system_acl != NULL )
	{
		libfwnt_access_control_list_free(
		 &( internal_security_descriptor->system_acl ),
		 NULL );
	}
	if( internal_security_descriptor->discretionary_acl != NULL )
	{
		libfwnt_access_control_list_free(
		 &( internal_security_descriptor->discretionary_acl ),
		 NULL );
	}
	if( internal_security_descriptor->group_sid != NULL )
	{
		libfwnt_security_identifier_free(
		 &( internal_security_descriptor->group_sid ),
		 NULL );
	}
	if( internal_security_descriptor->owner_sid != NULL )
	{
		libfwnt_security_identifier_free(
		 &( internal_security_descriptor->owner_sid ),
		 NULL );
	}
	return( -1 );
}

