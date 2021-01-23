/*
** EPITECH PROJECT, 2021
** file
** File description:
** file
*/

#include "my.h"

void fill_buff(byte_t *buff, char *pathname, int size)
{
    int fd = open(pathname, O_RDONLY);

    read(fd, buff, size);
    buff[size] = '\0';
    printf("buf : %s size : %d\n", buff, size);
}

int find_size_file(char *pathname)
{
    struct stat statbuff;

    stat(pathname, &statbuff);
    return statbuff.st_size;
}