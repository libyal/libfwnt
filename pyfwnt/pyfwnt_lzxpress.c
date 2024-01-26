/*
 * LZXPRESS (un)compression functions
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

#include "pyfwnt_error.h"
#include "pyfwnt_libcerror.h"
#include "pyfwnt_libfwnt.h"
#include "pyfwnt_lzxpress.h"
#include "pyfwnt_python.h"

/* Decompresses data using LZXPRESS compression
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_lzxpress_decompress(
           PyObject *self,
           PyObject *arguments,
           PyObject *keywords )
{
	libcerror_error_t *error                  = NULL;
	PyObject *compressed_data_string_object   = NULL;
	PyObject *uncompressed_data_string_object = NULL;
	static char *function                     = "pyfwnt_lzxpress_decompress";
	static char *keyword_list[]               = { "compressed_data", "uncompressed_data_size", NULL };
	char *compressed_data                     = NULL;
	char *uncompressed_data                   = NULL;
	Py_ssize_t compressed_data_size           = 0;
	size_t safe_uncompressed_data_size        = 0;
	int uncompressed_data_size                = 0;
	int result                                = 0;

	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "O|i",
	     keyword_list,
	     &compressed_data_string_object,
	     &uncompressed_data_size ) == 0 )
	{
		return( NULL );
	}
	if( uncompressed_data_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument uncompressed data size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( uncompressed_data_size > INT_MAX )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument uncompressed data size value exceeds maximum.",
		 function );

		return( NULL );
	}
/* TODO allow uncompressed_data_size to be 0 and estimate uncompressed data size */

#if PY_MAJOR_VERSION >= 3
	compressed_data = PyBytes_AsString(
	                   compressed_data_string_object );

	compressed_data_size = PyBytes_Size(
	                        compressed_data_string_object );
#else
	compressed_data = PyString_AsString(
	                   compressed_data_string_object );

	compressed_data_size = PyString_Size(
	                        compressed_data_string_object );
#endif
	if( ( compressed_data_size < 0 )
	 || ( compressed_data_size > (Py_ssize_t) SSIZE_MAX ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument compressed data size value out of bounds.",
		 function );

		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	uncompressed_data_string_object = PyBytes_FromStringAndSize(
	                                   NULL,
	                                   uncompressed_data_size );

	uncompressed_data = PyBytes_AsString(
	                     uncompressed_data_string_object );
#else
	uncompressed_data_string_object = PyString_FromStringAndSize(
	                                   NULL,
	                                   uncompressed_data_size );

	uncompressed_data = PyString_AsString(
	                     uncompressed_data_string_object );
#endif
	safe_uncompressed_data_size = (size_t) uncompressed_data_size;

	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_lzxpress_decompress(
	          (uint8_t *) compressed_data,
	          (size_t) compressed_data_size,
	          (uint8_t *) uncompressed_data,
	          &safe_uncompressed_data_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to decompress data.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Need to resize the string here in case read_size was not fully read.
	 */
#if PY_MAJOR_VERSION >= 3
	if( _PyBytes_Resize(
	     &uncompressed_data_string_object,
	     (Py_ssize_t) safe_uncompressed_data_size ) != 0 )
#else
	if( _PyString_Resize(
	     &uncompressed_data_string_object,
	     (Py_ssize_t) safe_uncompressed_data_size ) != 0 )
#endif
	{
		goto on_error;
	}
	return( uncompressed_data_string_object );

on_error:
	if( uncompressed_data_string_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) uncompressed_data_string_object );
	}
	return( NULL );
}

/* Decompresses data using LZXPRESS Huffman compression
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwnt_lzxpress_huffman_decompress(
           PyObject *self,
           PyObject *arguments,
           PyObject *keywords )
{
	libcerror_error_t *error                  = NULL;
	PyObject *compressed_data_string_object   = NULL;
	PyObject *uncompressed_data_string_object = NULL;
	static char *function                     = "pyfwnt_lzxpress_huffman_decompress";
	static char *keyword_list[]               = { "compressed_data", "uncompressed_data_size", NULL };
	char *compressed_data                     = NULL;
	char *uncompressed_data                   = NULL;
	Py_ssize_t compressed_data_size           = 0;
	size_t safe_uncompressed_data_size        = 0;
	int uncompressed_data_size                = 0;
	int result                                = 0;

	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "O|i",
	     keyword_list,
	     &compressed_data_string_object,
	     &uncompressed_data_size ) == 0 )
	{
		return( NULL );
	}
	if( uncompressed_data_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument uncompressed data size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( uncompressed_data_size > INT_MAX )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument uncompressed data size value exceeds maximum.",
		 function );

		return( NULL );
	}
/* TODO allow uncompressed_data_size to be 0 and estimate uncompressed data size */

#if PY_MAJOR_VERSION >= 3
	compressed_data = PyBytes_AsString(
	                   compressed_data_string_object );

	compressed_data_size = PyBytes_Size(
	                        compressed_data_string_object );
#else
	compressed_data = PyString_AsString(
	                   compressed_data_string_object );

	compressed_data_size = PyString_Size(
	                        compressed_data_string_object );
#endif
	if( ( compressed_data_size < 0 )
	 || ( compressed_data_size > (Py_ssize_t) SSIZE_MAX ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument compressed data size value out of bounds.",
		 function );

		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	uncompressed_data_string_object = PyBytes_FromStringAndSize(
	                                   NULL,
	                                   uncompressed_data_size );

	uncompressed_data = PyBytes_AsString(
	                     uncompressed_data_string_object );
#else
	uncompressed_data_string_object = PyString_FromStringAndSize(
	                                   NULL,
	                                   uncompressed_data_size );

	uncompressed_data = PyString_AsString(
	                     uncompressed_data_string_object );
#endif
	safe_uncompressed_data_size = (size_t) uncompressed_data_size;

	Py_BEGIN_ALLOW_THREADS

	result = libfwnt_lzxpress_huffman_decompress(
	          (uint8_t *) compressed_data,
	          (size_t) compressed_data_size,
	          (uint8_t *) uncompressed_data,
	          &safe_uncompressed_data_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwnt_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to decompress data.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Need to resize the string here in case read_size was not fully read.
	 */
#if PY_MAJOR_VERSION >= 3
	if( _PyBytes_Resize(
	     &uncompressed_data_string_object,
	     (Py_ssize_t) safe_uncompressed_data_size ) != 0 )
#else
	if( _PyString_Resize(
	     &uncompressed_data_string_object,
	     (Py_ssize_t) safe_uncompressed_data_size ) != 0 )
#endif
	{
		goto on_error;
	}
	return( uncompressed_data_string_object );

on_error:
	if( uncompressed_data_string_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) uncompressed_data_string_object );
	}
	return( NULL );
}

