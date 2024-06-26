/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds.h
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

#ifndef UDS_H_
#define UDS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>

#define BACK_LOG_MAXIMUM_LENGTH 5

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
 *                       (a nonnegative integer) | UDS_ERROR error number
 *                       is set to indicate the error:
 *                           EBADF, ECONNABORTED, EFAULT, EINTR, EINVAL,
 *                           EMFILE, ENFILE, ENOBUFS, ENOMEM, ENOTSOCK
 *                           EOPNOTSUPP, EPROTO, EPERM
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_accept(
    int socket_descriptor,
    struct sockaddr * restrict address,
    socklen_t * restrict address_length
) __attribute__((nonnull (2)));

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
 *                  EACCES, EADDRNOTAVAIL, EFAULT, ELOOP, ENAMETOOLONG
 *                  ENOENT, ENOMEM, ENOTDIR, EROFS
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_bind(int file_descriptor, struct sockaddr_un address);

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
 *                  EACCES, EPERM, EADDRINUSE, EADDRNOTAVAIL, EAFNOSUPPORT
 *                  EAGAIN, EALREADY, EBADF, ECONNREFUSED, EFAULT, EINPROGRESS
 *                  EINTR, EISCONN, ENETUNREACH, ENOTSOCK, EPROTOTYPE
 *                  ETIMEDOUT
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_connect(
    int socket_descriptor,
    const struct sockaddr * address,
    socklen_t address_length
) __attribute__((nonnull (2)));

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
 *                           EACCES, EAFNOSUPPORT, EINVAL, EMFILE, ENFILE
 *                           ENOBUFS, ENOMEM, EPROTONOSUPPORT
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_socket(void);

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
 *                  EACCES, EBUSY, EFAULT, EIO, EISDIR, ELOOP, ENAMETOOLONG
 *                  ENOENT, ENOMEM, ENOTDIR, EROFS, EBADF
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_unlink(const char * socket_path) __attribute__((nonnull (1)));

/**
 * Description:
 *     Write to a file descriptor.
 *
 * Arguments:
 *     file_descriptor - file descriptor
 *     buffer - socket address structure
 *     count -  size of peer address
 *
 * Return value:
 *     number_of_bytes - on success, the number of bytes written is returned |
 *                       UDS_ERROR and error number is set to indicate error:
 *                           EAGAIN, EWOULDBLOCK, EBADF, EDESTADDRREQ,
 *                           EDQUOT, EFAULT, EFBIG, EINTR, EINVAL, EIO, ENOSPC
 *                           EPERM, EPIPE
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
ssize_t uds_write(
    int file_descriptor, const void * buffer, size_t count
) __attribute__((nonnull (2)));

/**
 * Description:
 *     Read from a file descriptor.
 *
 * Arguments:
 *     file_descriptor - file descriptor
 *     buffer - socket address structure
 *     count -  size of peer address
 *
 * Return value:
 *     number_of_bytes - on success, the number of bytes read is returned
 *                       (zero indicates end of file), and the file position
 *                       is advanced by this number | UDS_ERROR and error
 *                       number is set to indicate the error:
 *                           EAGAIN, EWOULDBLOCK, EBADF, EFAULT, EINTR
 *                           EINVAL, EIO, EISDIR
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
ssize_t uds_read(
    int file_descriptor, void * buffer, size_t count
) __attribute__((nonnull (2)));

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
 *                  EADDRINUSE, EBADF, ENOTSOCK, EOPNOTSUPP
 *
 * Standards:
 *     POSIX.1-2001, POSIX.1-2008
 */
int uds_listen(int file_descriptor);

#ifdef __cplusplus
}
#endif

#endif
