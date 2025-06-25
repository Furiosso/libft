#include "ft_dprintf.h"

int	ft_dputper(int fd);
int	ft_dputchar(int fd, char c);
int	ft_dputstr(int fd, char *s);
int	ft_dputnbr(int fd, int n, int cont);

int	ft_dputper(int fd)
{
	if (write(fd, "%", 1) < 0)
		return (0x80000000);
	return (1);
}

int	ft_dputchar(int fd, char c)
{
	if (write(fd, &c, 1) < 0)
		return (0x80000000);
	return (1);
}

int	ft_dputstr(int fd, char *s)
{
	int	cont;

	if (!s)
	{
		if (write (fd, "(null)", 6) < 0)
			return (0x80000000);
		return (6);
	}
	cont = 0;
	while (*(s + cont))
		if (write(fd, &s[cont++], 1) < 0)
			return (0x80000000);
	return (cont);
}

int	ft_dputnbr(int fd, int n, int cont)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		if (write(fd, "-", 1) < 0)
			return (0x80000000);
		cont++;
		nb = -nb;
	}
	if (nb > 9)
		cont = ft_dputnbr(fd, nb / 10, ++cont);
	if (cont < 0)
		return (0x80000000);
	nb = nb % 10 + 48;
	if (write(fd, &nb, 1) < 0)
		return (0x80000000);
	return (cont);
}
