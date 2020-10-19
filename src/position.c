/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move
*/
#include "sokoban.h"

void nbr_x(base *use)
{
    for (int i = 0; use->buffer[i]; i++)
        if (use->buffer[i] == 'X')
            use->nbr_x++;
}

void position_o_static(base *use)
{
    use->nbr_o = 0;
    int a = 0;

    nbr_x(use);
    for (int i = 0; use->buffer[i]; i++)
        if (use->buffer[i] == 'O')
            use->nbr_o++;
    use->pos_o = malloc(sizeof(int *) * use->nbr_o);
    for (int i = 0; i != use->nbr_o; i++)
        use->pos_o[i] = malloc(sizeof(int) * 2);
    for (int i = 0, k = 0; i != use->lines; i++, k++)
        for (int j = 0; j != use->cols[k] + 1; j++)
            if (use->map[i][j] == 'O') {
                use->pos_o[a][0] = i;
                use->pos_o[a][1] = j;
                a++;
            }
}

void position_o(base *use)
{
    for (int k = 0; k != use->nbr_o; k++) {
        if (use->map[use->pos_o[k][0]][use->pos_o[k][1]] == 'P')
            use->map[use->pos_o[k][0]][use->pos_o[k][1]] = 'P';
        else if (use->map[use->pos_o[k][0]][use->pos_o[k][1]] == 'X')
            use->map[use->pos_o[k][0]][use->pos_o[k][1]] = 'X';
        else
            use->map[use->pos_o[k][0]][use->pos_o[k][1]] = 'O';
    }
}

void position_p(base *use)
{
    use->pos.pos_x = 0;
    use->pos.pos_y = 0;

    for (int i = 0, k = 0; i != use->lines; i++, k++)
        for (int j = 0; j != use->cols[k] + 1; j++)
            if (use->map[i][j] == 'P') {
                use->pos.pos_x = j;
                use->pos.pos_y = i;
            }
}