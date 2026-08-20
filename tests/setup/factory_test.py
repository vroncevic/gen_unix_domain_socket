# -*- coding: UTF-8 -*-

'''
Module
    factory_test.py
Info
    Unit tests for GenUnixDomainSocketBundleFactory class.
'''

from __future__ import annotations

import unittest

from gen_unix_domain_socket.setup.bundle import GenUnixDomainSocketBundle
from gen_unix_domain_socket.setup.factory import GenUnixDomainSocketBundleFactory


class TestGenUnixDomainSocketBundleFactory(unittest.TestCase):

    def test_create_bundle_default(self) -> None:
        bundle = GenUnixDomainSocketBundleFactory.create_bundle()
        self.assertIsInstance(bundle, GenUnixDomainSocketBundle)

    def test_create_bundle_with_options(self) -> None:
        options = {'info_file': 'gen_unix_domain_socket/infrastructure/config/gen_unix_domain_socket.cfg'}
        bundle = GenUnixDomainSocketBundleFactory.create_bundle(options)
        self.assertIsInstance(bundle, GenUnixDomainSocketBundle)

    def test_create_bundle_invalid_options(self) -> None:
        options = {'info_file': 123}
        with self.assertRaises(Exception):
            GenUnixDomainSocketBundleFactory.create_bundle(options)

    def test_get_version(self) -> None:
        self.assertEqual(GenUnixDomainSocketBundleFactory.get_version(), '1.0.7')
