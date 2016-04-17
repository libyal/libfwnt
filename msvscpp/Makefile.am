MSVSCPP_FILES = \
	fwnt_test_get_version/fwnt_test_get_version.vcproj \
	fwnt_test_lznt1_decompress/fwnt_test_lznt1_decompress.vcproj \
	fwnt_test_lzxpress_decompress/fwnt_test_lzxpress_decompress.vcproj \
	fwnt_test_lzxpress_huffman_decompress/fwnt_test_lzxpress_huffman_decompress.vcproj \
	fwnt_test_security_identifier_copy_from/fwnt_test_security_identifier_copy_from.vcproj \
	fwnt_test_security_identifier_to_string/fwnt_test_security_identifier_to_string.vcproj \
	libcdata/libcdata.vcproj \
	libcerror/libcerror.vcproj \
	libcfile/libcfile.vcproj \
	libclocale/libclocale.vcproj \
	libcnotify/libcnotify.vcproj \
	libcstring/libcstring.vcproj \
	libcthreads/libcthreads.vcproj \
	libfwnt/libfwnt.vcproj \
	libuna/libuna.vcproj \
	pyfwnt/pyfwnt.vcproj \
	libfwnt.sln

SCRIPT_FILES = \
	scripts/vs2008_x64.sh \
	scripts/vs2008_x64_sln.sed \
	scripts/vs2008_x64_vcproj.sed \
	scripts/vs2010_x64.sh \
	scripts/vs2010_x64_sln.sed \
	scripts/vs2010_x64_vcxproj.sed

EXTRA_DIST = \
	$(MSVSCPP_FILES) \
	$(SCRIPT_FILES)

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

