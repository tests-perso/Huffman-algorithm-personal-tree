/*
** EPITECH PROJECT, 2021
** myh
** File description:
** myhbyte
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef unsigned char byte_t;

typedef struct global_s {
    char *buf;
    byte_t *outbuf;
    int pos;
    int outpos;
    int start;
} global_t;

typedef struct path_s {
    int depth;
    byte_t *str;
} path_t;

typedef struct tab_s {
    int c;
    unsigned int nbr;
    byte_t *path;
} tab_t;

typedef struct tree_s {
    int weight;
    int leaf;
    struct tree_s *left;
    struct tree_s *right;
    int end;
} tree_t;

void decompress(tree_t *tree);
int find_size_tab(tab_t *tab);
tree_t *build_tree(tab_t *tab, int *size);
global_t *get_global_struct(char *pathname);
tab_t *get_tab(int *sizetab);
char get_one_bit(void);
char *read_file(char *pathname);

#endif /* !MY_H_ */
