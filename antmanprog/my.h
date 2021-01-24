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

void print_path(tab_t *finaltab, byte_t *buff, int size, int sizetab);
int my_strlen(char *str);
char *my_revstr(char *str);
void print_small_tree(tree_t **tree, int size);
void concat_buff_to_outbuf(global_t *global);
byte_t get_octet(char *str);
void print_bits_to_octets(char *str);
global_t *get_global_struct(void);
void force_flush(void);
tab_t *find_path(tree_t *tree, int size);
tree_t *build_tree(tab_t *tab, int *size);
byte_t *get_binary(int c, int bit);
int find_size_tab(tab_t *tab);
int find_size_file(char *pathname);
void fill_buff(byte_t *buff, char *pathname, int size);
void fill_tab(byte_t *buff, tab_t *tab, int size);
void pars_tab(tab_t *tab);

#endif /* !MY_H_ */
