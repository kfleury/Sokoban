/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move
*/
#include "sokoban.h"

void move_down(base *use)
{
    if (use->map[use->pos.pos_y + 1][use->pos.pos_x] == '#')
        return;
    if (use->map[use->pos.pos_y + 1][use->pos.pos_x] == 'X') {
        if (use->map[use->pos.pos_y + 2][use->pos.pos_x] == '#')
            return;
        if (use->map[use->pos.pos_y + 2][use->pos.pos_x] == 'X')
            return;
        use->map[use->pos.pos_y + 2][use->pos.pos_x] = 'X';
        use->map[use->pos.pos_y + 1][use->pos.pos_x] = 'P';
        use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
    }
    use->map[use->pos.pos_y + 1][use->pos.pos_x] = 'P';
    use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
}

void move_up(base *use)
{
    if (use->map[use->pos.pos_y - 1][use->pos.pos_x] == '#')
        return;
    if (use->map[use->pos.pos_y - 1][use->pos.pos_x] == 'X') {
        if (use->map[use->pos.pos_y - 2][use->pos.pos_x] == '#')
            return;
        if (use->map[use->pos.pos_y - 2][use->pos.pos_x] == 'X')
            return;
        use->map[use->pos.pos_y - 2][use->pos.pos_x] = 'X';
        use->map[use->pos.pos_y - 1][use->pos.pos_x] = 'P';
        use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
    }
    use->map[use->pos.pos_y - 1][use->pos.pos_x] = 'P';
    use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
}

void move_left(base *use)
{
    if (use->map[use->pos.pos_y][use->pos.pos_x - 1] == '#')
        return;
    if (use->map[use->pos.pos_y][use->pos.pos_x - 1] == 'X') {
        if (use->map[use->pos.pos_y][use->pos.pos_x - 2] == '#')
            return;
        if (use->map[use->pos.pos_y][use->pos.pos_x - 2] == 'X')
            return;
        use->map[use->pos.pos_y][use->pos.pos_x - 2] = 'X';
        use->map[use->pos.pos_y][use->pos.pos_x - 1] = 'P';
        use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
    }
    use->map[use->pos.pos_y][use->pos.pos_x - 1] = 'P';
    use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
}

void move_right(base *use)
{
    if (use->map[use->pos.pos_y][use->pos.pos_x + 1] == '#')
        return;
    if (use->map[use->pos.pos_y][use->pos.pos_x + 1] == 'X') {
        if (use->map[use->pos.pos_y ][use->pos.pos_x + 2] == '#')
            return;
        if (use->map[use->pos.pos_y][use->pos.pos_x + 2] == 'X')
            return;
        use->map[use->pos.pos_y][use->pos.pos_x + 2] = 'X';
        use->map[use->pos.pos_y][use->pos.pos_x + 1] = 'P';
        use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
    }
    use->map[use->pos.pos_y][use->pos.pos_x + 1] = 'P';
    use->map[use->pos.pos_y][use->pos.pos_x] = ' ';
}

void move_player(int ch, base *use)
{
    switch (ch) {
    case KEY_UP:
        move_up(use);
        break;

    case KEY_DOWN:
        move_down(use);
        break;

    case KEY_LEFT:
        move_left(use);
        break;

    case KEY_RIGHT:
        move_right(use);
        break;

    default:
        return;
    }
}