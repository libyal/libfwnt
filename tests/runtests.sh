#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfwnt/.libs/libfwnt.1.dylib && test -f ./pyfwnt/.libs/pyfwnt.so
then
	install_name_tool -change /usr/local/lib/libfwnt.1.dylib ${PWD}/libfwnt/.libs/libfwnt.1.dylib ./pyfwnt/.libs/pyfwnt.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

