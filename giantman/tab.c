/*
** EPITECH PROJECT, 2021
** tab
** File description:
** tab
*/

#include "my.h"

int puissance(int a, int b)
{
    int nbr = a;

    if (b == 0)
        return 1;
    for (int i = 0; i < b - 1; i++) {
        a = a * nbr;
    }
    return a;
}

int get_int_from_binary(char *str, int length)
{
    int result = 0;

    for (int i = 0; i < length; i++) {
        if (str[i] == '1')
            result += puissance(2, length - i - 1);
    }
    return result;
}

int get_word(int *fin)
{
    char bits[10];
    int nbr = 0;

    for (int i = 0; i < 9; i++) {
        bits[i] = get_one_bit();
    }
    bits[9] = 0;
    nbr = get_int_from_binary(bits, 9);
    if (256 == nbr)
        *fin = 1;
    return nbr;
}

unsigned int get_weight(void)
{
    char bits[17];
    int c = 0;

    for (int i = 0; i < 16; i++) {
        bits[i] = get_one_bit();
    }
    bits[16] = 0;
    c = get_int_from_binary(bits, 16);
    return c;
}

tab_t *get_tab(int *sizetab)
{
    tab_t *tab = malloc(sizeof(tab_t) * 256);
    int fin = 0;
    int i;

    for (i = 0; fin == 0; i++) {
        tab[i].c = get_word(&fin);
        tab[i].nbr = get_weight();
        printf("[%d] word : %d weight = %d\n", i, tab[i].c, tab[i].nbr);
    }
    tab[i].nbr = 0;
    *sizetab = i;
    return tab;
}