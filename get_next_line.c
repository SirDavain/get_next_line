/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:18:43 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/31 11:50:39 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*join_line(int nl_position, char **buf)
{
	char	*result;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
	{
		if (**buf == '\0')
		{
			free(*buf);
			*buf = NULL;
			return (NULL);
		}
		result = *buf;
		*buf = NULL;
		return (result);
	}
	tmp = ft_substr(*buf, nl_position, BUFFER_SIZE);
	result = *buf;
	result[nl_position] = 0;
	*buf = tmp;
	return (result);
}

char	*read_line(int fd, char **buf, char *read_chars)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*new_line;

	new_line = ft_strchr(*buf, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (new_line == NULL)
	{
		bytes_read = read(fd, read_chars, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buf));
		read_chars[bytes_read] = 0;
		tmp = ft_strjoin(*buf, read_chars);
		free_all(buf);
		*buf = tmp;
		new_line = ft_strchr(*buf, '\n');
	}
	return (join_line(new_line - *buf + 1, buf));
}

char	*get_next_line(int fd)
{
	static char		*buf[MAX_FD + 1];
	char			*read_chars;
	char			*the_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	read_chars = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_chars == NULL)
		return (NULL);
	if (!buf[fd])
		buf[fd] = ft_strdup("");
	the_line = read_line(fd, &buf[fd], read_chars);
	free_all(&read_chars);
	return (the_line);
}
// #include <stdio.h>
// int main(void)
// {
// 	int		fd;
// 	char	*print_line;
// 	int		lines;
// 	char	*res;

// 	lines = 1;
// 	fd = open("lorem.txt", O_RDONLY);
// 	while ((print_line = get_next_line(fd)))
// 		printf("%d->%s", lines++, print_line);
// 		//printf("%d", fd);
// 	// res = get_next_line(fd);
// 	// printf("%s", res);
// 	return (0);
// }