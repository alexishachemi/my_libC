/*
** EPITECH PROJECT, 2023
** my_str_tofile
** File description:
** my_str_tofile
*/

#include <unistd.h>
#include <fcntl.h>

int my_str_tofile(const char *str, const char *filepath, int append)
{
    int fd = 0;
    int flags = O_CREAT | O_WRONLY;

    flags |= append ? O_APPEND : O_TRUNC;
    if (str == NULL || (fd = open(filepath, flags, 777)) == -1) {
        return -1;
    }
    write(fd, str, my_strlen(str));
    close(fd);
    return 0;
}
