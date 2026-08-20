# Create UnixDomainSocket project skeleton

<img align="right" src="https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/gen_unix_domain_socket_logo.png" width="25%">

**gen_unix_domain_socket** is tool for creating UnixDomainSocket project skeleton.

Developed in **[python](https://www.python.org/)** code.

The README is used to introduce the tool and provide instructions on
how to install the tool, any machine dependencies it may have and any
other information that should be provided before the tool is installed.

[![gen_unix_domain_socket python checker](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python_checker.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python_checker.yml) [![gen_unix_domain_socket package checker](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_package_checker.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_package.yml) [![gen_unix_domain_socket interface checker](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_interface_checker.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_interface_checker.yml) [![gen_unix_domain_socket isp checker](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_isp_checker.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_isp_checker.yml) [![gen_unix_domain_socket srp checker](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_srp_checker.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_srp_checker.yml) [![GitHub issues open](https://img.shields.io/github/issues/vroncevic/gen_unix_domain_socket.svg) [![GitHub contributors](https://img.shields.io/github/contributors/vroncevic/gen_unix_domain_socket.svg)

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [🚀 Installation](#-installation)
    - [Install using pip](#install-using-pip)
    - [Install using build](#install-using-build)
    - [Install using py setup](#install-using-py-setup)
    - [Install using docker](#install-using-docker)
- [📦 Dependencies](#-dependencies)
- [📁 Tool structure](#-tool-structure)
  - [✨ Features](#-features)
- [📊 Code coverage](#-code-coverage)
- [🛠 Usage](#-usage)
- [📚 Docs](#-docs)
- [👥 Contributing](#-contributing)
- [📄 Copyright and licence](#-copyright-and-licence)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

### 🚀 Installation

Used next development environment

![debian linux os](https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/debtux.png)

[![gen_unix_domain_socket python3 build](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python3_build.yml/badge.svg)](https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python3_build.yml)

Currently there are four ways to install package
* Install process based on using pip mechanism
* Install process based on build mechanism
* Install process based on setup.py mechanism
* Install process based on docker mechanism

##### Install using pip

**gen_unix_domain_socket** is located at **[pypi.org](https://pypi.org/project/gen_unix_domain_socket/)**.

You can install by using pip

```bash
# python3
pip3 install gen_unix_domain_socket
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
# python3
python3 get-pip.py
python3 -m pip install --upgrade setuptools
python3 -m pip install --upgrade pip
python3 -m pip install --upgrade build
pip3 install -r requirements.txt
python3 -m build --no-isolation --wheel
pip3 install ./dist/gen_unix_domain_socket-*-py3-none-any.whl
rm -f get-pip.py
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

### 📦 Dependencies

**gen_unix_domain_socket** requires next modules and libraries

* [ats-utilities - Python App/Tool/Script Utilities](https://pypi.org/project/ats-utilities/)

### 📁 Tool structure

**gen_unix_domain_socket** is based on OOP.

Tool structure

<details>
<summary><b>Click to expand framework structure</b></summary>

```bash
    gen_unix_domain_socket/
         ├── core/
         │   ├── __init__.py
         │   ├── model/
         │   │   ├── __init__.py
         │   │   └── project_setup.py
         │   └── service/
         │       ├── engine.py
         │       ├── __init__.py
         │       ├── iservice.py
         │       └── isubprocessor.py
         ├── engine.py
         ├── infrastructure/
         │   ├── cli/
         │   │   ├── engine.py
         │   │   ├── icli.py
         │   │   ├── __init__.py
         │   │   └── setup/
         │   │       ├── bundle.py
         │   │       ├── dep_validator.py
         │   │       ├── dependencies.py
         │   │       ├── factory.py
         │   │       ├── __init__.py
         │   │       ├── keys.py
         │   │       ├── opt_validator.py
         │   │       ├── options.py
         │   │       ├── registry.py
         │   │       └── validator.py
         │   ├── command/
         │   │   ├── command.py
         │   │   ├── gen_unix_domain_socket_command_definition.py
         │   │   ├── gen_unix_domain_socket_command_executor.py
         │   │   ├── icommand_definition.py
         │   │   ├── icommand_executor.py
         │   │   └── __init__.py
         │   ├── config/
         │   │   ├── gen_unix_domain_socket.cfg
         │   │   ├── gen_unix_domain_socket.logo
         │   │   ├── scheme.json
         │   │   └── templates.tgz
         │   └── subprocessor.py
         ├── __init__.py
         ├── py.typed
         └── setup/
             ├── bundle.py
             ├── dep_validator.py
             ├── dependencies.py
             ├── factory.py
             ├── __init__.py
             ├── keys.py
             ├── opt_validator.py
             ├── options.py
             ├── registry.py
             └── validator.py

     10 directories, 44 files
```
</details>

#### ✨ Features

* Automatically scaffolds UnixDomainSocket projects with build/make files.
* Provides a modular and extensible architecture based on OOP and SOLID principles.
* Includes command line interface (CLI) support via a command/executor structure.
* Robust validation of project bundles, dependencies, and options.
* Comes with configurable templates and JSON schema definitions.
* High code quality with full type checking and 100% unit test coverage.

### 📊 Code coverage

<details>
<summary><b>Click to expand code coverage</b></summary>

| Name | Stmts | Miss | Cover |
|------|-------|------|-------|
| `gen_unix_domain_socket/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/core/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/core/model/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/core/model/project_setup.py` | 14 | 0 | 100%|
| `gen_unix_domain_socket/core/service/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/core/service/engine.py` | 27 | 0 | 100%|
| `gen_unix_domain_socket/core/service/iservice.py` | 14 | 0 | 100%|
| `gen_unix_domain_socket/core/service/isubprocessor.py` | 14 | 0 | 100%|
| `gen_unix_domain_socket/engine.py` | 57 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/engine.py` | 39 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/icli.py` | 14 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/bundle.py` | 22 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/dep_validator.py` | 36 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/dependencies.py` | 18 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/factory.py` | 35 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/keys.py` | 26 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/opt_validator.py` | 36 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/options.py` | 15 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/registry.py` | 24 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/cli/setup/validator.py` | 43 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/command/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/command/command.py` | 16 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/command/gen_unix_domain_socket_command_definition.py` | 24 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/command/gen_unix_domain_socket_command_executor.py` | 21 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/command/icommand_definition.py` | 14 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/command/icommand_executor.py` | 13 | 0 | 100%|
| `gen_unix_domain_socket/infrastructure/subprocessor.py` | 57 | 0 | 100%|
| `gen_unix_domain_socket/setup/__init__.py` | 9 | 0 | 100%|
| `gen_unix_domain_socket/setup/bundle.py` | 23 | 0 | 100%|
| `gen_unix_domain_socket/setup/dep_validator.py` | 36 | 0 | 100%|
| `gen_unix_domain_socket/setup/dependencies.py` | 19 | 0 | 100%|
| `gen_unix_domain_socket/setup/factory.py` | 48 | 0 | 100%|
| `gen_unix_domain_socket/setup/keys.py` | 27 | 0 | 100%|
| `gen_unix_domain_socket/setup/opt_validator.py` | 34 | 0 | 100%|
| `gen_unix_domain_socket/setup/options.py` | 12 | 0 | 100%|
| `gen_unix_domain_socket/setup/registry.py` | 32 | 0 | 100%|
| `gen_unix_domain_socket/setup/validator.py` | 48 | 0 | 100%|
| **Total** | 930 | 0 | 100% |

</details>

### 🛠 Usage

Install package

```bash
pip3 install gen_unix_domain_socket
```

Prepare main entry point by downloading [main.py](https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/main/main.py) or create your own.


```bash
wget -O main.py https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/main/main.py
```

Running tool for creating new UnixDomainSocket project skeleton

```bash
python3 main.py create --name mytool --type base --output ./demo/
```

### 📚 Docs

[![Documentation Status](https://readthedocs.org/projects/gen-unix-domain-socket/badge/?version=latest)](https://gen-unix-domain-socket.readthedocs.io/en/latest/?badge=latest)

More documentation and info at

* [gen_unix_domain_socket.readthedocs.io](https://gen-unix-domain-socket.readthedocs.io)
* [www.python.org](https://www.python.org/)

### 👥 Contributing

[Contributing to gen_unix_domain_socket](CONTRIBUTING.md)

### 📄 Copyright and licence

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

Copyright (C) 2025 - 2026 by [vroncevic.github.io/gen_unix_domain_socket](https://vroncevic.github.io/gen_unix_domain_socket/)

**gen_unix_domain_socket** is free software; you can redistribute it and/or modify
it under the same terms as Python itself, either Python version 3.x or,
at your option, any later version of Python 3 you may have available.

Lets help and support PSF.

[![Python Software Foundation](https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/psf-logo-alpha.png)](https://www.python.org/psf/)

[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.python.org/psf/donations/)
