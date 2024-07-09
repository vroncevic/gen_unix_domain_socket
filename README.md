# Generate Unix Domain Socket

<img align="right" src="https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/gen_unix_domain_socket_logo.png" width="25%">

**gen_unix_domain_socket** is tool for generation of unix domain socket.

Developed in **[python](https://www.python.org/)** code: **100%**.

The README is used to introduce the modules and provide instructions on
how to install the modules, any machine dependencies it may have and any
other information that should be provided before the modules are installed.

[![gen_unix_domain_socket python checker](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python_checker.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python_checker.yml) [![gen_unix_domain_socket package checker](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_package_checker.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_package.yml) [![GitHub issues open](https://img.shields.io/github/issues/vroncevic/gen_unix_domain_socket.svg)](https://github.com/vroncevic/gen_unix_domain_socket/issues) [![GitHub contributors](https://img.shields.io/github/contributors/vroncevic/gen_unix_domain_socket.svg)](https://github.com/vroncevic/gen_unix_domain_socket/graphs/contributors)

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [Installation](#installation)
    - [Install using pip](#install-using-pip)
    - [Install using build](#install-using-build)
    - [Install using py setup](#install-using-py-setup)
    - [Install using docker](#install-using-docker)
- [Dependencies](#dependencies)
- [Tool structure](#tool-structure)
- [Docs](#docs)
- [Contributing](#contributing)
- [Copyright and Licence](#copyright-and-licence)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

### Installation

Used next development environment

![debian linux os](https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/debtux.png)

[![gen_unix_domain_socket python3 build](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python3_build.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python3_build.yml)

Currently there are three ways to install package
* Install process based on using pip mechanism
* Install process based on build mechanism
* Install process based on setup.py mechanism
* Install process based on docker mechanism

##### Install using pip

Python is located at **[pypi.org](https://pypi.org/project/gen-unix-domain-socket/)**.

You can install by using pip

```bash
#python3
pip3 install gen-unix-domain-socket
```

##### Install using build

Navigate to release **[page](https://github.com/vroncevic/gen_unix_domain_socket/releases/)** download and extract release archive.

To install **gen_unix_domain_socket** type the following

```bash
tar xvzf gen_unix_domain_socket-x.y.z.tar.gz
cd gen_unix_domain_socket-x.y.z/
# python3
wget https://bootstrap.pypa.io/get-pip.py
python3 get-pip.py 
python3 -m pip install --upgrade setuptools
python3 -m pip install --upgrade pip
python3 -m pip install --upgrade build
pip3 install -r requirements.txt
python3 -m build --no-isolation --wheel
pip3 install ./dist/gen_unix_domain_socket-*-py3-none-any.whl
rm -f get-pip.py
chmod 755 /usr/local/lib/python3.9/dist-packages/usr/local/bin/gen_unix_domain_socket_run.py
ln -s /usr/local/lib/python3.9/dist-packages/usr/local/bin/gen_unix_domain_socket_run.py /usr/local/bin/gen_unix_domain_socket_run.py
```

##### Install using py setup

Navigate to **[release page](https://github.com/vroncevic/gen_unix_domain_socket/releases)** download and extract release archive.

To install **gen_unix_domain_socket** locate and run setup.py with arguments

```bash
tar xvzf gen_unix_domain_socket-x.y.z.tar.gz
cd gen_unix_domain_socket-x.y.z
# python3
pip3 install -r requirements.txt
python3 setup.py install_lib
python3 setup.py install_egg_info
```

##### Install using docker

You can use Dockerfile to create image/container.

### Dependencies

**gen_unix_domain_socket** tool requires other modules/libraries

- [ats-utilities - Python App/Tool/Script Utilities](https://vroncevic.github.io/gen_unix_domain_socket)

### Tool structure

**gen_unix_domain_socket** is based on OOP

Generator structure

```bash
    gen_unix_domain_socket/
            ├── conf/
            │   ├── gen_unix_domain_socket.cfg
            │   ├── gen_unix_domain_socket.logo
            │   ├── gen_unix_domain_socket_util.cfg
            │   ├── project.yaml
            │   └── template/
            │       ├── uds_accept.template
            │       ├── uds_bind.template
            │       ├── uds_connect.template
            │       ├── uds_fatal_error.template
            │       ├── uds_listen.template
            │       ├── uds_read.template
            │       ├── uds_socket.template
            │       ├── uds.template
            │       ├── uds_unlink.template
            │       └── uds_write.template
            ├── __init__.py
            ├── log/
            │   └── gen_unix_domain_socket.log
            ├── pro/
            │   ├── __init__.py
            │   ├── read_template.py
            │   └── write_template.py
            ├── py.typed
            └── run/
                └── gen_unix_domain_socket_run.py

    6 directories, 21 files
```

### Code coverage

| Name | Stmts | Miss | Cover |
|------|-------|------|-------|
| `gen_unix_domain_socket/__init__.py` | 71 | 14 | 80% |
| `gen_unix_domain_socket/pro/__init__.py` | 60 | 6 | 90% |
| `gen_unix_domain_socket/pro/read_template.py` | 43 | 4 | 91% |
| `gen_unix_domain_socket/pro/write_template.py` | 51 | 5 | 90% |
| **Total** | 225 | 29 | 87% |

### Docs

[![Documentation Status](https://readthedocs.org/projects/gen-unix-domain-socket/badge/?version=latest)](https://gen-unix-domain-socket.readthedocs.io/en/latest/?badge=latest)

More documentation and info at

* [gen_unix_domain_socket.readthedocs.io](https://gen-unix-domain-socket.readthedocs.io)
* [www.python.org](https://www.python.org/)

### Contributing

[Contributing to gen_unix_domain_socket](CONTRIBUTING.md)

### Copyright and Licence

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

Copyright (C) 2017 - 2024 by [vroncevic.github.io/gen_unix_domain_socket](https://vroncevic.github.io/gen_unix_domain_socket/)

**gen_unix_domain_socket** is free software; you can redistribute it and/or modify
it under the same terms as Python itself, either Python version 3.x or,
at your option, any later version of Python 3 you may have available.

Lets help and support PSF.

[![Python Software Foundation](https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/psf-logo-alpha.png)](https://www.python.org/psf/)

[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.python.org/psf/donations/)
