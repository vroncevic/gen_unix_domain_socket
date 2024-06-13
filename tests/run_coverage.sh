#!/bin/bash
#
# @brief   gen_unix_domain_socket
# @version v1.0.1
# @date    Thu Jun 13 08:47:12 PM CEST 2024
# @company None, free software to use 2024
# @author  Vladimir Roncevic <elektron.ronca@gmail.com>
#

rm -rf mytool
python3 -m coverage run -m --source=../gen_unix_domain_socket unittest discover -s ./ -p '*_test.py' -vvv
python3 -m coverage html

