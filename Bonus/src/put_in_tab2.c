/*
** EPITECH PROJECT, 2019
** Bonus
** File description:
** put_in_tab2
*/
#include "sokoban.h"

void put_in_tab2(base *use, int b, int a, int c)
{
    if (use->buffer[a] == '#')
        use->map[b][c] = '#';
    if (use->buffer[a] == 'O')
        use->map[b][c] = 'O';
    if (use->buffer[a] == 'X')
        use->map[b][c] = 'X';
    if (use->buffer[a] == ' ')
        use->map[b][c] = ' ';
    if (use->buffer[a] == 'P')
        use->map[b][c] = 'P';
    if (use->buffer[a] == 'M')
        use->map[b][c] = 'M';
    if (use->buffer[a] == '-')
        use->map[b][c] = '-';
}