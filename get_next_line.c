/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulrichd <ulrichd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:56:05 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/21 21:13:12 by ulrichd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	create_list(t_list **keep, int fd)
{


	while (!check_for_newline(*keep))
	{
		
	}
}

char	*get_next_line(int fd)
{
	static t_list	*keep = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&keep, fd);

	return (next_line);
}
