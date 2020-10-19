/*
** EPITECH PROJECT, 2019
** test
** File description:
** project.c
*/
#include <criterion/criterion.h>
#include "sokoban.h"

Test(sokoban, check_player_position)
{
struct sokoban_map *map;
struct position *pos;
cr_assert_neq(pos, NULL);
free(pos);
free_map(map);
}
