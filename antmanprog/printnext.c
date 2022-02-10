/*
** EPITECH PROJECT, 2021
** printnext
** File description:
** printnext
*/

#include "my.h"

void print_path(tab_t *finaltab, byte_t *buff, int size, int sizetab)
{
    tab_t *newtab = malloc(sizeof(tab_t)* 257);

    for (int i = 0; i < sizetab; i++) {
        newtab[finaltab[i].c].c = finaltab[i].c;
        newtab[finaltab[i].c].path = finaltab[i].path;
    }
    for (int i = 0; i < size; i++) {
        print_bits_to_octets(newtab[buff[i]].path);
    }
    print_bits_to_octets(newtab[256].path);
    // printf("caracter : %d, path : %s\n", newtab[256].c, newtab[256].path);
}

void print_small_tree(tree_t **tree, int size)
{
    char *str = malloc(sizeof(char) * 9);

    for (int i = 0; i < size; i++) {
        str = get_binary(tree[i]->leaf, 9);
        print_bits_to_octets(str);
        str = get_binary(tree[i]->weight, 16);
        print_bits_to_octets(str);
    }
}

void force_flush(void)
{
    global_t *global = get_global_struct();
    byte_t octet;

    for (int i = global->pos; i < 8; i++) {
        global->buf[i] = '0';
    }
    concat_buff_to_outbuf(global);
    write(1, global->outbuf, global->outpos);
}