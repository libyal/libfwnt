/*
 * Library to support common Windows NT specific formats
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

#if !defined( _LIBFWNT_H )
#define _LIBFWNT_H

#include <libfwnt/definitions.h>
#include <libfwnt/error.h>
#include <libfwnt/extern.h>
#include <libfwnt/features.h>
#include <libfwnt/types.h>

#include <stdio.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Support functions
 * ------------------------------------------------------------------------- */

/* Returns the library version
 */
LIBFWNT_EXTERN \
const char *libfwnt_get_version(
             void );

/* -------------------------------------------------------------------------
 * Notify functions
 * ------------------------------------------------------------------------- */

/* Sets the verbose notification
 */
LIBFWNT_EXTERN \
void libfwnt_notify_set_verbose(
      int verbose );

/* Sets the notification stream
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_notify_set_stream(
     FILE *stream,
     libfwnt_error_t **error );

/* Opens the notification stream using a filename
 * The stream is opened in append mode
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_notify_stream_open(
     const char *filename,
     libfwnt_error_t **error );

/* Closes the notification stream if opened using a filename
 * Returns 0 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_notify_stream_close(
     libfwnt_error_t **error );

/* -------------------------------------------------------------------------
 * Error functions
 * ------------------------------------------------------------------------- */

/* Frees an error
 */
LIBFWNT_EXTERN \
void libfwnt_error_free(
      libfwnt_error_t **error );

/* Prints a descriptive string of the error to the stream
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_error_fprint(
     libfwnt_error_t *error,
     FILE *stream );

/* Prints a descriptive string of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_error_sprint(
     libfwnt_error_t *error,
     char *string,
     size_t size );

/* Prints a backtrace of the error to the stream
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_error_backtrace_fprint(
     libfwnt_error_t *error,
     FILE *stream );

/* Prints a backtrace of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_error_backtrace_sprint(
     libfwnt_error_t *error,
     char *string,
     size_t size );

/* -------------------------------------------------------------------------
 * Locale identifier (LCID) functions
 * ------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------
 * Security descriptor functions
 * ------------------------------------------------------------------------- */

/* Creates a security descriptor
 * Make sure the value security_descriptor is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_descriptor_initialize(
     libfwnt_security_descriptor_t **security_descriptor,
     libfwnt_error_t **error );

/* Frees a security descriptor
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_descriptor_free(
     libfwnt_security_descriptor_t **security_descriptor,
     libfwnt_error_t **error );

/* Converts a security descriptor stored in a byte stream into a runtime version
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_descriptor_copy_from_byte_stream(
     libfwnt_security_descriptor_t *security_descriptor,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int byte_order,
     libfwnt_error_t **error );

/* Retrieves the owner security identifier (SID)
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_descriptor_get_owner(
     libfwnt_security_descriptor_t *security_descriptor,
     libfwnt_security_identifier_t **security_identifier,
     libfwnt_error_t **error );

/* Retrieves the group security identifier (SID)
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_descriptor_get_group(
     libfwnt_security_descriptor_t *security_descriptor,
     libfwnt_security_identifier_t **security_identifier,
     libfwnt_error_t **error );

/* Retrieves the discretionary access control list (ACL)
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_descriptor_get_discretionary_acl(
     libfwnt_security_descriptor_t *security_descriptor,
     libfwnt_access_control_list_t **access_control_list,
     libfwnt_error_t **error );

/* Retrieves the system access control list (ACL)
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_descriptor_get_system_acl(
     libfwnt_security_descriptor_t *security_descriptor,
     libfwnt_access_control_list_t **access_control_list,
     libfwnt_error_t **error );

/* -------------------------------------------------------------------------
 * Security identifier (SID) functions
 * ------------------------------------------------------------------------- */

