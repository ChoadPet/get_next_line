
#include "get_next_line.h"

int     fucking_line(char *buff)
{
    int i;
    int j;

    i = -1;
    while (buff[++i] != '\n' && buff[i])
        i++;
    return (i);
}

int     get_next_line(const int fd, char **line)
{
    static char buff[BUFF_SIZE + 1];
    char        *s;
    int         i;

    s = ft_strnew(BUFF_SIZE);
    if (read(fd, buff, BUFF_SIZE) == 0)
        return (0);
    s = buff;
    return (1);
}

int     main(int argc, char **argv)
{
    int     fd;
    char    **line;


    if (argc != 2)
    {
        write(1, "arguments_error\n", 16);
        return (-1);
    }
    if ((fd = open(argv[1], O_RDONLY)) == (-1));
    {
        write(1, "open_error\n", 11);
        return (-2);
    }
    get_next_line(fd, **line);
    return (0);
}
