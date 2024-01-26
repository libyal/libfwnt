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

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfwnt_access_control_entry.h"
#include "pyfwnt_error.h"
#include "pyfwnt_libcerror.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"
#include "pyfwnt_security_identifier.h"
#include "pyfwnt_unused.h"

PyMethodDef pyfwnt_access_control_entry_object_methods[] = {

	{ "get_type",
	  (PyCFunction) pyfwnt_access_control_entry_get_type,
	  METH_NOARGS,
	  "get_type() -> Integer\n"
	  "\n"
	  "Retrieves the type." },

	{ "get_flags",
	  (PyCFunction) pyfwnt_access_control_entry_get_flags,
	  METH_NOARGS,
	  "get_flags() -> Integer\n"
	  "\n"
	  "Retrieves the flags." },

	{ "get_access_mask",
	  (PyCFunction) pyfwnt_access_control_entry_get_access_mask,
	  METH_NOARGS,
	  "get_access_mask() -> Integer or None\n"
	  "\n"
	  "Retrieves the access mask." },

	{ "get_security_identifier",
	  (PyCFunction) pyfwnt_access_control_entry_get_security_identifier,
	  METH_NOARGS,
	  "get_security_identifier() -> Object or None\n"
	  "\n"
	  "Retrieves the security identifier." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwnt_access_control_entry_object_get_set_definitions[] = {

	{ "type",
	  (getter) pyfwnt_access_control_entry_get_type,
	  (setter) 0,
	  "The type.",
	  NULL },

	{ "flags",
	  (getter) pyfwnt_access_control_entry_get_flags,
	  (setter) 0,
	  "The flags.",
	  NULL },

	{ "access_mask",
	  (getter) pyfwnt_access_control_entry_get_access_mask,
	  (setter) 0,
	  "The access mask.",
	  NULL },

	{ "security_identifier",
	  (getter) pyfwnt_access_control_entry_get_security_identifier,
	  (setter) 0,
	  "The security identifier.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwnt_access_control_entry_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwnt.access_control_entry",
	/* tp_basicsize */
	sizeof( pyfwnt_access_control_entry_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwnt_access_control_entry_free,
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
	"pyfwnt access control entry object (wraps libfwnt_access_control_entry_t)",
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
	pyfwnt_access_control_entry_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwnt_access_control_entry_object_get_set_definitions,
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
	(initproc) pyfwnt_access_control_entry_init,
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

/* Creates a new access control entry object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_entry_new(
           libfwnt_access_control_entry_t *access_control_entry,
           PyObject *parent_object )
{
	pyfwnt_access_control_entry_t *pyfwnt_access_control_entry = NULL;
	static char *function                                      = "pyfwnt_access_control_entry_new";

	if( access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entry.",
		 function );

		return( NULL );
	}
	/* PyObject_New does not invoke tp_init
	 */
	pyfwnt_access_control_entry = PyObject_New(
	                               struct pyfwnt_access_control_entry,
	                               &pyfwnt_access_control_entry_type_object );

	if( pyfwnt_access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize access control entry.",
		 function );

		goto on_error;
	}
	pyfwnt_access_control_entry->access_control_entry = access_control_entry;
	pyfwnt_access_control_entry->parent_object        = parent_object;

	if( pyfwnt_access_control_entry->parent_object != NULL )
	{
		Py_IncRef(
		 pyfwnt_access_control_entry->parent_object );
	}
	return( (PyObject *) pyfwnt_access_control_entry );

on_error:
	if( pyfwnt_access_control_entry != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwnt_access_control_entry );
	}
	return( NULL );
}

/* Initializes an access control entry object
 * Returns 0 if successful or -1 on error
 */
int pyfwnt_access_control_entry_init(
     pyfwnt_access_control_entry_t *pyfwnt_access_control_entry )
{
	static char *function = "pyfwnt_access_control_entry_init";

	if( pyfwnt_access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entry.",
		 function );

		return( -1 );
	}
	/* Make sure libfwnt access control entry is set to NULL
	 */
	pyfwnt_access_control_entry->access_control_entry = NULL;

	PyErr_Format(
	 PyExc_NotImplementedError,
	 "%s: initialize of access control entry not supported.",
	 function );

	return( -1 );
}

/* Frees an access control entry object
 */
void pyfwnt_access_control_entry_free(
      pyfwnt_access_control_entry_t *pyfwnt_access_control_entry )
{
	struct _typeobject *ob_type = NULL;
	libcerror_error_t *error    = NULL;
	static char *function       = "pyfwnt_access_control_entry_free";
	int result                  = 0;

	if( pyfwnt_access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entry.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwnt_access_control_entry );

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
	if( pyfwnt_access_control_entry->access_control_entry != NULL )
	{
		Py_BEGIN_ALLOW_THREADS

		result = libfwnt_access_control_entry_free(
		          &( pyfwnt_access_control_entry->access_control_entry ),
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyfwnt_error_raise(
			 error,
			 PyExc_MemoryError,
			 "%s: unable to free libfwnt access control entry.",
			 function );

			libcerror_error_free(
			 &error );
		}
	}
	if( pyfwnt_access_control_entry->parent_object != NULL )
	{
		Py_DecRef(
		 pyfwnt_access_control_entry->parent_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwnt_access_control_entry );
}

/* Retrieves the type
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_entry_get_type(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwnt_access_control_entry_get_type";
	uint8_t type             = 0;
	int result               = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entry.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_access_control_entry_get_type(
	          pyfwnt_access_control_entry->access_control_entry,
	          &type,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve type.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	integer_object = PyLong_FromLong(
	                  (long) type );
#else
	integer_object = PyInt_FromLong(
	                  (long) type );
#endif
	return( integer_object );
}

/* Retrieves the flags
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_entry_get_flags(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwnt_access_control_entry_get_flags";
	uint8_t flags            = 0;
	int result               = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entry.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_access_control_entry_get_flags(
	          pyfwnt_access_control_entry->access_control_entry,
	          &flags,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve flags.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	integer_object = PyLong_FromLong(
	                  (long) flags );
#else
	integer_object = PyInt_FromLong(
	                  (long) flags );
#endif
	return( integer_object );
}

/* Retrieves the access mask
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_entry_get_access_mask(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwnt_access_control_entry_get_access_mask";
	uint32_t value_32bit     = 0;
	int result               = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entry.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_access_control_entry_get_access_mask(
	          pyfwnt_access_control_entry->access_control_entry,
	          &value_32bit,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve access mask.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	else if( result == 0 )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	integer_object = PyLong_FromUnsignedLong(
	                  (unsigned long) value_32bit );

	return( integer_object );
}

/* Retrieves the security identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_access_control_entry_get_security_identifier(
           pyfwnt_access_control_entry_t *pyfwnt_access_control_entry,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	PyObject *security_identifier_object               = NULL;
	libcerror_error_t *error                           = NULL;
	libfwnt_security_identifier_t *security_identifier = NULL;
	static char *function                              = "pyfwnt_access_control_entry_get_security_identifier";
	int result                                         = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_access_control_entry == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid access control entry.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_access_control_entry_get_security_identifier(
	          pyfwnt_access_control_entry->access_control_entry,
	          &security_identifier,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve security identifier.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( result == 0 )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	security_identifier_object = pyfwnt_security_identifier_new(
	                              security_identifier,
	                              (PyObject *) pyfwnt_access_control_entry );

	if( security_identifier_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create security identifier object.",
		 function );

		goto on_error;
	}
	return( security_identifier_object );

on_error:
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( NULL );
}

