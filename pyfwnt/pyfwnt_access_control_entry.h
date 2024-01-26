/*
 * Python object wrapper of libfwnt_access_control_entry_t
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

#if !defined( _PYFWNT_ACCESS_CONTROL_ENTRY_H )
#define _PYFWNT_ACCESS_CONTROL_ENTRY_H

#include <common.h>
#include <types.h>

#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwnt_access_control_entry pyfwnt_access_control_entry_t;

struct pyfwnt_access_control_entry
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libfwnt access control entry
	 */
	libfwnt_access_control_entry_t *access_control_entry;

	/* The parent object
	 */
	PyObject *parent_object;
};

extern PyMethodDef pyfwnt_access_control_entry_object_methods[];
extern PyTypeObject pyfwnt_access_control_entry_type_object;

PyObject *pyfwnt_access_control_entry_new(
           libfwnt_access_control_entry_t *access_control_entry,
           PyObject *parent_object );

int pyfwnt_access_control_entry_init(
     pyfwnt_access_control_entry_t *pyfwnt_access_control_entry );

void pyfwnt_access_control_entry_free(
      pyfwnt_access_control_entry_t *pyfwnt_access_control_entry );

PyObject *pyfwnt_access_control_entry_get_type(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments );

PyObject *pyfwnt_access_control_entry_get_flags(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments );

PyObject *pyfwnt_access_control_entry_get_access_mask(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments );

PyObject *pyfwnt_access_control_entry_get_security_identifier(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWNT_ACCESS_CONTROL_ENTRY_H ) */

