if HAVE_LIB_FUZZING_ENGINE
AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common

bin_PROGRAMS = \
	lznt1_fuzzer \
	lzx_fuzzer \
	lzxpress_fuzzer \
	lzxpress_huffman_fuzzer \
	security_descriptor_fuzzer \
	security_identifier_fuzzer

lznt1_fuzzer_SOURCES = \
	lznt1_fuzzer.cc \
	ossfuzz_libfwnt.h

lznt1_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwnt/libfwnt.la

lzx_fuzzer_SOURCES = \
	lzx_fuzzer.cc \
	ossfuzz_libfwnt.h

lzx_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwnt/libfwnt.la

lzxpress_fuzzer_SOURCES = \
	lzxpress_fuzzer.cc \
	ossfuzz_libfwnt.h

lzxpress_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwnt/libfwnt.la

lzxpress_huffman_fuzzer_SOURCES = \
	lzxpress_huffman_fuzzer.cc \
	ossfuzz_libfwnt.h

lzxpress_huffman_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwnt/libfwnt.la

security_descriptor_fuzzer_SOURCES = \
	ossfuzz_libfwnt.h \
	security_descriptor_fuzzer.cc

security_descriptor_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwnt/libfwnt.la

security_identifier_fuzzer_SOURCES = \
	ossfuzz_libfwnt.h \
	security_identifier_fuzzer.cc

security_identifier_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwnt/libfwnt.la
endif

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f Makefile

splint-local:
	@echo "Running splint on lznt1_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lznt1_fuzzer_SOURCES)
	@echo "Running splint on lzx_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lzx_fuzzer_SOURCES)
	@echo "Running splint on lzxpress_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lzxpress_fuzzer_SOURCES)
	@echo "Running splint on lzxpress_huffman_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lzxpress_huffman_fuzzer_SOURCES)
	@echo "Running splint on security_descriptor_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(security_descriptor_fuzzer_SOURCES)
	@echo "Running splint on security_identifier_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(security_identifier_fuzzer_SOURCES)

