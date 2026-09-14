#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libfwnt/.libs/libfwnt.1.dylib" ] && [ -f ./pyfwnt/.libs/pyfwnt.so ]
then
    install_name_tool -change /usr/local/lib/libfwnt.1.dylib "${PWD}/libfwnt/.libs/libfwnt.1.dylib" ./pyfwnt/.libs/pyfwnt.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

