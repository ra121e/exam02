#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}
int	ft_putstr(char *str, int len)
{
	if (!str)
	{
		write(1, "(null)", 6);
		len = len + 6;
	}
	else
	{
		while (*str)
		{
			len = ft_putchar(*str, len);
			str++;
		}
	}
	return (len);
}

int	ft_putnbr(int d, int len)
{
	
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = len + 11;
	}
	else if (d < 0)
	{
		len = ft_putchar('-', len);
		len = ft_putnbr(-d, len);
	}
	else if (d >= 0 && d <= 9)
	{
		len = ft_putchar(d + '0', len);
	}
	else
	{
		len = ft_putnbr(d / 10, len);
		len = ft_putchar(d % 10 + '0', len);
	}
	return (len);
}

int	ft_puthexa(int x, int len)
{
	unsigned int	u;	
	char			*hexabase;

	u = (unsigned int)x;
	hexabase = "0123456789abcdef";
	if (u == 0)
	{
		write(1, "0", 1);
		len++;
	}
	else if (u <= 15)
	{
		len = ft_putchar(hexabase[u % 16], len);
	}
	else
	{
		len = ft_puthexa(u / 16, len);
		len = ft_putchar(hexabase[u % 16], len);
	}
	return (len);
}

int	ft_filter(va_list ap, char c, int len)
{
	if (c == 's')
		len = ft_putstr(va_arg(ap, char *), len);
	else if (c == 'd')
	{
		len = ft_putnbr(va_arg(ap, int), len);
	}
	else if (c == 'x')
	{
		len = ft_puthexa(va_arg(ap, int), len);
	}
	return (len);
}

int	ft_printf(char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = ft_filter(ap, format[i + 1], len);
			i++;
		}
		else 
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

/*
int	main(void)
{
	char	s[] = "hogehoge";
	int		d;
	int		x;
	int		len;

	d = -42;
	x = -1;
	len = printf("s: %s d: %d x: %x\n", s, d, x);
	printf("len: %d\n", len);
	len = ft_printf("s: %s d: %d x: %x\n", s, d, x);
	printf("len: %d\n", len);

	return (0);
}
*/
