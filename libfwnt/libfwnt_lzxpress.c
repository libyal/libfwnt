/*
 * LZXPRESS (de)compression functions
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

#include <common.h>
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwnt_bit_stream.h"
#include "libfwnt_libcerror.h"
#include "libfwnt_libcnotify.h"
#include "libfwnt_lzxpress.h"

/* Determines the uncompressed data size from the LZXPRESS (LZ77 + DIRECT2) compressed data
 * Return 1 on success or -1 on error
 */
int libfwnt_lzxpress_get_uncompressed_data_size(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     size_t *uncompressed_data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwnt_lzxpress_get_uncompressed_data_size";

	if( compressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data.",
		 function );

		return( -1 );
	}
	if( compressed_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid compressed data size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( uncompressed_data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid uncompressed data size.",
		 function );

		return( -1 );
	}
	if( compressed_data_size <= 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: compressed data size value too small.",
		 function );

		return( -1 );
	}
	/* The uncompressed data size is: ( ( compressed data size - 1 ) * 2 ) + 2
	 * The first byte in the compressed data contains a bitmask no data.
	 * Every other compressed byte is uncompressed as an UTF-16 little-endian
	 * character. An additional end of string characters is added.
	 */
	*uncompressed_data_size = compressed_data_size * 2;

	return( 1 );
}

/* Compresses data using LZXPRESS (LZ77 + DIRECT2) compression
 * Returns 1 on success or -1 on error
 */
int libfwnt_lzxpress_compress(
     const uint8_t *uncompressed_data,
     size_t uncompressed_data_size,
     uint8_t *compressed_data,
     size_t *compressed_data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwnt_lzxpress_compress";

	if( uncompressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid uncompressed data.",
		 function );

		return( -1 );
	}
	if( uncompressed_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid uncompressed data size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( compressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data.",
		 function );

		return( -1 );
	}
	if( compressed_data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data size.",
		 function );

		return( -1 );
	}
/* TODO implement */
	return( -1 );
}

/* Decompresses data using LZXPRESS (LZ77 + DIRECT2) compression
 * Return 1 on success or -1 on error
 */
