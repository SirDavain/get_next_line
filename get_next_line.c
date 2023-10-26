/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:18:43 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/26 16:07:13 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (fd <= 0 || BUFFER_SIZE < 0)
		return (NULL);
	
}

/*
PSEUDOCODE:
check if passed fd is valid;
3 static vars:
#1: stores the read() function
#2: stores the output maybe
#3: 

If new line char is found (ft_strchr) return everything until that point and
set the var to +1 to skip it
Check the BUFFER_SIZE to see if there is still some left before calling read() again
*/