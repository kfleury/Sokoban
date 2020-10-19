/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** usage
*/
#include "sokoban.h"

int usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap  file representing the warehouse map,");
    my_putstr(" containing '#' for walls,\n");
    my_putstr("\t     'P' for the player, 'X' for boxes and 'O' for");
    my_putstr(" storage locations.\n");
    exit(0);
}