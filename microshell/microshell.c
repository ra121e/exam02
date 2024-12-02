#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void	error(char *str)
{
	while (*str)
		write (2, str++, 1);
}

int	cd(char **av, int i)
{
	if (i != 2)
	{
		error ("error: cd: bad args\n");
		return (1);
	}
	if (chdir(av[1]) == -1)
	{
		error ("error: cd: cannot change directory to \n");
		return (1);
	}
	return (0);
}

void	set_pipe(int flag_pipe, int *fd, int end)
{
	if (flag_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		error("error: dup\n");
		exit(1);
	}
}

int	exec(char **av, int i, char **envp)
{
	int	flag_pipe;
	int	fd[2];
	int	pid;
	int	status;

	flag_pipe = av[i] && !strcmp(av[i], "|");
	if (!flag_pipe && !strcmp(*av, "cd"))
	{
		return (cd(av, i));
	}
	if (flag_pipe && pipe(fd) == -1)
	{
		error("error: pip\n");
		exit(1);
	}
	if ((pid = fork()) == -1)
	{
		error("error: fork\n");
		exit(1);
	}
	if (!pid)
	{
		av[i] = 0;
		set_pipe(flag_pipe, fd, 1);
		if (!strcmp(*av, "cd"))
			exit(cd(av, i));
		execve(*av, av, envp);
		error("error: cannot execute\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(flag_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	status;

	(void)ac;
	status = 0;
	i = 0;
	while (av[i])
	{
		av = av + i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i)
			status = exec(av, i, envp);
	}
	return (status);
}