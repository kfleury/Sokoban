/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include "my.h"

typedef struct position {
    int pos_x;
    int pos_y;
}pos_t;

typedef struct {
    char **map;
    int **pos_o;
    int nbr_o;
    int nbr_x;
    char *buffer;
    int lines;
    int *cols;
    pos_t pos;
    int win;
    int lose;
}base;

void put_in_tab(base *use);
int open_map(char const *av, base *use);
int my_error(int ac, base *use);
void display_screen(base *use, char *str, int ac);
void position_p(base *use);
void move_player(int ch, base *use);
void move_up(base *use);
void move_down(base *use);
void move_right(base *use);
void move_left(base *use);
void position_o(base *use);
void position_o_static(base *use);
void put_in_tab2(base *use, int a, int b, int c);
int win_condition(base *use);
int lose_condition(base *use);
int is_it_block(base *use, int line, int col);
int usage(void);
int is_it_block2(base *use, int line, int col);
int block_down_right(base *use, int line, int col);
int block_up_left(base *use, int line, int col);
int block_down_left(base *use, int line, int col);
#endif
