/*
** EPITECH PROJECT, 2019
** my
** File description:
** sokoban
*/
#include "sokoban.h"

void free_all(base *use)
{
    free(use->buffer);
    free(use->cols);
    for (int i = 0; i != use->lines; i++)
        free(use->map[i]);
    free(use->map);
}

void malloc_tab(base *use)
{
    use->lines = 0;
    for (int i = 0; use->buffer[i]; i++)
        if (use->buffer[i] == '\n')
            use->lines++;
    use->cols = malloc(sizeof(int) * use->lines);
    for (int i = 0, j = 0; i != use->lines; i++, j++)
        for (int cmp = 0; use->buffer[j] != '\n'; j++, cmp++)
            use->cols[i] = cmp + 1;
    use->map = malloc(sizeof(char *) * use->lines);
    for (int i = 0; i != use->lines; i++)
        use->map[i] = malloc(sizeof(char) * (use->cols[i] + 1));
}

void put_in_tab(base *use)
{
    int b = 0;
    int c = 0;

    malloc_tab(use);
    for (int a = 0; use->buffer[a]; a++, c++) {
        if (use->buffer[a] == '\n') {
            use->map[b][c] = '\n';
            b++;
            c = -1;
        }
        put_in_tab2(use, b, a, c);
    }
}

int open_map(char const *av, base *use)
{
    struct stat data;
    int fd = 0;
    int len = 0;
    int size = 0;

    stat(av, &data);
    len = data.st_size;
    use->buffer = malloc(sizeof(char) * len + 1);
    fd = open(av, O_RDONLY);
    if (fd == -1) {
        write(2, "Invalid file\n", 14);
        exit(84);
    }
    size = read(fd, use->buffer, len + 1);
    use->buffer[size] = '\0';
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    base use;
    use.pos.pos_x = 0;
    use.pos.pos_y = 0;
    use.win = 0;
    use.music.win = sfMusic_createFromFile("music/win.wav");
    use.music.lose = sfMusic_createFromFile("music/lose.wav");
    use.music.music = sfMusic_createFromFile("music/music.ogg");

    initscr();
    keypad(stdscr, TRUE);
    open_map(av[1], &use);
    my_error(ac, &use);
    put_in_tab(&use);
    position_m(&use);
    position_p(&use);
    position_o_static(&use);
    sfMusic_play(use.music.music);
    display_screen(&use, av[1], ac);
    free_all(&use);
    return (0);
}