int libfwnt_lzxpress_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libcerror_error_t **error )
{
	static char *function                  = "libfwnt_lzxpress_decompress";
	size_t compressed_data_index           = 0;
	size_t compression_index               = 0;
	size_t compression_shared_byte_index   = 0;
	size_t uncompressed_data_index         = 0;
	uint32_t compression_indicator         = 0;
	uint32_t compression_indicator_bitmask = 0;
	uint16_t compression_size              = 0;
	uint16_t compression_tuple             = 0;
	int16_t compression_offset             = 0;

	if( compressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data.",
		 function );

		return( -1 );
	}
	if( compressed_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid compressed data size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( uncompressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid uncompressed data.",
		 function );

		return( -1 );
	}
	if( uncompressed_data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid uncompressed data size.",
		 function );

		return( -1 );
	}
	if( compressed_data_size <= 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: compressed data size value too small.",
		 function );

		return( -1 );
	}
	if( *uncompressed_data_size < ( 2 * compressed_data_size ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: uncompressed data size value too small.",
		 function );

		return( -1 );
	}
	while( compressed_data_index < compressed_data_size )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( compressed_data[ compressed_data_index ] ),
		 compression_indicator );

		compressed_data_index += 4;

		for( compression_indicator_bitmask = 0x80000000UL;
		     compression_indicator_bitmask > 0;
		     compression_indicator_bitmask >>= 1 )
		{
			if( compressed_data_index >= compressed_data_size )
			{
				break;
			}
			/* If the indicator bit is 0 the data is uncompressed
			 * or 1 if the data is compressed
			 */
			if( ( compression_indicator & compression_indicator_bitmask ) != 0 )
			{
				if( compressed_data_index >= ( compressed_data_size - 1 ) )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
					 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
					 "%s: compressed data too small.",
					 function );

					*uncompressed_data_size = uncompressed_data_index;

					return( -1 );
				}
		                byte_stream_copy_to_uint16_little_endian(
		                 &( compressed_data[ compressed_data_index ] ),
		                 compression_tuple );

				compressed_data_index += 2;

				/* The compression tuple contains:
				 * 0 - 2	the size
				 * 3 - 15	the offset - 1
				 */
				compression_size   = ( compression_tuple & 0x0007 );
				compression_offset = ( compression_tuple >> 3 ) + 1;

				/* Check for a first level extended size
				 * stored in the 4-bits of a shared extended compression size byte
				 * the size is added to the previous size
				 */
				if( compression_size == 0x07 )
				{
					if( compression_shared_byte_index == 0 )
					{
						if( compressed_data_index >= compressed_data_size )
						{
							libcerror_error_set(
							 error,
							 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
							 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
							 "%s: compressed data too small.",
							 function );

							*uncompressed_data_size = uncompressed_data_index;

							return( -1 );
						}
						compression_size += compressed_data[ compressed_data_index ] & 0x0f;

						compression_shared_byte_index = compressed_data_index++;
					}
					else
					{
						compression_size += compressed_data[ compression_shared_byte_index ] >> 4;

						compression_shared_byte_index = 0;
					}
				}
				/* Check for a second level extended size
				 * stored in the 8-bits of the next byte
				 * the size is added to the previous size
				 */
				if( compression_size == ( 0x07 + 0x0f ) )
				{
					if( compressed_data_index >= compressed_data_size )
					{
						libcerror_error_set(
						 error,
						 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
						 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
						 "%s: compressed data too small.",
						 function );

						*uncompressed_data_size = uncompressed_data_index;

						return( -1 );
					}
					compression_size += compressed_data[ compressed_data_index++ ];
				}
				/* Check for a third level extended size
				 * stored in the 16-bits of the next two bytes
				 * the previous size is ignored
				 */
				if( compression_size == ( 0x07 + 0x0f + 0xff ) )
				{
					if( compressed_data_index >= ( compressed_data_size - 1 ) )
					{
						libcerror_error_set(
						 error,
						 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
						 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
						 "%s: compressed data too small.",
						 function );

						*uncompressed_data_size = uncompressed_data_index;

						return( -1 );
					}
			                byte_stream_copy_to_uint16_little_endian(
			                 &( compressed_data[ compressed_data_index ] ),
			                 compression_size );
		
					compressed_data_index += 2;

				}
				/* The size value is stored as
				 * size - 3
				 */
				compression_size += 3;

				if( compression_size > 32771 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
					 "%s: compression size value out of bounds.",
					 function );

					*uncompressed_data_size = uncompressed_data_index;

					return( -1 );
				}
				compression_index = uncompressed_data_index - compression_offset;

				while( compression_size > 0 )
				{
					if( compression_index > uncompressed_data_index )
					{
						libcerror_error_set(
						 error,
						 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
						 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
						 "%s: invalid compressed data at offset: %" PRIzd " - compression index: %" PRIzd " out of range: %" PRIzd ".",
						 function,
						 compressed_data_index,
						 compression_index,
						 uncompressed_data_index );

						*uncompressed_data_size = uncompressed_data_index;

						return( -1 );
					}
					if( uncompressed_data_index > *uncompressed_data_size )
					{
						libcerror_error_set(
						 error,
						 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
						 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
						 "%s: uncompressed data too small.",
						 function );

						*uncompressed_data_size = uncompressed_data_index;

						return( -1 );
					}
					uncompressed_data[ uncompressed_data_index++ ] = uncompressed_data[ compression_index++ ];

					compression_size--;
				}
			}
			else
			{
				if( compressed_data_index >= compressed_data_size )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
					 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
					 "%s: compressed data too small.",
					 function );

					*uncompressed_data_size = uncompressed_data_index;

					return( -1 );
				}
				if( uncompressed_data_index > *uncompressed_data_size )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
					 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
					 "%s: uncompressed data too small.",
					 function );

					*uncompressed_data_size = uncompressed_data_index;

					return( -1 );
				}
				uncompressed_data[ uncompressed_data_index++ ] = compressed_data[ compressed_data_index++ ];
			}
		}
	}
	*uncompressed_data_size = uncompressed_data_index;

	return( 1 );
}

/* Copmares two Huffman code symbols
 * Returns 1 if the first symbol is larger than the second, 0 if equal or -1 if smaller
 */
