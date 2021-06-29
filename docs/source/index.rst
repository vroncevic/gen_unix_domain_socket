Generate Unix Domain Socket
----------------------------

**gen_unix_domain_socket** is framework for generation Unix Domain Socket modules.

Developed in `python <https://www.python.org/>`_ code: **100%**.

The README is used to introduce the modules and provide instructions on
how to install the modules, any machine dependencies it may have and any
other information that should be provided before the modules are installed.

|Python package| |GitHub issues| |Documentation Status| |GitHub contributors|

.. |Python package| image:: https://github.com/vroncevic/gen_unix_domain_socket/workflows/Python%20package%20gen_unix_domain_socket/badge.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/workflows/Python%20package%20gen_unix_domain_socket/badge.svg?branch=master

.. |GitHub issues| image:: https://img.shields.io/github/issues/vroncevic/gen_unix_domain_socket.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/issues

.. |GitHub contributors| image:: https://img.shields.io/github/contributors/vroncevic/gen_unix_domain_socket.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/graphs/contributors

.. |Documentation Status| image:: https://readthedocs.org/projects/gen_unix_domain_socket/badge/?version=latest
   :target: https://gen_unix_domain_socket.readthedocs.io/projects/gen_unix_domain_socket/en/latest/?badge=latest

.. toctree::
   :maxdepth: 4
   :caption: Contents:

   self
   modules

Installation
-------------

|Install Python2 Package| |Install Python3 Package|

.. |Install Python2 Package| image:: https://github.com/vroncevic/gen_unix_domain_socket/workflows/Install%20Python2%20Package%20gen_unix_domain_socket/badge.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/workflows/Install%20Python2%20Package%20gen_unix_domain_socket/badge.svg?branch=master

.. |Install Python3 Package| image:: https://github.com/vroncevic/gen_unix_domain_socket/workflows/Install%20Python3%20Package%20gen_unix_domain_socket/badge.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/workflows/Install%20Python3%20Package%20gen_unix_domain_socket/badge.svg?branch=master

Navigate to release `page`_ download and extract release archive.

.. _page: https://github.com/vroncevic/gen_unix_domain_socket/releases

To install package type the following:

.. code-block:: bash

    tar xvzf gen_unix_domain_socket-x.y.z.tar.gz
    cd gen_unix_domain_socket-x.y.z/
    # python2
    pip install -r requirements.txt
    python setup.py install_lib
    python setup.py install_data
    python setup.py install_egg_info
    # pyton3
    pip3 install -r requirements.txt
    python3 setup.py install_lib
    python3 setup.py install_data
    python3 setup.py install_egg_info

You can use Docker to create image/container, or You can use pip to install:

.. code-block:: bash

    # python2
    pip install gen-unix-domain-socket
    # python3
    pip3 install gen-unix-domain-socket

|GitHub docker checker|

.. |GitHub docker checker| image:: https://github.com/vroncevic/gen_unix_domain_socket/workflows/gen_unix_domain_socket%20docker%20checker/badge.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/actions?query=workflow%3A%22gen_unix_domain_socket+docker+checker%22

Dependencies
-------------

**gen_unix_domain_socket** requires next modules and libraries:

* `ats-utilities - Python App/Tool/Script Utilities <https://pypi.org/project/ats-utilities/>`_

Framework structure
--------------------

**gen_unix_domain_socket** is based on OOP:

.. image:: https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/gen_unix_domain_socket_flow.png

Framework structure:

.. code-block:: bash

    gen_unix_domain_socket/
    ├── conf/
    │   ├── gen_unix_domain_socket.cfg
    │   ├── gen_unix_domain_socket_util.cfg
    │   ├── project.yaml
    │   └── template/
    │       └── posix/
    │           ├── uds_accept.template
    │           ├── uds_bind.template
    │           ├── uds_connect.template
    │           ├── uds_fatal_error.template
    │           ├── uds_listen.template
    │           ├── uds_read.template
    │           ├── uds_socket.template
    │           ├── uds.template
    │           ├── uds_unlink.template
    │           └── uds_write.template
    ├── __init__.py
    ├── log/
    │   └── gen_unix_domain_socket.log
    ├── pro/
    │   ├── config/
    │   │   ├── __init__.py
    │   │   ├── pro_name.py
    │   │   └── template_dir.py
    │   ├── __init__.py
    │   ├── read_template.py
    │   └── write_template.py
    └── run/
        └── gen_unix_domain_socket_run.py

Copyright and licence
----------------------

|License: GPL v3| |License: Apache 2.0|

.. |License: GPL v3| image:: https://img.shields.io/badge/License-GPLv3-blue.svg
   :target: https://www.gnu.org/licenses/gpl-3.0

.. |License: Apache 2.0| image:: https://img.shields.io/badge/License-Apache%202.0-blue.svg
   :target: https://opensource.org/licenses/Apache-2.0

Copyright (C) 2018 by `vroncevic.github.io/gen_unix_domain_socket <https://vroncevic.github.io/gen_unix_domain_socket>`_

**gen_unix_domain_socket** is free software; you can redistribute it and/or modify
it under the same terms as Python itself, either Python version 2.x/3.x or,
at your option, any later version of Python 3 you may have available.

Lets help and support PSF.

|Python Software Foundation|

.. |Python Software Foundation| image:: https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/psf-logo-alpha.png
   :target: https://www.python.org/psf/

|Donate|

.. |Donate| image:: https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif
   :target: https://psfmember.org/index.php?q=civicrm/contribute/transact&reset=1&id=2

Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
