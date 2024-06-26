/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_socket.c
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
 *     address_length -  size of peer address
 *
 * Return value:
 *     file_descriptor - on success, a file descriptor for the new socket is
 *                       returned | UDS_ERROR and error number is set to
 *                       indicate the error:
 *                           EACCES (permission to create socket of specified
 *                                   type and/or protocol is denied)
 *                           EAFNOSUPPORT (implementation does not support
 *                                         specified address family)
 *                           EINVAL (unknown protocol, or protocol family
 *                                   not available)
 *                           EMFILE (per-process limit on number of open file
 *                                   descriptors has been reached)
 *                           ENFILE (system-wide limit on the total number of
 *                                   open files has been reached)
 *                           ENOBUFS, ENOMEM (insufficient memory is available,
 *                                            socket cannot be created until
 *                                            sufficient resources are freed)
 *                           EPROTONOSUPPORT (protocol type or specified
 *                                            protocol is not supported within
 *                                            this domain)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_socket(void) {
    int file_descriptor;
    file_descriptor = socket(AF_UNIX, SOCK_STREAM, 0);
    return file_descriptor;
}

