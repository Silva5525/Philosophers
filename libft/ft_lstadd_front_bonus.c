/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:28:48 by wdegraf           #+#    #+#             */
/*   Updated: 2023/11/09 15:46:15 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/// @brief Adds the node ’new’ at the beginning of the list.
/// @param lst is the list which takes new on the beginnging 
/// @param new node for the beginning
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
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
// 	ft_lstadd_front(&head, new);
// 	printf("Linked List after adding to the front: ");
//     print_list(head);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	free(new);
// 	return (0);
// }
