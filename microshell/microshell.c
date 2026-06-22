#include <unistd.h> //write, pipe, fork, dup2, execve
#include <string.h> // strcmp
#include <stdlib.h> // exit
#include <sys/wait.h> //waitpid

void	err(char* msg)
{
	while (*msg)
		write(2, msg++, 1);
}

void	set_fd(int	fd[2], int end)
{
	if (dup2(fd[end], end) < 0)
	{
		err("error: fatal\n");
		exit(1);
	}
	if (close(fd[0]) < 0)
	{
		err("error: fatal\n");
		exit(1);
	}
	if (close(fd[1]) < 0)
	{
		err("error: fatal\n");
		exit(1);
	}
}

int	exec(char** av, int i, char** envp)
{
	int	status;
	int	pid;
	int	to_pipe;
	int	fd[2];

	to_pipe = 0;
	if (av[i] && !strcmp(av[i], "|"))
	{
		to_pipe = 1;
		if (pipe(fd) < 0)
		{
			err("error: fatal\n");
			exit(1);
		}
	}

	pid = fork();
	if (pid < 0)
	{
		err("error: fatal\n");
		exit(1);
	}
	else if (pid == 0)
	{
		av[i] = '\0';
		if (to_pipe == 1)
			set_fd(fd, 1);
		execve(av[0], av, envp);
		err("error: cannot execute ");
		err(av[0]);
		err("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (to_pipe == 1)
		set_fd(fd, 0);
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
