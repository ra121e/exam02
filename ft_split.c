/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:03:34 by athonda           #+#    #+#             */
/*   Updated: 2024/07/26 15:42:39 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_word(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != '\0' && (str[i] >= '!' && str[i] <= '~'))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *str)
{
	int	count;
	int	i;
	int	j;
	int	k;
	int	n;
	int	start;
	char	**word;

	count = count_word(str);
	if (count == 0)
		return (NULL);
	word = (char **)malloc(sizeof (char *) * (count + 1));
	if (word == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] >= '!' && str[i] <= '~')
		{
			j = 0;
			start = i;
			while (str[i] != '\0' && (str[i] >= '!' && str[i] <= '~'))
			{
				i++;
				j++;
			}
			word[k] = (char *)malloc(sizeof (char) * (j + 1));
			if (word[k] == NULL)
			{
				while (k >= 0)
				{
					free(word[k]);
					k--;
				}
				free(word);
				return (NULL);
			}
			n = 0;
			while (n < j)
			{
				word[k][n] = str[start + n];
				n++;
			}
			word[k][n] = '\0';
			k++;
		}
	}
	word[k] = NULL;
	return (word);
}

int	main(int argc, char **argv)
{
	char	**word;
	int		i;

	if (argc == 2)
	{
		word = ft_split(argv[1]);
		i = 0;
		while (word[i])
		{
			printf("%s\n", word[i]);
			i++;
		}
		while (i >= 0)
		{
			free(word[i]);
			i--;
		}
		free(word);
	}
	return (0);
}