#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
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
	if (dest == NULL)
		return (NULL);
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
	static char	buf[BUFFER_SIZE + 1];
	int			i;
	char		line[100000];
	static int	pos;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
			pos++;
			i++;
			break ;
		}
		i++;
		pos++;
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

	path = "test.txt";
	fd = open(path, O_RDONLY);
	while (1)
	{
		if (str == NULL)
			break ;
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
	return (0);
}
*/
