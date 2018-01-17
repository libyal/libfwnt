/*
 * Python object definition of the access control entry sequence and iterator
 *
 * Copyright (C) 2011-2018, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _PYFWNT_ACCESS_CONTROL_ENTRIES_H )
#define _PYFWNT_ACCESS_CONTROL_ENTRIES_H

#include <common.h>
#include <types.h>

#include "pyfwnt_access_control_list.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwnt_access_control_entries pyfwnt_access_control_entries_t;

struct pyfwnt_access_control_entries
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The access control list object
	 */
	pyfwnt_access_control_list_t *access_control_list_object;

	/* The get entry by index callback function
	 */
	PyObject* (*get_entry_by_index)(
	             pyfwnt_access_control_list_t *access_control_list_object,
	             int entry_index );

	/* The (current) entry index
	 */
	int entry_index;

	/* The number of entries
	 */
	int number_of_entries;
};

extern PyTypeObject pyfwnt_access_control_entries_type_object;

PyObject *pyfwnt_access_control_entries_new(
           pyfwnt_access_control_list_t *access_control_list_object,
           PyObject* (*get_entry_by_index)(
                        pyfwnt_access_control_list_t *access_control_list_object,
                        int entry_index ),
           int number_of_entries );

int pyfwnt_access_control_entries_init(
     pyfwnt_access_control_entries_t *pyfwnt_access_control_entries );

void pyfwnt_access_control_entries_free(
      pyfwnt_access_control_entries_t *pyfwnt_access_control_entries );

Py_ssize_t pyfwnt_access_control_entries_len(
            pyfwnt_access_control_entries_t *pyfwnt_access_control_entries );

PyObject *pyfwnt_access_control_entries_getitem(
           pyfwnt_access_control_entries_t *pyfwnt_access_control_entries,
           Py_ssize_t item_index );

PyObject *pyfwnt_access_control_entries_iter(
           pyfwnt_access_control_entries_t *pyfwnt_access_control_entries );

PyObject *pyfwnt_access_control_entries_iternext(
           pyfwnt_access_control_entries_t *pyfwnt_access_control_entries );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWNT_ACCESS_CONTROL_ENTRIES_H ) */

