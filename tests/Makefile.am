AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFWNT_DLL_IMPORT@

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

if HAVE_PYTHON_TESTS
check_AUTOTESTS += test_python_module
endif

check_SCRIPTS = \
	pyfwnt_test_access_control_entry.py \
	pyfwnt_test_access_control_list.py \
	pyfwnt_test_lznt1.py \
	pyfwnt_test_lzx.py \
	pyfwnt_test_lzxpress.py \
	pyfwnt_test_security_descriptor.py \
	pyfwnt_test_security_identifier.py \
	pyfwnt_test_support.py

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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: \
	package.m4 \
	test_library.at \
	test_macros.at

test_manpages: \
	package.m4 \
	test_manpages.at

test_python_module: \
	package.m4 \
	test_python_module.at

EXTRA_DIST = \
	$(check_SCRIPTS) \
	package.m4 \
	test_library.at \
	test_macros.at \
	test_manpages.at \
	test_python_module.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp \
	notify_stream.log

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

