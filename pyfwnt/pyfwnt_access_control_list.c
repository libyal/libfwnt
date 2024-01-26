/*
 * Python object wrapper of libfwnt_access_control_list_t
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
#include "pyfwnt_access_control_list.h"
#include "pyfwnt_error.h"
#include "pyfwnt_libcerror.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"
#include "pyfwnt_unused.h"

PyMethodDef pyfwnt_access_control_list_object_methods[] = {

	{ "get_number_of_entries",
	  (PyCFunction) pyfwnt_access_control_list_get_number_of_entries,
	  METH_NOARGS,
	  "get_number_of_entries() -> Integer\n"
	  "\n"
	  "Retrieves the number of access control entries." },

	{ "get_entry",
	  (PyCFunction) pyfwnt_access_control_list_get_entry,
	  METH_VARARGS | METH_KEYWORDS,
	  "get_entry(entry_index) -> Object\n"
	  "\n"
	  "Retrieves the access control entry specified by the index." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwnt_access_control_list_object_get_set_definitions[] = {

	{ "number_of_entries",
	  (getter) pyfwnt_access_control_list_get_number_of_entries,
	  (setter) 0,
	  "The number of access control entries.",
	  NULL },

	{ "entries",
	  (getter) pyfwnt_access_control_list_get_entries,
	  (setter) 0,
	  "The access control entries.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwnt_access_control_list_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwnt.access_control_list",
	/* tp_basicsize */
	sizeof( pyfwnt_access_control_list_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwnt_access_control_list_free,
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
	0,
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
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyfwnt access control list object (wraps libfwnt_access_control_list_t)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	pyfwnt_access_control_list_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwnt_access_control_list_object_get_set_definitions,
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
	(initproc) pyfwnt_access_control_list_init,
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

/* Creates a new access control list object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_list_new(
           libfwnt_access_control_list_t *access_control_list,
           PyObject *parent_object )
{
	pyfwnt_access_control_list_t *pyfwnt_access_control_list = NULL;
	static char *function                                    = "pyfwnt_access_control_list_new";

	if( access_control_list == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control list.",
		 function );

		return( NULL );
	}
	/* PyObject_New does not invoke tp_init
	 */
	pyfwnt_access_control_list = PyObject_New(
	                              struct pyfwnt_access_control_list,
	                              &pyfwnt_access_control_list_type_object );

	if( pyfwnt_access_control_list == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize access control list.",
		 function );

		goto on_error;
	}
	pyfwnt_access_control_list->access_control_list = access_control_list;
	pyfwnt_access_control_list->parent_object       = parent_object;

	if( pyfwnt_access_control_list->parent_object != NULL )
	{
		Py_IncRef(
		 pyfwnt_access_control_list->parent_object );
	}
	return( (PyObject *) pyfwnt_access_control_list );

on_error:
	if( pyfwnt_access_control_list != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwnt_access_control_list );
	}
	return( NULL );
}

/* Initializes an access control list object
 * Returns 0 if successful or -1 on error
 */
int pyfwnt_access_control_list_init(
     pyfwnt_access_control_list_t *pyfwnt_access_control_list )
{
	static char *function = "pyfwnt_access_control_list_init";

	if( pyfwnt_access_control_list == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control list.",
		 function );

		return( -1 );
	}
	/* Make sure libfwnt access control list is set to NULL
	 */
	pyfwnt_access_control_list->access_control_list = NULL;

	PyErr_Format(
	 PyExc_NotImplementedError,
	 "%s: initialize of access control list not supported.",
	 function );

	return( -1 );
}

/* Frees an access control list object
 */
