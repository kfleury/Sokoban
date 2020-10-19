/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move
*/
#include "sokoban.h"

void nbr_x(base *use)
{
    use->nbr_x = 0;

    for (int i = 0; use->buffer[i]; i++)
        if (use->buffer[i] == 'X')
            use->nbr_x++;
}

void position_o_static(base *use)
{
    use->nbr_o = 0;
    int a = 0;

    position_6_static(use);
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
        switch (use->map[use->pos_o[k][0]][use->pos_o[k][1]])
        {
        case 'P':
            use->map[use->pos_o[k][0]][use->pos_o[k][1]] = 'P';
            break;

        case 'X':
            use->map[use->pos_o[k][0]][use->pos_o[k][1]] = 'X';
            break;

        case 'M':
            use->map[use->pos_o[k][0]][use->pos_o[k][1]] = 'M';
            break;

        default:
            use->map[use->pos_o[k][0]][use->pos_o[k][1]] = 'O';
            break;
        }
    }
}

void position_p(base *use)
{
    use->pos.pos_x = 2;
    use->pos.pos_y = 1;

    for (int i = 0, k = 0; i != use->lines; i++, k++)
        for (int j = 0; j != use->cols[k] + 1; j++)
            if (use->map[i][j] == 'P') {
                use->pos.pos_x = j;
                use->pos.pos_y = i;
            }
}

void position_m(base *use)
{
    use->pos_m.pos_x = 2;
    use->pos_m.pos_y = 1;

    for (int i = 0, k = 0; i != use->lines; i++, k++)
        for (int j = 0; j != use->cols[k] + 1; j++)
            if (use->map[i][j] == 'M') {
                use->pos_m.pos_x = j;
                use->pos_m.pos_y = i;
            }
}