/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_accept.c
 * Copyright (C) 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
 *
 * mytool is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mytool is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "uds.h"

/**
 * Description:
 *     Accept a connection on a socket.
 *
 * Arguments:
 *     socket_descriptor - socket descriptor
 *     address - socket address structure
 *     address_length - size of peer address
 *
 * Return value:
 *     file_descriptor - file descriptor for the accepted socket
 *                       (a nonnegative integer) | UDS_ERROR  error number
 *                       is set to indicate the error:
 *                           EBADF (sockfd is not an open file descriptor)
 *                           ECONNABORTED (connection has been aborted)
 *                           EFAULT (address argument is not in a writable
 *                                   part of the user  address space)
 *                           EINTR (system call was interrupted by a signal
 *                                  that was caught before a valid connection
 *                                  arrived)
 *                           EINVAL (socket is not listening for connections,
 *                                   or addrlen is invalid (e.g., is negative))
 *                           EMFILE (per-process limit on the number of open
 *                                   file descriptors has been reached)
 *                           ENFILE (system-wide limit on the total number of
 *                                   open files has been reached)
 *                           ENOBUFS, ENOMEM (not enough free memory, often
 *                                            means that the memory allocation
 *                                            is limited by the socket buffer
 *                                            limits, not by the system memory)
 *                           ENOTSOCK (file descriptor doesn't refer to socket)
 *                           EOPNOTSUPP (referenced socket isn't of type
 *                                       SOCK_STREAM)
 *                           EPROTO (protocol error)
 *                           EPERM (firewall rules forbid connection)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_accept(
    int socket_descriptor,
    struct sockaddr * restrict address,
    socklen_t * restrict address_length
) {
    int file_descriptor;
    if (socket_descriptor >= 0 && address != NULL) {
        file_descriptor = accept(socket_descriptor, address, address_length);
    } else {
        file_descriptor = UDS_ERROR;
    }
    return file_descriptor;
}

