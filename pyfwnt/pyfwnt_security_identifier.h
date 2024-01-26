/*
 * Python object wrapper of libfwnt_security_identifier_t
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

#if !defined( _PYFWNT_SECURITY_IDENTIFIER_H )
#define _PYFWNT_SECURITY_IDENTIFIER_H

#include <common.h>
#include <types.h>

#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwnt_security_identifier pyfwnt_security_identifier_t;

struct pyfwnt_security_identifier
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libfwnt security identifier
	 */
	libfwnt_security_identifier_t *security_identifier;

	/* The parent object
	 */
	PyObject *parent_object;
};

extern PyMethodDef pyfwnt_security_identifier_object_methods[];
extern PyTypeObject pyfwnt_security_identifier_type_object;

PyObject *pyfwnt_security_identifier_new(
           libfwnt_security_identifier_t *security_identifier,
           PyObject *parent_object );

int pyfwnt_security_identifier_init(
     pyfwnt_security_identifier_t *pyfwnt_security_identifier );

void pyfwnt_security_identifier_free(
      pyfwnt_security_identifier_t *pyfwnt_security_identifier );

PyObject *pyfwnt_security_identifier_copy_from_byte_stream(
           pyfwnt_security_identifier_t *pyfwnt_security_identifier,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyfwnt_security_identifier_get_string(
           pyfwnt_security_identifier_t *pyfwnt_security_identifier,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWNT_SECURITY_IDENTIFIER_H ) */

