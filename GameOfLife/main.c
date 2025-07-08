#include <stdio.h>
#include <unistd.h>

int	main(int ac, char** av)
{
	size_t	width, height, iteration
	char	**board;

	if (ac != 4)
	{
		printf("Usage: ./life width height iterations\n");
		return (1);
	}
	if(!validate(ac, av))
		return (1);
	board = make_board(width, height);
	if (board == NULL)
		return (1);
	read_draw(board, width, height);
	iterator(board, width, height, iteration);
	free(board, height);
	return (0);
}