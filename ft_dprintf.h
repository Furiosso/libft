/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-04 09:40:00 by dagimeno          #+#    #+#             */
/*   Updated: 2025-07-04 09:40:00 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_dprintf(int fd, const char *string, ...);
int	ft_dputper(int fd);
int	ft_dputchar(int fd, char c);
int	ft_dputstr(int fd, char *s);
int	ft_dputnbr(int fd, int n, int cont);

#endif
