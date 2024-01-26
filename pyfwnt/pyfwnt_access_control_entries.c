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

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfwnt_access_control_entries.h"
#include "pyfwnt_access_control_entry.h"
#include "pyfwnt_libcerror.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"

PySequenceMethods pyfwnt_access_control_entries_sequence_methods = {
	/* sq_length */
	(lenfunc) pyfwnt_access_control_entries_len,
	/* sq_concat */
	0,
	/* sq_repeat */
	0,
	/* sq_item */
	(ssizeargfunc) pyfwnt_access_control_entries_getitem,
	/* sq_slice */
	0,
	/* sq_ass_item */
	0,
	/* sq_ass_slice */
	0,
	/* sq_contains */
	0,
	/* sq_inplace_concat */
	0,
	/* sq_inplace_repeat */
	0
};

PyTypeObject pyfwnt_access_control_entries_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwnt.access_control_entries",
	/* tp_basicsize */
	sizeof( pyfwnt_access_control_entries_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwnt_access_control_entries_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	&pyfwnt_access_control_entries_sequence_methods,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_ITER,
	/* tp_doc */
	"pyfwnt sequence and iterator object of access control entries",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	(getiterfunc) pyfwnt_access_control_entries_iter,
	/* tp_iternext */
	(iternextfunc) pyfwnt_access_control_entries_iternext,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyfwnt_access_control_entries_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new access control entries sequence and iterator object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_entries_new(
           PyObject *parent_object,
           PyObject* (*get_item_by_index)(
                        PyObject *parent_object,
                        int index ),
           int number_of_items )
{
	pyfwnt_access_control_entries_t *sequence_object = NULL;
	static char *function                            = "pyfwnt_access_control_entries_new";

	if( parent_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid parent object.",
		 function );

		return( NULL );
	}
	if( get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid get item by index function.",
		 function );

		return( NULL );
	}
	/* Make sure the access control entries values are initialized
	 */
	sequence_object = PyObject_New(
	                   struct pyfwnt_access_control_entries,
	                   &pyfwnt_access_control_entries_type_object );

	if( sequence_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create sequence object.",
		 function );

		goto on_error;
	}
	if( pyfwnt_access_control_entries_init(
	     sequence_object ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize sequence object.",
		 function );

		goto on_error;
	}
	sequence_object->parent_object     = parent_object;
	sequence_object->get_item_by_index = get_item_by_index;
	sequence_object->number_of_items   = number_of_items;

	Py_IncRef(
	 (PyObject *) sequence_object->parent_object );

	return( (PyObject *) sequence_object );

on_error:
	if( sequence_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) sequence_object );
	}
	return( NULL );
}

/* Initializes an access control entries sequence and iterator object
 * Returns 0 if successful or -1 on error
 */
int pyfwnt_access_control_entries_init(
     pyfwnt_access_control_entries_t *sequence_object )
{
	static char *function = "pyfwnt_access_control_entries_init";

	if( sequence_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object.",
		 function );

		return( -1 );
	}
	/* Make sure the access control entries values are initialized
	 */
	sequence_object->parent_object     = NULL;
	sequence_object->get_item_by_index = NULL;
	sequence_object->current_index     = 0;
	sequence_object->number_of_items   = 0;

	PyErr_Format(
	 PyExc_NotImplementedError,
	 "%s: initialize of access control entries not supported.",
	 function );

	return( 0 );
}

/* Frees an access control entries sequence object
 */
void pyfwnt_access_control_entries_free(
      pyfwnt_access_control_entries_t *sequence_object )
{
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwnt_access_control_entries_free";

	if( sequence_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           sequence_object );

	if( ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: missing ob_type.",
		 function );

		return;
	}
	if( ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( sequence_object->parent_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) sequence_object->parent_object );
	}
	ob_type->tp_free(
	 (PyObject*) sequence_object );
}

/* The access control entries len() function
 */
Py_ssize_t pyfwnt_access_control_entries_len(
            pyfwnt_access_control_entries_t *sequence_object )
{
	static char *function = "pyfwnt_access_control_entries_len";

	if( sequence_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object.",
		 function );

		return( -1 );
	}
	return( (Py_ssize_t) sequence_object->number_of_items );
}

/* The access control entries getitem() function
 */
PyObject *pyfwnt_access_control_entries_getitem(
           pyfwnt_access_control_entries_t *sequence_object,
           Py_ssize_t item_index )
{
	PyObject *access_control_entry_object = NULL;
	static char *function                 = "pyfwnt_access_control_entries_getitem";

	if( sequence_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object.",
		 function );

		return( NULL );
	}
	if( sequence_object->get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object - missing get item by index function.",
		 function );

		return( NULL );
	}
	if( sequence_object->number_of_items < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object - invalid number of items.",
		 function );

		return( NULL );
	}
	if( ( item_index < 0 )
	 || ( item_index >= (Py_ssize_t) sequence_object->number_of_items ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid invalid item index value out of bounds.",
		 function );

		return( NULL );
	}
	access_control_entry_object = sequence_object->get_item_by_index(
	                               sequence_object->parent_object,
	                               (int) item_index );

	return( access_control_entry_object );
}

/* The access control entries iter() function
 */
PyObject *pyfwnt_access_control_entries_iter(
           pyfwnt_access_control_entries_t *sequence_object )
{
	static char *function = "pyfwnt_access_control_entries_iter";

	if( sequence_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object.",
		 function );

		return( NULL );
	}
	Py_IncRef(
	 (PyObject *) sequence_object );

	return( (PyObject *) sequence_object );
}

/* The access control entries iternext() function
 */
PyObject *pyfwnt_access_control_entries_iternext(
           pyfwnt_access_control_entries_t *sequence_object )
{
	PyObject *access_control_entry_object = NULL;
	static char *function                 = "pyfwnt_access_control_entries_iternext";

	if( sequence_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object.",
		 function );

		return( NULL );
	}
	if( sequence_object->get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object - missing get item by index function.",
		 function );

		return( NULL );
	}
	if( sequence_object->current_index < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object - invalid current index.",
		 function );

		return( NULL );
	}
	if( sequence_object->number_of_items < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid sequence object - invalid number of items.",
		 function );

		return( NULL );
	}
	if( sequence_object->current_index >= sequence_object->number_of_items )
	{
		PyErr_SetNone(
		 PyExc_StopIteration );

		return( NULL );
	}
	access_control_entry_object = sequence_object->get_item_by_index(
	                               sequence_object->parent_object,
	                               sequence_object->current_index );

	if( access_control_entry_object != NULL )
	{
		sequence_object->current_index++;
	}
	return( access_control_entry_object );
}