int libfwnt_lzxpress_huffman_compare_symbols(
     libfwnt_lzxpress_huffman_code_symbol_t *first_symbol,
     libfwnt_lzxpress_huffman_code_symbol_t *second_symbol )
{
	if( first_symbol == NULL )
	{
		return( -1 );
	}
	if( second_symbol == NULL )
	{
		return( 1 );
	}
	if( first_symbol->code_size < second_symbol->code_size )
	{
		return( -1 );
	}
	else if( first_symbol->code_size > second_symbol->code_size )
	{
		return( 1 );
	}
	else if( first_symbol->symbol < second_symbol->symbol )
	{
		return( -1 );
	}
	else if( first_symbol->symbol > second_symbol->symbol )
	{
		return( 1 );
	}
	return( 0 );
}

/* Adds a leaf node to the Huffman tree
 * Returns 1 on success or -1 on error
 */
int libfwnt_lzxpress_huffman_tree_add_leaf(
     libfwnt_lzxpress_huffman_tree_node_t tree_nodes[ 1024 ],
     int tree_node_index,
     uint32_t bits,
     uint8_t number_of_bits )
{
	libfwnt_lzxpress_huffman_tree_node_t *tree_node = NULL;
	uint8_t sub_tree_node_index                     = 0;
	int next_tree_node_index                        = 0;

	tree_node            = &( tree_nodes[ 0 ] );
	next_tree_node_index = tree_node_index + 1;

	while( number_of_bits > 1 )
	{
		number_of_bits--;

		sub_tree_node_index = (uint8_t) ( bits >> number_of_bits ) & 0x00000001UL;

		if( tree_node->sub_tree_nodes[ sub_tree_node_index ] == NULL )
		{
			tree_node->sub_tree_nodes[ sub_tree_node_index ] = &( tree_nodes[ next_tree_node_index ] );
			tree_nodes[ next_tree_node_index ].is_leaf       = 0;

			next_tree_node_index++;
		}
		tree_node = tree_node->sub_tree_nodes[ sub_tree_node_index ];
	}
	tree_node->sub_tree_nodes[ bits & 0x00000001UL ] = &( tree_nodes[ tree_node_index ] );

	return( next_tree_node_index );
}

/* Reads the Huffman tree
 * Returns 1 on success or -1 on error
 */
int libfwnt_lzxpress_huffman_tree_read(
     libfwnt_lzxpress_huffman_tree_node_t tree_nodes[ 1024 ],
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     size_t compressed_data_index,
     libcerror_error_t **error )
{
	libfwnt_lzxpress_huffman_code_symbol_t code_symbols[ 512 ];

	static char *function  = "libfwnt_lzxpress_huffman_tree_read";
	size_t byte_index      = 0;
	uint32_t bits          = 0;
	uint16_t symbol_index  = 0;
	uint8_t byte_value     = 0;
	uint8_t number_of_bits = 0;
	int tree_node_index    = 0;

	if( compressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data.",
		 function );

		return( -1 );
	}
	if( compressed_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid compressed data size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( ( compressed_data_index >= compressed_data_size )
	 || ( ( compressed_data_size - compressed_data_index ) < 256 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: compressed data index value out of bounds.",
		 function );

		return( -1 );
	}
	if( memory_set(
	     tree_nodes,
	     0,
	     sizeof( libfwnt_lzxpress_huffman_tree_node_t ) * 1024 ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear tree nodes.",
		 function );

		return( -1 );
	}
	for( byte_index = 0;
	     byte_index < 256;
	     byte_index++ )
	{
		byte_value = compressed_data[ compressed_data_index ];

		compressed_data_index++;

		code_symbols[ symbol_index ].symbol    = symbol_index;
		code_symbols[ symbol_index ].code_size = (uint16_t) ( byte_value & 0x0f );

		symbol_index++;

		byte_value >>= 4;

		code_symbols[ symbol_index ].symbol    = symbol_index;
		code_symbols[ symbol_index ].code_size = (uint16_t) ( byte_value & 0x0f );

		symbol_index++;
	}
	/* Sort the symbols
	 */
	qsort(
	 code_symbols,
	 512,
	 sizeof( libfwnt_lzxpress_huffman_code_symbol_t ),
	 (int (*)(const void *, const void *)) &libfwnt_lzxpress_huffman_compare_symbols );

	/* Find the first symbol with a code size > 0
	 */
	for( symbol_index = 0;
 	     symbol_index < 512;
	     symbol_index++ )
	{
		if( code_symbols[ symbol_index ].code_size > 0 )
		{
			break;
		}
	}
	bits           = 0;
	number_of_bits = 1;

	tree_nodes[ tree_node_index ].is_leaf = 0;

	tree_node_index++;

	while( symbol_index < 512 )
	{
		tree_nodes[ tree_node_index ].symbol  = code_symbols[ symbol_index ].symbol;
		tree_nodes[ tree_node_index ].is_leaf = 1;

		bits         <<= code_symbols[ symbol_index ].code_size - number_of_bits;
		number_of_bits = (uint8_t) code_symbols[ symbol_index ].code_size;

		tree_node_index = libfwnt_lzxpress_huffman_tree_add_leaf(
		                   tree_nodes,
		                   tree_node_index,
		                   bits,
		                   number_of_bits );

		bits++;

		symbol_index++;
	}
	return( 1 );
}

