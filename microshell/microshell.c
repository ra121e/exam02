#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void	err(char* msg)
{
	while (*msg)
		write(2, msg++, 1);
}

void	set_fd(int	fd[2], int end)
{
	dup2(fd[end], end);
	close(fd[0]);
	close(fd[1]);
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
		pipe(fd);
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
