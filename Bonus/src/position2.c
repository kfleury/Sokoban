/*
** EPITECH PROJECT, 2019
** Bonus
** File description:
** position2
*/
#include "sokoban.h"

void door(base *use)
{
    if (use->map[use->pos_6[0][0]][use->pos_6[0][1]] != '-') {
        if (use->map[2][24] == 'X')
            use->map[2][24] = 'X';
        else if (use->map[2][24] == 'M')
            use->map[2][24] = 'M';
        else
            use->map[2][24] = ' ';
    }
    else
        use->map[2][24] = '#';
    if (use->map[use->pos_6[1][0]][use->pos_6[1][1]] != '-') {
        if (use->map[3][25] == 'X')
            use->map[3][25] = 'X';
        else if (use->map[3][25] == 'M')
            use->map[3][25] = 'M';
        else
            use->map[3][25] = ' ';
    }
    else
        use->map[3][25] = '#';
}

void position_6_static(base *use)
{
    use->nbr_6 = 0;
    int a = 0;

    for (int i = 0; use->buffer[i]; i++)
        if (use->buffer[i] == '-')
            use->nbr_6 += 1;
    use->pos_6 = malloc(sizeof(int *) * use->nbr_6);
    for (int i = 0; i != use->nbr_6; i++)
        use->pos_6[i] = malloc(sizeof(int) * 2);
    for (int i = 0, k = 0; i != use->lines; i++, k++)
        for (int j = 0; j != use->cols[k] + 1; j++)
            if (use->map[i][j] == '-') {
                use->pos_6[a][0] = i;
                use->pos_6[a][1] = j;
                a++;
            }
}

void position_6(base *use)
{
    for (int k = 0; k != use->nbr_6; k++) {
        switch (use->map[use->pos_6[k][0]][use->pos_6[k][1]])
        {
        case 'P':
            use->map[use->pos_6[k][0]][use->pos_6[k][1]] = 'P';
            break;

        case 'M':
            use->map[use->pos_6[k][0]][use->pos_6[k][1]] = 'M';
            break;

        case 'X':
            use->map[use->pos_6[k][0]][use->pos_6[k][1]] = 'X';
            break;

        default:
            use->map[use->pos_6[k][0]][use->pos_6[k][1]] = '-';
            break;
        }
    }
}
