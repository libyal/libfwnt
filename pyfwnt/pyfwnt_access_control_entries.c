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

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfwnt_access_control_entries.h"
#include "pyfwnt_access_control_entry.h"
#include "pyfwnt_access_control_list.h"
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
	"pyfwnt._access_control_entries",
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
	"internal pyfwnt access control entries sequence and iterator object",
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

/* Creates a new access control entries object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_entries_new(
           pyfwnt_access_control_list_t *access_control_list_object,
           PyObject* (*get_entry_by_index)(
                        pyfwnt_access_control_list_t *access_control_list_object,
                        int entry_index ),
           int number_of_entries )
{
	pyfwnt_access_control_entries_t *pyfwnt_access_control_entries = NULL;
	static char *function                                          = "pyfwnt_access_control_entries_new";

	if( access_control_list_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control list object.",
		 function );

		return( NULL );
	}
	if( get_entry_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid get entry by index function.",
		 function );

		return( NULL );
	}
	/* Make sure the access control entries values are initialized
	 */
	pyfwnt_access_control_entries = PyObject_New(
	                 struct pyfwnt_access_control_entries,
	                 &pyfwnt_access_control_entries_type_object );

	if( pyfwnt_access_control_entries == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize access control entries.",
		 function );

		goto on_error;
	}
	if( pyfwnt_access_control_entries_init(
	     pyfwnt_access_control_entries ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize access control entries.",
		 function );

		goto on_error;
	}
	pyfwnt_access_control_entries->access_control_list_object = access_control_list_object;
	pyfwnt_access_control_entries->get_entry_by_index         = get_entry_by_index;
	pyfwnt_access_control_entries->number_of_entries          = number_of_entries;

	Py_IncRef(
	 (PyObject *) pyfwnt_access_control_entries->access_control_list_object );

	return( (PyObject *) pyfwnt_access_control_entries );

on_error:
	if( pyfwnt_access_control_entries != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwnt_access_control_entries );
	}
	return( NULL );
}

/* Intializes a access control entries object
 * Returns 0 if successful or -1 on error
 */
int pyfwnt_access_control_entries_init(
     pyfwnt_access_control_entries_t *pyfwnt_access_control_entries )
{
	static char *function = "pyfwnt_access_control_entries_init";

	if( pyfwnt_access_control_entries == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries.",
		 function );

		return( -1 );
	}
	/* Make sure the access control entries values are initialized
	 */
	pyfwnt_access_control_entries->access_control_list_object = NULL;
	pyfwnt_access_control_entries->get_entry_by_index         = NULL;
	pyfwnt_access_control_entries->entry_index                = 0;
	pyfwnt_access_control_entries->number_of_entries          = 0;

	return( 0 );
}

/* Frees a access control entries object
 */
void pyfwnt_access_control_entries_free(
      pyfwnt_access_control_entries_t *pyfwnt_access_control_entries )
{
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwnt_access_control_entries_free";

	if( pyfwnt_access_control_entries == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwnt_access_control_entries );

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
	if( pyfwnt_access_control_entries->access_control_list_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwnt_access_control_entries->access_control_list_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwnt_access_control_entries );
}

/* The access control entries len() function
 */
Py_ssize_t pyfwnt_access_control_entries_len(
            pyfwnt_access_control_entries_t *pyfwnt_access_control_entries )
{
	static char *function = "pyfwnt_access_control_entries_len";

	if( pyfwnt_access_control_entries == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries.",
		 function );

		return( -1 );
	}
	return( (Py_ssize_t) pyfwnt_access_control_entries->number_of_entries );
}

/* The access control entries getitem() function
 */
PyObject *pyfwnt_access_control_entries_getitem(
           pyfwnt_access_control_entries_t *pyfwnt_access_control_entries,
           Py_ssize_t item_index )
{
	PyObject *entry_object = NULL;
	static char *function  = "pyfwnt_access_control_entries_getitem";

	if( pyfwnt_access_control_entries == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries.",
		 function );

		return( NULL );
	}
	if( pyfwnt_access_control_entries->get_entry_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries - missing get entry by index function.",
		 function );

		return( NULL );
	}
	if( pyfwnt_access_control_entries->number_of_entries < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries - invalid number of entries.",
		 function );

		return( NULL );
	}
	if( ( item_index < 0 )
	 || ( item_index >= (Py_ssize_t) pyfwnt_access_control_entries->number_of_entries ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid invalid item index value out of bounds.",
		 function );

		return( NULL );
	}
	entry_object = pyfwnt_access_control_entries->get_entry_by_index(
	                pyfwnt_access_control_entries->access_control_list_object,
	                (int) item_index );

	return( entry_object );
}

/* The access control entries iter() function
 */
PyObject *pyfwnt_access_control_entries_iter(
           pyfwnt_access_control_entries_t *pyfwnt_access_control_entries )
{
	static char *function = "pyfwnt_access_control_entries_iter";

	if( pyfwnt_access_control_entries == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries.",
		 function );

		return( NULL );
	}
	Py_IncRef(
	 (PyObject *) pyfwnt_access_control_entries );

	return( (PyObject *) pyfwnt_access_control_entries );
}

/* The access control entries iternext() function
 */
PyObject *pyfwnt_access_control_entries_iternext(
           pyfwnt_access_control_entries_t *pyfwnt_access_control_entries )
{
	PyObject *entry_object = NULL;
	static char *function  = "pyfwnt_access_control_entries_iternext";

	if( pyfwnt_access_control_entries == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries.",
		 function );

		return( NULL );
	}
	if( pyfwnt_access_control_entries->get_entry_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries - missing get entry by index function.",
		 function );

		return( NULL );
	}
	if( pyfwnt_access_control_entries->entry_index < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries - invalid entry index.",
		 function );

		return( NULL );
	}
	if( pyfwnt_access_control_entries->number_of_entries < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entries - invalid number of entries.",
		 function );

		return( NULL );
	}
	if( pyfwnt_access_control_entries->entry_index >= pyfwnt_access_control_entries->number_of_entries )
	{
		PyErr_SetNone(
		 PyExc_StopIteration );

		return( NULL );
	}
	entry_object = pyfwnt_access_control_entries->get_entry_by_index(
	                pyfwnt_access_control_entries->access_control_list_object,
	                pyfwnt_access_control_entries->entry_index );

	if( entry_object != NULL )
	{
		pyfwnt_access_control_entries->entry_index++;
	}
	return( entry_object );
}

