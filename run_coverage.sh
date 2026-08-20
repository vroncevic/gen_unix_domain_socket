#!/bin/bash
#
# @brief   gen_unix_domain_socket
# @version 1.0.7
# @date    Sun Aug 09 08:03:10 2026
# @company None, free software to use 2026
# @author  Vladimir Roncevic <elektron.ronca@gmail.com>
#

python3 coverage/ats_coverage.py gen_unix_domain_socket
pylint gen_unix_domain_socket > gen_unix_domain_socket.report
echo "Done"
