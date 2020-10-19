/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/System.h>
#include <SFML/Audio.h>
#include <ncurses.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

typedef struct list_t
{
    long long int data;
    struct list_t *next;
}linked;

int my_strlen(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
void my_swap(char *a, char *b);
int my_str_isnum(char const *str);
char *my_revstr(char *str);
unsigned long long my_getnbr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
void my_putnbr(int nbr);
char *my_strcpy(char *dest, char const *src);
linked *my_params_to_list(int ac, char **av);
linked *my_create_list();
int *my_strcat_int(int *dest, int const *src, int size_dest, int size_src);
void print_link(linked *head);
linked *add_list(long long int data, linked *list);
int count_link(linked *head);
linked *remove_link(int num, linked *head);
void convert_in_bit(char const *str);
#endif /* !MY_H_ */
