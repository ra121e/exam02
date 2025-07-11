#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int	parse(char **av, size_t *w, size_t *h, size_t *i)
{
	int w_ = atoi(av[1]);
	int h_ = atoi(av[2]);
	int i_ = atoi(av[3]);

	if(w_ <= 0 || h_ <= 0 || i_ < 0)
		return (1);
	*w = (size_t)w_;
	*h = (size_t)h_;
	*i = (size_t)i_;
	return (0);
}

char	**make_board(size_t w, size_t h)
{
	char	**board;
	board = (char**)malloc(sizeof(char*) * h);
	if (board == NULL)
		return (NULL);
	for (size_t i = 0; i < h; ++i)
	{
		board[i] = (char*)calloc(w, sizeof(char));
		if (board[i] == NULL)
		{
			for (size_t n = 0; n < i; ++n)
				free(board[n]);
			free(board);
			return (NULL);
		}
	}
	return (board);
}

void	read_draw(char **b, size_t w, size_t h)
{
	char	c;
	size_t	y = 0, x = 0;
	bool	pen = false;

	while (read(0, &c, 1))
	{
		if (c == 'a' && x > 0)
			x--;
		else if (c == 'w' && y > 0)
			y--;
		else if (c == 'd' && x < w - 1)
			x++;
		else if (c == 's' && y < h - 1)
			y++;
		else if (c == 'x')
			pen = !pen;
		else
			continue;
		if (pen)
			b[y][x] = 1;
	}
}

void	print_board(char **b, size_t w, size_t h)
{
	for (size_t y = 0; y < h; ++y)
	{
		for (size_t x = 0; x < w; ++x)
		{
			if (b[y][x] == 1)
				write(1, "0", 1);
			else
				write(1," ", 1);
		}
		write(1, "\n", 1);
	}
}

int	count_num(char **board, size_t y, size_t x, size_t w, size_t h)
{
	int	count = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
				continue ;
			int ny = (int)y + i;
			int nx = (int)x + j;
			if (ny >= 0 && nx >= 0 && nx < (int)w && ny < (int)h)
				if (board[ny][nx])
					count++;
		}
	}
	return (count);
}

char	**iterator(char **board, size_t w, size_t h, size_t iteration)
{
	char **next;

	next = make_board(w, h);
	for (size_t n = 0; n < iteration; n++)
	{
		for (size_t y = 0; y < w; ++y)
		{
			for (size_t x = 0; x < h; ++x)
			{
				int count = count_num(board, y, x, w, h);
				if (board[y][x] && (count == 2 || count == 3))
					next[y][x] = 1;
				else if (!board[y][x] && (count == 3))
					next[y][x] = 1;
				else
					next[y][x] = 0;
			}
		}
		char	**tmp;
		tmp = board;
		board = next;
		next = tmp;
	}
	return (board);
}

void	free_board(char **board, size_t h)
{
	for (size_t n = 0; n < h; ++n)
		free(board[n]);
	free(board);
}

int	main(int ac, char **av)
{
	size_t	w, h, i;
	char	**b;

	if (ac != 4)
		return (1);
	if(parse(av, &w, &h, &i))
		return (1);
	b = make_board(w, h);
	if (b == NULL)
		return (1);
	read_draw(b, w, h);
	if (i == 0)
	{
		print_board(b, w, h);
		free_board(b, h);
	}
	else
	{
		char	**l = iterator(b, w, h, i);
		print_board(l, w, h);
		free_board(l, h);
	}
	return (0);
}