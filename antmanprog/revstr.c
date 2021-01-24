/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int n;
    int i = 0;
    int temp;

    n = my_strlen(str) - 1;
    while (i < n) {
        temp = str[i];
        str[i] = str[n];
        str[n] = temp;
        i++;
        n--;
    }
    return str;
}