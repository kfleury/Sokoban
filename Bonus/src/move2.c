/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move
*/
#include "sokoban.h"

void move2_down(base *use)
{
    if (use->map[use->pos_m.pos_y + 1][use->pos_m.pos_x] == '#')
        return;
    if (use->map[use->pos_m.pos_y + 1][use->pos_m.pos_x] == 'X') {
        if (use->map[use->pos_m.pos_y + 2][use->pos_m.pos_x] == '#')
            return;
        if (use->map[use->pos_m.pos_y + 2][use->pos_m.pos_x] == 'X')
            return;
        use->map[use->pos_m.pos_y + 2][use->pos_m.pos_x] = 'X';
        use->map[use->pos_m.pos_y + 1][use->pos_m.pos_x] = 'M';
        use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
    }
    use->map[use->pos_m.pos_y + 1][use->pos_m.pos_x] = 'M';
    use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
}

void move2_up(base *use)
{
    if (use->map[use->pos_m.pos_y - 1][use->pos_m.pos_x] == '#')
        return;
    if (use->map[use->pos_m.pos_y - 1][use->pos_m.pos_x] == 'X') {
        if (use->map[use->pos_m.pos_y - 2][use->pos_m.pos_x] == '#')
            return;
        if (use->map[use->pos_m.pos_y - 2][use->pos_m.pos_x] == 'X')
            return;
        use->map[use->pos_m.pos_y - 2][use->pos_m.pos_x] = 'X';
        use->map[use->pos_m.pos_y - 1][use->pos_m.pos_x] = 'M';
        use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
    }
    use->map[use->pos_m.pos_y - 1][use->pos_m.pos_x] = 'M';
    use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
}

void move2_left(base *use)
{
    if (use->map[use->pos_m.pos_y][use->pos_m.pos_x - 1] == '#')
        return;
    if (use->map[use->pos_m.pos_y][use->pos_m.pos_x - 1] == 'X') {
        if (use->map[use->pos_m.pos_y][use->pos_m.pos_x - 2] == '#')
            return;
        if (use->map[use->pos_m.pos_y][use->pos_m.pos_x - 2] == 'X')
            return;
        use->map[use->pos_m.pos_y][use->pos_m.pos_x - 2] = 'X';
        use->map[use->pos_m.pos_y][use->pos_m.pos_x - 1] = 'M';
        use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
    }
    use->map[use->pos_m.pos_y][use->pos_m.pos_x - 1] = 'M';
    use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
}

void move2_right(base *use)
{
    if (use->map[use->pos_m.pos_y][use->pos_m.pos_x + 1] == '#')
        return;
    if (use->map[use->pos_m.pos_y][use->pos_m.pos_x + 1] == 'X') {
        if (use->map[use->pos_m.pos_y ][use->pos_m.pos_x + 2] == '#')
            return;
        if (use->map[use->pos_m.pos_y][use->pos_m.pos_x + 2] == 'X')
            return;
        use->map[use->pos_m.pos_y][use->pos_m.pos_x + 2] = 'X';
        use->map[use->pos_m.pos_y][use->pos_m.pos_x + 1] = 'M';
        use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
    }
    use->map[use->pos_m.pos_y][use->pos_m.pos_x + 1] = 'M';
    use->map[use->pos_m.pos_y][use->pos_m.pos_x] = ' ';
}

void move2_player(int ch, base *use)
{
    switch (ch) {
    case 'z':
        move2_up(use);
        break;

    case 's':
        move2_down(use);
        break;

    case 'q':
        move2_left(use);
        break;

    case 'd':
        move2_right(use);
        break;

    default:
        return;
    }
}
