/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulrichd <ulrichd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:56:05 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/22 21:18:01 by ulrichd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_list(t_list **keep)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = get_last_node(*keep);
	i = 0;
	j = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	while (last_node->buffer[i] && last_node->buffer[++i])
		buf[j++] = last_node->buffer[i];
	buf[j] = '\0';
	clean_node->buffer = buf;
	clean_node->next = NULL;
	free_all(keep, clean_node, buf);
}

char	*get_the_line(t_list *keep)
{
	int		str_len;
	char	*next_str;

	if (keep == NULL)
		return (NULL);
	str_len = len_of_newline(keep);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(keep, next_str);
	return (next_str);
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
