/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:12:45 by athonda           #+#    #+#             */
/*   Updated: 2024/07/11 20:02:37 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char   swap_bits(unsigned char octet)
{
	unsigned char   ones;
	unsigned char   tens;
	unsigned char   result;

	tens = "0123456789:;<=>?"[octet / 16];
	ones = "0123456789:;<=>?"[octet % 16];
	result = 0;
	result = (ones - '0') * 16 + tens - '0';
	return (result);
}

int main(void)
{
	unsigned char octet;
	unsigned char   ones;
	unsigned char   tens;

	octet = 125;
	printf("%d\n", octet);
	tens = "0123456789ABCDEF"[octet / 16];
	ones = "0123456789ABCDEF"[octet % 16];
	printf("%c%c\n", tens, ones);
	printf("%c%c\n", ones, tens);
	printf("%d\n", swap_bits(octet));

	return (0);
}
