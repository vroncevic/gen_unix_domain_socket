/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_bind.c
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
 *     bind a name to a socket.
 *
 * Arguments:
 *     socket_descriptor - socket descriptor
 *     address - socket address structure
 *
 * Return value:
 *     status - on success, zero is returned | UDS_ERROR and error number
 *              is set to indicate the error:
 *                  EACCES (search permission is denied on a component of the
 *                          path prefix)
 *                  EADDRNOTAVAIL (nonexistent interface was requested or the
 *                                 requested address was not local)
 *                  EFAULT (address points outside the user's accessible
 *                          address space)
 *                  ELOOP (too many symbolic links were encountered in
 *                         resolving address)
 *                  ENAMETOOLONG (address is too long)
 *                  ENOENT (component in the directory prefix of the socket
 *                          pathname does not exist)
 *                  ENOMEM (insufficient kernel memory was available)
 *                  ENOTDIR (component of the path prefix is not a directory)
 *                  EROFS (socket inode would reside on a read-only filesystem)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_bind(int file_descriptor, struct sockaddr_un address) {
    int status;
    if (file_descriptor >= 0) {
        status = bind(
            file_descriptor, (struct sockaddr*)&address, sizeof(address)
        );
    } else {
        status = UDS_ERROR;
    }
    return status;
}

