/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:19:06 by athonda           #+#    #+#             */
/*   Updated: 2024/07/11 22:27:22 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char bit[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit[i] = octet % 2 + '0';
		octet = octet / 2;
		i--;
	}
	bit[8] = '\0';
	i = 0;
	while (i < 8)
	{
		write(1, &bit[i], 1);
		i++;
	}
}

int	main(void)
{
	unsigned char	octet;

	octet = 115;
	print_bits(octet);
	return (0);
}