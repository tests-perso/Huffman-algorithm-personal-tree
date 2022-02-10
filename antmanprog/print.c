/*
** EPITECH PROJECT, 2021
** print
** File description:
** print
*/

#include "my.h"

global_t *get_global_struct(void)
{
    static global_t *global = NULL;
    if (NULL == global) {
        global = malloc(sizeof(global_t));
        global->buf = malloc(sizeof(char) * 30);
        global->buf[0] = 0;
        global->outbuf = malloc(sizeof(byte_t) * 4096);
        global->outbuf[0] = 0;
        global->pos = 0;
        global->outpos = 0;
        global->start = 1;
    }
    return global;
}

byte_t get_octet(char *str)
{
    byte_t octet = 0;

    for (int i = 0; i < 8; i++) {
        octet = octet << 1;
        octet += str[i] - 48;
    }
    return octet;
}

void flush_outbuf(global_t *global)
{
    write(1, global->outbuf, 4096);
    global->pos = 0;
}

void concat_buff_to_outbuf(global_t *global)
{
    byte_t octet = get_octet(global->buf);

    if (global->outpos == 4096)
        flush_outbuf(global);
    global->outbuf[global->outpos] = octet;
    global->outpos++;
    global->pos = 0;
}

void print_bits_to_octets(char *str)
{
    global_t *global = get_global_struct();

    // printf("str : %s\n", str);
    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (global->pos == 8)
            concat_buff_to_outbuf(global);
        global->buf[global->pos] = str[i];
        global->pos++;
    }
    global->buf[global->pos] = 0;
}