void pyfwnt_access_control_list_free(
      pyfwnt_access_control_list_t *pyfwnt_access_control_list )
{
	struct _typeobject *ob_type = NULL;
	libcerror_error_t *error    = NULL;
	static char *function       = "pyfwnt_access_control_list_free";
	int result                  = 0;

	if( pyfwnt_access_control_list == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control list.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwnt_access_control_list );

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
	if( pyfwnt_access_control_list->access_control_list != NULL )
	{
		Py_BEGIN_ALLOW_THREADS

		result = libfwnt_access_control_list_free(
		          &( pyfwnt_access_control_list->access_control_list ),
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyfwnt_error_raise(
			 error,
			 PyExc_MemoryError,
			 "%s: unable to free libfwnt access control list.",
			 function );

			libcerror_error_free(
			 &error );
		}
	}
	if( pyfwnt_access_control_list->parent_object != NULL )
	{
		Py_DecRef(
		 pyfwnt_access_control_list->parent_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwnt_access_control_list );
}

/* Retrieves the number of access control entries
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_list_get_number_of_entries(
           pyfwnt_access_control_list_t *pyfwnt_access_control_list,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwnt_access_control_list_get_number_of_entries";
	int number_of_entries    = 0;
	int result               = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_access_control_list == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control list.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_access_control_list_get_number_of_entries(
	          pyfwnt_access_control_list->access_control_list,
	          &number_of_entries,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve number of access control entries.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	integer_object = PyLong_FromLong(
	                  (long) number_of_entries );
#else
	integer_object = PyInt_FromLong(
	                  (long) number_of_entries );
#endif
	return( integer_object );
}

/* Retrieves a specific access control entry by index
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_list_get_entry_by_index(
           PyObject *pyfwnt_access_control_list,
           int entry_index )
{
	PyObject *entry_object                = NULL;
	libcerror_error_t *error              = NULL;
	libfwnt_access_control_entry_t *entry = NULL;
	static char *function                 = "pyfwnt_access_control_list_get_entry_by_index";
	int result                            = 0;

	if( pyfwnt_access_control_list == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control list.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_access_control_list_get_entry_by_index(
	          ( (pyfwnt_access_control_list_t *) pyfwnt_access_control_list )->access_control_list,
	          entry_index,
	          &entry,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve access control entry: %d.",
		 function,
		 entry_index );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	entry_object = pyfwnt_access_control_entry_new(
	                entry,
	                pyfwnt_access_control_list );

	if( entry_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create access control entry object.",
		 function );

		goto on_error;
	}
	return( entry_object );

on_error:
	if( entry != NULL )
	{
		libfwnt_access_control_entry_free(
		 &entry,
		 NULL );
	}
	return( NULL );
}

/* Retrieves a specific access control entry
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_list_get_entry(
           pyfwnt_access_control_list_t *pyfwnt_access_control_list,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *entry_object      = NULL;
	static char *keyword_list[] = { "entry_index", NULL };
	int entry_index             = 0;

	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "i",
	     keyword_list,
	     &entry_index ) == 0 )
	{
		return( NULL );
	}
	entry_object = pyfwnt_access_control_list_get_entry_by_index(
	                (PyObject *) pyfwnt_access_control_list,
	                entry_index );

	return( entry_object );
}

/* Retrieves a sequence and iterator object for the entries
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_list_get_entries(
           pyfwnt_access_control_list_t *pyfwnt_access_control_list,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	PyObject *sequence_object = NULL;
	libcerror_error_t *error  = NULL;
	static char *function     = "pyfwnt_access_control_list_get_entries";
	int number_of_entries     = 0;
	int result                = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_access_control_list == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control list.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_access_control_list_get_number_of_entries(
	          pyfwnt_access_control_list->access_control_list,
	          &number_of_entries,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve number of entries.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	sequence_object = pyfwnt_access_control_entries_new(
	                   (PyObject *) pyfwnt_access_control_list,
	                   &pyfwnt_access_control_list_get_entry_by_index,
	                   number_of_entries );

	if( sequence_object == NULL )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to create sequence object.",
		 function );

		return( NULL );
	}
	return( sequence_object );
}

