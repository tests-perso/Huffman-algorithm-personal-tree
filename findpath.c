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
        pathtab[*pos].path = temp.str;
        printf("path for [%d] : %s\n", pathtab[*pos].c, pathtab[*pos].path);
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

    temp.str = malloc(sizeof(byte_t) * 256);
    for (int i = 0; i < size; i++) {
        pathtab[i].path = malloc(sizeof(byte_t) * 256);
    }
    get_path(pathtab, tree, &pos, temp);
    printf("pos %d\n", pos);
    return pathtab;
}