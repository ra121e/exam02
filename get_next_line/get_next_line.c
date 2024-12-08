#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof (char) * (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	int			i;
	char		line[10000];
	static int	len;
	static char	buf[BUFFER_SIZE + 1];
	static int	pos;
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
		else
		{
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
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	str = ft_strdup(line);
	return (str);
}

/*
int	main(void)
{
	int	fd;
	char	*path;
	char	*str;

	path = "./test";
	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
	}
	return (0);
}
*/