/*
** EPITECH PROJECT, 2021
** tab
** File description:
** tab
*/

#include "my.h"

byte_t *get_binary(int c, int bit)
{
    int divi = c;
    byte_t *result = malloc((sizeof(char) * divi) + 1);
    int i = 0;

    for (; divi != 0; i++) {
        result[i] = (divi % 2) + 48;
        divi = divi / 2;
    }
    for (; i < bit && i < sizeof(char) * divi; i++)
        result[i] = '0';
    result[i] = '\0';
    result = my_revstr(result);
    return result;
}

int find_size_tab(tab_t *tab)
{
    int size = 0;

    for (int i = 255; i > 0 && tab[i].nbr > 0; i--)
        size++;
    return size;
}

void pars_tab(tab_t *tab)
{
    tab_t temp;

    for (int i = 0; i < 256; i++) {
        for (int j = i + 1; j < 256; j++) {
            if (tab[j].nbr < tab[i].nbr) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void fill_tab(byte_t *buff, tab_t *tab, int size)
{
    for (int i = 0; i < 256; i++) {
        tab[i].c = i;
        tab[i].nbr = 0;
    }
    for (int i = 0; i < size; i++) {
        if (tab[buff[i]].nbr < 32767)
            (tab[buff[i]].nbr)++;
    }
}

