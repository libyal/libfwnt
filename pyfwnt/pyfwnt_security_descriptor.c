/*
 * Python object wrapper of libfwnt_security_descriptor_t
 *
 * Copyright (C) 2009-2018, Joachim Metz <joachim.metz@gmail.com>
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

#include "pyfwnt_access_control_list.h"
#include "pyfwnt_error.h"
#include "pyfwnt_libcerror.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_python.h"
#include "pyfwnt_security_descriptor.h"
#include "pyfwnt_security_identifier.h"
#include "pyfwnt_unused.h"

PyMethodDef pyfwnt_security_descriptor_object_methods[] = {

	{ "copy_from_byte_stream",
	  (PyCFunction) pyfwnt_security_descriptor_copy_from_byte_stream,
	  METH_VARARGS | METH_KEYWORDS,
	  "copy_from_byte_stream(byte_stream)\n"
	  "\n"
	  "Copies the the security descriptor from the byte stream." },

	/* Functions to access the security identifier */

	{ "get_owner",
	  (PyCFunction) pyfwnt_security_descriptor_get_owner,
	  METH_NOARGS,
	  "get_owner() -> Object or None\n"
	  "\n"
	  "Retrieves the owner security identifier (SID)." },

	{ "get_group",
	  (PyCFunction) pyfwnt_security_descriptor_get_group,
	  METH_NOARGS,
	  "get_group() -> Object or None\n"
	  "\n"
	  "Retrieves the group security identifier (SID)." },

	{ "get_discretionary_acl",
	  (PyCFunction) pyfwnt_security_descriptor_get_discretionary_acl,
	  METH_NOARGS,
	  "get_discretionary_acl() -> Object or None\n"
	  "\n"
	  "Retrieves the discretionary access control list (ACL)." },

	{ "get_system_acl",
	  (PyCFunction) pyfwnt_security_descriptor_get_system_acl,
	  METH_NOARGS,
	  "get_system_acl() -> Object or None\n"
	  "\n"
	  "Retrieves the system access control list (ACL)." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwnt_security_descriptor_object_get_set_definitions[] = {

	{ "owner",
	  (getter) pyfwnt_security_descriptor_get_owner,
	  (setter) 0,
	  "The owner security identifier (SID).",
	  NULL },

	{ "group",
	  (getter) pyfwnt_security_descriptor_get_group,
	  (setter) 0,
	  "The group security identifier (SID).",
	  NULL },

	{ "discretionary_acl",
	  (getter) pyfwnt_security_descriptor_get_discretionary_acl,
	  (setter) 0,
	  "The discretionary access control list (ACL).",
	  NULL },

	{ "system_acl",
	  (getter) pyfwnt_security_descriptor_get_system_acl,
	  (setter) 0,
	  "The system access control list (ACL).",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwnt_security_descriptor_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwnt.security_descriptor",
	/* tp_basicsize */
	sizeof( pyfwnt_security_descriptor_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwnt_security_descriptor_free,
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
	"pyfwnt security descriptor object (wraps libfwnt_security_descriptor_t)",
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
	pyfwnt_security_descriptor_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwnt_security_descriptor_object_get_set_definitions,
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
	(initproc) pyfwnt_security_descriptor_init,
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

/* Intializes a security descriptor object
 * Returns 0 if successful or -1 on error
 */
int pyfwnt_security_descriptor_init(
     pyfwnt_security_descriptor_t *pyfwnt_security_descriptor )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwnt_security_descriptor_init";

	if( pyfwnt_security_descriptor == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid security descriptor.",
		 function );

		return( -1 );
	}
	/* Make sure libfwnt security descriptor is set to NULL
	 */
	pyfwnt_security_descriptor->security_descriptor = NULL;

	if( libfwnt_security_descriptor_initialize(
	     &( pyfwnt_security_descriptor->security_descriptor ),
	     &error ) != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to initialize security descriptor.",
		 function );

		libcerror_error_free(
		 &error );

		return( -1 );
	}
	return( 0 );
}

/* Frees a security descriptor object
 */
void pyfwnt_security_descriptor_free(
      pyfwnt_security_descriptor_t *pyfwnt_security_descriptor )
{
	libcerror_error_t *error    = NULL;
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwnt_security_descriptor_free";
	int result                  = 0;

	if( pyfwnt_security_descriptor == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid security descriptor.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwnt_security_descriptor );

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
	if( pyfwnt_security_descriptor->security_descriptor != NULL )
	{
		Py_BEGIN_ALLOW_THREADS

		result = libfwnt_security_descriptor_free(
		          &( pyfwnt_security_descriptor->security_descriptor ),
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyfwnt_error_raise(
			 error,
			 PyExc_MemoryError,
			 "%s: unable to free security descriptor.",
			 function );

			libcerror_error_free(
			 &error );
		}
	}
	ob_type->tp_free(
	 (PyObject*) pyfwnt_security_descriptor );
}

/* Copies the security descriptor from a byte stream
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_security_descriptor_copy_from_byte_stream(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *string_object     = NULL;
	libcerror_error_t *error    = NULL;
	static char *function       = "pyfwnt_security_descriptor_copy_from_byte_stream";
	static char *keyword_list[] = { "byte_stream", NULL };
	const char *byte_stream     = NULL;
	Py_ssize_t byte_stream_size = 0;
	int result                  = 0;

	if( pyfwnt_security_descriptor == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid security descriptor.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "O",
	     keyword_list,
	     &string_object ) == 0 )
	{
		return( NULL );
	}
	PyErr_Clear();

#if PY_MAJOR_VERSION >= 3
	result = PyObject_IsInstance(
		  string_object,
		  (PyObject *) &PyBytes_Type );
#else
	result = PyObject_IsInstance(
		  string_object,
		  (PyObject *) &PyString_Type );
#endif
	if( result == -1 )
	{
		pyfwnt_error_fetch_and_raise(
	         PyExc_RuntimeError,
		 "%s: unable to determine if string object is of type string.",
		 function );

		return( NULL );
	}
	else if( result == 0 )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: unsupported string object type",
		 function );

		return( NULL );
	}
	PyErr_Clear();

#if PY_MAJOR_VERSION >= 3
	byte_stream = PyBytes_AsString(
	               string_object );

	byte_stream_size = PyBytes_Size(
	                    string_object );
#else
	byte_stream = PyString_AsString(
	               string_object );

	byte_stream_size = PyString_Size(
	                    string_object );
#endif
/* TODO size bounds check */

	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_security_descriptor_copy_from_byte_stream(
	          pyfwnt_security_descriptor->security_descriptor,
	          (uint8_t *) byte_stream,
	          (size_t) byte_stream_size,
	          LIBFWNT_ENDIAN_LITTLE,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to copy security descriptor from byte stream.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );
}

