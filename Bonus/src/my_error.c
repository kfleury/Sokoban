/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_error
*/
#include "sokoban.h"

int my_error(int ac, base *use)
{
    if (ac != 2) {
        write(2, "Invalid number of arg\n", 22);
        exit(84);
    }
    for (int i = 0; use->buffer[i + 1] != '\0'; i++) {
        if (use->buffer[i] != 'P' && use->buffer[i] != 'X'
            && use->buffer[i] != 'O' && use->buffer[i] != ' '
            && use->buffer[i] != '\n' && use->buffer[i] != '#'
            && use->buffer[i] != 'M' && use->buffer[i] != '-') {
            write(2, "Invalid map\n", 12);
            exit(84);
        }
    }
    return (0);
}
