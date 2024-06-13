UDS code generator
====================

**gen_unix_domain_socket** is toolset for generation of UDS skeleton for
development embedded applications.

Developed in `python <https://www.python.org/>`_ code.

The README is used to introduce the tool modules and provide instructions on
how to install the tool modules, any machine dependencies it may have and any
other information that should be provided before the modules are installed.

|gen_unix_domain_socket python checker| |gen_unix_domain_socket python package| |github issues| |documentation status| |github contributors|

.. |gen_unix_domain_socket python checker| image:: https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python_checker.yml/badge.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python_checker.yml

.. |gen_unix_domain_socket python package| image:: https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_package_checker.yml/badge.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_package.yml

.. |github issues| image:: https://img.shields.io/github/issues/vroncevic/gen_unix_domain_socket.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/issues

.. |github contributors| image:: https://img.shields.io/github/contributors/vroncevic/gen_unix_domain_socket.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/graphs/contributors

.. |documentation status| image:: https://readthedocs.org/projects/gen-unix-domain-socket/badge/?version=latest
   :target: https://gen-unix-domain-socket.readthedocs.io/en/latest/?badge=latest

.. toctree::
   :maxdepth: 4
   :caption: Contents

   modules
   self

Installation
-------------

|gen_unix_domain_socket python3 build|

.. |gen_unix_domain_socket python3 build| image:: https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python3_build.yml/badge.svg
   :target: https://github.com/vroncevic/gen_unix_domain_socket/actions/workflows/gen_unix_domain_socket_python3_build.yml

Navigate to release `page`_ download and extract release archive.

.. _page: https://github.com/vroncevic/gen_unix_domain_socket/releases

To install **gen_unix_domain_socket** type the following

.. code-block:: bash

    tar xvzf gen_unix_domain_socket-x.y.z.tar.gz
    cd gen_unix_domain_socket-x.y.z/
    #python3
    python3 setup.py install_lib
    python3 setup.py install_data
    python3 setup.py install_egg_info

You can use Docker to create image/container, or You can use pip to install

.. code-block:: bash

    #python3
    pip3 install gen-unix-domain-socket

Dependencies
-------------

**gen_unix_domain_socket** tool-module requires other modules and libraries

* `ats-utilities - Python App/Tool/Script Utilities <https://pypi.org/project/ats-utilities/>`_

Tool structure
---------------

**gen_unix_domain_socket** is based on Template mechanism

Generator structure

.. code-block:: bash

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

Copyright and licence
----------------------

|license: gpl v3| |license: apache 2.0|

.. |license: gpl v3| image:: https://img.shields.io/badge/license-gplv3-blue.svg
   :target: https://www.gnu.org/licenses/gpl-3.0

.. |license: apache 2.0| image:: https://img.shields.io/badge/license-apache%202.0-blue.svg
   :target: https://opensource.org/licenses/apache-2.0

Copyright (C) 2017 - 2024 by `vroncevic.github.io/gen_unix_domain_socket <https://vroncevic.github.io/gen_unix_domain_socket>`_

**gen_unix_domain_socket** is free software; you can redistribute it and/or modify
it under the same terms as Python itself, either Python version 3.x or,
at your option, any later version of Python 3 you may have available.

Lets help and support PSF.

|python software foundation|

.. |python software foundation| image:: https://raw.githubusercontent.com/vroncevic/gen_unix_domain_socket/dev/docs/psf-logo-alpha.png
   :target: https://www.python.org/psf/

|donate|

.. |donate| image:: https://www.paypalobjects.com/en_us/i/btn/btn_donatecc_lg.gif
   :target: https://www.python.org/psf/donations/

Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`