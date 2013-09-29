#!/bin/bash
#
# Windows NT format library security identifier (SID) to string testing script
#
# Copyright (c) 2009-2012, Joachim Metz <joachim.metz@gmail.com>
#
# Refer to AUTHORS for acknowledgements.
#
# This software is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this software.  If not, see <http://www.gnu.org/licenses/>.
#

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

test_security_identifier_to_string()
{ 
	echo "Testing identifier to string function";

	./${FWNT_TEST_SECURITY_IDENTIFIER_TO_STRING};

	RESULT=$?;

	echo "";

	return ${RESULT};
}

FWNT_TEST_SECURITY_IDENTIFIER_TO_STRING="fwnt_test_security_identifier_to_string";

if ! test -x ${FWNT_TEST_SECURITY_IDENTIFIER_TO_STRING};
then
	FWNT_TEST_SECURITY_IDENTIFIER_TO_STRING="fwnt_test_security_identifier_to_string.exe";
fi

if ! test -x ${FWNT_TEST_SECURITY_IDENTIFIER_TO_STRING};
then
	echo "Missing executable: ${FWNT_TEST_SECURITY_IDENTIFIER_TO_STRING}";

	exit ${EXIT_FAILURE};
fi

if ! test_security_identifier_to_string;
then
	exit ${EXIT_FAILURE};
fi

exit ${EXIT_SUCCESS};

