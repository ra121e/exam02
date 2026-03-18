#include <stdio.h>
#include <stdlib.h>

int	count_word(char *str, char delimiter)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
			count++;
		i++;
	}
	return (count);
}

char	**ft_sprit(char *str, char delimiter)
{
	int		wordnum;
	char	**words;
	int		head;
	int		pos;
	int		box;
	int		i;

	wordnum	= count_word(str, delimiter);
	printf("[debug] number of words is %d\n", wordnum);
	words = malloc(sizeof(char*) * (wordnum + 1));
	if (words == NULL)
		return (NULL);

	head = 0;
	pos = 0;
	box = 0;
	while (str[head])
	{
		if (str[head] == delimiter)
		{
//			words[box] = malloc(sizeof(char *));
//			if (words[box] == NULL)
//				return (NULL);
//			*words[box] = '\0';
//			box++;
			head++;
		}
		else
		{
			pos = head;
			while (str[pos] != '\0' && str[pos] != delimiter)
			{
				pos++;
			}
			words[box] = malloc(sizeof(char) * (pos - head + 1));
			if (words[box] == NULL)
			{
				for (int n = 0; n < box; n++)
				{
					free (words[n]);
				}
				return (NULL);
			}
			i = 0;
			while (head < pos)
			{
				words[box][i] = str[head];
				i++;
				head++;
			}
			words[box][i] = '\0';
			box++;
//			head++;
		}
	}
	words[box] = NULL;
	return (words);
}

int	main(int ac, char **av)
{
	int		i;
	char	**words;
	int		n;

	if (ac != 3)
	{
		printf("Expected 2 arguments, string and delimiter\n");
		return (1);
	}

	words = ft_sprit(av[1], *av[2]);
	if (words == NULL)
		exit (1);
	i = 0;
	while (words && words[i])
	{
		printf("%s\n", words[i]);
		i++;
	}

	n = 0;
	while (words[n])
	{
		free(words[n]);
		n++;
	}
	free(words);
}
