/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** display_screen
*/
#include "sokoban.h"

void lose_menu(base *use)
{
    char *msg = "YOU LOSE";
    int taille = 0;
    int ch = 0;

    sfMusic_stop(use->music.music);
    sfMusic_play(use->music.lose);
    taille = my_strlen(msg);
    initscr();
    while (true) {
        if (ch == 32) {
            destroy_thing(use);
            exit(1);
        }
        mvprintw(LINES/2, (COLS / 2) - (taille / 2), msg);
        refresh();
        ch = getch();
        clear();
    }
    endwin();
}

void win_menu(base *use)
{
    char *msg = "YOU WIN";
    int taille = 0;
    int ch = 0;

    sfMusic_stop(use->music.music);
    sfMusic_play(use->music.win);
    taille = my_strlen(msg);
    initscr();
    while (true) {
        if (ch == 32) {
            destroy_thing(use);
            exit(0);
        }
        attron(A_BOLD);
        mvprintw(LINES/2, (COLS / 2) - (taille / 2), msg);
        refresh();
        ch = getch();
        clear();
    }
    endwin();
}

void menu_win_lose(base *use)
{
    if (win_condition(use) == 1)
        win_menu(use);
    if (lose_condition(use) == 1)
        lose_menu(use);
    else
        return;
}

void display(base *use)
{
    for (int i = 0; i != use->lines; i++) {
        mvprintw(i, 45, "%s", use->map[i]);
    }
}

void display_screen(base *use, char *str, int ac)
{
    int ch = 0;

    cbreak();
    noecho();
    curs_set(0);
    while (true) {
        game(use, ch);
        ch = getch();
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
