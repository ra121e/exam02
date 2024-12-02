#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define WRITE_END 1
#define READ_END 0

void	err_exit(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	builtin_cd(char *av[], int i)
{
	if (i != 2)
	{
		err_exit("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(av[1]) == -1)
	{
		err_exit("error: cd\n");
		return (1);
	}
	return (0);
}

void	set_fd(int to_pipe, int *fd, int end)
{
	if (to_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		err_exit("error: dup\n");
		exit(1);
	}
}
//void	set_fd(int to_pipe, int fd[2], int end)
//{
//	if (to_pipe)
//	{
//		dup2(fd[end], end);
//		close(fd[0]);
//		close(fd[1]);
//	}
//}

int	exec(char *av[], int i, char *envp[])
{
	int	to_pipe;
	int	fd[2];
	int	pid;
	int	status;

	if (av[i] && !strcmp(av[i], "|"))
		to_pipe = 1;
	else
		to_pipe = 0;
	if (!to_pipe && !strcmp(av[0], "cd"))
	{
		return(builtin_cd(av, i));
	}
	if (to_pipe && pipe(fd) == -1)
	{
		err_exit("error: pip\n");
		exit(1);
	}
//	if (to_pipe)
//	{
//		if (pipe(fd) == -1)
//		{
//			err_exit("error: pipe \n");
//			exit(1);
//		}
//	}
	pid = fork();
	if (pid == -1)
	{
		err_exit("error: fork\n");
		exit(1);
	}
	if (pid == 0)
	{
		av[i] = 0;
		set_fd(to_pipe, fd, WRITE_END);
		if (!strcmp(av[0], "cd"))
		{
			exit(builtin_cd(av, i));
		}
		execve(*av, av, envp);
		err_exit("error: cannot execute ");
		err_exit(*av);
		err_exit("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	set_fd(to_pipe, fd, READ_END);
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