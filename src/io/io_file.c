/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_file
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "myio.h"
#include "mystr.h"

/// @brief Reads a file and returns its content as a string.
/// Reads the file byte per byte (slow)
/// @param filepath path of the file to read
/// @return allocated string containing the data of the file (NULL on failure)
char *my_file_to_str(const char *filepath)
{
    int fd = 0;
    int status = 0;
    char *str = NULL;
    char c = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        return NULL;
    }
    while (read(fd, &c, 1) == 1) {
        status = my_str_append(&str, c);
        if (status == -1 && str) {
            free(str);
        }
        if (status == -1) {
            close(fd);
            return NULL;
        }
    }
    close(fd);
    return str;
}

/// @brief Reads a file and returns its content as a string.
/// Reads the file using the stat syscall
/// @param filepath path of the file to read
/// @return allocated string containing the data of the file (NULL on failure)
char *my_sfile_to_str(const char *filepath)
{
    struct stat statbuf = {0};
    int fd = 0;
    char *str = NULL;
    int size = 0;

    if (stat(filepath, &statbuf) == -1) {
        return NULL;
    }
    if ((fd = open(filepath, O_RDONLY)) == -1) {
        return NULL;
    }
    str = my_str_alloc(statbuf.st_size, -1);
    if (!str) {
        close(fd);
        return NULL;
    }
    size = read(fd, str, statbuf.st_size);
    str[size] = '\0';
    close(fd);
    return str;
}

/// @brief Write the content of a string in a file
/// @param str the string to write
/// @param append true to append the content to the file,
/// false to clear the file before writing
/// @return 0 on success, -1 on failure
int my_file_from_str(const char *filepath, const char *str, bool append)
{
    int fd = 0;
    int flags = O_RDWR | O_CREAT | (append ? O_APPEND : O_TRUNC);
    int perms = S_IRWXU;

    if (!str || !filepath) {
        return -1;
    }
    if ((fd = open(filepath, flags, perms)) == -1) {
        return -1;
    }
    write(fd, str, my_strlen(str));
    close(fd);
    return 0;
}
