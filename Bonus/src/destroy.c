/*
** EPITECH PROJECT, 2019
** Bonus
** File description:
** destroy
*/
#include "sokoban.h"

void destroy_thing(base *use)
{
    sfMusic_destroy(use->music.lose);
    sfMusic_destroy(use->music.win);
    sfMusic_destroy(use->music.music);
}