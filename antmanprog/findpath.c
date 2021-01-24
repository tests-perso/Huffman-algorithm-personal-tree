/*
** EPITECH PROJECT, 2021
** findpath
** File description:
** findpath
*/

#include "my.h"

void get_path(tab_t *pathtab, tree_t *tree, int *pos, path_t temp)
{
    if (tree == NULL)
        return;
    if (tree->end == 1) {
        temp.str[temp.depth] = '\0';
        pathtab[*pos].c = tree->leaf;
        pathtab[*pos].path = malloc(sizeof(char) * (temp.depth + 1));
        for (int i = 0; i <= temp.depth; i++)
            pathtab[*pos].path[i] = temp.str[i];
        temp.str;
        (*pos)++;
        return;
    }
    temp.depth += 1;
    temp.str[temp.depth - 1] = '1';
    get_path(pathtab, tree->right, pos, temp);
    temp.str[temp.depth - 1] = '0';
    get_path(pathtab, tree->left, pos, temp);
}

tab_t *find_path(tree_t *tree, int size)
{
    tab_t *pathtab = malloc(sizeof(tab_t) * size);
    path_t temp;
    int pos = 0;

    temp.str = malloc(sizeof(byte_t) * 257);
    for (int i = 0; i < size; i++) {
        pathtab[i].path = malloc(sizeof(byte_t) * 257);
    }
    temp.depth = 0;
    get_path(pathtab, tree, &pos, temp);
    return pathtab;
}