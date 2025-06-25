#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_dputper(int fd);
int	ft_dputchar(int fd, char c);
int	ft_dputstr(int fd, char *s);
int	ft_dputnbr(int fd, int n, int cont);

#endif