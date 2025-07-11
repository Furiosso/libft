/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagimeno <dagimeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:34:05 by dagimeno          #+#    #+#             */
/*   Updated: 2024/01/30 19:37:11 by dagimeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_p(void *content)
{
	t_list	*newnode;

	newnode = ft_alloc(sizeof(t_list), 1);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
