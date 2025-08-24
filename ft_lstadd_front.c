/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joabotel <joabotel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:43:48 by joabotel          #+#    #+#             */
/*   Updated: 2025/04/15 14:46:53 by joabotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>
void print_list(t_list *head)
{
    while (head)
    {
        printf("%s -> ", (char *)head->content);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("World");
    t_list *node2 = ft_lstnew("Hello");

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    printf("List content:\n");
    print_list(list);

    free(node1);
    free(node2);
    return 0;
}*/
