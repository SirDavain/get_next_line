/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulrichd <ulrichd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:57:06 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/21 21:29:23 by ulrichd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

typedef struct	s_list
{
	char			*buffer;
	struct s_list	*next;
} t_list;

char 	*get_next_line(int fd);
char	create_list(t_list **keep, int fd);
int		check_for_newline(t_list *keep);

#endif