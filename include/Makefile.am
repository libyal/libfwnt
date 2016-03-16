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
	/bin/rm -f libfwnt.h
	/bin/rm -f libfwnt/definitions.h
	/bin/rm -f libfwnt/features.h
	/bin/rm -f libfwnt/types.h
	/bin/rm -f Makefile

