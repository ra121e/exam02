#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
		write(1,"\n", 1);
	}
}

void	read_draw(char **board, size_t width, size_t height)
{
	size_t		x = 0, y = 0;
	int			pen = 0;
	char		c;

	while (read(0, &c, 1))
	{
		if (c == 'a')
		{
			if (x > 0)
				x--;
		}
		else if (c == 'w')
		{
			if (y > 0)
				y--;
		}
		else if (c == 'd')
		{
			if (x < width - 1)
				x++;
		}
		else if (c == 's')
		{
			if (y < height - 1)
				y++;
		}
		else if (c == 'x')
		{
			if (pen == 0)
				pen = 1;
			else
				pen = 0;
		}
		else
			continue ;
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

int	count(char ** board, size_t y, size_t x, size_t width, size_t height)
{
	int	count = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			int	ny = (int)y + i;
			int	nx = (int)x + j;

			if (ny >= 0 && nx >= 0 && nx < (int)width && ny < (int)height)
				if (board[ny][nx] == 1)
					count++;
		}
	}
	return (count);
}

void	iterate(char **board, size_t width, size_t height, size_t iteration)
{
	char	**next;

	next = make_board(width, height);
	for (size_t n = 0; n < iteration; ++n)
	{
		for (size_t y = 0; y < height; ++y)
		{
			for (size_t x = 0; x < width; ++x)
			{
				int	sum = count(board, y, x, width, height);
				if (board[y][x] && (sum == 2 || sum == 3))
					next[y][x] = 1;
				else if (!(board[y][x]) && sum == 3)
					next[y][x] = 1;
				else
					next[y][x] = 0;
			}
		}
		char	**tmp;
		tmp = board;
		board = next;
		next = tmp;
		print_board(board, width, height);
	}
	free_board(next, height);
	free_board(board, height);
}

int	main(int ac, char** av)
{
	size_t	width, height, iteration;
	char	**board;

	if (ac != 4)
	{
//		printf("Usage: ./life width height iterations\n");
		return (1);
	}
	if (!parse(av, &width, &height, &iteration))
		return (1);
	board = make_board(width, height);
	if (board == NULL)
		return (1);
	read_draw(board, width, height);
	print_board(board, width, height);
	if (iteration == 0)
		free_board(board, height);
	else
		iterate(board, width, height, iteration);
	return (0);
}