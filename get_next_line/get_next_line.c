#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof (char) + (len + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static int	len;
	static int	pos;
	static char	buf[BUFFER_SIZE + 1];
	char		line[100000];
	char		*str;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= len)
		{
			len = read(fd, buf, BUFFER_SIZE);
			pos = 0;
			if (len <= 0)
				break ;
		}
		if (line[i] == '\n')
			break ;
		line[i] = buf[pos];
		i++;
		pos++;
	}
	line[i + 1] = '\0';
	if (i == 0)
		return (NULL);
	str = ft_strdup(line);
	return (str);
}

int	main(void)
{
	int	fd;
	char	*path;
	char	*str;

	path = "test.txt";
	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
	}
	close(fd);
	free(str);
	return (0);
}

