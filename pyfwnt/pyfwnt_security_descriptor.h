/*
 * Python object wrapper of libfwnt_security_descriptor_t
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

#if !defined( _PYFWNT_SECURITY_DESCRIPTOR_H )
#define _PYFWNT_SECURITY_DESCRIPTOR_H

#include <common.h>
#include <types.h>

#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwnt_security_descriptor pyfwnt_security_descriptor_t;

struct pyfwnt_security_descriptor
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libfwnt security descriptor
	 */
	libfwnt_security_descriptor_t *security_descriptor;
};

extern PyMethodDef pyfwnt_security_descriptor_object_methods[];
extern PyTypeObject pyfwnt_security_descriptor_type_object;

int pyfwnt_security_descriptor_init(
     pyfwnt_security_descriptor_t *pyfwnt_security_descriptor );

void pyfwnt_security_descriptor_free(
      pyfwnt_security_descriptor_t *pyfwnt_security_descriptor );

PyObject *pyfwnt_security_descriptor_copy_from_byte_stream(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyfwnt_security_descriptor_get_owner(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments );

PyObject *pyfwnt_security_descriptor_get_group(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments );

PyObject *pyfwnt_security_descriptor_get_discretionary_acl(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments );

PyObject *pyfwnt_security_descriptor_get_system_acl(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWNT_SECURITY_DESCRIPTOR_H ) */

