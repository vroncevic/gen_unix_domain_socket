# -*- coding: UTF-8 -*-

'''
Module
    opt_validator_test.py
Info
    Unit tests for GenUnixDomainSocketBundleOptionsValidator class.
'''

from __future__ import annotations

import unittest

from gen_unix_domain_socket.setup.opt_validator import GenUnixDomainSocketBundleOptionsValidator


class TestGenUnixDomainSocketBundleOptionsValidator(unittest.TestCase):

    def test_validate_success(self) -> None:
        options = {'info_file': 'some_path'}
        GenUnixDomainSocketBundleOptionsValidator.validate(options)

    def test_validate_none(self) -> None:
        with self.assertRaises(Exception):
            GenUnixDomainSocketBundleOptionsValidator.validate(None)

    def test_validate_invalid_type(self) -> None:
        with self.assertRaises(Exception):
            GenUnixDomainSocketBundleOptionsValidator.validate("not_a_mapping")

    def test_validate_invalid_option_type(self) -> None:
        with self.assertRaises(Exception):
            options = {'info_file': 123}
            GenUnixDomainSocketBundleOptionsValidator.validate(options)

    def test_is_valid_success(self) -> None:
        options = {'info_file': 'some_path'}
        self.assertTrue(GenUnixDomainSocketBundleOptionsValidator.is_valid(options))

    def test_is_valid_failure(self) -> None:
        self.assertFalse(GenUnixDomainSocketBundleOptionsValidator.is_valid(None))
        self.assertFalse(GenUnixDomainSocketBundleOptionsValidator.is_valid("not_a_mapping"))
        self.assertFalse(GenUnixDomainSocketBundleOptionsValidator.is_valid({'info_file': 123}))
