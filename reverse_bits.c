/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:45:04 by athonda           #+#    #+#             */
/*   Updated: 2024/07/11 22:11:47 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	char	bit[9];
	int		i;
	char	tmp;
	int		result;

	i = 7;
	while (i >= 0)
	{
		bit[i] = (octet % 2) + '0';
		octet = octet / 2;
		i--;
	}
	bit[8] = '\0';
	i = 0;
	while (i < 4)
	{
		tmp = bit[i];
		bit[i] = bit[7 - i];
		bit[7 - i] = tmp;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		result = result * 2 + bit[i] - '0';
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	unsigned char octet;
	unsigned char nbr;
	char	bit[9];
	int		i;
	char	tmp;
	int		result;

	octet = 192;
	nbr = octet;
	printf("%d\n", octet);
	i = 7;
	while (i >= 0)
	{
		bit[i] = (octet % 2) + '0';
		octet = octet / 2;
		i--;
	}
	bit[8] = '\0';
	printf("%s\n", bit);
	i = 0;
	while (i < 4)
	{
		tmp = bit[i];
		bit[i] = bit[7 - i];
		bit[7 - i] = tmp;
		i++;
	}
	printf("%s\n", bit);
	printf("%d\n", reverse_bits(nbr));
	return (0);
}