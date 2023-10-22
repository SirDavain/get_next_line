/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:57:22 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/22 21:53:52 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(t_list **keep, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (*keep == NULL)
		return ;
	while (*keep)
	{
		tmp = (*keep)->next;
		free((*keep)->buffer);
		free(*keep);
		*keep = tmp;
	}
	*keep = NULL;
	if (clean_node->buffer[0])
		*keep = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

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
		return (NULL);
	while (keep->next)
		keep = keep->next;
	return (keep);
}

int	len_of_newline(t_list *keep)
{
	int	i;
	int	len;
	if (keep == NULL)
		return (0);
	len = 0;
	while (keep)
	{
		i = 0;
		while (keep->buffer[i])
		{
			if (keep->buffer[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		keep = keep->next;
	}
	return (len);
}
void	copy_str(t_list *keep, char *str)
{
	int	i;
	int	j;

	if (keep == NULL)
		return ;
	j = 0;
	while (keep)
	{
		i = 0;
		while (keep->buffer[i])
		{
			if (keep->buffer[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = keep->buffer[i++];
		}
		keep = keep->next;
	}
	str[j] = '\0';
}