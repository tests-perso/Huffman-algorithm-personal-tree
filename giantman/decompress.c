/*
** EPITECH PROJECT, 2021
** decompress
** File description:
** decompress
*/

#include "my.h"

int travel_tree(tree_t *tree)
{
    if (tree == NULL)
        return 0;
    if (tree->end == 1) {
        return tree->leaf;
    }
    if (get_one_bit() == '1')
        return travel_tree(tree->right);
    else
        return travel_tree(tree->left);
}

void decompress(tree_t *tree)
{
    int end = 0;
    int c;

    for (int i = 0; 1; i++) {
        c = travel_tree(tree);
        // write(1, "yo\n", 3);
        write(1, &c, 1);
        if (c == 256)
            return;
        //break;
    }
}