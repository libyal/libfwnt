if HAVE_PYTHON
AM_CFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBFWNT_DLL_IMPORT@

pyexec_LTLIBRARIES = pyfwnt.la

pyfwnt_la_SOURCES = \
	pyfwnt.c pyfwnt.h \
	pyfwnt_access_control_entries.c pyfwnt_access_control_entries.h \
	pyfwnt_access_control_entry.c pyfwnt_access_control_entry.h \
	pyfwnt_access_control_list.c pyfwnt_access_control_list.h \
	pyfwnt_access_control_types.c pyfwnt_access_control_types.h \
	pyfwnt_error.c pyfwnt_error.h \
	pyfwnt_integer.c pyfwnt_integer.h \
	pyfwnt_libcerror.h \
	pyfwnt_libfwnt.h \
	pyfwnt_python.h \
	pyfwnt_security_descriptor.c pyfwnt_security_descriptor.h \
	pyfwnt_security_identifier.c pyfwnt_security_identifier.h \
	pyfwnt_unused.h

pyfwnt_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	../libfwnt/libfwnt.la \
	@LIBCDATA_LIBADD@

pyfwnt_la_CPPFLAGS = $(PYTHON_CPPFLAGS)
pyfwnt_la_LDFLAGS  = -module -avoid-version $(PYTHON_LDFLAGS)

endif

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

