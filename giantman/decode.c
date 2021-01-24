/*
** EPITECH PROJECT, 2021
** decode
** File description:
** decode
*/

#include "my.h"

global_t *get_global_struct(char *pathname)
{
    static global_t *global = NULL;
    if (NULL == global) {
        global = malloc(sizeof(global_t));
        global->outbuf = read_file(pathname);
        global->buf = malloc(sizeof(char) * 9);
        global->buf[0] = 0;
        global->pos = 8;
        global->outpos = 0;
    }
    return global;
}

void get_bits_from_octet(void)
{
    byte_t temp;
    global_t *global = get_global_struct(NULL);

    temp = global->outbuf[global->outpos];
    global->outpos++;
    global->pos = 0;
    for (int i = 0; i < 8; i++) {
        if ((temp & 128) == 128)
            global->buf[i] = '1';
        else {
            global->buf[i] = '0';
        }
        temp = temp << 1;
    }
    global->buf[8] = 0;
}

char get_one_bit(void)
{
    global_t *global = get_global_struct(NULL);
    char bit;

    if (global->pos == 8)
        get_bits_from_octet();
    bit = global->buf[global->pos];
    global->pos++;
    return bit;
}