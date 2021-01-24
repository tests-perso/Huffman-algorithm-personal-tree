/*
** EPITECH PROJECT, 2021
** main
** File description:
** amain
*/

#include "my.h"

void main(int ac, char **av)
{
    int size = find_size_file(av[1]);
    byte_t buff[size + 1];
    tab_t tab[256];
    tab_t *finaltab;
    tree_t *tree;
    int othersize = size;

    fill_buff(buff, av[1], size);
    fill_tab(buff, tab, size);
    pars_tab(tab);
    tree = build_tree(tab, &size);
    finaltab = malloc(sizeof(tab_t) * size);
    finaltab = find_path(tree, size);
    print_path(finaltab, buff, othersize, size);
    force_flush();
}