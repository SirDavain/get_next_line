/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulrichd <ulrichd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:57:06 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/22 09:38:19 by ulrichd          ###   ########.fr       */
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
void	create_list(t_list **keep, int fd);
int		check_for_newline(t_list *keep);
void	add_node(t_list **keep, char *buf);
t_list	*get_last_node(t_list *keep);
char	*get_the_line(t_list *keep);
void	copy_str(t_list *keep, char *str);
int		len_of_newline(t_list *keep);
void	clean_list(t_list **keep);

#endif