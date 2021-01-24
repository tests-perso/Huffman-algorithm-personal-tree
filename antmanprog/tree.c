/*
** EPITECH PROJECT, 2021
** tree
** File description:
** tree'
*/

#include "my.h"

void fill_tree(tree_t **tree, int size)
{
    for (int i = 0; i <= size; i++) {
        tree[i] = malloc(sizeof(tree_t));
        tree[i]->weight = 0;
        tree[i]->end = 0;
        tree[i]->right = NULL;
        tree[i]->left = NULL;
    }
}

void get_first_trees(tree_t **tree, tab_t *tab, int size)
{
    int i = 0;

    for (; i < size; i++) {
        tree[i]->weight = tab[256 - size + i].nbr;
        tree[i]->leaf = tab[256 - size + i].c;
        tree[i]->end = 1;
    }
    tree[i]->weight = 1;
    tree[i]->leaf = 256;
    tree[i]->end = 1;
    print_small_tree(tree, size + 1);
}

void pars_tree(tree_t **tree, int size)
{
    tree_t *temp;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tree[j]->weight < tree[i]->weight) {
                temp = tree[i];
                tree[i] = tree[j];
                tree[j] = temp;
            }
        }
    }
}

void print_tree(tree_t *tree, int depth)
{
    if (tree == NULL)
        return;
    if (tree->end == 1) {
        return;
    }
    print_tree(tree->right, depth);
    print_tree(tree->left, depth+1);
}

tree_t *build_tree(tab_t *tab, int *size)
{
    int sizetab = find_size_tab(tab);
    tree_t **tree = malloc(sizeof(tree_t *) * (sizetab + 1));
    tree_t *temptree;
    tree_t *finaltree;

    fill_tree(tree, sizetab);
    get_first_trees(tree, tab, sizetab);
    sizetab++;
    for (int i = 0; i < sizetab - 1; i++) {
        temptree = malloc(sizeof(tree_t));
        temptree->weight = tree[0]->weight + tree[1]->weight;
        temptree->left = tree[0];
        temptree->right = tree[1];
        temptree->end = 0;
        tree[1] = temptree;
        tree++;
        pars_tree(tree, sizetab - i - 1);
    }
    finaltree = tree[0];
    print_tree(finaltree, 0);
    *size = sizetab;
    return finaltree;
}