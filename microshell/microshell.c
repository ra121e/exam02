#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void	ft_execute(char *av[], int i, int fd_r, char *envp[])
{

}

int	main(int ac, char **av, char ** envp)
{
	int		i;

	i = 0;
	while (av[i] && av[i + 1])
	{
		i = 0;
		av = &av[i + 1];
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (i != 0 && (!av[i] || !strcmp(av[i], ";")))
		{
			if (fork() == 0)
			{
				ft_execute(av, i, fd_r, envp);
			}
			else
				close(fd_r);
				while (waitpid(-1, NULL, WUNTRACE) != -1)
					;
				fd_r = dup(STDIN_FILENO);
		}
	}
	return (0);
}