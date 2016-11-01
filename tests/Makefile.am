AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFWNT_DLL_IMPORT@

TESTS = \
	test_api_functions.sh \
	test_api_types.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fwnt_test_access_control_entry \
	fwnt_test_access_control_list \
	fwnt_test_error \
	fwnt_test_lznt1 \
	fwnt_test_lzxpress \
	fwnt_test_security_descriptor \
	fwnt_test_security_identifier \
	fwnt_test_support

fwnt_test_access_control_entry_SOURCES = \
	fwnt_test_access_control_entry.c \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_unused.h

fwnt_test_access_control_entry_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fwnt_test_access_control_list_SOURCES = \
	fwnt_test_access_control_list.c \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_unused.h

fwnt_test_access_control_list_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fwnt_test_error_SOURCES = \
	fwnt_test_error.c
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_unused.h

fwnt_test_error_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCSTRING_LIBADD@

fwnt_test_lznt1_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_lznt1.c \
	fwnt_test_macros.h \
	fwnt_test_unused.h

fwnt_test_lznt1_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fwnt_test_lzxpress_SOURCES = \
	fwnt_test_libcfile.h \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_lzxpress.c \
	fwnt_test_macros.h \
	fwnt_test_unused.h

fwnt_test_lzxpress_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fwnt_test_security_descriptor_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_security_descriptor.c \
	fwnt_test_unused.h

fwnt_test_security_descriptor_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fwnt_test_security_identifier_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_security_identifier.c \
	fwnt_test_unused.h

fwnt_test_security_identifier_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

fwnt_test_support_SOURCES = \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_support.c
	fwnt_test_unused.h

fwnt_test_support_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

