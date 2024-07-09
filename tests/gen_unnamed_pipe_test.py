# -*- coding: UTF-8 -*-

'''
Module
    gen_unix_domain_socket_test.py
Copyright
    Copyright (C) 2017 - 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
    gen_unix_domain_socket is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    gen_unix_domain_socket is distributed in the hope that it will be useful,
    but SWITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.
Info
    Defines class TestGenUnixDomainSocket with attribute(s) and method(s).
    Creates test cases for checking functionalities of GenUnixDomainSocket.
Execute
    python3 -m unittest -v gen_unix_domain_socket_test
'''

import sys
from unittest import TestCase, main

try:
    from gen_unix_domain_socket import GenUnixDomainSocket
except ImportError as test_error_message:
    # Force close python test #################################################
    sys.exit(f'\n{__file__}\n{test_error_message}\n')


class TestGenUnixDomainSocket(TestCase):
    '''
        Defines class TestGenUnixDomainSocket with attribute(s) and method(s).
        Creates test cases for checking functionalities of GenUnixDomainSocket.
        GenUnixDomainSocket unit tests.

        It defines:

            :attributes:
                | None
            :methods:
                | setUp - Call before test case.
                | tearDown - Call after test case.
                | test_default_create - Default on create (not None).
                | test_missing_args - Test missing args.
                | test_process_tool - Test generation of tool structure.
    '''
    def setUp(self) -> None:
        '''Call before test case.'''

    def tearDown(self) -> None:
        '''Call after test case.'''

    def test_default_create(self) -> None:
        '''Default on create (not None)'''
        generator: GenUnixDomainSocket = GenUnixDomainSocket()
        self.assertIsNotNone(generator)

    def test_missing_args(self) -> None:
        '''Test missing args'''
        sys.argv.clear()
        generator: GenUnixDomainSocket = GenUnixDomainSocket()
        self.assertFalse(generator.process())

    def test_process_tool(self) -> None:
        '''Test generation of tool structure'''
        sys.argv.clear()
        sys.argv.insert(0, '-n')
        sys.argv.insert(1, 'mytool')
        generator: GenUnixDomainSocket = GenUnixDomainSocket()
        self.assertTrue(generator.process())


if __name__ == '__main__':
    main()
