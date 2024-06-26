/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_connect.c
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
 *     Initiate a connection on a socket.
 *
 * Arguments:
 *     socket_descriptor - socket descriptor
 *     address - socket address structure
 *     address_length -  size of peer address
 *
 * Return value:
 *     status - if the connection or binding succeeds, zero is returned |
 *              UDS_ERROR error number is set to indicate the error:
 *                  EACCES (for UNIX domain sockets, which are identified by
 *                          pathname write permission is denied on the socket
 *                          file, or search permission is denied for one of
 *                          the directories in the path prefix)
 *                  EACCES, EPERM (user tried to connect to a broadcast
 *                                 address without having socket broadcast
 *                                 flag enabled or connection equest failed
 *                                 because of a local firewall rule, EACCES
 *                                 can also be returned if an SELinux policy
 *                                 denied a connection (for example, if there
 *                                 is a policy saying that an HTTP proxy can
 *                                 only connect to ports associated with HTTP
 *                                 servers, and the proxy tries to connect to
 *                                 a different port)
 *                  EADDRINUSE (local address is already in use)
 *                  EADDRNOTAVAIL ((internet domain sockets) socket referred
 *                                 to by had not previously been bound
 *                                 to an address and, upon attempting to bind
 *                                 it to an ephemeral port, it was determined
 *                                 that all port numbers in the ephemeral port
 *                                 range are currently in use)
 *                  EAFNOSUPPORT (passed address didn't have correct address
 *                                family in its sa_family field)
 *                  EAGAIN (for nonblocking UNIX domain sockets, socket is
 *                          nonblocking, and the connection cannot be
 *                          completed immediately, for other socket families,
 *                          there are insufficient entries in routing cache)
 *                  EALREADY (socket is nonblocking and a previous connection
 *                            attempt has not yet been completed)
 *                  EBADF (not a valid open file descriptor)
 *                  ECONNREFUSED (on a stream socket found no one listening
 *                                on the remote address)
 *                  EFAULT (socket structure address is outside the user's
 *                          address space)
 *                  EINPROGRESS (socket is nonblocking and connection cannot
 *                               be completed immediately (UNIX domain sockets
 *                               failed with EAGAIN instead)
 *                  EINTR (sys call was interrupted by signal that was caught)
 *                  EISCONN (socket is already connected)
 *                  ENETUNREACH (network is unreachable)
 *                  ENOTSOCK (file descriptor does not refer to a socket)
 *                  EPROTOTYPE (socket type does not support requested
 *                              communications protocol example, on an
 *                              attempt to connect a UNIX domain datagram
 *                              socket to a stream socket)
 *                  ETIMEDOUT (timeout while attempting connection, server may
 *                             be too busy to accept new connections)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_connect(
    int socket_descriptor,
    const struct sockaddr * address,
    socklen_t address_length
) {
    int status;
    if (socket_descriptor >= 0 && address != NULL) {
        status = connect(socket_descriptor, address, address_length);
    } else {
        status = UDS_ERROR;
    }
    return status;
}

