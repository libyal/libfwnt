AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFWNT_DLL_EXPORT@

lib_LTLIBRARIES = libfwnt.la

libfwnt_la_SOURCES = \
	libfwnt.c \
	libfwnt_access_control_entry.c libfwnt_access_control_entry.h \
	libfwnt_access_control_list.c libfwnt_access_control_list.h \
	libfwnt_bit_stream.c libfwnt_bit_stream.h \
	libfwnt_debug.c libfwnt_debug.h \
	libfwnt_definitions.h \
	libfwnt_extern.h \
	libfwnt_error.c libfwnt_error.h \
	libfwnt_huffman_tree.c libfwnt_huffman_tree.h \
	libfwnt_libcerror.h \
	libfwnt_libcdata.h \
	libfwnt_libcnotify.h \
	libfwnt_locale_identifier.c libfwnt_locale_identifier.h \
	libfwnt_lznt1.c libfwnt_lznt1.h \
	libfwnt_lzx.c libfwnt_lzx.h \
	libfwnt_lzxpress.c libfwnt_lzxpress.h \
	libfwnt_notify.c libfwnt_notify.h \
	libfwnt_security_descriptor.c libfwnt_security_descriptor.h \
	libfwnt_security_identifier.c libfwnt_security_identifier.h \
	libfwnt_support.c libfwnt_support.h \
	libfwnt_types.h \
	libfwnt_unused.h

libfwnt_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	@LIBCTHREADS_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@PTHREAD_LIBADD@

libfwnt_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfwnt_definitions.h.in \
	libfwnt.rc \
	libfwnt.rc.in

DISTCLEANFILES = \
	libfwnt_definitions.h \
	libfwnt.rc \
	Makefile \
	Makefile.in

sources-local: $(BUILT_SOURCES)

splint-local:
	@echo "Running splint on libfwnt ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfwnt_la_SOURCES)

