/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:18:43 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/27 22:07:34 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_for_newline()
{
	while (the line is not \n or BUFFER_SIZE is 0)
	{
		put what is at the current position in the buf;

	}
	if (\n)
		return (something);
}

char	*get_next_line(int fd)
{
	static int		chars_read;
	static char		*output;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE); //BUFFER_SIZE + 1 instead?
	chars_read = read(fd, buf, BUFFER_SIZE);
}

/*
PSEUDOCODE:
Process: 
	check if passed fd is valid;
	read until either BUFFER_SIZE is 0 or \n was found
	if BUFFER_SIZE is 0, read again
	if \n is found, return the line
	if EOF return the line
3 static vars:
#1: stores the read() function
#2: a char pointer stores the output
#3: 

If new line char is found (ft_strchr) return everything until that point and
set the var to +1 to skip it
Check the BUFFER_SIZE to see if there is still some left before calling read() again
*/