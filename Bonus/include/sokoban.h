/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include "my.h"
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct position {
    int pos_x;
    int pos_y;
}pos_t;

typedef struct {
    sfMusic *win;
    sfMusic *lose;
    sfMusic *music;
}sound;

typedef struct {
    char **map;
    int **pos_o;
    int **pos_6;
    int nbr_o;
    int nbr_6;
    int nbr_x;
    char *buffer;
    int lines;
    int *cols;
    pos_t pos;
    pos_t pos_m;
    int win;
    int lose;
    sound music;
}base;

void position_6(base *use);
void position_6_static(base *use);
void put_in_tab(base *use);
int open_map(char const *av, base *use);
int my_error(int ac, base *use);
void display_screen(base *use, char *str, int ac);
void position_p(base *use);
void position_m(base *use);
void move_player(int ch, base *use);
void move_up(base *use);
void move_down(base *use);
void move_right(base *use);
void move_left(base *use);
void move2_player(int ch, base *use);
void move2_up(base *use);
void move2_down(base *use);
void move2_right(base *use);
void move2_left(base *use);
void position_o(base *use);
void position_o_static(base *use);
int win_condition(base *use);
int lose_condition(base *use);
int is_it_block(base *use, int line, int col);
void destroy_thing(base *use);
void func_ncurse(void);
void game(base *use, int ch);
void display(base *use);
void menu_win_lose(base *use);
void put_in_tab2(base *use, int b, int a, int c);
void position_m(base *use);
void door(base *use);
#endif
