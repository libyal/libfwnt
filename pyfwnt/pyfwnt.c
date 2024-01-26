/*
 * Python bindings module for libfwnt (pyfwnt)
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
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfwnt.h"
#include "pyfwnt_access_control_entries.h"
#include "pyfwnt_access_control_entry.h"
#include "pyfwnt_access_control_list.h"
#include "pyfwnt_access_control_types.h"
#include "pyfwnt_error.h"
#include "pyfwnt_libcerror.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_lznt1.h"
#include "pyfwnt_lzx.h"
#include "pyfwnt_lzxpress.h"
#include "pyfwnt_python.h"
#include "pyfwnt_security_descriptor.h"
#include "pyfwnt_security_identifier.h"
#include "pyfwnt_unused.h"

/* The pyfwnt module methods
 */
PyMethodDef pyfwnt_module_methods[] = {
	{ "get_version",
	  (PyCFunction) pyfwnt_get_version,
	  METH_NOARGS,
	  "get_version() -> String\n"
	  "\n"
	  "Retrieves the version." },

	{ "lznt1_decompress",
	  (PyCFunction) pyfwnt_lznt1_decompress,
	  METH_VARARGS | METH_KEYWORDS,
	  "lznt1_compress(compressed_data, uncompressed_data_size) -> Bytes\n"
	  "\n"
	  "Decompresses data using LZNT1 compression." },

	{ "lzx_decompress",
	  (PyCFunction) pyfwnt_lzx_decompress,
	  METH_VARARGS | METH_KEYWORDS,
	  "lzx_compress(compressed_data, uncompressed_data_size) -> Bytes\n"
	  "\n"
	  "Decompresses data using LZX compression." },

	{ "lzxpress_decompress",
	  (PyCFunction) pyfwnt_lzxpress_decompress,
	  METH_VARARGS | METH_KEYWORDS,
	  "lzxpress_compress(compressed_data, uncompressed_data_size) -> Bytes\n"
	  "\n"
	  "Decompresses data using LZXPRESS compression." },

	{ "lzxpress_huffman_decompress",
	  (PyCFunction) pyfwnt_lzxpress_huffman_decompress,
	  METH_VARARGS | METH_KEYWORDS,
	  "lzxpress_huffman_compress(compressed_data, uncompressed_data_size) -> Bytes\n"
	  "\n"
	  "Decompresses data using LZXPRESS Huffman compression." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

/* Retrieves the pyfwnt/libfwnt version
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_get_version(
           PyObject *self PYFWNT_ATTRIBUTE_UNUSED,
           PyObject *arguments PYFWNT_ATTRIBUTE_UNUSED )
{
	const char *version_string   = NULL;
	size_t version_string_length = 0;

	PYFWNT_UNREFERENCED_PARAMETER( self )
	PYFWNT_UNREFERENCED_PARAMETER( arguments )

	Py_BEGIN_ALLOW_THREADS

	version_string = libfwnt_get_version();

	Py_END_ALLOW_THREADS

	version_string_length = narrow_string_length(
	                         version_string );

	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	return( PyUnicode_DecodeUTF8(
	         version_string,
	         (Py_ssize_t) version_string_length,
	         NULL ) );
}

#if PY_MAJOR_VERSION >= 3

/* The pyfwnt module definition
 */
PyModuleDef pyfwnt_module_definition = {
	PyModuleDef_HEAD_INIT,

	/* m_name */
	"pyfwnt",
	/* m_doc */
	"Python libfwnt module (pyfwnt).",
	/* m_size */
	-1,
	/* m_methods */
	pyfwnt_module_methods,
	/* m_reload */
	NULL,
	/* m_traverse */
	NULL,
	/* m_clear */
	NULL,
	/* m_free */
	NULL,
};

#endif /* PY_MAJOR_VERSION >= 3 */

/* Initializes the pyfwnt module
 */
#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit_pyfwnt(
                void )
#else
PyMODINIT_FUNC initpyfwnt(
                void )
#endif
{
	PyObject *module           = NULL;
	PyGILState_STATE gil_state = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libfwnt_notify_set_stream(
	 stderr,
	 NULL );
	libfwnt_notify_set_verbose(
	 1 );
#endif

	/* Create the module
	 * This function must be called before grabbing the GIL
	 * otherwise the module will segfault on a version mismatch
	 */
#if PY_MAJOR_VERSION >= 3
	module = PyModule_Create(
	          &pyfwnt_module_definition );
#else
	module = Py_InitModule3(
	          "pyfwnt",
	          pyfwnt_module_methods,
	          "Python libfwnt module (pyfwnt)." );
#endif
	if( module == NULL )
	{
#if PY_MAJOR_VERSION >= 3
		return( NULL );
#else
		return;
#endif
	}
#if PY_VERSION_HEX < 0x03070000
	PyEval_InitThreads();
#endif
	gil_state = PyGILState_Ensure();

	/* Setup the access_control_entries type object
	 */
	pyfwnt_access_control_entries_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwnt_access_control_entries_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwnt_access_control_entries_type_object );

	PyModule_AddObject(
	 module,
	 "access_control_entries",
	 (PyObject *) &pyfwnt_access_control_entries_type_object );

	/* Setup the access_control_entry type object
	 */
	pyfwnt_access_control_entry_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwnt_access_control_entry_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwnt_access_control_entry_type_object );

	PyModule_AddObject(
	 module,
	 "access_control_entry",
	 (PyObject *) &pyfwnt_access_control_entry_type_object );

	/* Setup the access_control_list type object
	 */
	pyfwnt_access_control_list_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwnt_access_control_list_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwnt_access_control_list_type_object );

	PyModule_AddObject(
	 module,
	 "access_control_list",
	 (PyObject *) &pyfwnt_access_control_list_type_object );

	/* Setup the access_control_types type object
	 */
	pyfwnt_access_control_types_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwnt_access_control_types_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwnt_access_control_types_type_object );

	PyModule_AddObject(
	 module,
	 "access_control_types",
	 (PyObject *) &pyfwnt_access_control_types_type_object );

	/* Setup the security_descriptor type object
	 */
	pyfwnt_security_descriptor_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwnt_security_descriptor_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwnt_security_descriptor_type_object );

	PyModule_AddObject(
	 module,
	 "security_descriptor",
	 (PyObject *) &pyfwnt_security_descriptor_type_object );

	/* Setup the security_identifier type object
	 */
	pyfwnt_security_identifier_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwnt_security_identifier_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwnt_security_identifier_type_object );

	PyModule_AddObject(
	 module,
	 "security_identifier",
	 (PyObject *) &pyfwnt_security_identifier_type_object );

	PyGILState_Release(
	 gil_state );

#if PY_MAJOR_VERSION >= 3
	return( module );
#else
	return;
#endif

on_error:
	PyGILState_Release(
	 gil_state );

#if PY_MAJOR_VERSION >= 3
	return( NULL );
#else
	return;
#endif
}

