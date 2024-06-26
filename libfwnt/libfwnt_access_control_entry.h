/*
 * Windows NT Access Contol Entry (ACE) functions
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

#if !defined( _LIBFWNT_INTERNAL_ACCESS_CONTROL_ENTRY_H )
#define _LIBFWNT_INTERNAL_ACCESS_CONTROL_ENTRY_H

#include <common.h>
#include <types.h>

#include "libfwnt_extern.h"
#include "libfwnt_libcerror.h"
#include "libfwnt_security_identifier.h"
#include "libfwnt_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The Windows NT Access Control Entry is formatted as following:
 * header: type, flags, size
 * data
 */

typedef struct libfwnt_internal_access_control_entry libfwnt_internal_access_control_entry_t;

struct libfwnt_internal_access_control_entry
{
	/* The size
	 */
	uint16_t size;

	/* The type
	 */
	uint8_t type;

	/* The flags
	 */
	uint8_t flags;

	/* The access mask
	 */
	uint32_t access_mask;

	/* The security identifier
	 */
	libfwnt_security_identifier_t *security_identifier;
};

int libfwnt_access_control_entry_initialize(
     libfwnt_access_control_entry_t **access_control_entry,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_free(
     libfwnt_access_control_entry_t **access_control_entry,
     libcerror_error_t **error );

int libfwnt_internal_access_control_entry_free(
     libfwnt_internal_access_control_entry_t **internal_access_control_entry,
     libcerror_error_t **error );

int libfwnt_access_control_entry_copy_from_byte_stream(
     libfwnt_access_control_entry_t *access_control_entry,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int byte_order,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_type(
     libfwnt_access_control_entry_t *access_control_entry,
     uint8_t *type,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_flags(
     libfwnt_access_control_entry_t *access_control_entry,
     uint8_t *flags,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_access_mask(
     libfwnt_access_control_entry_t *access_control_entry,
     uint32_t *access_mask,
     libcerror_error_t **error );

LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_security_identifier(
     libfwnt_access_control_entry_t *access_control_entry,
     libfwnt_security_identifier_t **security_identifier,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWNT_INTERNAL_ACCESS_CONTROL_ENTRY_H ) */

