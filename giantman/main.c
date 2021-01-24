/*
** EPITECH PROJECT, 2021
** main
** File description:
** amain
*/

#include "my.h"

int find_size_tab(tab_t *tab)
{
    int size = 0;

    for (int i = 255; tab[i].nbr > 0; i--)
        size++;
    return size;
}

void main(int ac, char **av)
{
    global_t *global = get_global_struct(av[1]);
    int sizetab = 0;
    int size;
    tab_t *tab = get_tab(&sizetab);
    tree_t *tree = build_tree(tab, &sizetab);

    decompress(tree);
}