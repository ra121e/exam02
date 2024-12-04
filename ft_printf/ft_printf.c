#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_putstr(char *str, int len)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		len = len + 6;
	}
	else
	{
		i = 0;
		while (str[i])
		{
			len = ft_putchar(str[i], len);
			i++;
		}
	}
	return (len);
}

int	ft_putnbr(int nb, int len)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = len + 11;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		len++;
		len = ft_putnbr(-nb, len);
	}
	else if (nb >= 0 && nb < 10)
	{
		len = ft_putchar(nb + '0', len);
	}
	else
	{
		len = ft_putnbr(nb / 10, len);
		len = ft_putchar(nb % 10 + '0', len);
	}
	return (len);
}

int	ft_puthexa(int nb, int len)
{
	char	*hexabase;
	unsigned int	u;

	hexabase = "0123456789abcdef";
	u = (unsigned int)nb;
	if (u == 0)
	{
		write(1, "0", 1);
		len++;
	}
	else if (u > 0 && u < 16)
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

int	ft_filter(char c, int len, va_list ap)
{
	if (c == 's')
	{
		len = ft_putstr(va_arg(ap, char *), len);
	}
	if (c == 'd')
	{
		len = ft_putnbr(va_arg(ap, int), len);
	}
	if (c == 'x')
	{
		len = ft_puthexa(va_arg(ap, int), len);
	}
	return (len);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = ft_filter(format[i + 1], len, ap);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			len++;
		}
	}
	return (len);
	va_end(ap);
}
/*
int	main(void)
{
	char	*s;
	int		d;
	int		x;
	int		len;

	s = "Singapore   gogo";
	d = -42;
	x = -1;
	len = printf("s: %s, d: %d, x: %x\n", s, d, x);
	printf("len: %d\n", len);
	len = ft_printf("s: %s, d: %d, x: %x\n", s, d, x);
	printf("len: %d\n", len);
	return (0);
}
*/