/* Retrieves the owner security identifier (SID)
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_security_descriptor_get_owner(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	libfwnt_security_identifier_t *security_identifier = NULL;
	libcerror_error_t *error                           = NULL;
	static char *function                              = "pyfwnt_security_descriptor_get_owner";
	int result                                         = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_security_descriptor == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid security descriptor.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_security_descriptor_get_owner(
	          pyfwnt_security_descriptor->security_descriptor,
	          &security_identifier,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve owner security identifier.",
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
	return( pyfwnt_security_identifier_new(
	         security_identifier,
	         (PyObject *) pyfwnt_security_descriptor ) );

on_error:
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( NULL );
}

/* Retrieves the group security identifier (SID)
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_security_descriptor_get_group(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	libfwnt_security_identifier_t *security_identifier = NULL;
	libcerror_error_t *error                           = NULL;
	static char *function                              = "pyfwnt_security_descriptor_get_group";
	int result                                         = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_security_descriptor == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid security descriptor.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_security_descriptor_get_group(
	          pyfwnt_security_descriptor->security_descriptor,
	          &security_identifier,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve group security identifier.",
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
	return( pyfwnt_security_identifier_new(
	         security_identifier,
	         (PyObject *) pyfwnt_security_descriptor ) );

on_error:
	if( security_identifier != NULL )
	{
		libfwnt_security_identifier_free(
		 &security_identifier,
		 NULL );
	}
	return( NULL );
}

/* Retrieves the discretionary access control list (ACL)
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_security_descriptor_get_discretionary_acl(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	libfwnt_access_control_list_t *access_control_list = NULL;
	libcerror_error_t *error                           = NULL;
	static char *function                              = "pyfwnt_security_descriptor_get_discretionary_acl";
	int result                                         = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_security_descriptor == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid security descriptor.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_security_descriptor_get_discretionary_acl(
	          pyfwnt_security_descriptor->security_descriptor,
	          &access_control_list,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve discretionary access control list.",
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
	return( pyfwnt_access_control_list_new(
	         access_control_list,
	         (PyObject *) pyfwnt_security_descriptor ) );

on_error:
	if( access_control_list != NULL )
	{
		libfwnt_access_control_list_free(
		 &access_control_list,
		 NULL );
	}
	return( NULL );
}

/* Retrieves the system access control list (ACL)
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_security_descriptor_get_system_acl(
           pyfwnt_security_descriptor_t *pyfwnt_security_descriptor,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	libfwnt_access_control_list_t *access_control_list = NULL;
	libcerror_error_t *error                           = NULL;
	static char *function                              = "pyfwnt_security_descriptor_get_system_acl";
	int result                                         = 0;

	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	if( pyfwnt_security_descriptor == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid security descriptor.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_security_descriptor_get_system_acl(
	          pyfwnt_security_descriptor->security_descriptor,
	          &access_control_list,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve system access control list.",
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
	return( pyfwnt_access_control_list_new(
	         access_control_list,
	         (PyObject *) pyfwnt_security_descriptor ) );

on_error:
	if( access_control_list != NULL )
	{
		libfwnt_access_control_list_free(
		 &access_control_list,
		 NULL );
	}
	return( NULL );
}

