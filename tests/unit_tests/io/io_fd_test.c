/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_fd_test
*/

#include <criterion/criterion.h>
#include "myio.h"
#include "mystr.h"
#include <unistd.h>

Test(my_readfd, known_size)
{
    int fd[2] = {0, 0};
    char *str = NULL;
    const char *ref = "Hello World";
    int size = my_strlen(ref);

    pipe(fd);
    write(fd[1], ref, size);
    close(fd[1]);
    str = my_readfd(fd[0], size);
    close(fd[0]);
    cr_assert_str_eq(str, ref);
    free(str);
}

Test(my_readfd, default_size)
{
    int fd[2] = {0, 0};
    char *str = NULL;
    const char *ref = "This is a test string !!!";
    int size = my_strlen(ref);

    pipe(fd);
    write(fd[1], ref, size);
    close(fd[1]);
    str = my_readfd(fd[0], -1);
    close(fd[0]);
    cr_assert_str_eq(str, ref);
    free(str);
}

Test(my_fd_to_fd, simple)
{
    int fd[2] = {0, 0};
    int fd2[2] = {0, 0};
    char *str = NULL;
    const char *ref = "This is another test string";
    int size = my_strlen(ref);
    
    pipe(fd);
    pipe(fd2);
    write(fd[1], ref, size);
    close(fd[1]);
    my_fd_to_fd(fd[0], fd2[1]);
    close(fd[0]);
    close(fd2[1]);
    str = my_readfd(fd2[0], size);
    close(fd2[0]);
    cr_assert_str_eq(str, ref);
    free(str);
}
