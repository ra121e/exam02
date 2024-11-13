#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_puthexa(int x, int len)
{
	unsigned int	u;
	char			*hexabase;

	u = (unsigned int)x;
	hexabase = "0123456789abcdef";
	if (u <= 15)
		len = ft_putchar(hexabase[u], len);
	else
	{
		len = ft_puthexa(u / 16, len);
		len = ft_putchar(hexabase[u % 16], len);
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
	else if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = len + 11;
	}
	else if (d >= 0 && d <= 9)
	{
		len = ft_putchar(d % 10 + '0', len);
	}
	else
	{
		len = ft_putnbr(d / 10, len);
		len = ft_putchar(d % 10 + '0', len);
	}
	return (len);
}

int	ft_putstr(char *str, int len)
{
	if (!str)
	{
		write(1,"(null)", 6);
		len = len + 6;
	}	
	while (str && *str)
	{
		len = ft_putchar(*str, len);
		str++;
	}
	return (len);
}

int	filter(va_list ap, char c, int len)
{
	if (c == 's')
		len = ft_putstr(va_arg(ap, char *), len);
	else if (c == 'd')
		len = ft_putnbr(va_arg(ap, int), len);
	else if (c == 'x')
		len = ft_puthexa(va_arg(ap, int), len);
	return (len);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;
	
	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = filter(ap, format[i + 1], len);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
/*
int	main(void)
{
	char	s[] = "";
	int		d;
	int		x;
	int		len;

	d = 42;
	x = -42;
	len = 0;
	
	len = printf("s: %s d: %d x: %x\n", NULL, d, x);
	printf("original length: %d\n", len);
	len = ft_printf("s: %s d: %d x: %x\n", NULL, d, x);
	printf("ft length: %d\n", len);
	return (0);
}
*/
