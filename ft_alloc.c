#include "libft.h"

static void	*ft_new_alloc(t_list **lst, size_t size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		ft_alloc(0, 0);
		ft_putstr_fd("malloc fail\n", 2);
		exit(1);
	}
	node->content = ft_calloc(1, size);
	if (!node->content)
	{
		ft_alloc(0, 0);
		free(node);
		ft_putstr_fd("malloc fail\n", 2);
		exit (1);
	}
	node->next = NULL;
	ft_lstadd_back(lst, node);
	return (node->content);
}

void	*ft_alloc(size_t size, int mode)
{
	static t_list	*lst;

	if (mode == 0)
	{
		ft_lstclear(&lst, free);
		return (NULL);
	}
	else
		return (ft_new_alloc(&lst, size));
}
