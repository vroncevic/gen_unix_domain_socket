#!/bin/bash
#
# @brief   gen_unix_domain_socket
# @version 1.0.7
# @date    Sun Aug 09 08:03:10 2026
# @company None, free software to use 2026
# @author  Vladimir Roncevic <elektron.ronca@gmail.com>
#

python3 gates/gates/interfaces_checker.py gen_unix_domain_socket
python3 gates/gates/isp_checker.py gen_unix_domain_socket
python3 gates/gates/limits_checker.py gen_unix_domain_socket
python3 gates/gates/srp_checker.py gen_unix_domain_socket

echo "Done"