/* Creates a security identifier
 * Make sure the value security_identifier is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_initialize(
     libfwnt_security_identifier_t **security_identifier,
     libfwnt_error_t **error );

/* Frees a security identifier
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_free(
     libfwnt_security_identifier_t **security_identifier,
     libfwnt_error_t **error );

/* Converts a security identifier stored in a byte stream into a runtime version
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_copy_from_byte_stream(
     libfwnt_security_identifier_t *security_identifier,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int byte_order,
     libfwnt_error_t **error );

/* Deterimes the size of the string for the security identifier
 * The string size includes the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_get_string_size(
     libfwnt_security_identifier_t *security_identifier,
     size_t *string_size,
     uint32_t string_format_flags,
     libfwnt_error_t **error );

/* Converts the security identifier into an UTF-8 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_copy_to_utf8_string(
     libfwnt_security_identifier_t *security_identifier,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     uint32_t string_format_flags,
     libfwnt_error_t **error );

/* Converts the security identifier into an UTF-8 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_copy_to_utf8_string_with_index(
     libfwnt_security_identifier_t *security_identifier,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     size_t *utf8_string_index,
     uint32_t string_format_flags,
     libfwnt_error_t **error );

/* Converts the security identifier into an UTF-16 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_copy_to_utf16_string(
     libfwnt_security_identifier_t *security_identifier,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     uint32_t string_format_flags,
     libfwnt_error_t **error );

/* Converts the security identifier into an UTF-16 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_copy_to_utf16_string_with_index(
     libfwnt_security_identifier_t *security_identifier,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     size_t *utf16_string_index,
     uint32_t string_format_flags,
     libfwnt_error_t **error );

/* Converts the security identifier into an UTF-32 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_copy_to_utf32_string(
     libfwnt_security_identifier_t *security_identifier,
     uint32_t *utf32_string,
     size_t utf32_string_size,
     uint32_t string_format_flags,
     libfwnt_error_t **error );

/* Converts the security identifier into an UTF-32 string
 * The string size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_security_identifier_copy_to_utf32_string_with_index(
     libfwnt_security_identifier_t *security_identifier,
     uint32_t *utf32_string,
     size_t utf32_string_size,
     size_t *utf32_string_index,
     uint32_t string_format_flags,
     libfwnt_error_t **error );

/* -------------------------------------------------------------------------
 * Access control list (ACL) functions
 * ------------------------------------------------------------------------- */

/* Frees an access control list
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_list_free(
     libfwnt_access_control_list_t **access_control_list,
     libfwnt_error_t **error );

/* Retrieves the number of access control entries
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_list_get_number_of_entries(
     libfwnt_access_control_list_t *access_control_list,
     int *number_of_entries,
     libfwnt_error_t **error );

/* Retrieves a specific access control entry
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_list_get_entry_by_index(
     libfwnt_access_control_list_t *access_control_list,
     int entry_index,
     libfwnt_access_control_entry_t **access_control_entry,
     libfwnt_error_t **error );

/* -------------------------------------------------------------------------
 * Access control entry (ACE) functions
 * ------------------------------------------------------------------------- */

/* Frees an access control entry
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_entry_free(
     libfwnt_access_control_entry_t **access_control_entry,
     libfwnt_error_t **error );

/* Retrieves the type
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_type(
     libfwnt_access_control_entry_t *access_control_entry,
     uint8_t *type,
     libfwnt_error_t **error );

/* Retrieves the flags
 * Returns 1 if successful or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_flags(
     libfwnt_access_control_entry_t *access_control_entry,
     uint8_t *flags,
     libfwnt_error_t **error );

/* Retrieves the access mask
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_access_mask(
     libfwnt_access_control_entry_t *access_control_entry,
     uint32_t *access_mask,
     libfwnt_error_t **error );

/* Retrieves the security identifier
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_access_control_entry_get_security_identifier(
     libfwnt_access_control_entry_t *access_control_entry,
     libfwnt_security_identifier_t **security_identifier,
     libfwnt_error_t **error );

/* -------------------------------------------------------------------------
 * LZNT1 functions
 * ------------------------------------------------------------------------- */

/* Decompresses data using LZNT1 compression
 * Returns 1 on success or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_lznt1_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libfwnt_error_t **error );

/* -------------------------------------------------------------------------
 * LZX functions
 * ------------------------------------------------------------------------- */

/* Decompresses data using LZX compression
 * Return 1 on success or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_lzx_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libfwnt_error_t **error );

/* -------------------------------------------------------------------------
 * LZXPRESS functions
 * ------------------------------------------------------------------------- */

/* Decompresses data using LZXPRESS (LZ77 + DIRECT2) compression
 * Return 1 on success or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_lzxpress_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libfwnt_error_t **error );

/* Decompresses data using LZXPRESS Huffman compression
 * Return 1 on success or -1 on error
 */
LIBFWNT_EXTERN \
int libfwnt_lzxpress_huffman_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libfwnt_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWNT_H ) */

