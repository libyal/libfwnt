/*
 * Debug functions
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
#include <memory.h>
#include <types.h>

#include "libfwnt_debug.h"
#include "libfwnt_definitions.h"
#include "libfwnt_libcnotify.h"

#if defined( HAVE_DEBUG_OUTPUT )

/* Prints the security descriptor control flags
 */
void libfwnt_debug_print_security_descriptor_control_flags(
      uint32_t control_flags )
{
	if( ( control_flags & 0x0001 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_OWNER_DEFAULTED)\n" );
	}
	if( ( control_flags & 0x0002 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_GROUP_DEFAULTED)\n" );
	}
	if( ( control_flags & 0x0004 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_DACL_PRESENT)\n" );
	}
	if( ( control_flags & 0x0008 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_DACL_DEFAULTED)\n" );
	}
	if( ( control_flags & 0x0010 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_SACL_PRESENT)\n" );
	}
	if( ( control_flags & 0x0020 ) != 0 )
	{
		libcnotify_printf(
		 "\t(Unknown 0x0020)\n" );
	}
	if( ( control_flags & 0x0040 ) != 0 )
	{
		libcnotify_printf(
		 "\t(Unknown 0x0040)\n" );
	}
	if( ( control_flags & 0x0080 ) != 0 )
	{
		libcnotify_printf(
		 "\t(Unknown 0x0080)\n" );
	}
	if( ( control_flags & 0x0100 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_DACL_AUTO_INHERIT_REQ)\n" );
	}
	if( ( control_flags & 0x0200 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_SACL_AUTO_INHERIT_REQ)\n" );
	}
	if( ( control_flags & 0x0400 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_DACL_AUTO_INHERITED)\n" );
	}
	if( ( control_flags & 0x0800 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_SACL_AUTO_INHERITED)\n" );
	}
	if( ( control_flags & 0x1000 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_DACL_PROTECTED)\n" );
	}
	if( ( control_flags & 0x2000 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_SACL_PROTECTED)\n" );
	}
	if( ( control_flags & 0x4000 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_RM_CONTROL_VALID)\n" );
	}
	if( ( control_flags & 0x8000 ) != 0 )
	{
		libcnotify_printf(
		 "\t(SE_SELF_RELATIVE)\n" );
	}
}

/* Retrieves a string containing the access control entry type
 */
const char *libfwnt_debug_print_access_control_entry_type(
             uint8_t entry_type )
{
	switch( entry_type )
	{
		case 0x00:
			return( "Access allowed (ACCESS_ALLOWED_ACE_TYPE)" );

		case 0x01:
			return( "Access denied (ACCESS_DENIED_ACE_TYPE)" );

		case 0x02:
			return( "System-audit (SYSTEM_AUDIT_ACE_TYPE)" );

		case 0x03:
			return( "System-alarm (SYSTEM_ALARM_ACE_TYPE)" );

		case 0x04:
			return( "Access allowed (ACCESS_ALLOWED_COMPOUND_ACE_TYPE)" );

		case 0x05:
			return( "Access allowed (ACCESS_ALLOWED_OBJECT_ACE_TYPE)" );

		case 0x06:
			return( "Access denied (ACCESS_DENIED_OBJECT_ACE_TYPE)" );

		case 0x07:
			return( "System-audit (SYSTEM_AUDIT_OBJECT_ACE_TYPE)" );

		case 0x08:
			return( "System-alarm (SYSTEM_ALARM_OBJECT_ACE_TYPE)" );

		case 0x09:
			return( "Access allowed (ACCESS_ALLOWED_CALLBACK_ACE_TYPE)" );

		case 0x0a:
			return( "Access denied (ACCESS_DENIED_CALLBACK_ACE_TYPE)" );

		case 0x0b:
			return( "Access allowed (ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE)" );

		case 0x0c:
			return( "Access denied (ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE)" );

		case 0x0d:
			return( "System-audit (SYSTEM_AUDIT_CALLBACK_ACE_TYPE)" );

		case 0x0e:
			return( "System-alarm (SYSTEM_ALARM_CALLBACK_ACE_TYPE)" );

		case 0x0f:
			return( "System-audit (SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE)" );

		case 0x10:
			return( "System-alarm (SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE)" );

		case 0x11:
			return( "Mandatory label (SYSTEM_MANDATORY_LABEL_ACE_TYPE)" );
	}
	return( "UNKNOWN" );
}

#endif /* defined( HAVE_DEBUG_OUTPUT ) */

