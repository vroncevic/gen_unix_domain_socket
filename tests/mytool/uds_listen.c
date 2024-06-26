/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_listen.c
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
 *     Listen for connections on a socket.
 *
 * Arguments:
 *     file_descriptor - socket descriptor
 *
 * Return value:
 *     status - on success, zero is returned | UDS_ERROR and error number is
 *              set to indicate the error:
 *                  EADDRINUSE (another socket is already listening on
 *                              same port)
 *                  EBADF (not a valid file descriptor)
 *                  ENOTSOCK (file descriptor does not refer to a socket)
 *                  EOPNOTSUPP (socket is not of a type that supports listen()
 *                              operation)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_listen(int file_descriptor) {
    int status;
    if (file_descriptor >= 0) {
        status = listen(file_descriptor, BACK_LOG_MAXIMUM_LENGTH);
    } else {
        status = UDS_ERROR;
    }
    return status;
}

