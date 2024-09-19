/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:10 by athonda           #+#    #+#             */
/*   Updated: 2024/09/19 08:12:41 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!(str))
			break ;
		i = 0;
		while (str)
		{
			write(1, str, 1);
			str++;
		}
	}
	return (0);
}