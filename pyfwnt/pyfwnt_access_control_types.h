/*
 * Python object definition of the libfwnt access control types
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

#if !defined( _PYFWNT_ACCESS_CONTROL_TYPES_H )
#define _PYFWNT_ACCESS_CONTROL_TYPES_H

#include <common.h>
#include <types.h>

#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwnt_access_control_types pyfwnt_access_control_types_t;

struct pyfwnt_access_control_types
{
	/* Python object initialization
	 */
	PyObject_HEAD
};

extern PyTypeObject pyfwnt_access_control_types_type_object;

int pyfwnt_access_control_types_init_type(
     PyTypeObject *type_object );

PyObject *pyfwnt_access_control_types_new(
           void );

int pyfwnt_access_control_types_init(
     pyfwnt_access_control_types_t *definitions_object );

void pyfwnt_access_control_types_free(
      pyfwnt_access_control_types_t *definitions_object );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWNT_ACCESS_CONTROL_TYPES_H ) */

