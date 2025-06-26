/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:37:26 by dagimeno          #+#    #+#             */
/*   Updated: 2024/07/12 13:44:47 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_P_H
# define GET_NEXT_LINE_P_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}				t_buffer;

typedef struct s_fd
{
	int			fd;
	struct s_fd	*next;
	struct s_fd	*previous;
	t_buffer	*list;
}				t_index;

char		*get_next_line_p(int fd);
t_index		*create_list_p(int fd, t_index **index);
size_t		get_len_p(t_buffer *list);
void		record_first_line_p(t_buffer **list);
char		*clean_bonus_p(t_index **index, int fd);

#endif