/* Reads a Huffman tree symbol
 * Returns 1 on success or -1 on error
 */
int libfwnt_lzxpress_huffman_tree_read_symbol(
     libfwnt_lzxpress_huffman_tree_node_t tree_nodes[ 1024 ],
     libfwnt_bit_stream_t *compressed_data_bit_stream,
     uint16_t *symbol,
     libcerror_error_t **error )
{
	libfwnt_lzxpress_huffman_tree_node_t *tree_node = NULL;
	static char *function                           = "libfwnt_lzxpress_huffman_tree_read_symbol";
	uint8_t sub_tree_node_index                     = 0;

	if( compressed_data_bit_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data bit stream.",
		 function );

		return( -1 );
	}
	if( symbol == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid symbol.",
		 function );

		return( -1 );
	}
	tree_node = &( tree_nodes[ 0 ] );

	do
	{
/* TODO add a read number of bits function ? */
		sub_tree_node_index = (uint8_t) ( ( compressed_data_bit_stream->bits >> 31 ) & 0x00000001UL );

		compressed_data_bit_stream->bits          <<= 1;
		compressed_data_bit_stream->number_of_bits -= 1;

		tree_node = tree_node->sub_tree_nodes[ sub_tree_node_index ];

		if( tree_node == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_MISSING,
			 "%s: missing tree node value.",
			 function );

			return( -1 );
		}
	}
	while( tree_node->is_leaf == 0 );

	*symbol = tree_node->symbol;

	return( 1 );
}

/* Decompresses data using LZXPRESS Huffman compression
 * Return 1 on success or -1 on error
 */
int libfwnt_lzxpress_huffman_decompress_with_index(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     size_t *compressed_data_index,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     size_t uncompressed_data_index,
     libcerror_error_t **error )
{
	libfwnt_lzxpress_huffman_tree_node_t tree_nodes[ 1024 ];

	libfwnt_bit_stream_t *compressed_data_bit_stream = NULL;
	static char *function                            = "libfwnt_lzxpress_huffman_decompress_with_index";
	size_t compression_uncompressed_data_index       = 0;
	size_t initial_uncompressed_data_index           = 0;
	uint32_t compression_offset                      = 0;
	uint16_t bits                                    = 0;
	uint16_t compression_size                        = 0;
	uint16_t symbol                                  = 0;
	uint8_t end_of_input                             = 0;

	if( compressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data.",
		 function );

		return( -1 );
	}
	if( compressed_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid compressed data size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( compressed_data_index == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed data index.",
		 function );

		return( -1 );
	}
	if( ( *compressed_data_index >= compressed_data_size )
	 || ( ( compressed_data_size - *compressed_data_index ) < 260 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: compressed data index value out of bounds.",
		 function );

		return( -1 );
	}
	if( uncompressed_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid uncompressed data.",
		 function );

		return( -1 );
	}
	if( uncompressed_data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid uncompressed data size.",
		 function );

		return( -1 );
	}
	if( uncompressed_data_index > *uncompressed_data_size )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: uncompressed data index value out of bounds.",
		 function );

		return( -1 );
	}
	if( libfwnt_lzxpress_huffman_tree_read(
	     tree_nodes,
	     compressed_data,
	     compressed_data_size,
	     *compressed_data_index,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to read Huffman tree.",
		 function );

		goto on_error;
	}
	if( libfwnt_bit_stream_initialize(
	     &compressed_data_bit_stream,
	     &( compressed_data[ *compressed_data_index ] ),
	     compressed_data_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create compressed data bit stream.",
		 function );

		goto on_error;
	}
