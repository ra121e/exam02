/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 07:54:13 by athonda           #+#    #+#             */
/*   Updated: 2024/09/19 11:57:53 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	static char	buf[BUFFER_SIZE + 1];
	size_t		len;
	static char	*p;
	char		*box;
	int			i;
	int			j;

	box = malloc()
	i = 0;
	while (1)
	{
		if (p)
		{
			while (*p && *p != '\n')
			{
				box[i] = *p;
				p++;
				i++;
			}
			if (*p == '\n')
			{
				p++;
				box[i] = '\0';
				return (box);
			}
			if (p >= buf + len)
				p = NULL;
		}
		else
		{
			len = read(fd, buf, BUFFER_SIZE);
			if (len < 0)
				return (NULL);
			else if (len == 0)
			{
				box[i] = '\0';
				return (box);
			}
			else if (len > 0)
			{
				p = buf;
				while (len && *p != '\n')
				{
					box[i] = *p;
					p++;
					i++;
					len--;
				}
				if (*p == '\n')
				{
					p++;
					break ;
				}
			}
		}
	}
	box[i] = '\n';
	box[i + 1] = '\0';
	return (box);
}