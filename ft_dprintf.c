#include "ft_dprintf.h"

static int	parse_argument(int fd, va_list ap, char item);
static int	ft_putuns(int fd, unsigned int x, int cont);
static int	ft_puthex(int fd, unsigned int x, char item, int cont);
static int	ft_putptr(int fd, unsigned long x, int cont);

int	ft_dprintf(int fd, char const *string, ...)
{
	va_list	ap;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	va_start(ap, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			cont += parse_argument(fd, ap, string[i++]);
			if (cont < 0)
				return (-1);
			continue ;
		}
		if (write(fd, &string[i++], 1) < 0)
			return (-1);
		cont++;
	}
	va_end(ap);
	return (cont);
}

static int	parse_argument(int fd, va_list ap, char item)
{
	int	cont;

	cont = 0;
	if (item == '%')
		cont += ft_dputper(fd);
	else if (item == 'c')
		cont += ft_dputchar(fd, va_arg(ap, int));
	else if (item == 's')
		cont += ft_dputstr(fd, va_arg(ap, char *));
	else if (item == 'p')
		cont += ft_putptr(fd, va_arg(ap, unsigned long), 1);
	else if (item == 'i' || item == 'd')
		cont += ft_dputnbr(fd, va_arg(ap, int), 1);
	else if (item == 'u')
		cont += ft_putuns(fd, va_arg(ap, unsigned int), 1);
	else if (item == 'x' || item == 'X')
		cont += ft_puthex(fd, va_arg(ap, unsigned int), item, 1);
	return (cont);
}

static int	ft_putuns(int fd, unsigned int x, int cont)
{
	if (x > 9)
		cont = ft_putuns(fd, x / 10, ++cont);
	if (cont < 0)
		return (0x80000000);
	x = x % 10 + 48;
	if (write(fd, &x, 1) < 0)
		return (0x80000000);
	return (cont);
}

static int	ft_puthex(int fd, unsigned int x, char item, int cont)
{
	char			*hexa;
	unsigned int	aux;

	aux = x;
	hexa = "0123456789abcdef";
	if (item == 'X')
		hexa = "0123456789ABCDEF";
	if (aux >= 16)
	{
		aux /= 16;
		cont = ft_puthex(fd, aux, item, ++cont);
	}
	if (cont < 0)
		return (0x80000000);
	aux = x % 16;
	if (write(fd, &hexa[aux], 1) < 0)
		return (0x80000000);
	return (cont);
}

static int	ft_putptr(int fd, unsigned long x, int cont)
{
	char			*hexa;
	unsigned long	aux;

	if (cont == 1)
	{
		if (write(fd, "0x", 2) < 0)
			return (0x80000000);
		cont += 2;
	}
	aux = x;
	hexa = "0123456789abcdef";
	if (aux >= 16)
	{
		aux /= 16;
		cont = ft_putptr(fd, aux, ++cont);
	}
	if (cont < 0)
		return (0x80000000);
	aux = x % 16;
	if (write(fd, &hexa[aux], 1) < 0)
		return (0x80000000);
	return (cont);
}
