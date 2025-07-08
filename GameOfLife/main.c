#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

char	**make_board(size_t width, size_t height)
{
	char	**board;

	board = (char**)malloc(sizeof(char*) * height);
	if (board == NULL)
		return (NULL);
	size_t	i = 0;
	while (i < height)
	{
		board[i] = (char*)calloc(width, sizeof(char));
		if (board[i] == NULL)
		{
			size_t	n = i;
			while (n > 0)
			{
				free(board[n - 1]);
				n--;
			}
			free(board);
			return (NULL);
		}
		i++;
	}
	return (board);
}

int	parse(char **av, size_t	*width, size_t *height, size_t *iteration)
{
	int	w = atoi(av[1]);
	int	h = atoi(av[2]);
	int	i = atoi(av[3]);

	if (w <= 0 || h <= 0 || i < 0)
		return (0);
	*width = (size_t)w;
	*height = (size_t)h;
	*iteration = (size_t)i;
	return (1);
}
void	print_board(char **board, size_t width, size_t height)
{
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			if (board[y][x])
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1,"$\n", 2);
	}
}
enum e_cmd	input_check(char c)
{
	if (c == 'a')
		return (LEFT);
	else if (c == 'w')
		return (UP);
	else if (c == 'd')
		return (RIGHT);
	else if (c == 's')
		return (DOWN);
	else if (c == 'x')
		return (TOGGLE);
	else
		return (NONE);
}

void	read_draw(char **board, size_t width, size_t height)
{
	enum e_cmd	type;
	size_t		x = 0, y = 0;
	int			pen = 0;
	char		c;

	while (read(0, &c, 1))
	{
		type = input_check(c);
		switch (type)
		{
			case LEFT:
				if (x > 0)
					x--;
				break;
			case UP:
				if (y > 0)
					y--;
				break;
			case RIGHT:
				if (x < width - 1)
					x++;
				break;
			case DOWN:
				if (y < height - 1)
					y++;
				break;
			case TOGGLE:
				if (pen == 0)
					pen = 1;
				else
					pen = 0;
				break;
			case NONE:
				break;
		}
		if (pen == 1)
			board[y][x] = 1;
	}
}

void	free_board(char **board, size_t height)
{
	for (size_t i = 0; i < height; i++)
		free(board[i]);
	free(board);
}

int	main(int ac, char** av)
{
	size_t	width, height, iteration;
	char	**board;

	if (ac != 4)
	{
		printf("Usage: ./life width height iterations\n");
		return (1);
	}
	if (!parse(av, &width, &height, &iteration))
		return (1);
	board = make_board(width, height);
	if (board == NULL)
		return (1);
	read_draw(board, width, height);
//	iterator(board, width, height, iteration);
	print_board(board, width, height);
	free_board(board, height);
	return (0);
}