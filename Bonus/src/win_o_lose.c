/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** win_o_lose
*/

#include "sokoban.h"

void lose_condition2(base *use, int line, int col)
{
    if (is_it_block(use, line, col) == 1)
        use->lose++;
}

int lose_condition(base *use)
{
    use->lose = 0;

    for (int i = 0, k = 0; i != use->lines; i++, k++)
        for (int j = 0; j != use->cols[k] + 1; j++)
            if (use->map[i][j] == 'X')
                lose_condition2(use, i, j);
    if (use->lose == use->nbr_x)
        return (1);
    else
        return (0);
}

int win_condition(base *use)
{
    int win = 0;
    int nbr = use->nbr_o;

    nbr--;
    for (; nbr != -1; nbr--) {
        if (use->map[use->pos_o[nbr][0]][use->pos_o[nbr][1]] == 'X') {
            win++;
        }
    }
    if (win == use->nbr_o)
        return (1);
    else
        return (0);
}
