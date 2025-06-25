/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:48:19 by dagimeno          #+#    #+#             */
/*   Updated: 2024/02/01 13:41:57 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_p(const char *s1)
{
	char			*str;
	unsigned int	length;

	length = 0;
	while (*(s1 + length))
		length++;
	length++;
	str = ft_alloc(sizeof(char) * length, 1);
	str[length - 1] = 0;
	while (length)
	{
		str[length - 1] = s1[length - 1];
		length--;
	}
	return (str);
}
