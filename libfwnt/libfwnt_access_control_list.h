/*
 * Windows NT Access Contol List (ACL) functions
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

#if !defined( _LIBFWNT_INTERNAL_ACCESS_CONTROL_LIST_H )
#define _LIBFWNT_INTERNAL_ACCESS_CONTROL_LIST_H

#include <common.h>
#include <types.h>

#include "libfwnt_extern.h"
#include "libfwnt_libcdata.h"
#include "libfwnt_libcerror.h"
#include "libfwnt_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The Windows NT Access Control List is formatted as following:
 * header: revision number, padding, size, count, padding
 * access control entries (ACE)
 */

typedef struct libfwnt_internal_access_control_list libfwnt_internal_access_control_list_t;

struct libfwnt_internal_access_control_list
{
	/* The revision number
	 */
	uint8_t revision_number;

	/* The (access control) entries array
	 */
	libcdata_array_t *entries_array;
};

int libfwnt_access_control_list_initialize(
     libfwnt_access_control_list_t **access_control_list,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_list_free(
     libfwnt_access_control_list_t **access_control_list,
     libcerror_error_t **error );

int libfwnt_internal_access_control_list_free(
     libfwnt_internal_access_control_list_t **internal_access_control_list,
     libcerror_error_t **error );

int libfwnt_access_control_list_copy_from_byte_stream(
     libfwnt_access_control_list_t *access_control_list,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int byte_order,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_list_get_number_of_entries(
     libfwnt_access_control_list_t *access_control_list,
     int *number_of_entries,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_list_get_entry_by_index(
     libfwnt_access_control_list_t *access_control_list,
     int entry_index,
     libfwnt_access_control_entry_t **access_control_entry,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWNT_INTERNAL_ACCESS_CONTROL_LIST_H ) */

