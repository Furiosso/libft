/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-04 09:41:47 by dagimeno          #+#    #+#             */
/*   Updated: 2025-07-04 09:41:47 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRINTF_H
# define FT_SPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_sprintf(char *str, char const *string, ...);
void	ft_sputper(char *str, int *cont);
void	ft_sputchar(char *str, int *cont, char c);
void	ft_sputstr(char *str, int *cont, char *s);
void	ft_sputnbr(char *str, int *cont, int n);

#endif