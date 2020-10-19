/*
** EPITECH PROJECT, 2019
** Bonus
** File description:
** func_ncurse
*/
#include "sokoban.h"

void game(base *use, int ch)
{
    func_ncurse();
    position_m(use);
    position_p(use);
    move_player(ch, use);
    move2_player(ch, use);
    position_o(use);
    position_6(use);
    door(use);
    display(use);
    menu_win_lose(use);
    if (ch == 111) {
        destroy_thing(use);
        exit(84);
    }
}

void func_ncurse(void)
{
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_MAGENTA);
    clear();
}