/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_unlink.c
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
 *     socket_path - socket descriptor 
 *
 * Return value:
 *     status - on success, zero is returned | UDS_ERROR and error number is
 *              set to indicate the error:
 *                  EACCES (write access to the directory containing pathname
 *                          is not allowed for the process's effective UID,
 *                          or one of the directories in pathname did not
 *                          allow search permission)
 *                  EBUSY (file pathname cannot be unlinked because it is
 *                         being used by the system or another process;
 *                         for example, it is a mount point or the NFS client
 *                         software created it to represent an active but
 *                         otherwise nameless inode ("NFS silly renamed"))
 *                  EFAULT (pathname points outside accessible address space)
 *                  EIO (I/O error occurred)
 *                  EISDIR (pathname refers to a directory)
 *                  ELOOP (too many symbolic links were encountered in
 *                         translating pathname)
 *                  ENAMETOOLONG (pathname was too long)
 *                  ENOENT (component in pathname does not exist or is a
 *                          dangling symbolic link, or pathname is empty)
 *                  ENOMEM (insufficient kernel memory was available)
 *                  ENOTDIR (component used as a directory in pathname is not,
 *                           in fact, a directory)
 *                  EROFS (pathname refers to a file on a read-only filesystem)
 *                  EBADF (not a valid file descriptor)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_unlink(const char * socket_path) {
    int status;
    if (socket_path != NULL) {
        status = unlink(socket_path);
    } else {
        status = UDS_ERROR;
    }
    return status;
}

