#!/usr/bin/env python
# -*- coding: UTF-8 -*-

'''
Module
    setup.py
Copyright
    Copyright (C) 2017 - 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
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
    Defines setup for tool gen_unix_domain_socket.
'''

from __future__ import print_function
from typing import List, Optional
from os.path import abspath, dirname, join
from setuptools import setup

__author__ = 'Vladimir Roncevic'
__copyright__ = '(C) 2024, https://vroncevic.github.io/gen_unix_domain_socket'
__credits__: List[str] = ['Vladimir Roncevic', 'Python Software Foundation']
__license__ = 'https://bit.ly/3vMKs5L'
__version__ = '1.0.5'
__maintainer__ = 'Vladimir Roncevic'
__email__ = 'elektron.ronca@gmail.com'
__status__ = 'Updated'

TOOL_DIR: str = 'gen_unix_domain_socket/'
CONF: str = 'conf'
TEMPLATE: str = 'conf/template'
LOG: str = 'log'
THIS_DIR: str = abspath(dirname(__file__))
long_description: Optional[str] = None
with open(join(THIS_DIR, 'README.md'), encoding='utf-8') as readme:
    long_description = readme.read()
PROGRAMMING_LANG: str = 'Programming Language :: Python ::'
VERSIONS: List[str] = ['3.10', '3.11']
SUPPORTED_PY_VERSIONS: List[str] = [
    f'{PROGRAMMING_LANG} {VERSION}' for VERSION in VERSIONS
]
LICENSE_PREFIX: str = 'License :: OSI Approved ::'
LICENSES: List[str] = [
    'GNU Lesser General Public License v2 (LGPLv2)',
    'GNU Lesser General Public License v2 or later (LGPLv2+)',
    'GNU Lesser General Public License v3 (LGPLv3)',
    'GNU Lesser General Public License v3 or later (LGPLv3+)',
    'GNU Library or Lesser General Public License (LGPL)'
]
APPROVED_LICENSES: List[str] = [
    f'{LICENSE_PREFIX} {LICENSE}' for LICENSE in LICENSES
]
PYP_CLASSIFIERS: List[str] = SUPPORTED_PY_VERSIONS + APPROVED_LICENSES
setup(
    name='gen_unix_domain_socket',
    version='1.0.5',
    description='Generating Unix Domain Socket',
    author='Vladimir Roncevic',
    author_email='elektron.ronca@gmail.com',
    url='https://vroncevic.github.io/gen_unix_domain_socket',
    license='GPL 2017 - 2024 Free software to use and distributed it.',
    long_description=long_description,
    long_description_content_type='text/markdown',
    keywords='Unix, Linux, Development, Unix Domain Socket, Modules',
    platforms='POSIX',
    classifiers=PYP_CLASSIFIERS,
    packages=['gen_unix_domain_socket', 'gen_unix_domain_socket.pro'],
    install_requires=['ats-utilities'],
    package_data={
        'gen_unix_domain_socket': [
            'py.typed',
            f'{CONF}/gen_unix_domain_socket.logo',
            f'{CONF}/gen_unix_domain_socket.cfg',
            f'{CONF}/gen_unix_domain_socket_util.cfg',
            f'{CONF}/project.yaml',
            f'{TEMPLATE}/uds.template',
            f'{TEMPLATE}/uds_fatal_error.template',
            f'{TEMPLATE}/uds_socket.template',
            f'{TEMPLATE}/uds_accept.template',
            f'{TEMPLATE}/uds_bind.template',
            f'{TEMPLATE}/uds_connect.template',
            f'{TEMPLATE}/uds_listen.template',
            f'{TEMPLATE}/uds_read.template',
            f'{TEMPLATE}/uds_write.template',
            f'{TEMPLATE}/uds_unlink.template',
            f'{LOG}/gen_unix_domain_socket.log'
        ]
    },
    data_files=[(
        '/usr/local/bin/', [
            f'{TOOL_DIR}run/gen_unix_domain_socket_run.py'
        ]
    )]
)
