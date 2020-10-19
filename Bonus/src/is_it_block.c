/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** is_it_block
*/
#include "sokoban.h"

int block_up_right(base *use, int line, int col)
{
    if ((use->map[line-1][col] == '#' && use->map[line][col+1] == '#')
        || (use->map[line-1][col] == '#' && use->map[line][col+1] == 'X')
        || (use->map[line-1][col] == 'X' && use->map[line][col+1] == '#')
        || (use->map[line-1][col] == 'X' && use->map[line][col+1] == 'X'))
        return (1);
    else
        return (0);
}

int block_up_left(base *use, int line, int col)
{
    if ((use->map[line-1][col] == '#' && use->map[line][col-1] == '#')
        || (use->map[line-1][col] == '#' && use->map[line][col-1] == 'X')
        || (use->map[line-1][col] == 'X' && use->map[line][col-1] == '#')
        || (use->map[line-1][col] == 'X' && use->map[line][col-1] == 'X'))
        return (1);
    else
        return (0);
}

int block_down_right(base *use, int line, int col)
{
    if ((use->map[line+1][col] == '#' && use->map[line][col+1] == '#')
        || (use->map[line+1][col] == '#' && use->map[line][col+1] == 'X')
        || (use->map[line+1][col] == 'X' && use->map[line][col+1] == '#')
        || (use->map[line+1][col] == 'X' && use->map[line][col+1] == 'X'))
        return (1);
    else
        return (0);
}

int block_down_left(base *use, int line, int col)
{
    if ((use->map[line+1][col] == '#' && use->map[line][col-1] == '#')
        || (use->map[line+1][col] == '#' && use->map[line][col-1] == 'X')
        || (use->map[line+1][col] == 'X' && use->map[line][col-1] == '#')
        || (use->map[line+1][col] == 'X' && use->map[line][col-1] == 'X'))
        return (1);
    else
        return (0);
}

int is_it_block(base *use, int line, int col)
{
    if (block_up_left(use, line, col) == 1)
        return (1);
    if (block_up_right(use, line, col) == 1)
        return (1);
    if (block_down_left(use, line, col) == 1)
        return (1);
    if (block_down_right(use, line, col) == 1)
        return (1);
    return (0);
}
