/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds_read.c
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
 *     Read from a file descriptor.
 *
 * Arguments:
 *     file_descriptor - file descriptor
 *     buffer - socket address structure
 *     count - size of peer address
 *
 * Return value:
 *     number_of_bytes - on success, the number of bytes read is returned
 *                       (zero indicates end of file), and the file position
 *                       is advanced by this number | UDS_ERROR and error
 *                       number is set to indicate the error:
 *                           EAGAIN, EWOULDBLOCK (file descriptor refers to a
 *                                                file other than a socket and
 *                                                has been marked nonblocking
 *                                                (O_NONBLOCK), and the write
 *                                                would block)
 *                           EBADF (not a valid file descriptor or is not
 *                                  open for reading)
 *                           EFAULT (buffer is outside accessible address space)
 *                           EINTR (call was interrupted by a signal before
 *                                  any data was read)
 *                           EINVAL (file_descriptor is attached to an object
 *                                   which is unsuitable for read; or the
 *                                   file was opened with the O_DIRECT flag
 *                                   and either the address specified in buf,
 *                                   the value specified in count, or the file
 *                                   offset is not suitably aligned)
 *                           EIO (I/O error, this will happen for example when
 *                                process is in a background process group,
 *                                tries to read from its controlling terminal,
 *                                and either it is ignoring or blocking
 *                                SIGTTIN or its process group is orphaned, it
 *                                may also occur when there is a low-level I/O
 *                                error while reading from a disk or tape
 *                                further possible cause of EIO on networked
 *                                filesystems is when an advisory lock had
 *                                been taken out on the file descriptor and
 *                                this lock has been lost)
 *                           EISDIR (file_descriptor refers to a directory)
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
ssize_t uds_read(int file_descriptor, void * buffer, size_t count) {
    ssize_t number_of_bytes;
    if (file_descriptor >= 0) {
        number_of_bytes = read(file_descriptor, buffer, count);
    } else {
        number_of_bytes = UDS_ERROR;
    }
    return number_of_bytes;
}

