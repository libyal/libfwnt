/*
 * Python object definition of the sequence and iterator object of access control entries
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

#if !defined( _PYFWNT_ACCESS_CONTROL_ENTRIES_H )
#define _PYFWNT_ACCESS_CONTROL_ENTRIES_H

#include <common.h>
#include <types.h>

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

	/* The parent object
	 */
	PyObject *parent_object;

	/* The get item by index callback function
	 */
	PyObject* (*get_item_by_index)(
	             PyObject *parent_object,
	             int index );

	/* The current index
	 */
	int current_index;

	/* The number of items
	 */
	int number_of_items;
};

extern PyTypeObject pyfwnt_access_control_entries_type_object;

PyObject *pyfwnt_access_control_entries_new(
           PyObject *parent_object,
           PyObject* (*get_item_by_index)(
                        PyObject *parent_object,
                        int index ),
           int number_of_items );

int pyfwnt_access_control_entries_init(
     pyfwnt_access_control_entries_t *sequence_object );

void pyfwnt_access_control_entries_free(
      pyfwnt_access_control_entries_t *sequence_object );

Py_ssize_t pyfwnt_access_control_entries_len(
            pyfwnt_access_control_entries_t *sequence_object );

PyObject *pyfwnt_access_control_entries_getitem(
           pyfwnt_access_control_entries_t *sequence_object,
           Py_ssize_t item_index );

PyObject *pyfwnt_access_control_entries_iter(
           pyfwnt_access_control_entries_t *sequence_object );

PyObject *pyfwnt_access_control_entries_iternext(
           pyfwnt_access_control_entries_t *sequence_object );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWNT_ACCESS_CONTROL_ENTRIES_H ) */

