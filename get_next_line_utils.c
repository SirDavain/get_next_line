/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulrichd <ulrichd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:57:22 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/22 00:20:02 by ulrichd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_for_newline(t_list *keep)
{
	int	i;

	if (keep == NULL)
		return (0);
	while (keep)
	{
		i = 0;
		while (keep->buffer[i] && i < BUFFER_SIZE)
		{
			if (keep->buffer[i] == '\n')
				return (1);
			i++;
		}
		keep = keep->next;
	}
	return (0);
}

t_list	*get_last_node(t_list *keep)
{
	if (keep == NULL)
		return ;
	while (keep->next)
		keep = keep->next;
	return (keep);
}