AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@MEMWATCH_CPPFLAGS@

TESTS = \
	test_security_identifier_copy_from.sh \
	test_security_identifier_to_string.sh

check_SCRIPTS = \
	test_security_identifier_copy_from.sh \
	test_security_identifier_to_string.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fwnt_test_security_identifier_copy_from \
	fwnt_test_security_identifier_to_string

fwnt_test_security_identifier_copy_from_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_security_identifier_copy_from.c

fwnt_test_security_identifier_copy_from_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libfwnt/libfwnt.la \
        @MEMWATCH_LIBADD@

fwnt_test_security_identifier_to_string_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcstring.h \
	fwnt_test_libfwnt.h \
	fwnt_test_security_identifier_to_string.c

fwnt_test_security_identifier_to_string_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libfwnt/libfwnt.la \
        @MEMWATCH_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

