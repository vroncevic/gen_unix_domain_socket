#!/usr/bin/env python
# -*- coding: UTF-8 -*-

'''
 Module
     gen_unix_domain_socket_run.py
 Copyright
     Copyright (C) 2018 Vladimir Roncevic <elektron.ronca@gmail.com>
     gen_unix_domain_socket is free software: you can redistribute it and/or
     modify it under the terms of the GNU General Public License as published
     by the Free Software Foundation, either version 3 of the License, or
     (at your option) any later version.
     gen_unix_domain_socket is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
     See the GNU General Public License for more details.
     You should have received a copy of the GNU General Public License along
     with this program. If not, see <http://www.gnu.org/licenses/>.
 Info
     Main entry point of tool gen_unix_domain_socket.
'''

import sys

try:
    from gen_unix_domain_socket import GenUnixDomainSocket
except ImportError as ats_error_message:
    MESSAGE = '\n{0}\n{1}\n'.format(__file__, ats_error_message)
    sys.exit(MESSAGE)  # Force close python ATS ##############################

__author__ = 'Vladimir Roncevic'
__copyright__ = 'Copyright 2018, https://bit.ly/3j6QOtZ'
__credits__ = ['Vladimir Roncevic']
__license__ = 'https://bit.ly/3vMKs5L'
__version__ = '1.0.0'
__maintainer__ = 'Vladimir Roncevic'
__email__ = 'elektron.ronca@gmail.com'
__status__ = 'Updated'

if __name__ == '__main__':
    TOOL = GenUnixDomainSocket(verbose=False)
    TOOL.process(verbose=False)
