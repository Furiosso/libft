/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:58:10 by dagimeno          #+#    #+#             */
/*   Updated: 2024/02/02 16:56:58 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_p(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	cont;

	if (!s)
		return (NULL);
	cont = ft_strlen(s);
	if (cont <= start)
		return (ft_alloc(sizeof(char), 1));
	cont = 0;
	while (*(s + start + cont))
		cont++;
	if (cont < len)
		len = cont;
	len++;
	sbstr = ft_alloc(sizeof(char) * len, 1);
	cont = 0;
	while (cont < len - 1)
	{
		sbstr[cont] = *(s + start + cont);
		cont++;
	}
	sbstr[cont] = 0;
	return (sbstr);
}
