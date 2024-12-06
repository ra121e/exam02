#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	set_fd(int to_pipe, int fd[2], int end)
{
	if (to_pipe)
	{
		if (dup2(fd[end], end) == -1)
		{
			err("error: fatal\n");
			exit(1);
		}
		if (close(fd[0]) == -1)
		{
			err("error: fatal\n");
			exit(1);
		}
		if (close(fd[1]) == -1)
		{
			err("error: fatal\n");
			exit(1);
		}
	}
}

int	builtin_cd(char **av, int i)
{
	if (i != 2)
	{
		err("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(av[1]) == -1)
	{
		err("error: cd: cannot change directory ");
		err(av[1]);
		err("\n");
		return (1);
	}
	return (0);
}

int	exec(char **av, int i, char **envp)
{
	int	pid;
	int	fd[2];
	int	to_pipe;
	int	status;

	to_pipe = 0;
	if (av[i] && !strcmp(av[i], "|"))
		to_pipe = 1;
	if (av[0] && !strcmp(av[0], "cd"))
	{
		status = builtin_cd(av, i);
		return (status);
	}
	if (pipe(fd) == -1)
	{
		err("error: fatal\n");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		err("error: fatal\n");
		exit(1);
	}
	else if (pid == 0)
	{
		av[i] = 0;
		set_fd(to_pipe, fd, 1);
		execve(av[0], av, envp);
		err("error: cannot execute ");
		err(av[0]);
		err("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	set_fd(to_pipe, fd, 0);
	return (WEXITSTATUS(status));
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