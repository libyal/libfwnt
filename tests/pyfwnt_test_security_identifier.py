#!/usr/bin/env python
#
# Python-bindings security_identifier type test script
#
# Copyright (C) 2009-2021, Joachim Metz <joachim.metz@gmail.com>
#
# Refer to AUTHORS for acknowledgements.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

from __future__ import unicode_literals

import unittest

import pyfwnt


class SecurityIdentifierTypeTests(unittest.TestCase):
  """Tests the security_identifier type."""

  _TEST_DATA = bytes(bytearray([
      0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x15, 0x00, 0x00, 0x00,
      0xc7, 0x99, 0x2e, 0x25, 0x7c, 0x57, 0x85, 0xc0, 0x94, 0x5a, 0xce, 0x01,
      0xf5, 0x03, 0x00, 0x00]))

  def test_copy_from_byte_stream(self):
    """Tests the copy_from_byte_stream function."""
    security_identifier = pyfwnt.security_identifier()
    security_identifier.copy_from_byte_stream(self._TEST_DATA)

    with self.assertRaises(TypeError):
      security_identifier.copy_from_byte_stream(None)

    with self.assertRaises(IOError):
      security_identifier.copy_from_byte_stream(self._TEST_DATA[:4])

  def test_get_string(self):
    """Tests the get_string function."""
    security_identifier = pyfwnt.security_identifier()
    security_identifier.copy_from_byte_stream(self._TEST_DATA)

    string = security_identifier.get_string()
    self.assertEqual(string, 'S-1-5-21-623811015-3229964156-30300820-1013')


if __name__ == "__main__":
  unittest.main(verbosity=2)
