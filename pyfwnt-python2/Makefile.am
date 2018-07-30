# Note that we cannot use: AUTOMAKE_OPTIONS = subdir-objects
# subdir-objects will compile the source files to a single version of Python.
# Since subdir-objects is being deprecated we copy the source files instead.
am__installdirs = "$(DESTDIR)$(pyexecdir2)"
pyexecdir = $(pyexecdir2)

if HAVE_PYTHON2
AM_CFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBFWNT_DLL_IMPORT@

am_pyfwnt_la_rpath = -rpath $(pyexecdir2)

BUILT_SOURCES = \
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

pyexec_LTLIBRARIES = pyfwnt.la

nodist_pyfwnt_la_SOURCES = $(BUILT_SOURCES)

pyfwnt_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	../libfwnt/libfwnt.la \
	@LIBCDATA_LIBADD@

pyfwnt_la_CPPFLAGS = $(PYTHON2_CPPFLAGS)
pyfwnt_la_LDFLAGS  = -module -avoid-version $(PYTHON2_LDFLAGS)

$(BUILT_SOURCES):
	/bin/cp -f $(top_srcdir)/pyfwnt/$@ $@

endif

MAINTAINERCLEANFILES = \
	Makefile.in

clean-local:
	/bin/rm -f pyfwnt*.[ch]

distclean: clean
	/bin/rm -f Makefile

