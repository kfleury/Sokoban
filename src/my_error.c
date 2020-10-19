/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_error
*/
#include "sokoban.h"

int is_it_block2(base *use, int line, int col)
{
    if (block_down_left(use, line, col) == 1)
        return (1);
    if (block_down_right(use, line, col) == 1)
        return (1);
    return (0);
}

void put_in_tab2(base *use, int a, int b, int c)
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
}

int my_error(int ac, base *use)
{
    if (ac != 2) {
        write(2, "Invalid number of arg\n", 22);
        exit(84);
    }
    for (int i = 0; use->buffer[i + 1] != '\0'; i++) {
        if (use->buffer[i] != 'P' && use->buffer[i] != 'X'
            && use->buffer[i] != 'O' && use->buffer[i] != ' '
            && use->buffer[i] != '\n' && use->buffer[i] != '#') {
            write(2, "Invalid map\n", 12);
            exit(84);
        }
    }
    return (0);
}
