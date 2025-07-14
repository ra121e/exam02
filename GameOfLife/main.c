#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int	parse(char **av, int *width, int *height, int *iteration)
{
	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int i = atoi(av[3]);

	if (w <= 0 || h <= 0 || i < 0)
		return (1);
	*width = w;
	*height = h;
	*iteration = i;
	return (0);
}

char	**make_board(int width, int height)
{
	char **board;

	board = (char**)malloc(sizeof(char*) * height);
	if (board == NULL)
		return (NULL);
	for (int i = 0; i < width; ++i)
	{
		board[i] = (char*)calloc(width, sizeof(char));
		if (board[i] == NULL)
		{
			for (int n = 0; n < i; ++n)
				free(board[n]);
			free(board);
			return (NULL);
		}
	}
	return (board);
}

void	draw(char **board, int width, int height)
{
	char	c;
	int		x = 0, y = 0;
	bool	pen = false;

	while (read(0, &c, 1))
	{
		if (c == 'a' && x > 0)
			x--;
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 'd' && x < width - 1)
			x++;
		else if (c == 's' && y < height - 1)
			y++;
		else if (c == 'x')
			pen = !pen;
		else
			continue;
		if (pen)
			board[y][x] = 1;
	}
}

void	print_board(char **board, int width, int height)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (board[y][x])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

void	free_board(char **board, int height)
{
	for (int i = 0; i < height; ++i)
		free(board[i]);
	free(board);
}

int	count(char **board, int width, int height, int x, int y)
{
	int count = 0;

	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			int ny = y + i;
			int nx = x + j;
			if (ny >=0 && nx >= 0 && ny < height && nx < width)
				if (board[ny][nx] == 1)
					count++;
		}
	}
	return (count);
}

char	**iterator(char **board, int width, int height, int iteration)
{
	char	**next;
	next = make_board(width, height);
	for (int i = 0; i < iteration; ++i)
	{
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				int sum = count(board, width, height, x, y);
				if (board[y][x] && (sum == 2 || sum == 3))
					next[y][x] = 1;
				else if (!board[y][x] && sum == 3)
					next[y][x] = 1;
				else
					next[y][x] = 0;
			}
		}
		char **tmp;
		tmp = next;
		next = board;
		board = tmp;
	}
	free_board(next, height);
	return (board);
}

int	main(int ac, char **av)
{
	int width, height, iteration;

	if (ac != 4)
		return (1);
	if (parse(av, &width, &height, &iteration))
		return (1);
	char **board = make_board(width, height);
	if (board == NULL)
		return (1);
	draw(board, width, height);
	if (iteration == 0)
	{
		print_board(board, width, height);
		free_board(board, height);
	}
	else
	{
		char **last = iterator(board, width, height, iteration);
		print_board(last, width, height);
		free_board(last, height);
	}
	return (0);
}