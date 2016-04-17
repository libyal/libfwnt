/*
 * Python object definition of the libfwnt access control list
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

#if !defined( _PYFWNT_ACCESS_CONTROL_LIST_H )
#define _PYFWNT_ACCESS_CONTROL_LIST_H

#include <common.h>
#include <types.h>

#include "pyfwnt_access_control_list.h"
#include "pyfwnt_libcerror.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwnt_access_control_list pyfwnt_access_control_list_t;

struct pyfwnt_access_control_list
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libfwnt extension block
	 */
	libfwnt_access_control_list_t *access_control_list;

	/* The parent object
	 */
	PyObject *parent_object;
};

extern PyMethodDef pyfwnt_access_control_list_object_methods[];
extern PyTypeObject pyfwnt_access_control_list_type_object;

PyObject *pyfwnt_access_control_list_new(
           libfwnt_access_control_list_t *access_control_list,
           PyObject *parent_object );

int pyfwnt_access_control_list_init(
     pyfwnt_access_control_list_t *pyfwnt_access_control_list );

void pyfwnt_access_control_list_free(
      pyfwnt_access_control_list_t *pyfwnt_access_control_list );

PyObject *pyfwnt_access_control_list_get_number_of_entries(
           pyfwnt_access_control_list_t *pyfwnt_access_control_list,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWNT_ACCESS_CONTROL_LIST_H ) */

