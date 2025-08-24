/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:57:34 by joabotel          #+#    #+#             */
/*   Updated: 2025/04/24 20:11:52 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*   #include <stdio.h>
void	print_list(t_list *head)
{
	while (head)
	{
		printf("%s -> ", (char *)head->content);
		head = head->next;
	}
	printf("NULL\n");
}
void	*str_toupper(void *str)
{
	if (!str)
		return (NULL);
	char	*original = (char *)str;
	char	*new_str = malloc(ft_strlen(original) + 1);
	if (!new_str)
		return (NULL);
	for (size_t i = 0; original[i]; i++)
		new_str[i] = ft_toupper(original[i]);
	new_str[ft_strlen(original)] = '\0';
	return (new_str);
}

int	main(){

	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("World");
	t_list	*node2 = ft_lstnew("Hello");
	t_list	*node3 = ft_lstnew("42");
	t_list	*node4 = ft_lstnew("Porto");

	ft_lstadd_back(&list, node1);
	ft_lstadd_front(&list, node2);
	ft_lstadd_back(&list, node3);
	ft_lstadd_back(&list, node4);

	printf("Original list:\n");
	print_list(list);

	t_list *mapped_list = ft_lstmap(list, str_toupper, free);
	printf("Mapped list:\n");
	print_list(mapped_list);
	printf("List size: %d\n", ft_lstsize(list));
}  
 */
