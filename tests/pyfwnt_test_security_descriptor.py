#!/usr/bin/env python
#
# Python-bindings security_descriptor type test script
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


class SecurityDescriptorTypeTests(unittest.TestCase):
  """Tests the security_descriptor type."""

  _TEST_DATA = bytes(bytearray([
      0x01, 0x00, 0x04, 0x80, 0x48, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x02, 0x00, 0x34, 0x00,
      0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x9f, 0x01, 0x12, 0x00,
      0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x12, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x18, 0x00, 0x9f, 0x01, 0x12, 0x00, 0x01, 0x02, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x05, 0x20, 0x00, 0x00, 0x00, 0x20, 0x02, 0x00, 0x00,
      0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x15, 0x00, 0x00, 0x00,
      0x52, 0xaa, 0xc8, 0x68, 0xdd, 0xe8, 0xe4, 0x1c, 0x8a, 0xa7, 0x32, 0x3f,
      0xeb, 0x03, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
      0x20, 0x00, 0x00, 0x00, 0x20, 0x02, 0x00, 0x00]))

  def test_copy_from_byte_stream(self):
    """Tests the copy_from_byte_stream function."""
    security_descriptor = pyfwnt.security_descriptor()
    security_descriptor.copy_from_byte_stream(self._TEST_DATA)

    with self.assertRaises(TypeError):
      security_descriptor.copy_from_byte_stream(None)

    with self.assertRaises(IOError):
      security_descriptor.copy_from_byte_stream(self._TEST_DATA[:16])

  def test_get_owner(self):
    """Tests the get_owner function."""
    security_descriptor = pyfwnt.security_descriptor()
    security_descriptor.copy_from_byte_stream(self._TEST_DATA)

    security_identifier = security_descriptor.get_owner()
    self.assertIsNotNone(security_identifier)

    string = security_identifier.get_string()
    self.assertEqual(string, 'S-1-5-21-1757981266-484763869-1060284298-1003')

  def test_get_group(self):
    """Tests the get_group function."""
    security_descriptor = pyfwnt.security_descriptor()
    security_descriptor.copy_from_byte_stream(self._TEST_DATA)

    security_identifier = security_descriptor.get_group()
    self.assertIsNotNone(security_identifier)

    string = security_identifier.get_string()
    self.assertEqual(string, 'S-1-5-32-544')

  def test_get_discretionary_acl(self):
    """Tests the get_discretionary_acl function."""
    security_descriptor = pyfwnt.security_descriptor()
    security_descriptor.copy_from_byte_stream(self._TEST_DATA)

    access_control_list = security_descriptor.get_discretionary_acl()
    self.assertIsNotNone(access_control_list)

  def test_get_system_acl(self):
    """Tests the get_system_acl function."""
    security_descriptor = pyfwnt.security_descriptor()
    security_descriptor.copy_from_byte_stream(self._TEST_DATA)

    access_control_list = security_descriptor.get_system_acl()
    self.assertIsNone(access_control_list)


if __name__ == "__main__":
  unittest.main(verbosity=2)
