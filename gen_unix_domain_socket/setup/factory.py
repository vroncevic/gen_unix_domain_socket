# -*- coding: UTF-8 -*-

'''
Module
    factory.py
Copyright
    Copyright (C) 2026 Vladimir Roncevic <elektron.ronca@gmail.com>
    gen_unix_domain_socket is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    gen_unix_domain_socket is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.
Info
    Factory for creating the gen_unix_domain_socket bundle.
'''

from __future__ import annotations

from ats_utilities.base.setup.factory import BaseBundleFactory
from ats_utilities.base.setup.bundle import BaseBundle
from ats_utilities.base.setup.options import BaseBundleOptions
from ats_utilities.context.bundle import ContextBundle
from ats_utilities.context.factory import ContextBundleFactory

from gen_unix_domain_socket.setup.bundle import GenUnixDomainSocketBundle
from gen_unix_domain_socket.setup.options import GenUnixDomainSocketBundleOptions
from gen_unix_domain_socket.setup.registry import GenUnixDomainSocketBundleRegistry
from gen_unix_domain_socket.setup.dependencies import GenUnixDomainSocketBundleDependencies
from gen_unix_domain_socket.setup.opt_validator import GenUnixDomainSocketBundleOptionsValidator
from gen_unix_domain_socket.setup.keys import GenUnixDomainSocketBundleKeys
from gen_unix_domain_socket.core.service.engine import Service
from gen_unix_domain_socket.infrastructure.subprocessor import SubProcessor
from gen_unix_domain_socket.infrastructure.cli.engine import CLI
from gen_unix_domain_socket.infrastructure.cli.setup.bundle import CLIBundle
from gen_unix_domain_socket.infrastructure.cli.setup.dependencies import CLIBundleDependencies
from gen_unix_domain_socket.infrastructure.cli.setup.registry import CLIBundleRegistry
from gen_unix_domain_socket.infrastructure.command.command import CommandBundle
from gen_unix_domain_socket.infrastructure.command.gen_unix_domain_socket_command_definition import GenUnixDomainSocketCommandDefinition
from gen_unix_domain_socket.infrastructure.command.gen_unix_domain_socket_command_executor import GenUnixDomainSocketCommandExecutor

__author__ = 'Vladimir Roncevic'
__copyright__ = '(C) 2026, https://vroncevic.github.io/gen_unix_domain_socket'
__credits__ = ['Vladimir Roncevic', 'Python Software Foundation']
__license__ = 'https://github.com/vroncevic/gen_unix_domain_socket/blob/dev/LICENSE'
__version__ = '1.0.7'
__maintainer__ = 'Vladimir Roncevic'
__email__ = 'elektron.ronca@gmail.com'
__status__ = 'Updated'


class GenUnixDomainSocketBundleFactory:
    '''
        Factory for creating the gen_unix_domain_socket bundle.

        It defines:

            :attributes:
                | _info_file - Path to the gen_unix_domain_socket info file.
            :methods:
                | create_bundle - Creates the gen_unix_domain_socket bundle with optional pre-configured options.
                | get_version - Returns the factory version.
    '''

    _info_file: str = 'gen_unix_domain_socket/infrastructure/config/gen_unix_domain_socket.cfg'

    @classmethod
    def create_bundle(cls, options: GenUnixDomainSocketBundleOptions | None = None) -> GenUnixDomainSocketBundle:
        '''
            Creates the gen_unix_domain_socket bundle with optional pre-configured options.

            :param options: The pre-configured options for the gen_unix_domain_socket bundle.
            :return: The gen_unix_domain_socket bundle.
            :exceptions:
                | ATSValueError: The gen_unix_domain_socket bundle options must be provided and have proper values.
                | ATSTypeError:  The gen_unix_domain_socket bundle options must be an instance of Mapping and its
                |                attributes must be instances of their respective types.
                | ATSValueError: The gen_unix_domain_socket bundle dependencies must be provided and have proper values.
                | ATSTypeError:  The gen_unix_domain_socket bundle dependencies must be an instance of Mapping and its
                |                attributes must be instances of their respective types.
                | ATSValueError: The gen_unix_domain_socket bundle must be provided and have proper values.
                | ATSTypeError:  The gen_unix_domain_socket bundle must be an instance of GenUnixDomainSocketBundle and
                |                its attributes must be instances of their respective types.
        '''
        if options is not None:
            GenUnixDomainSocketBundleOptionsValidator.validate(options)

        info_file = options.get(GenUnixDomainSocketBundleKeys.OPTION_INFO_FILE) if options else cls._info_file

        context_bundle: ContextBundle = ContextBundleFactory.create_bundle()

        base_bundle: BaseBundle = BaseBundleFactory.create_bundle(
            options=BaseBundleOptions(
                info_file=info_file,
                use_generator=True,
                context_bundle=context_bundle
            )
        )

        subprocessor: SubProcessor = SubProcessor(generator=base_bundle.generation_manager)

        service: Service = Service(subprocessor=subprocessor)

        gen_unix_domain_socket_definition: GenUnixDomainSocketCommandDefinition = GenUnixDomainSocketCommandDefinition()

        gen_unix_domain_socket_bundle: CommandBundle = CommandBundle(
            definition=gen_unix_domain_socket_definition,
            executor=GenUnixDomainSocketCommandExecutor(gen_unix_domain_socket_definition)
        )

        cli_bundle: CLIBundle = CLIBundleRegistry.create_bundle(
            dependencies=CLIBundleDependencies(
                service=service,
                parser=base_bundle.option_manager,
                commands=[gen_unix_domain_socket_bundle]
            )
        )

        cli: CLI = CLI(cli_bundle)

        return GenUnixDomainSocketBundleRegistry.create_bundle(
            dependencies=GenUnixDomainSocketBundleDependencies(
                base=base_bundle,
                service=service,
                subprocessor=subprocessor,
                cli=cli
            )
        )

    @classmethod
    def get_version(cls) -> str:
        '''
            Returns the factory version.

            :return: The factory version.
            :exceptions: None.
        '''
        return __version__
