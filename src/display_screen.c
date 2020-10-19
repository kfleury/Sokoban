/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** display_screen
*/
#include "sokoban.h"

void display(base *use)
{
    for (int i = 0, k = 0; i != use->lines; i++, k++) {
        for (int j = 0; j != use->cols[k] + 1; j++) {
            mvprintw(i, 45, "%s", use->map[i]);
        }
    }
}

void func_screen(base *use, int ch)
{
    position_p(use);
    move_player(ch, use);
    position_o(use);
    win_condition(use);
    lose_condition(use);
    display(use);
}

void display_screen(base *use, char *str, int ac)
{
    int ch = 0;

    cbreak();
    noecho();
    curs_set(0);
    while (true) {
        func_screen(use, ch);
        ch = getch();
        if (ch == 27)
            return;
        if (ch == 32) {
            open_map(str, use);
            my_error(ac, use);
            put_in_tab(use);
            position_p(use);
            position_o_static(use);
        }
        refresh();
        endwin();
    }
}
