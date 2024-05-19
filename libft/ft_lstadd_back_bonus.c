/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:41:02 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/05 21:18:49 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Adds the node ’new’ at the end of the lst.
/// @param lst lst which get extendet by new on the end
/// @param new new node for lst
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	end = *lst;
	while (end -> next != NULL)
	{
		end = end -> next;
	}
	end -> next = new;
	return ;
}

// #include <stdio.h>
// void	print_list(t_list *head)
// {
// 	t_list *current = head;
// 	while (current != NULL){
// 		printf("%d -> ", *((int *)current -> content));
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// }
// int	main(void)
// {
// 	t_list 		*head = NULL;
// 	int 		data1 = 42;
// 	int			data2 = 23;
// 	int 		data3 = 48;
// 	t_list *node1 = ft_lstnew(&data1);
// 	t_list *node2 = ft_lstnew(&data2);
// 	t_list *node3 = ft_lstnew(&data3);
// 	node1->next = node2;
// 	node2->next = node3;
// 	head = node1;
// 	printf("Linked List before adding to the front: ");
//     print_list(head);
// 	int data4 = 1;
// 	t_list	*new = ft_lstnew(&data4);
// 	int data5 = 9;
// 	t_list	*new2 = ft_lstnew(&data5);
// 	ft_lstadd_front(&head, new);
// 	printf("Linked List after adding to the front: ");
//     print_list(head);
// 	ft_lstadd_back(&head, new2);
// 	print_list(head);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	free(new);
// 	return (0);
// }
