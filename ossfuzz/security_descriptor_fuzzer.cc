/*
 * OSS-Fuzz target for libfwnt security descriptor type
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

/* Retrieves the entries of the access control list
 */
static void inspect_access_control_list(
           libfwnt_access_control_list_t *access_control_list )
{
	libfwnt_access_control_entry_t *access_control_entry  = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;

	uint8_t type     = 0;
	uint8_t flags    = 0;
	uint32_t access_mask = 0;

	int number_of_entries = 0;
	int entry_index       = 0;

	if( access_control_list == NULL )
	{
		return;
	}
	libfwnt_access_control_list_get_number_of_entries(
	 access_control_list,
	 &number_of_entries,
	 NULL );

	for( entry_index = 0;
	     entry_index < number_of_entries;
	     entry_index++ )
	{
		access_control_entry = NULL;

		if( libfwnt_access_control_list_get_entry_by_index(
		     access_control_list,
		     entry_index,
		     &access_control_entry,
		     NULL ) != 1 )
		{
			break;
		}
		if( access_control_entry == NULL )
		{
			break;
		}
		libfwnt_access_control_entry_get_type(
		 access_control_entry,
		 &type,
		 NULL );

		libfwnt_access_control_entry_get_flags(
		 access_control_entry,
		 &flags,
		 NULL );

		libfwnt_access_control_entry_get_access_mask(
		 access_control_entry,
		 &access_mask,
		 NULL );

		security_identifier = NULL;

		if( libfwnt_access_control_entry_get_security_identifier(
		     access_control_entry,
		     &security_identifier,
		     NULL ) == 1 )
		{
			libfwnt_security_identifier_get_string_size(
			 security_identifier,
			 NULL,
			 0,
			 NULL );
		}
	}
} /* inspect_access_control_list */

int LLVMFuzzerTestOneInput(
     const uint8_t *data,
     size_t size )
{
	libfwnt_access_control_list_t *access_control_list = NULL;
	libfwnt_security_descriptor_t *security_descriptor = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;

	if( libfwnt_security_descriptor_initialize(
	     &security_descriptor,
	     NULL ) != 1 )
	{
		return( 0 );
	}
	libfwnt_security_descriptor_copy_from_byte_stream(
	 security_descriptor,
	 data,
	 size,
	 LIBFWNT_ENDIAN_LITTLE,
	 NULL );

	/* The owner and group are managed by the security descriptor
	 */
	security_identifier = NULL;

	if( libfwnt_security_descriptor_get_owner(
	     security_descriptor,
	     &security_identifier,
	     NULL ) == 1 )
	{
		libfwnt_security_identifier_get_string_size(
		 security_identifier,
		 NULL,
		 0,
		 NULL );
	}

	security_identifier = NULL;

	if( libfwnt_security_descriptor_get_group(
	     security_descriptor,
	     &security_identifier,
	     NULL ) == 1 )
	{
		libfwnt_security_identifier_get_string_size(
		 security_identifier,
		 NULL,
		 0,
		 NULL );
	}

	access_control_list = NULL;

	if( libfwnt_security_descriptor_get_discretionary_acl(
	     security_descriptor,
	     &access_control_list,
	     NULL ) == 1 )
	{
		inspect_access_control_list(
		 access_control_list );
	}

	access_control_list = NULL;

	if( libfwnt_security_descriptor_get_system_acl(
	     security_descriptor,
	     &access_control_list,
	     NULL ) == 1 )
	{
		inspect_access_control_list(
		 access_control_list );
	}

	libfwnt_security_descriptor_free(
	 &security_descriptor,
	 NULL );

	return( 0 );
}

} /* extern "C" */
