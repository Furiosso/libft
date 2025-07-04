/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-04 09:41:24 by dagimeno          #+#    #+#             */
/*   Updated: 2025-07-04 09:41:24 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

void	ft_sputper(char *str, int *cont)
{
	str[(*cont)++] = '%';
}

void	ft_sputchar(char *str, int *cont, char c)
{
	str[(*cont)++] = c;
}

void	ft_sputstr(char *str, int *cont, char *s)
{
	int	i;

	if (!s)
	{
		ft_strlcpy(&str[*cont], "(null)", 7);
		*cont += 6;
		return ;
	}
	i = 0;
	while (*(s + i))
	{
		ft_sputchar(str, cont, s[i]);
		i++;
	}
}

void	ft_sputnbr(char *str, int *cont, int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		str[(*cont)++] = '-';
		nb = -nb;
	}
	if (nb > 9)
		ft_sputnbr(str, cont, nb / 10);
	nb = nb % 10 + 48;
	str[(*cont)++] = nb;
}
