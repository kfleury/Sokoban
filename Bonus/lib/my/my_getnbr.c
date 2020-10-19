/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** atoy
*/
#include "my.h"

unsigned long long my_getnbr(char const *str)
{
    long long int count = 0;
    long long int negativ = 1;
    long long int nb = 0;

    for (; str[count] < '0' || str[count] > '9'; count++) {
        if (str[count] == '-')
            negativ = -negativ;
    }
    for (; str[count] >= '0' && str[count] <= '9'; count++) {
        nb *= 10;
        nb += str[count] - '0';
    }
    return (nb * negativ);
}
