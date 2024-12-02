#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr_fd2(char *str, char *av)
{
	while (*str)
		write (2, str++, 1);
	if (av)
		while (*av)
			write (2, av++, 1);
	write (2, "\n", 1);
}

void	ft_execute(char *av[], int i, int fd_r, char *envp[])
{
	av[i] = NULL;
	execve(av[0], av, envp);
	ft_putstr_fd2("error: cannot execute ", av[0]);
	exit (1);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		fd_r;
	int		pid;

	i = 0;
	av = &av[i + 1];
	//fd_r = dup(STDIN_FILENO);
	while (av[i] && av[i + 1])
	{
		if (i != 0 && (!av[i] || !strcmp(av[i], ";")))
		{
			pid = fork();
			if (pid == 0)
				ft_execute(av, i, fd_r, envp);
			else
			{
				//close(fd_r);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				//fd_r = dup(STDIN_FILENO);
			}
			av = &av[i + 1];
			i = 0;
		}
		else
			i++;
	}
	//close(fd_r);
	return (0);
}