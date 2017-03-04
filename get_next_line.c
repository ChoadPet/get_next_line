
#include "get_next_line.h"

int 	give_me_newline(char **s, char **line)
{
	int i;

	i = 0;
	while (**s != '\n' && *(*s)++)
		i++;
	if (**s == '\n')
	{
		*s -= i;
		*line = ft_strsub(*s, 0, (size_t)i);
		*s += i + 1;
	}
	else if (**s != '\n')
	{
		*s -= i;
		*line = ft_strsub(*s, 0, BUFF_SIZE);
		*s += i;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char 	*s;
	char 			*buff;
	ssize_t			i;
	int 			j;

	buff = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		(s != NULL) ? (s = ft_strjoin(s, buff)) : (s = ft_strdup(buff));
		while (!give_me_newline(&s, line))
		{
			printf("*line: %s\n", *line);
			printf("s: %s\n", s);
			printf("buff: %s\n", buff);
			return (1);
		}
	}
	if (i == (-1))
		return (-1);
	if ((i == 0) && (ft_strlen(buff) == 0))
		return (0);
}

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		write(1, "error_1\n", 8);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == (-1))
	{
		write(1, "error_2\n", 8);
		return (-2);
	}
	printf("\tWe are comin to Get_Next_Line() function\n");
	while(get_next_line(fd,  &argv[1]))
		printf("---------------------\n");
	return (0);
}

