
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

#define BUFF_SIZE 55

/*typedef struct		s_line
{
	int 			fd;
	char 			**d_line;
	struct s_line 	*node;
}					t_line;*/

int		get_next_line(const int fd, char **line);

#endif
