/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:21:50 by vpoltave          #+#    #+#             */
/*   Updated: 2017/03/17 14:10:21 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 10

typedef struct		s_bacon
{
	int				fd;
	char			*s;
	struct s_bacon	*next;
}					t_bacon;

int					get_next_line(const int fd, char **line);
void				where_is_n(char **s, char **line);
int					where_is_smth(int fd, char **line, char **s, char *buff);
char				**where_is_bacon(int fd, t_bacon **bacon);

#endif
