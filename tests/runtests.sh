#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libfwnt/.libs/libfwnt.1.dylib && test -f ./pyfwnt/.libs/pyfwnt.so;
then
	install_name_tool -change /usr/local/lib/libfwnt.1.dylib ${PWD}/libfwnt/.libs/libfwnt.1.dylib ./pyfwnt/.libs/pyfwnt.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

