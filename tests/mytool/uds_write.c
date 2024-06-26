/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_write.c
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
 *     Write to a file descriptor.
 *
 * Arguments:
 *     file_descriptor - file descriptor
 *     buffer - socket address structure
 *     count - size of peer address
 *
 * Return value:
 *     number_of_bytes - on success, the number of bytes written is returned |
 *                       UDS_ERROR and error number is set to indicate error:
 *                           EAGAIN, EWOULDBLOCK (file descriptor refers to a
 *                                                file other than a socket and
 *                                                has been marked nonblocking
 *                                                (O_NONBLOCK), and the write
 *                                                would block)
 *                           EBADF (not a valid file descriptor or is not
 *                                  open for writing)
 *                           EDESTADDRREQ (file_descriptor refers to datagram
 *                                         socket for which a peer address has
 *                                         not been set using connect)
 *                           EDQUOT (user's quota of disk blocks on the
 *                                   filesystem containing the file referred
 *                                   to by fd has been exhausted)
 *                           EFAULT (buf is outside accessible address space)
 *                           EFBIG (attempt was made to write a file that
 *                                  exceeds the implementation-defined maximum
 *                                  file size or process's file size limit,
 *                                  or to write at a position past the maximum
 *                                  allowed offset)
 *                           EINTR (call was interrupted by a signal before
 *                                  any data was written)
 *                           EINVAL (file_descriptor is attached to an object
 *                                   which is unsuitable for writing; or the
 *                                   file was opened with the O_DIRECT flag
 *                                   and either the address specified in buf,
 *                                   the value specified in count, or the file
 *                                   offset is not suitably aligned)
 *                           EIO (low-level I/O error occurred while modifying
 *                                the inode, error may relate to write-back of
 *                                data written by an earlier write(), which
 *                                may have been issued to a different file
 *                                descriptor on the same file)
 *                           ENOSPC (device containing the file referred to by
 *                                   file_descriptor has no room for the data)
 *                           EPERM (operation was prevented by a file seal)
 *                           EPIPE (file_descriptor is connected to a pipe or
 *                                  socket whose reading end is closed, when
 *                                  this happens the writing process will also
 *                                  receive a SIGPIPE signal)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
ssize_t uds_write(int file_descriptor, const void * buffer, size_t count) {
    ssize_t number_of_bytes;
    if (file_descriptor >= 0 && buffer != NULL) {
        number_of_bytes = write(file_descriptor, buffer, count);
    } else {
        number_of_bytes = UDS_ERROR;
    }
    return number_of_bytes;
}

