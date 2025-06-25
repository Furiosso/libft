#include "ft_sprintf.h"

int			ft_sprintf(char *str, char const *string, ...);
static void	parse_argument(va_list ap, char *str, int *cont, char item);
static void	ft_putuns(char *str, int *cont, unsigned int x);
static void	ft_puthex(char *str, int *cont, unsigned int x, char item);
static void	ft_putptr(char *str, int *cont, unsigned long x, int flag);

int	ft_sprintf(char *str, char const *string, ...)
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
			parse_argument(ap, str, &cont, string[i]);
			i++;
			continue ;
		}
		str[cont] = string[i];
		i++;
		cont++;
	}
	str[cont] = '\0';
	va_end(ap);
	return (cont);
}

static void	parse_argument(va_list ap, char *str, int *cont, char item)
{
	if (item == '%')
		ft_sputper(str, cont);
	else if (item == 'c')
		ft_sputchar(str, cont, va_arg(ap, int));
	else if (item == 's')
		ft_sputstr(str, cont, va_arg(ap, char *));
	else if (item == 'p')
		ft_putptr(str, cont, va_arg(ap, unsigned long), 1);
	else if (item == 'i' || item == 'd')
		ft_sputnbr(str, cont, va_arg(ap, int));
	else if (item == 'u')
		ft_putuns(str, cont, va_arg(ap, unsigned int));
	else if (item == 'x' || item == 'X')
		ft_puthex(str, cont, va_arg(ap, unsigned int), item);
}

static void	ft_putuns(char *str, int *cont, unsigned int x)
{
	if (x > 9)
		ft_putuns(str, cont, x / 10);
	x = x % 10 + 48;
	str[(*cont)++] = x;
}

static void	ft_puthex(char *str, int *cont, unsigned int x, char item)
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
		ft_puthex(str, cont, aux, item);
	}
	aux = x % 16;
	str[(*cont)++] = hexa[aux];
}

static void	ft_putptr(char *str, int *cont, unsigned long x, int flag)
{
	char			*hexa;
	unsigned long	aux;

	if (flag)
	{
		ft_strlcpy(&str[*cont], "0x", 3);
		*cont += 2;
	}
	aux = x;
	hexa = "0123456789abcdef";
	if (aux >= 16)
	{
		aux /= 16;
		ft_putptr(str, cont, aux, 0);
	}
	aux = x % 16;
	str[(*cont)++] = hexa[aux];
}
