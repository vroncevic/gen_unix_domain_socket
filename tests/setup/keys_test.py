# -*- coding: UTF-8 -*-

'''
Module
    keys_test.py
Info
    Unit tests for GenUnixDomainSocketBundleKeys class.
'''

from __future__ import annotations

import unittest
from types import MappingProxyType

from gen_unix_domain_socket.setup.keys import GenUnixDomainSocketBundleKeys


class TestGenUnixDomainSocketBundleKeys(unittest.TestCase):

    def test_get_dependency_to_type(self) -> None:
        deps = GenUnixDomainSocketBundleKeys.get_dependency_to_type()
        self.assertIsInstance(deps, MappingProxyType)
        self.assertIn(GenUnixDomainSocketBundleKeys.DEPENDENCY_BASE, deps)
        self.assertIn(GenUnixDomainSocketBundleKeys.DEPENDENCY_SERVICE, deps)
        self.assertIn(GenUnixDomainSocketBundleKeys.DEPENDENCY_SUBPROCESSOR, deps)
        self.assertIn(GenUnixDomainSocketBundleKeys.DEPENDENCY_CLI, deps)

    def test_get_option_to_type(self) -> None:
        opts = GenUnixDomainSocketBundleKeys.get_option_to_type()
        self.assertIsInstance(opts, MappingProxyType)
        self.assertIn(GenUnixDomainSocketBundleKeys.OPTION_INFO_FILE, opts)
