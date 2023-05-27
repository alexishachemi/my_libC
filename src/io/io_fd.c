/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_fd
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/// @brief write the content of a file descriptor into another
/// @param src source file descriptor
/// @param dest destination file descriptor
/// @return the number of bytes written
int my_fd_to_fd(int src, int dest)
{
    char c = 0;
    int total = 0;

    while (read(src, &c, 1) == 1) {
        write(dest, &c, 1);
        total++;
    }
    return total;
}

/// @brief Read a file descriptor and return the content as a string
/// @param fd file descriptor ro read
/// @param size size of the data to read (8192 if zero or less)
/// @return the content of the file descriptor as a string (allocated),
/// NULL on failure
char *my_readfd(int fd, int size)
{
    char *buf = NULL;

    if (size <= 0) {
        size = BUFSIZ;
    }
    buf = malloc(sizeof(char) * size);
    if (!buf) {
        return NULL;
    }
    size = read(fd, buf, size);
    if (size == -1) {
        free(buf);
        return NULL;
    }
    buf[size] = '\0';
    return buf;
}
