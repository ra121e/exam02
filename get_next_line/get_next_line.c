#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i++])
	dest = (char *)malloc(sizeof (char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (*src)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}

char	*get_next_line(int fd)
{
	static int	len;
	static char	buf[BUFFER_SIZE + 1];
	int			i;
	static int	pos;
	char		line[100000];
	char		*str;

	i = 0;
	while (1)
	{
		if (pos >= len)
		{
			len = read(fd, buf, BUFFER_SIZE);
			if (len <= 0)
				break ;
			pos = 0;
		}
		line[i] = buf[pos];
		if (line[i] == '\n')
		{
			i++;
			pos++;
			break ;
		}
		i++;
		pos++;
	}
	line[i] = 0;
	if (i == 0)
		return (NULL);
	str = ft_strdup(line);
	return (str);
}

/*
int	main(void)
{
	int	fd;
	char path[] = "test.txt";
	char	*str;

	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
	}
	close(fd);
	return (0);
}
*/