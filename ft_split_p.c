/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:56 by dagimeno          #+#    #+#             */
/*   Updated: 2024/02/02 13:33:26 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c);
static char		*ft_fillarray(char const *s, char c);

char	**ft_split_p(char const *s, char c)
{
	char		**matrix;
	size_t		cont;
	size_t		i;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	cont = ft_count(s, c);
	matrix = ft_alloc((cont + 1) * sizeof(char *), 1);
	i = 0;
	while (i < cont)
	{
		matrix[i] = ft_fillarray (s, c);
		i++;
		if (ft_strchr(s, c))
			s = ft_strchr(s, c);
		while (*s && *s == c)
			s++;
	}
	matrix[cont] = NULL;
	return (matrix);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	cont;

	cont = 0;
	while (*s)
	{
		cont++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (cont);
}

static char	*ft_fillarray(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ft_alloc((i + 1) * sizeof(char), 1);
	i = 0;
	while (*s && *s != c)
		str[i++] = *s++;
	str[i] = 0;
	return (str);
}