/* TODO add a bit stream seek function ? */
	compressed_data_bit_stream->byte_stream_offset = 256;

	if( libfwnt_bit_stream_read(
	     compressed_data_bit_stream,
	     4,
	     error ) != 4 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_READ_FAILED,
		 "%s: unable to read 32-bit from bit stream.",
		 function );

		goto on_error;
	}
	initial_uncompressed_data_index = uncompressed_data_index;

        while( ( compressed_data_bit_stream->byte_stream_offset < compressed_data_bit_stream->byte_stream_size )
            || ( compressed_data_bit_stream->number_of_bits > 0 ) )
	{
		if( libfwnt_lzxpress_huffman_tree_read_symbol(
		     tree_nodes,
		     compressed_data_bit_stream,
		     &symbol,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to read symbol.",
			 function );

			goto on_error;
		}
		if( ( compressed_data_bit_stream->number_of_bits < 16 )
		 && ( compressed_data_bit_stream->byte_stream_offset <= ( compressed_data_bit_stream->byte_stream_size - 2 ) ) )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( compressed_data_bit_stream->byte_stream[ compressed_data_bit_stream->byte_stream_offset ] ),
			 bits );

			if( bits == 0 )
			{
				end_of_input = 1;
			}
/* TODO bits read infront of the bit stream ? */
			compressed_data_bit_stream->bits               |= bits << ( 16 - compressed_data_bit_stream->number_of_bits );
			compressed_data_bit_stream->byte_stream_offset += 2;
			compressed_data_bit_stream->number_of_bits     += 16;
		}
		if( symbol < 256 )
		{
			uncompressed_data[ uncompressed_data_index ] = (uint8_t) symbol;

			uncompressed_data_index++;
		}
		/* Check if we have an end-of-block marker (remaining bits are 0)
		 */
		if( ( compressed_data_bit_stream->bits == 0 )
		 && ( uncompressed_data_index >= *uncompressed_data_size ) )
		{
			break;
		}
		if( symbol >= 256 )
		{
			symbol          -= 256;
			compression_size = symbol & 0x000f;
			symbol         >>= 4;

			if( symbol == 0 )
			{
				compression_offset = 0;
			}
			else
			{
/* TODO add a read number of bits function ? */
				compression_offset = (uint32_t) ( compressed_data_bit_stream->bits >> ( 32 - symbol ) );
			}
			compression_offset = (uint32_t) ( ( 1 << symbol ) + compression_offset );

			compressed_data_bit_stream->bits          <<= symbol;
			compressed_data_bit_stream->number_of_bits -= (uint8_t) symbol;

			/* Ignore any data beyond the uncompressed block size
			 */
			if( compression_size == 15 )
			{
				if( compressed_data_bit_stream->byte_stream_offset > ( compressed_data_bit_stream->byte_stream_size - 1 ) )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
					 "%s: compressed data size value too small.",
					 function );

					goto on_error;
				}
				compression_size = compressed_data_bit_stream->byte_stream[ compressed_data_bit_stream->byte_stream_offset ] + 15;

				compressed_data_bit_stream->byte_stream_offset += 1;

				if( compression_size == 270 )
				{
					if( compressed_data_bit_stream->byte_stream_offset > ( compressed_data_bit_stream->byte_stream_size - 2 ) )
					{
						libcerror_error_set(
						 error,
						 LIBCERROR_ERROR_DOMAIN_RUNTIME,
						 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
						 "%s: compressed data size value too small.",
						 function );

						goto on_error;
					}
					byte_stream_copy_to_uint16_little_endian(
					 &( compressed_data_bit_stream->byte_stream[ compressed_data_bit_stream->byte_stream_offset ] ),
					 compression_size );

					compressed_data_bit_stream->byte_stream_offset += 2;
				}
			}
			compression_size += 3;

			if( compression_offset > uncompressed_data_index )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
				 "%s: compression offset value out of bounds.",
				 function );

				goto on_error;
			}
			if( compression_size > ( *uncompressed_data_size - uncompressed_data_index ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
				 "%s: compression size value out of bounds.",
				 function );

				goto on_error;
			}
			compression_uncompressed_data_index = uncompressed_data_index - compression_offset;

			while( compression_size > 0 )
			{
				uncompressed_data[ uncompressed_data_index ] = uncompressed_data[ compression_uncompressed_data_index ];

				compression_uncompressed_data_index++;
				uncompressed_data_index++;
				compression_size--;
			}
			if( ( compressed_data_bit_stream->number_of_bits < 16 )
			 && ( compressed_data_bit_stream->byte_stream_offset <= ( compressed_data_bit_stream->byte_stream_size - 2 ) ) )
			{
				byte_stream_copy_to_uint16_little_endian(
				 &( compressed_data_bit_stream->byte_stream[ compressed_data_bit_stream->byte_stream_offset ] ),
				 bits );

				if( bits == 0 )
				{
					end_of_input = 1;
				}
/* TODO bits read infront of the bit stream ? */
				compressed_data_bit_stream->bits               |= bits << ( 16 - compressed_data_bit_stream->number_of_bits );
				compressed_data_bit_stream->byte_stream_offset += 2;
				compressed_data_bit_stream->number_of_bits     += 16;
			}
		}
	}
	*compressed_data_index += compressed_data_bit_stream->byte_stream_offset;

	if( libfwnt_bit_stream_free(
	     &compressed_data_bit_stream,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free compressed data bit stream.",
		 function );

		goto on_error;
	}
	*uncompressed_data_size = uncompressed_data_index - initial_uncompressed_data_index;

	return( 1 );

