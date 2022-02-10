/*
** EPITECH PROJECT, 2021
** file
** File description:
** file
*/

#include "my.h"

char *read_file(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    struct stat statbuff;
    int size = 0;
    static char *buff;

    stat(pathname, &statbuff);
    size = statbuff.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size] = '\0';
    // printf("case 0 : %d\n", buff[0]);
    return buff;
}