# -*- coding: UTF-8 -*-

'''
 Module
     template_dir.py
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
     Defined class TemplateDir with attribute(s) and method(s).
     Defined API for template directory for generation.
'''

import sys

try:
    from ats_utilities.checker import ATSChecker
    from ats_utilities.console_io.verbose import verbose_message
    from ats_utilities.exceptions.ats_type_error import ATSTypeError
    from ats_utilities.exceptions.ats_bad_call_error import ATSBadCallError
except ImportError as ats_error_message:
    MESSAGE = '\n{0}\n{1}\n'.format(__file__, ats_error_message)
    sys.exit(MESSAGE)  # Force close python ATS ##############################

__author__ = 'Vladimir Roncevic'
__copyright__ = 'Copyright 2018, https://bit.ly/3j6QOtZ'
__credits__ = ['Vladimir Roncevic']
__license__ = 'https://bit.ly/3vMKs5L'
__version__ = '1.0.3'
__maintainer__ = 'Vladimir Roncevic'
__email__ = 'elektron.ronca@gmail.com'
__status__ = 'Updated'


class TemplateDir:
    '''
        Defined class TemplateDir with attribute(s) and method(s).
        Defined API for template directory for generation.
        It defines:

            :attributes:
                | GEN_VERBOSE - console text indicator for process-phase.
                | __verbose - enable/disable verbose option.
                | __template_dir - project template dir.
            :methods:
                | __init__ - initial constructor.
                | template_dir - property methods for set/get operations.
                | is_template_dir_ok - checking is template dir ok.
                | __str__ - dunder method for TemplateDir.
    '''

    GEN_VERBOSE = 'GEN_UNIX_DOMAIN_SOCKET::PRO::CONFIG::TEMPLATE_DIR'

    def __init__(self, verbose=False):
        '''
            Initial constructor.

            :param verbose: enable/disable verbose option.
            :type verbose: <bool>
            :exceptions: None
        '''
        self.__verbose = verbose
        self.__template_dir = None
        verbose_message(TemplateDir.GEN_VERBOSE, verbose, 'init template dir')

    @property
    def template_dir(self):
        '''
            Property method for getting template dir.

            :return: formatted template dir | None.
            :rtype: <str> | <NoneType>
            :exceptions: None
        '''
        return self.__template_dir

    @template_dir.setter
    def template_dir(self, template_dir):
        '''
            Property method for setting project template dir.

            :param template_dir: set project template dir.
            :type template_dir: <str>
            :exceptions: ATSTypeError | ATSBadCallError
        '''
        checker, error, status = ATSChecker(), None, False
        error, status = checker.check_params([
            ('str:template_dir', template_dir)
        ])
        if status == ATSChecker.TYPE_ERROR:
            raise ATSTypeError(error)
        if status == ATSChecker.VALUE_ERROR:
            raise ATSBadCallError(error)
        self.__template_dir = template_dir
        verbose_message(
            TemplateDir.GEN_VERBOSE, self.__verbose,
            'set project template dir', template_dir
        )

    def is_template_dir_ok(self):
        '''
            Checking is project template dir ok.

            :return: boolean status, True (not None) | False.
            :rtype: <bool>
            :exceptions: None
        '''
        return all([
            self.__template_dir is not None,
            isinstance(self.__template_dir, str)
        ])

    def __str__(self):
        '''
            Dunder method for TemplateDir.

            :return: object in a human-readable format.
            :rtype: <str>
            :exceptions: None
        '''
        return '{0} ({1}, {2})'.format(
            self.__class__.__name__, str(self.__verbose), self.__template_dir
        )