on_error:
	if( compressed_data_bit_stream != NULL )
	{
		libfwnt_bit_stream_free(
		 &compressed_data_bit_stream,
		 NULL );
	}
	return( -1 );
}

/* Decompresses data using LZXPRESS Huffman compression
 * Return 1 on success or -1 on error
 */
int libfwnt_lzxpress_huffman_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libcerror_error_t **error )
{
	static char *function        = "libfwnt_lzxpress_huffman_decompress";
	size_t compressed_data_index = 0;

	if( libfwnt_lzxpress_huffman_decompress_with_index(
	     compressed_data,
	     compressed_data_size,
	     &compressed_data_index,
	     uncompressed_data,
	     uncompressed_data_size,
	     0,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_COMPRESSION,
		 LIBCERROR_COMPRESSION_ERROR_DECOMPRESS_FAILED,
		 "%s: unable to decompress compressed data.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Decompresses data using LZXPRESS Huffman stream compression
 * Return 1 on success or -1 on error
 */
int libfwnt_lzxpress_huffman_stream_decompress(
     const uint8_t *compressed_data,
     size_t compressed_data_size,
     uint8_t *uncompressed_data,
     size_t *uncompressed_data_size,
     libcerror_error_t **error )
{
	static char *function          = "libfwnt_lzxpress_huffman_stream_decompress";
	size_t compressed_data_index   = 0;
	size_t uncompressed_block_size = 0;
	size_t uncompressed_data_index = 0;

	if( uncompressed_data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid uncompressed data size.",
		 function );

		return( -1 );
	}
	while( compressed_data_index < compressed_data_size )
	{
		uncompressed_block_size = uncompressed_data_index + 65536;

		if( uncompressed_block_size > *uncompressed_data_size )
		{
			uncompressed_block_size = *uncompressed_data_size;
		}
		if( libfwnt_lzxpress_huffman_decompress_with_index(
		     compressed_data,
		     compressed_data_size,
		     &compressed_data_index,
		     uncompressed_data,
		     &uncompressed_block_size,
		     uncompressed_data_index,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_COMPRESSION,
			 LIBCERROR_COMPRESSION_ERROR_DECOMPRESS_FAILED,
			 "%s: unable to decompress compressed data.",
			 function );

			return( -1 );
		}
		uncompressed_data_index += uncompressed_block_size;
	}
	*uncompressed_data_size = uncompressed_data_index;

	return( 1 );
}
