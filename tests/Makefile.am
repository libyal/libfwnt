AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFWNT_DLL_IMPORT@

if HAVE_PYTHON_TESTS
TESTS_PYFWNT = \
	test_python_module.sh
endif

TESTS = \
	test_library.sh \
	$(TESTS_PYFWNT)

check_SCRIPTS = \
	pyfwnt_test_access_control_entry.py \
	pyfwnt_test_access_control_list.py \
	pyfwnt_test_lznt1.py \
	pyfwnt_test_lzxpress.py \
	pyfwnt_test_lzx.py \
	pyfwnt_test_security_descriptor.py \
	pyfwnt_test_security_identifier.py \
	pyfwnt_test_support.py \
	test_library.sh \
	test_manpage.sh \
	test_python_module.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fwnt_test_access_control_entry \
	fwnt_test_access_control_list \
	fwnt_test_bit_stream \
	fwnt_test_error \
	fwnt_test_huffman_tree \
	fwnt_test_lznt1 \
	fwnt_test_lzx \
	fwnt_test_lzxpress \
	fwnt_test_notify \
	fwnt_test_security_descriptor \
	fwnt_test_security_identifier \
	fwnt_test_support

fwnt_test_access_control_entry_SOURCES = \
	fwnt_test_access_control_entry.c \
	fwnt_test_libcerror.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_unused.h

fwnt_test_access_control_entry_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@

fwnt_test_access_control_list_SOURCES = \
	fwnt_test_access_control_list.c \
	fwnt_test_libcerror.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_unused.h

fwnt_test_access_control_list_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@

fwnt_test_bit_stream_SOURCES = \
	fwnt_test_bit_stream.c \
	fwnt_test_libcerror.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_unused.h

fwnt_test_bit_stream_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@

fwnt_test_error_SOURCES = \
	fwnt_test_error.c \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_unused.h

fwnt_test_error_LDADD = \
	../libfwnt/libfwnt.la

fwnt_test_huffman_tree_SOURCES = \
	fwnt_test_huffman_tree.c \
	fwnt_test_libcerror.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_unused.h

fwnt_test_huffman_tree_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@

fwnt_test_lznt1_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcnotify.h \
	fwnt_test_libfwnt.h \
	fwnt_test_lznt1.c \
	fwnt_test_macros.h \
	fwnt_test_unused.h

fwnt_test_lznt1_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCERROR_LIBADD@

fwnt_test_lzx_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcnotify.h \
	fwnt_test_libfwnt.h \
	fwnt_test_lzx.c \
	fwnt_test_macros.h \
	fwnt_test_unused.h

fwnt_test_lzx_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCERROR_LIBADD@

fwnt_test_lzxpress_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libcnotify.h \
	fwnt_test_libfwnt.h \
	fwnt_test_lzxpress.c \
	fwnt_test_macros.h \
	fwnt_test_unused.h

fwnt_test_lzxpress_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCERROR_LIBADD@

fwnt_test_notify_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_notify.c \
	fwnt_test_unused.h

fwnt_test_notify_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@

fwnt_test_security_descriptor_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_security_descriptor.c \
	fwnt_test_unused.h

fwnt_test_security_descriptor_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@

fwnt_test_security_identifier_SOURCES = \
	fwnt_test_libcerror.h \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_memory.c fwnt_test_memory.h \
	fwnt_test_security_identifier.c \
	fwnt_test_unused.h

fwnt_test_security_identifier_LDADD = \
	../libfwnt/libfwnt.la \
	@LIBCERROR_LIBADD@

fwnt_test_support_SOURCES = \
	fwnt_test_libfwnt.h \
	fwnt_test_macros.h \
	fwnt_test_support.c \
	fwnt_test_unused.h

fwnt_test_support_LDADD = \
	../libfwnt/libfwnt.la

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f Makefile

