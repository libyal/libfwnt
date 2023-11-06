include_HEADERS = \
	libfwnt.h

pkginclude_HEADERS = \
	libfwnt/definitions.h \
	libfwnt/error.h \
	libfwnt/extern.h \
	libfwnt/features.h \
	libfwnt/types.h

EXTRA_DIST = \
	libfwnt.h.in \
	libfwnt/definitions.h.in \
	libfwnt/features.h.in \
	libfwnt/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libfwnt.h
	-rm -f libfwnt/definitions.h
	-rm -f libfwnt/features.h
	-rm -f libfwnt/types.h
	-rm -f Makefile

