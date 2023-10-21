/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulrichd <ulrichd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:56:05 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/22 00:30:52 by ulrichd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(t_list *keep)
{
	int		str_len;
	char	*next_str;

	if (keep == NULL)
		return (NULL);
	
}

void	add_node(t_list **keep, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = get_last_node(*keep);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*keep = new_node;
	else
		last_node->next = new_node;
	new_node->buffer = buf;
	new_node->next = NULL;
}

void	create_list(t_list **keep, int fd)
{
	int		chars_read;
	char	*buf;

	while (!check_for_newline(*keep))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buf);
			return ;
		}
		buf[chars_read] = '\0';
		add_node(keep, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*keep = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&keep, fd);
	if (keep == NULL)
		return (NULL);
	next_line = get_the_line(keep);

	return (next_line);
}
