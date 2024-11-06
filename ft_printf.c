#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c, int i)
{
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_found_x(int x, int i)
{
	unsigned int	u;
	char			*hexabase;

	hexabase = "0123456789abcdef";
	u = (unsigned int)x;
	if (u == 0)
	{
		write(1, "0", 1);
		i = i + 1;
	}
	else if (u <= 15)
	{
		i = ft_putchar(hexabase[u], i);
	}
	else
	{
		i = ft_found_x(u / 16, i);
		i = ft_putchar(hexabase[u % 16], i);
	}
	return (i);
}

int	ft_found_d(int d, int i)
{
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = i + 11;
	}
	else if (d < 0)
	{
		write(1, "-", 1);
		i++;
		i = ft_found_d(-d, i);
	}
	else if (d >= 0 && d <= 9)
	{
		i = ft_putchar(d + '0', i);
	}
	else
	{
		i = ft_found_d(d / 10, i);
		i = ft_putchar(d % 10 + '0', i);
	}
	return (i);
}
int	ft_found_s(char *s, int i)
{
	if (s == NULL)
		i = ft_found_s("(null)", i);
	else
	{
		while (*s)
		{
			write(1, &(*s), 1);
			i++;
			s++;
		}
	}
	return (i);
}
int	ft_next_percent(char *format, va_list ap, int i, int j)
{
	if (format[j] == 's')
		i = ft_found_s(va_arg(ap, char *), i);
	else if (format[j] == 'd')
	{
		i = ft_found_d(va_arg(ap, int), i);
	}
	else if (format[j] == 'x')
	{
		i = ft_found_x(va_arg(ap, int), i);
	}
	return (i);
}
int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			i = ft_next_percent(format, ap, i, ++j);
		}
		else
		{
			write(1, &format[j], 1);
			i++;
		}
		j++;
	}
	va_end(ap);
	return (i);
}
/*
int	main(void)
{
	int	i;

	char	str[] = "hohoho";
	printf("printf: hello 42\n: s: %s, d: %d x: %x\n", str, -42, 42);
	ft_printf("ft_printf: hello 42\n: s: %s, d: %d x: %x\n", str, -42, 42);
	return (0);
}
*/